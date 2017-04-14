//
//  SimpleShader.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/20.
//  Copyright © 2017年 thezzk. All rights reserved.
//
#include "fstream"

#include "SimpleShader.h"
#include "EngineVertexBuffer.h"
#include "ResourceMap.h"

namespace gEngine {

SimpleShader::~SimpleShader()
{
    glDetachShader(mCompiledShader, vertexShaderID);
    glDetachShader(mCompiledShader, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

GLuint SimpleShader::compileShader(const std::string path, GLuint shaderType)
{
    //Step A: Get the shader source
    std::string shaderSource = ((ResourceMap::getInstance())->retrieveAsset<TextAsset>(path))->getTextContent();
    //Step B: Create the shader based on the source type: vertex or fragement
    GLuint shaderID = glCreateShader(shaderType);
    //Step C: Compile and created shader
    char const* shaderSourcePointer = shaderSource.c_str();
    glShaderSource(shaderID, 1, &shaderSourcePointer, NULL);
    glCompileShader(shaderID);
    //Step D: check for error and return result
    GLint result = GL_FALSE;
    int infoLogLength;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength > 0)
    {
        std::vector<char> shaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(shaderID, infoLogLength, NULL, &shaderErrorMessage[0]);
        printf("%s\n", &shaderErrorMessage[0]);
    }
    assert(result == GL_TRUE);
    return shaderID;
}
    
SimpleShader::SimpleShader(std::string vertexFilePath, std::string fragmentFilePath)
{
    //A: load and compile vertex and fragment shaders
    vertexShaderID = compileShader(vertexFilePath, GL_VERTEX_SHADER);
    fragmentShaderID  = compileShader(fragmentFilePath, GL_FRAGMENT_SHADER);
    //B: Create and link the shaders into a program and hold the PROGRAM ID
    mCompiledShader = glCreateProgram();
    glAttachShader(mCompiledShader, vertexShaderID);
    glAttachShader(mCompiledShader, fragmentShaderID);
    glLinkProgram(mCompiledShader);
    //C: check for error and detach/delete shader
    GLint result = GL_FALSE;
    int infoLogLength;
    glGetProgramiv(mCompiledShader, GL_LINK_STATUS, &result);
    glGetProgramiv(mCompiledShader, GL_INFO_LOG_LENGTH, &infoLogLength);
    if( infoLogLength > 0)
    {
        std::vector<char> programErrorMessage(infoLogLength + 1);
        glGetProgramInfoLog(mCompiledShader, infoLogLength, NULL, &programErrorMessage[0]);
        printf("%s\n", &programErrorMessage[0]);
    }
    assert(result == GL_TRUE);
    
    glDetachShader(mCompiledShader, vertexShaderID);
    glDetachShader(mCompiledShader, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
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

GLuint SimpleShader::getShader()
{
    return this->mCompiledShader;
}
    
} //namespace gEngine