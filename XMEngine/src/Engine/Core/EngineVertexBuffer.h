//
//  EngineVertexBuffer.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef EngineVertexBuffer_hpp
#define EngineVertexBuffer_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "SingletonBase.h"

namespace gEngine {

class VertexBuffer: public SingletonBase<VertexBuffer>
{
public:
    friend SingletonBase<VertexBuffer>;
    void initialize();
    const GLuint getGLVertexRef() const;
private:
    /*Singleton pattern support*/
    VertexBuffer(){}
    VertexBuffer(const VertexBuffer&){}
    VertexBuffer &operator=(const VertexBuffer&);
    /*-------------------------*/
    
    const static GLfloat verticesOfSquare[];
    GLuint mSquareVertexBuffer;
    
};
} // namespace gEngine

#endif /* EngineVertexBuffer_hpp */
