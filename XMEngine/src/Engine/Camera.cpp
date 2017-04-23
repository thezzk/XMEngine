//
//  Camera.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/28.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "Camera.h"
namespace gEngine {
    
Camera::Camera(glm::vec2 wcCenter, GLfloat wcWidth, std::vector<GLfloat> viewportArray): mWCCenter(wcCenter), mWCWidth(wcWidth), mViewport(viewportArray), mNearPlane(0.0f), mFarPlane(1000.0f), mBgColor({0.8, 0.8, 0.8, 0.8})
{
}

Camera::Camera():mWCCenter(glm::vec2(20, 60)), mWCWidth(20.f), mViewport({20, 40, 600, 300}), mNearPlane(0.0f), mFarPlane(1000.0f), mBgColor({0.8, 0.0, 0.0, 1})
{
}

void Camera::setWCCenter(float xPos, float yPos)
{
    mWCCenter.x = xPos;
    mWCCenter.y = yPos;
}

glm::vec2 Camera::getWCCenter()
{
    return mWCCenter;
}

void Camera::setWCWidth(float width)
{
    mWCWidth = width;
}

void Camera::setViewport(std::vector<float> viewportArray)
{
    this->mViewport = viewportArray;
}

std::vector<float> Camera::getViewport()
{
    return mViewport;
}

void Camera::setBackgroundColor(std::vector<float> newColor)
{
    this->mBgColor = newColor;
}

std::vector<float> Camera::getBackgroundColor()
{
    return mBgColor;
}

glm::mat4 Camera::getVPMatrix() const
{
    return mVPMatrix;
}

void Camera::setupViewProjection()
{
    //A: Configure the viewport
    //A1: Set up the viewport: area on canvas to be drawn
    glViewport(mViewport[0],    //x position of bottom-left corner
               mViewport[1],    //y position of bottom-left corner
               mViewport[2],    //width of the area to be drawn
               mViewport[3]);   //height of the area to be drawn
    //A2: Set up the corresponding scissor area to limit clear area
    glScissor(mViewport[0], mViewport[1], mViewport[2], mViewport[3]); //parameter as A1
    //A3: set the color to be clear
    glClearColor(mBgColor[0], mBgColor[1], mBgColor[2], mBgColor[3]);
    //A4: enable and clear the scissor area
    glEnable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
    //B: define the View-Projection matrix
    //B1: define the view matrix
    mViewMatrix = glm::lookAt(glm::vec3({mWCCenter[0], mWCCenter[1], 10.f}), // WC center
                glm::vec3({mWCCenter[0], mWCCenter[1], 0.f}),
                glm::vec3({0.f, 1.f, 0.f})); // Orirntation
    //B2: define the projection matrix
    GLfloat halfWCWidth = 0.5 * mWCWidth;
    GLfloat halfWCHeight = halfWCWidth * mViewport[3] / mViewport[2]; // Calculate half-height according the ratio define in mViewport
    mProjMatrix = glm::ortho(-halfWCWidth, // distance to left of WC
                             halfWCWidth,  // distance to right of WC
                             -halfWCHeight,// disrance to bottom of WC
                             halfWCHeight, // distance to top of WC
                             mNearPlane,   // z-distance to near plane
                             mFarPlane);   // z-distance to far plane
    //B3: concatnate view and project matrices
    mVPMatrix = mProjMatrix * mViewMatrix;
}

}// namespace gEngine