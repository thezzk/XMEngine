//
//  EngineFonts.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/11.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "EngineFonts.h"
#include "ResourceMap.h"
#include "TextFileLoader.h"
#include "EngineTexture.h"
#include "XMLAsset.h"
#include "TextureAsset.h"

namespace gEngine{
    
    void Fonts::loadFont(std::string fontName)
    {
        if(!(gEngine::ResourceMap::getInstance())->isAssetLoaded(fontName))
        {
            std::string fontInfoSourceString = fontName + ".fnt";
            std::string textureSourceString = fontName + ".tga";
            
            (ResourceMap::getInstance())->asyncLoadRequest(fontName);
            (Textures::getInstance())->loadTexture(textureSourceString);
            (TextFileLoader::getInstance())->loadTextFile(fontInfoSourceString, TextFileLoader::E_XML_FILE);
            storeLoadedFont(fontName);
        }
        else
        {
            (ResourceMap::getInstance())->incAssetRefCount(fontName);
        }
    }
    
    void Fonts::storeLoadedFont(std::string fontName)
    {
        std::string fontInfoSourceString = fontName + ".fnt";
        std::shared_ptr<XMLAsset> xmlAsset = (ResourceMap::getInstance())->retrieveAsset<XMLAsset>(fontInfoSourceString);
        std::string fontTexString = fontName + ".tga";
        std::shared_ptr<TextureAsset> texAsset = (ResourceMap::getInstance())->retrieveAsset<TextureAsset>(fontTexString);
        std::shared_ptr<FontAsset> fontAsset = std::shared_ptr<FontAsset>(new FontAsset(xmlAsset, texAsset));
        (ResourceMap::getInstance())->asyncLoadCompleted(fontName, fontAsset);
    }
    
    void Fonts::unloadFont(std::string fontName)
    {
        (ResourceMap::getInstance())->unloadAsset(fontName);
        if(!((ResourceMap::getInstance())->isAssetLoaded(fontName)))
        {
            std::string fontInfoSourceString = fontName + ".fnt";
            std::string textureSourceString = fontName + ".tga";
            
            (Textures::getInstance())->unloadTexture(textureSourceString);
            (TextFileLoader::getInstance())->unloadTextFile(fontInfoSourceString);
        }
    }
    
    Fonts::CharacterInfo Fonts::getCharInfo(std::string fontName, char aChar)
    {
        std::shared_ptr<FontAsset> fontInfo = (ResourceMap::getInstance())->retrieveAsset<FontAsset>(fontName);
        const std::shared_ptr<XMLAsset> fontXML = fontInfo->getFontInfo();
        const tinyxml2::XMLDocument& fontXMLDoc = fontXML->getXMLDoc();
        const tinyxml2::XMLElement* root = fontXMLDoc.RootElement();
        assert(root != NULL);
        const tinyxml2::XMLElement* commonInfoElement = root->FirstChildElement("common");
        assert(commonInfoElement != NULL);
        GLint charHeight = commonInfoElement->FindAttribute("base")->IntValue();
        const tinyxml2::XMLElement* charsInfoElement = root ->FirstChildElement("chars");
        assert(charsInfoElement != NULL);
        const tinyxml2::XMLElement* aCharInfoElement = charsInfoElement -> FirstChildElement("char");
        while(1)
        {
            if(aCharInfoElement == NULL)
            {
                CharacterInfo retval;
                return retval;
            }
            if(aCharInfoElement->FindAttribute("id")->IntValue() == aChar)
            {
                break;
            }
            aCharInfoElement = aCharInfoElement -> NextSiblingElement();
        }
        TextureAsset::TextureInfo texInfo = fontInfo->getTextureInfo()->getTextureInfo();
        GLint leftPixel = aCharInfoElement->FindAttribute("x")->IntValue();
        GLint rightPixel = leftPixel + aCharInfoElement->FindAttribute("width")->IntValue() - 1;
        GLint topPixel = (texInfo.height - 1) - aCharInfoElement->FindAttribute("y")->IntValue();
        GLint bottomPixel = topPixel - aCharInfoElement->FindAttribute("height")->IntValue() + 1;
        
        CharacterInfo retval;
        retval.mTexCoordLeft = (GLfloat)leftPixel / (GLfloat)(texInfo.width - 1);
        retval.mTexCoordTop = (GLfloat)topPixel / (GLfloat)(texInfo.height - 1);
        retval.mTexCoordRight = (GLfloat)rightPixel / (GLfloat)(texInfo.width - 1);
        retval.mTexCoordBottom = (GLfloat)bottomPixel / (GLfloat)(texInfo.height -1);
        
        GLint charWidth = aCharInfoElement->FindAttribute("xadvance")->IntValue();
        retval.mCharWidth = (GLfloat)aCharInfoElement->FindAttribute("width")->IntValue() / (GLfloat)charWidth;
        retval.mCharHeight = (GLfloat)aCharInfoElement->FindAttribute("height")->IntValue() / (GLfloat)charHeight;
        retval.mCharWidthOffset = (GLfloat)aCharInfoElement->FindAttribute("xoffset")->IntValue() / (GLfloat)charWidth;
        retval.mCharHeightOffset = (GLfloat)aCharInfoElement->FindAttribute("yoffset")->IntValue() / (GLfloat)charHeight;
        retval.mCharAspectRation = (GLfloat)charWidth / (GLfloat)charHeight;
        return retval;
    }

}// namespace gEngine