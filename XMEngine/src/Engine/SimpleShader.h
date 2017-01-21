//
//  SimpleShader.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/20.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SimpleShader_hpp
#define SimpleShader_hpp

#include "iostream"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace gEngine{
class SimpleShader
{
public:
    SimpleShader(std::string vertexFilePath, std::string fragmentFilePath);
    void activateShader();
    GLuint getShader();
private:
    GLuint mCompiledShader;
    GLuint mShaderVertexPositionAttribute;
    
};
}// namespace gEngine
#endif /* SimpleShader_hpp */
