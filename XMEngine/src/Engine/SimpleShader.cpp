//
//  SimpleShader.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/20.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "SimpleShader.h"
#include "shader.h"
#include "EngineVertexBuffer.h"

namespace gEngine {
SimpleShader::SimpleShader(std::string vertexFilePath, std::string fragmentFilePath)
{
    //A: load and compile vertex and fragment shaders
    //B: Create and link the shaders into a program and hold the PROGRAM ID
    //C: "LoadShaders" gets responsible for checking errorsa
    mCompiledShader = LoadShaders(vertexFilePath.c_str(), fragmentFilePath.c_str());
    
    //D: Gets a reference to the aSquareVertexPosition attribute
    this->mShaderVertexPositionAttribute = glGetAttribLocation(this->mCompiledShader,
                                                               "aSquareVertexPosition");
    
    //E: Activates the vertex buffer initialized in Core
    glBindBuffer(GL_ARRAY_BUFFER, (VertexBuffer::getInstance())->getGLVertexRef());
    
    //F:Describe the characteristic of the vertex position attribute
    glVertexAttribPointer(
                          this->mShaderVertexPositionAttribute,
                          3,        //each element is a 3-float (x,y,z)
                          GL_FLOAT,  //data type is FLOAT
                          false,    //if the content is normalized vectors
                          0,        //number of bytes to skip in between elements
                          (void*)0  //offsets to the first element
    );
}
void SimpleShader::activateShader()
{
    glUseProgram(this->mCompiledShader);
    glEnableVertexAttribArray(this->mShaderVertexPositionAttribute);
}

inline GLuint SimpleShader::getShader()
{
    return this->mCompiledShader;
}
    
} //namespace gEngine