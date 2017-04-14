//
//  Renderable.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef Renderable_hpp
#define Renderable_hpp

#include "iostream"
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "SimpleShader.h"
#include "Transform.h"

namespace gEngine{

class Renderable
{
public:
    Renderable();
    virtual ~Renderable();
    virtual void draw(glm::mat4 vpMatrix);
    void setShader(std::shared_ptr<SimpleShader> s);
    std::shared_ptr<SimpleShader> getShader();
    virtual void setColor(std::vector<GLfloat> color);
    virtual std::vector<GLfloat> getColor();
    Transform& getXform();
private:
    std::shared_ptr<SimpleShader> mShader;
    Transform mXform;
    std::vector<GLfloat> mColor;
};

}// namespace gEngine
#endif /* Renderable_hpp */
