//
//  SpriteShader.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/6.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "SpriteShader.h"

namespace gEngine {
    const GLfloat SpriteShader::initTexCoord[] =
    {
        1.0f, 1.0f,
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f
    };
    
    SpriteShader::SpriteShader(std::string vertexShaderpath, std::string fragmentShaderPath): TextureShader(vertexShaderpath, fragmentShaderPath)
    {
        glGenBuffers(1, &mTexCoordBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, mTexCoordBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(initTexCoord), initTexCoord, GL_DYNAMIC_DRAW);
    }
    
    SpriteShader::~SpriteShader()
    {
        glDeleteBuffers(1, &mTexCoordBuffer);
    }
    
    void SpriteShader::setTextureCoordinate(const std::vector<GLfloat>& texCoord)
    {
        glBindBuffer(GL_ARRAY_BUFFER, mTexCoordBuffer);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * texCoord.size(), &texCoord[0]); //Use a trick
    }
    
    void SpriteShader::activateShader(std::vector<GLfloat> pixelColor, glm::mat4 vpMatrix)
    {
        SimpleShader::activateShader(pixelColor, vpMatrix);
        
        //now binds the proper texture coordinate buffer
        glBindBuffer(GL_ARRAY_BUFFER, mTexCoordBuffer);
        glVertexAttribPointer(getShaderTextureCoordAttribute(), 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(getShaderTextureCoordAttribute());
    }
    
}// namespace gEngine