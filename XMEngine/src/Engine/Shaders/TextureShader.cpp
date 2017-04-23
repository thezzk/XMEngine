//
//  TextureShader.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/24.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "TextureShader.h"
#include "EngineVertexBuffer.h"

namespace gEngine {
    TextureShader::TextureShader(std::string vertexShaderPath, std::string fragmentShaderPath):SimpleShader(vertexShaderPath, fragmentShaderPath)
    {
        mShaderTextureCoordAttribute = glGetAttribLocation(SimpleShader::getShader(), "aTextureCoordinate");
    }
    
    
    void TextureShader::activateShader(std::vector<GLfloat> pixelColor, std::shared_ptr<const Camera> aCamera)
    {
        //Call the super class's activate
        SimpleShader::activateShader(pixelColor, aCamera);
        
        //enable texture coordinate array
        glBindBuffer(GL_ARRAY_BUFFER, (VertexBuffer::getInstance())->getGLTexCoordRef());
        glEnableVertexAttribArray(mShaderTextureCoordAttribute);
        glVertexAttribPointer(mShaderTextureCoordAttribute, 2, GL_FLOAT, false, 0, (void*)0);
    }
    
    const GLuint TextureShader::getShaderTextureCoordAttribute()
    {
        return mShaderTextureCoordAttribute;
    }
    
    TextureShader::~TextureShader()
    {
        
    }
}
