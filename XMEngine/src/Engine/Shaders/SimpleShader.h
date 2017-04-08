//
//  SimpleShader.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/20.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SimpleShader_hpp
#define SimpleShader_hpp

#include "iostream"
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace gEngine{
class SimpleShader
{
public:
    SimpleShader(std::string vertexFilePath, std::string fragmentFilePath);
    virtual ~SimpleShader();
    virtual void activateShader(std::vector<GLfloat> pixelColor, glm::mat4 vpMatrix);
    void loadObjectTransform(glm::mat4 modelTransform);
    GLuint compileShader(std::string path, GLuint shaderType);
    GLuint getShader();
private:
    GLuint mPixelColor; // the uniform loaction of shader's pixel color
    GLuint mModelTransform; // the M of MVP Matrix -- uniform loaction
    GLuint mViewProjTransform;// the V,P of MVP Matrix -- uniform loaction
    GLuint mCompiledShader;
    GLuint mShaderVertexPositionAttribute;
    
    
};
}// namespace gEngine
#endif /* SimpleShader_hpp */
