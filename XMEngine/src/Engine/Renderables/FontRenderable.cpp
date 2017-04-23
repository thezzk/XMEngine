//
//  FontRenderable.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/12.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "FontRenderable.h"
#include "DefaultResources.h"

namespace gEngine{
    
    FontRenderable::FontRenderable(std::string aString)
    {
        mFont = (DefaultResources::getInstance())->getDefaultFont();
        OneCharRenderable = std::shared_ptr<SpriteRenderable>(new SpriteRenderable(mFont + ".tga"));
        mText = aString;
    }
    
    FontRenderable::~FontRenderable()
    {
        
    }
    
    void FontRenderable::draw(std::shared_ptr<const Camera> aCamera)
    {
        GLfloat widthOfOneChar = getXform().getWidth() / (GLfloat)mText.size();
        GLfloat heightOfOneChar = getXform().getHeight();
        GLfloat yPos = getXform().getYPos();
        GLfloat xPos = getXform().getXPos();
        for(int i = 0; i < mText.size(); i++)
        {
            char aChar = mText.at(i);
            Fonts::CharacterInfo charInfo = (Fonts::getInstance())->getCharInfo(mFont, aChar);
            //Texture coord
            OneCharRenderable->setElementUVCoordinate(charInfo.mTexCoordLeft, charInfo.mTexCoordRight, charInfo.mTexCoordBottom, charInfo.mTexCoordTop);
            
            //size of the char
            GLfloat xSize = widthOfOneChar * charInfo.mCharWidth;
            GLfloat ySize = heightOfOneChar * charInfo.mCharHeight;
            (OneCharRenderable->getXform()).setSize(xSize, ySize);
            
            //Offset
            GLfloat xOffset = widthOfOneChar * charInfo.mCharWidthOffset * 0.5f;
            GLfloat yOffset = heightOfOneChar * charInfo.mCharHeightOffset * 0.5f;
            
            (OneCharRenderable->getXform()).setPosition(xPos - xOffset, yPos - yOffset);
            OneCharRenderable->draw(aCamera);
            xPos += widthOfOneChar;
        }
    }
    
    std::string FontRenderable::getText()
    {
        return mText;
    }
    
    void FontRenderable::setText(std::string text)
    {
        mText = text;
        setTextHeight(getXform().getHeight());
    }
    
    std::string FontRenderable::getFont()
    {
        return mFont;
    }
    
    void FontRenderable::setFont(std::string font)
    {
        mFont =font;
        OneCharRenderable->setTexturePath(font + ".tga");
    }
    
    void FontRenderable::setColor(std::vector<GLfloat> c)
    {
        OneCharRenderable->setColor(c);
    }
    
    std::vector<GLfloat> FontRenderable::getColor()
    {
        return OneCharRenderable->getColor();
    }
    
    void FontRenderable::setTextHeight(GLfloat h)
    {
        Fonts::CharacterInfo charInfo = (Fonts::getInstance())->getCharInfo(mFont, 'A');
        GLfloat w = h * charInfo.mCharAspectRation;
        (getXform()).setSize(w * mText.size(), h);
        
    }
    
}// namespace gEngine