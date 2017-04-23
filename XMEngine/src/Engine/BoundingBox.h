//
//  BoundingBox.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef BoundingBox_hpp
#define BoundingBox_hpp

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "Transform.h"

namespace gEngine{
    
class Projection
{
public:
    Projection(float min, float max);
    ~Projection();
    
public:
    bool overlap(Projection* proj);
    
public:
    float getMin() const;
    float getMax() const ;
    
private:
    float min ;
    float max ;
};

class OBB
{
public:
    friend OBB;
    OBB(std::vector<glm::vec2> v);
    ~OBB();
    
public:  
    bool isCollidWithOBB(OBB* obb);  
    
private:
    std::vector<glm::vec2> getAxies();
    Projection getProjection(glm::vec2 axie);

private:  
    std::vector<glm::vec2> vertex;
};
    
class BoundingBox
{
public:
    BoundingBox();
    BoundingBox(glm::vec2 sizeScale, glm::vec2 offset);
    glm::vec2 getSizeScale() const;
    void setSizeScale(glm::vec2 sizeSca);
    glm::vec2 getOffset() const;
    void setOffset(glm::vec2 off);
    std::vector<glm::vec2> getBoxVertex(Transform transform);
private:
    
    glm::vec2 sizeScale;
    glm::vec2 offset;
    
};
    
}// namespace gEngine

#endif /* BoundingBox_hpp */
