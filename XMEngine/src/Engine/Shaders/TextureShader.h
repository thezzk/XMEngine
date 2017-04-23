//
//  TextureShader.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/24.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef TextureShader_hpp
#define TextureShader_hpp

#include <iostream>

#include "SimpleShader.h"

namespace gEngine {
    
class TextureShader: public SimpleShader
{
public:
    TextureShader(std::string vertexShaderPath, std::string fragmentShaderPath);
    virtual ~TextureShader();
    virtual void activateShader(std::vector<GLfloat> pixelColor, std::shared_ptr<const Camera> aCamera);
    const GLuint getShaderTextureCoordAttribute();

private:
    GLuint mShaderTextureCoordAttribute;
    
};
    
}// namespce gEngine

#endif /* TextureShader_hpp */
