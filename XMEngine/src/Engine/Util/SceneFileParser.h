//
//  SceneFileParser.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/8.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SceneFileParser_hpp
#define SceneFileParser_hpp

#include "iostream"
#include "vector"
#include "sstream"

#include "tinyxml2.h"
#include "XMLAsset.h"
#include "Camera.h"
#include "Renderable.h"
#include "TextureRenderable.h"

namespace gEngine{
typedef std::vector<const tinyxml2::XMLElement*> XmlElmListType;
    
class SceneFileParser
{
public:
    SceneFileParser(std::string sceneFilePath);
    XmlElmListType getElm(std::string tagElm);
    
    template <typename T>
    static std::vector<T> xmlStringSplit(std::string str)
    {
        std::stringstream ss(str);
        T var;
        std::vector<T> varArray;
        while(ss >> var)
        {
            varArray.push_back(var);
        }
        return varArray;
    }
    
    // unstable code
    std::shared_ptr<Camera> parseCamera();
    void parseSquares(std::vector<std::shared_ptr<Renderable>>& squares);
    void parseTextureSquares(std::vector<std::shared_ptr<Renderable>>& squares);
    
private:
    std::shared_ptr<XMLAsset> mSceneXml;
};
    
} //namespace gEngine

#endif /* SceneFileParser_hpp */
