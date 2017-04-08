//
//  Renderable.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "Renderable.h"
#include "EngineCore.h"
#include "DefaultResources.h"

namespace gEngine {

Renderable::Renderable():mShader((DefaultResources::getInstance())->getConstColorShader()),mColor({1, 1, 1, 1})
{
}
    
Renderable::~Renderable()
{
    
}

void Renderable::draw(glm::mat4 vpMatrix)
{
    mShader->activateShader(mColor, vpMatrix);
    mShader->loadObjectTransform(mXform.getModelMatrix());
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Renderable::setShader(std::shared_ptr<SimpleShader> s)
{
    mShader = s;
}

std::shared_ptr<SimpleShader> Renderable::getShader()
{
    return mShader;
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