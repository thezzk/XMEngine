//
//  Transform.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/24.
//  Copyright © 2017年 thezzk. All rights reserved.
//
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>

#include "Transform.h"

namespace gEngine {
    
Transform::Transform():mPosition(glm::vec2(0.0f, 0.0f)), mScale(glm::vec2(1.0f, 1.0f)), mRotationInRad(0.0f)
{
        
}
/* Position */
void Transform::setPosition(GLfloat xPos, GLfloat yPos)
{
    setXPos(xPos);
    setYPos(yPos);
}
glm::vec2 Transform::getPosition()
{
    return mPosition;
}
void Transform::setXPos(GLfloat xPos)
{
    mPosition.x = xPos;
}
GLfloat Transform::getXPos()
{
    return mPosition.x;
}
void Transform::setYPos(GLfloat yPos)
{
    mPosition.y = yPos;
}
GLfloat Transform::getYPos()
{
    return mPosition.y;
}
void Transform::incXPosBy(GLfloat delta)
{
    mPosition.x += delta;
    mPosition.x = mPosition.x;
}
void Transform::incYPosBy(GLfloat delta)
{
    mPosition.y += delta;
}

/* Scale */
void Transform::setSize(GLfloat width, GLfloat height)
{
    setWidth(width);
    setHeight(height);
}
glm::vec2 Transform::getSize()
{
    return mScale;
}
void Transform::setWidth(GLfloat width)
{
    mScale.x = width;
}
GLfloat Transform::getWidth()
{
    return mScale.x;
}
void Transform::setHeight(GLfloat height)
{
    mScale.y = height;
}
GLfloat Transform::getHeight()
{
    return mScale.y;
}
void Transform::incWidthBy(GLfloat delta)
{
    mScale.x += delta;
}
void Transform::incHeightBy(GLfloat delta)
{
    mScale.y += delta;
}
void Transform::incSizeBy(GLfloat delta)
{
    mScale.x += delta;
    mScale.y += delta;
}

/* Rotation */
void Transform::setRotationInRad(GLfloat rotationInRadians)
{
    mRotationInRad  = rotationInRadians;
}
void Transform::setRotationInDegree(GLfloat rotationInDegree)
{
    mRotationInRad  = rotationInDegree * M_PI / 180.0;
}
GLfloat Transform::getRotationInRad()
{
    return mRotationInRad;
}
GLfloat Transform::getRotationInDegree()
{
    return mRotationInRad * 180.0 / M_PI;
}
void Transform::incRotationByRad(GLfloat delta)
{
    mRotationInRad += delta;
}

void Transform::incRotationByDegree(GLfloat delta)
{
    mRotationInRad += (delta / 180.0) * M_PI;
}


glm::mat4 Transform::getModelMatrix()
{
    glm::mat4 matrix = glm::mat4(1.0f);
    //Step1: compute translatiom
    matrix = glm::translate(matrix, glm::vec3(getXPos(), getYPos(), 0.0f));
    //Step2: concatenate with rotation
    matrix = glm::rotate(matrix, getRotationInRad(), glm::vec3(0.0f, 0.0f, 1.0f));
    //Step3: concatenate with scaling
    matrix = glm::scale(matrix, glm::vec3(getWidth(), getHeight(), 1.0));
    return matrix;
}
   
}// namespace gEngine