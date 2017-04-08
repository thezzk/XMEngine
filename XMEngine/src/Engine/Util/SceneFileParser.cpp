//
//  SceneFileParser.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/8.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "SceneFileParser.h"
#include "ResourceMap.h"
#include "DefaultResources.h"


namespace gEngine{
    
  
    SceneFileParser::SceneFileParser(std::string sceneFilePath)
    {
        mSceneXml = (ResourceMap::getInstance())->retrieveAsset<XMLAsset>(sceneFilePath);
    }
    
    
    XmlElmListType SceneFileParser::getElm(std::string tagElm)
    {
    
        assert(mSceneXml.get() != NULL);
        
        const tinyxml2::XMLElement* scene = (mSceneXml->getXMLDoc()).RootElement();
        
        XmlElmListType retval;
        const tinyxml2::XMLElement* elm = scene->FirstChildElement(tagElm.c_str());
        while(elm != NULL && std::strcmp(elm->Name(), tagElm.c_str()) == 0)
        {
            retval.push_back(elm);
            elm = elm->NextSiblingElement();
        }
        return retval;
    }
    
    std::shared_ptr<Camera> SceneFileParser::parseCamera()
    {
        XmlElmListType camElm = getElm("Camera");
        float cx = camElm[0]->FindAttribute("CenterX")->FloatValue();
        float cy = camElm[0]->FindAttribute("CenterY")->FloatValue();
        float w = camElm[0]->FindAttribute("Width")->FloatValue();
        std::vector<float> viewport = xmlStringSplit<float>(camElm[0]->FindAttribute("Viewport")->Value());
        std::vector<float> bgColor = xmlStringSplit<float>(camElm[0]->FindAttribute("BgColor")->Value());
        
        std::shared_ptr<Camera> cam(new Camera(glm::vec2(cx, cy), w, viewport));
        cam->setBackgroundColor(bgColor);
        return cam;
    }
    void SceneFileParser::parseSquares(std::vector<std::shared_ptr<Renderable>>& squares)
    {
        XmlElmListType squareElms = getElm("Square");
        
        for(int i = 0; i < squareElms.size(); i++)
        {
            float x = squareElms[i]->FindAttribute("PosX")->FloatValue();
            float y = squareElms[i]->FindAttribute("PosY")->FloatValue();
            float w = squareElms[i]->FindAttribute("Width")->FloatValue();
            float h = squareElms[i]->FindAttribute("Height")->FloatValue();
            float r = squareElms[i]->FindAttribute("Rotation")->FloatValue();
            std::vector<float> c =
            xmlStringSplit<float>(squareElms[i]->FindAttribute("Color")->Value());
            //create square and set it
            std::shared_ptr<Renderable> sq(new Renderable());
            sq->setColor(c);
            sq->getXform().setPosition(x, y);
            sq->getXform().setRotationInDegree(r);
            sq->getXform().setSize(w, h);
            squares.push_back(sq);
        }
    }
    
    void SceneFileParser::parseTextureSquares(std::vector<std::shared_ptr<Renderable>>& squares)
    {
        XmlElmListType squareElms = getElm("TextureSquare");
        
        for(int i = 0; i < squareElms.size(); i++)
        {
            float x = squareElms[i]->FindAttribute("PosX")->FloatValue();
            float y = squareElms[i]->FindAttribute("PosY")->FloatValue();
            float w = squareElms[i]->FindAttribute("Width")->FloatValue();
            float h = squareElms[i]->FindAttribute("Height")->FloatValue();
            float r = squareElms[i]->FindAttribute("Rotation")->FloatValue();
            std::string path(squareElms[i]->FindAttribute("Texture")->Value());
            std::vector<float> c =
            xmlStringSplit<float>(squareElms[i]->FindAttribute("Color")->Value());
            //create square and set it
            std::shared_ptr<TextureRenderable> sq(new TextureRenderable(path));
            sq->setColor(c);
            sq->getXform().setPosition(x, y);
            sq->getXform().setRotationInDegree(r);
            sq->getXform().setSize(w, h);
            squares.push_back(sq);
        }
        
        
    }
    
} //namespace gEngine