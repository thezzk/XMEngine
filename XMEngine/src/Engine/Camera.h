//
//  Camera.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/28.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "iostream"
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>


namespace gEngine {
    

class Camera
{
public:
    void setWCCenter(GLfloat xPos, GLfloat yPos);
    glm::vec2 getWCCenter();
    void setWCWidth(GLfloat width);
    void setViewport(std::vector<GLfloat> viewportArray);
    std::vector<GLfloat> getViewport();
    void setBackgroundColor(std::vector<GLfloat> newColor);
    std::vector<GLfloat> getBackgroundColor();
    glm::mat4 getVPMatrix();
    void setupViewProjection(); //Initializes the camera to begin drawing
    
    Camera();
    Camera(glm::vec2 wcCenter, GLfloat wcWidth, std::vector<GLfloat> viewportArray);
    
private:
    // WC and viewport position and size
    glm::vec2 mWCCenter;
    GLfloat mWCWidth;
    std::vector<GLfloat> mViewport;
    GLfloat mNearPlane;
    GLfloat mFarPlane;
    
    // transformation matrices
    glm::mat4 mViewMatrix;
    glm::mat4 mProjMatrix;
    glm::mat4 mVPMatrix;
    
    //background color
    std::vector<GLfloat> mBgColor;
};

} // namespace gEngine
#endif /* Camera_hpp */
