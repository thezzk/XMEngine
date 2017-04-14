//
//  Transform.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/24.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace gEngine {
    
class Transform
{
public:
    Transform();
    
    /* Position */
    void setPosition(GLfloat xPos, GLfloat yPos);
    glm::vec2 getPosition();
    void setXPos(GLfloat xPos);
    GLfloat getXPos();
    void setYPos(GLfloat yPos);
    GLfloat getYPos();
    void incXPosBy(GLfloat delta);
    void decXPosBy(GLfloat delta);
    void incYPosBy(GLfloat delta);
    void decYPosBy(GLfloat delta);
    
    /* Scale */
    void setSize(GLfloat width, GLfloat height);
    glm::vec2 getSize();
    void setWidth(GLfloat width);
    GLfloat getWidth();
    void setHeight(GLfloat height);
    GLfloat getHeight();
    void incSizeBy(GLfloat delta);
    void decSizeBy(GLfloat delta);
    void incWidthBy(GLfloat delta);
    void incHeightBy(GLfloat delta);
    
    /* Rotation */
    void setRotationInRad(GLfloat rotationInRadians);
    void setRotationInDegree(GLfloat rotationInDegree);
    GLfloat getRotationInRad();
    GLfloat getRotationInDegree();
    void incRotationByDegree(GLfloat delta);
    void decRotationByDegree(GLfloat delta);
    void incRotationByRad(GLfloat delta);
    void decRotationByRad(GLfloat delta);
    
    //Get the matrix as result
    glm::mat4 getModelMatrix();
    
private:
    glm::vec2 mPosition;
    glm::vec2 mScale;
    GLfloat mRotationInRad;
    
};

} // namespace gEngine

#endif /* Transform_hpp */
