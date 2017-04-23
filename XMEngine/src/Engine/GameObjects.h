//
//  GameObjects.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef GameObjects_hpp
#define GameObjects_hpp

#include <iostream>
#include "BoundingBox.h"
#include "Renderable.h"


namespace gEngine{

class GameObject
{
public:
    typedef enum
    {
        SELF_SPACE = 0,
        WORLF_SPACE = 1
    }SpaceType;
    
    GameObject(std::shared_ptr<Renderable> renderableObj);
    Transform& getXform();
    virtual void update();
    virtual void draw(std::shared_ptr<const Camera> camera);
    std::shared_ptr<Renderable> getRenderable();
    void setVisibility(bool v);
    bool isVisible() const;
    void setCurrentFrontDir(glm::vec2 frontDir);
    glm::vec2 getCurrentFrontDir() const;
    void setBoundingBox(std::shared_ptr<BoundingBox> box);
    std::shared_ptr<BoundingBox> getBoundingBox() const;
    
    
    void translate(glm::vec2 dir, SpaceType relSpaceType);
    void rotateInDegree(GLfloat degree);
    void rotateInRad(GLfloat rad);
    
private:
    std::shared_ptr<Renderable> mRenderComponent;
    std::shared_ptr<BoundingBox> mBoundingBox;
    bool mVisible;
    glm::vec2 mCurrentFrontDir;
    
};
    
}// namespace gEngine

#endif /* GameObjects_hpp */
