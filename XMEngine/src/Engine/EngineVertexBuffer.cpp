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
    
void VertexBuffer::initialize()
{
    //Step A: Create a buffer on the context for our vertex positions
    glGenBuffers(1, &mSquareVertexBuffer);
    //Step B: Activate vertexBuffer
    glBindBuffer(GL_ARRAY_BUFFER, mSquareVertexBuffer);
    //Step C: Loads verticesOfSquare into the vertexBuffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesOfSquare), verticesOfSquare, GL_STATIC_DRAW);
}
const GLuint VertexBuffer::getGLVertexRef() const
{
    return mSquareVertexBuffer;
}
    
} //namespace gEngine
