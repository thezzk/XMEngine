//
//  DefaultResources.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/2.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef DefaultResources_hpp
#define DefaultResources_hpp

#include "iostream"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "SingletonBase.h"
#include "SimpleShader.h"
#include "TextureShader.h"
#include "SpriteShader.h"
#include "EngineCore.h"

namespace gEngine{

class DefaultResources:public SingletonBase<DefaultResources>
{
public:
    friend SingletonBase<DefaultResources>;
    void createShaders();
    void initialize();
    std::shared_ptr<SimpleShader> getConstColorShader();
    std::shared_ptr<TextureShader> getTextureShader();
    std::shared_ptr<SpriteShader> getSpriteShader();
    static void LoadCompleteCallback()
    {
        std::cout<<"load Resources complete, this is the callback"<<std::endl;
        (DefaultResources::getInstance())->createShaders();
        //StartScene
        (Core::getInstance())->startScene((Core::getInstance())->getCurrentScene());
    }
private:
    //Singleton pattern support
    DefaultResources(){};
    DefaultResources(const DefaultResources&){};
    DefaultResources &operator=(const DefaultResources&);
    
    const std::string kSimpleVS = "src/GLSLShaders/SimpleVS.glsl";
    const std::string kSimpleFS = "src/GLSLShaders/SimpleFS.glsl";
    const std::string kTextureVS = "src/GLSLShaders/TextureVS.glsl";
    const std::string kTextureFS = "src/GLSLShaders/TextureFS.glsl";
    
    std::shared_ptr<SimpleShader> mConstColorShader;
    std::shared_ptr<TextureShader> mTextureShader;
    std::shared_ptr<SpriteShader> mSpriteShader;
};
    
} //namespace gEngine

#endif /* DefaultResources_hpp */
