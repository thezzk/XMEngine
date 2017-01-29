//
//  Renderable.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "Renderable.h"
#include "EngineCore.h"

namespace gEngine {

Renderable::Renderable(SimpleShader shader):mShader(shader),mColor({1, 1, 1, 1})
{
}

void Renderable::draw(glm::mat4 vpMatrix)
{
    GLFWwindow* window = (Core::getInstance())->getGLWindow();
    mShader.activateShader(mColor, vpMatrix);
    mShader.loadObjectTransform(mXform.getModelMatrix());
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Renderable::setColor(std::vector<GLfloat> color)
{
    mColor = color;
}

std::vector<GLfloat> Renderable::getColor()
{
    return mColor;
}
    
Transform& Renderable::getXform()
{
    return mXform;
}

}// namespace gEngine