//
//  EngineVertexBuffer.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "EngineVertexBuffer.h"
namespace gEngine{
    
const GLfloat VertexBuffer::verticesOfSquare[]=
{
    0.5,    0.5,    0.0,
    -0.5,   0.5,    0.0,
    0.5,    -0.5,   0.0,
    -0.5,   -0.5,   0.0
};
   
const GLfloat VertexBuffer::textureCoordinates[]=
{
    1.0, 1.0,
    0.0, 1.0,
    1.0, 0.0,
    0.0, 0.0
};
    
void VertexBuffer::initialize()
{
    //Step A: Allocate and store vertex positions into the GL context
    //Create a buffer
    glGenBuffers(1, &mSquareVertexBuffer);
    //Activate vertexBuffer
    glBindBuffer(GL_ARRAY_BUFFER, mSquareVertexBuffer);
    //Loads verticesOfSquare into the vertexBuffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesOfSquare), verticesOfSquare, GL_STATIC_DRAW);
    
    //Step B: Allocate and store texture coordinates
    //Create buffer
    glGenBuffers(1, &mTextureCoordBuffer);
    //Activate texture coordinate buffer
    glBindBuffer(GL_ARRAY_BUFFER, mTextureCoordBuffer);
    //Loads textureCoordinates into the textureCoordBuffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoordinates), textureCoordinates, GL_STATIC_DRAW);
}
const GLuint VertexBuffer::getGLVertexRef() const
{
    return mSquareVertexBuffer;
}

const GLuint VertexBuffer::getGLTexCoordRef() const
{
    return mTextureCoordBuffer;
}
    
} //namespace gEngine
