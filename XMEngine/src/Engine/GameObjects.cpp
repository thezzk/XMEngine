//
//  GameObjects.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "GameObjects.h"
#include "MathExtension.h"

namespace gEngine {
    
    GameObject::GameObject(std::shared_ptr<Renderable> renderableObj)
    {
        mCurrentFrontDir = glm::vec2(0.0f, 1.0f);
        mRenderComponent = renderableObj;
        mVisible = true;
    }
    
    Transform& GameObject::getXform()
    {
        return mRenderComponent->getXform();
    }
    
    void GameObject::update()
    {
        
    }
    
    void GameObject::draw(std::shared_ptr<const Camera> camera)
    {
        if(mVisible)
            mRenderComponent->draw(camera);
    }
    
    std::shared_ptr<Renderable> GameObject::getRenderable()
    {
        return mRenderComponent;
    }
    
    void GameObject::setVisibility(bool v)
    {
        mVisible = v;
    }
    
    bool GameObject::isVisible() const
    {
        return mVisible;
    }
    
    void GameObject::setCurrentFrontDir(glm::vec2 frontDir)
    {
        mCurrentFrontDir = frontDir;
    }
    
    glm::vec2 GameObject::getCurrentFrontDir() const
    {
        return mCurrentFrontDir;
    }
    
    void GameObject::setBoundingBox(std::shared_ptr<BoundingBox> box)
    {
        mBoundingBox = box;
    }
    
    std::shared_ptr<BoundingBox> GameObject::getBoundingBox() const
    {
        return mBoundingBox;
    }
    
    void GameObject::translate(glm::vec2 dir, SpaceType relSpaceType)
    {
        Transform& mXform = getXform();
        if(relSpaceType == SELF_SPACE)
        {
            mXform.incXPosBy(mCurrentFrontDir[0] * dir[1] + mCurrentFrontDir[1] * dir[0]);
            mXform.incYPosBy(mCurrentFrontDir[1] * dir[1] - mCurrentFrontDir[0] * dir[0]);
        }
        else if(relSpaceType == WORLF_SPACE)
        {
            mXform.incXPosBy(dir[0]);
            mXform.incYPosBy(dir[1]);
        }
    }
    
    void GameObject::rotateInRad(GLfloat rad)
    {
        mCurrentFrontDir = glm::rotate_2d(mCurrentFrontDir, rad);
        Transform& mXform = getXform();
        mXform.incRotationByRad(rad);
    }
    
    void GameObject::rotateInDegree(GLfloat degree)
    {
        mCurrentFrontDir = glm::rotate_2d(mCurrentFrontDir, M_PI * (degree / 180.0f));
        Transform& mXform = getXform();
        mXform.incRotationByDegree(degree);
    }
    
    
}// namespace gEngine
