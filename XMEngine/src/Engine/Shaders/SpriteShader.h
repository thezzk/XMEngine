//
//  SpriteShader.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/6.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SpriteShader_hpp
#define SpriteShader_hpp

#include "iostream"

#include "TextureShader.h"

namespace gEngine {
    
    class SpriteShader: public TextureShader
    {
    public:
        SpriteShader(std::string vertexShaderpath, std::string fragmentShaderPath);
        virtual ~SpriteShader();
        void setTextureCoordinate(const std::vector<GLfloat>& texCoord);
        virtual void activateShader(std::vector<GLfloat> pixelColor, glm::mat4 vpMatrix);
    private:
        GLuint mTexCoordBuffer;
        const static GLfloat initTexCoord[];
 
    };
    
}// namespace gEngine

#endif /* SpriteShader_hpp */
