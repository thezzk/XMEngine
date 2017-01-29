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
    Renderable(SimpleShader shader);
    void draw(glm::mat4 vpMatrix);
    void setColor(std::vector<GLfloat> color);
    std::vector<GLfloat> getColor();
    Transform& getXform();
private:
    SimpleShader mShader;
    Transform mXform;
    std::vector<GLfloat> mColor;
};

}// namespace gEngine
#endif /* Renderable_hpp */
