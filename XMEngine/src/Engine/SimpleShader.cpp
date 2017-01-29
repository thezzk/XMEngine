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
    
    //F: Describe the characteristic of the vertex position attribute
    glVertexAttribPointer(
                          this->mShaderVertexPositionAttribute,
                          3,        //each element is a 3-float (x,y,z)
                          GL_FLOAT,  //data type is FLOAT
                          false,    //if the content is normalized vectors
                          0,        //number of bytes to skip in between elements
                          (void*)0  //offsets to the first element
    );
    
    //G: Gets a reference  to the uniform variable: uPixelColor, uModelTransform, uViewProjTransform
    this->mPixelColor = glGetUniformLocation(this->mCompiledShader, "uPixelColor");
    this->mModelTransform = glGetUniformLocation(this->mCompiledShader, "uModelTransform");
    this->mViewProjTransform = glGetUniformLocation(this->mCompiledShader, "uViewProjTransform");
}
    
void SimpleShader::activateShader(std::vector<GLfloat> pixelColor, glm::mat4 vpMatrix)
{
    glUseProgram(this->mCompiledShader);
    glUniformMatrix4fv(mViewProjTransform, 1, GL_FALSE, &vpMatrix[0][0]);
    glEnableVertexAttribArray(this->mShaderVertexPositionAttribute);
    assert(pixelColor.size() >= 4);
    glUniform4fv(mPixelColor, 1, pixelColor.data());
}

void SimpleShader::loadObjectTransform(glm::mat4 modelTransform)
{
    glUniformMatrix4fv(mModelTransform, 1, GL_FALSE, &modelTransform[0][0]);
}

inline GLuint SimpleShader::getShader()
{
    return this->mCompiledShader;
}
    
} //namespace gEngine