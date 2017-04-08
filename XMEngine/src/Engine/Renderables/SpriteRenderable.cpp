//
//  SpriteRenderable.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/7.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "SpriteRenderable.h"
#include "TextureAsset.h"
#include "ResourceMap.h"
#include "SpriteShader.h"
#include "DefaultResources.h"

namespace gEngine{
    
    SpriteRenderable::SpriteRenderable(std::string mTexturePath):TextureRenderable(mTexturePath)
    {
        setShader((DefaultResources::getInstance())->getSpriteShader());
        mTexLeft = 0.0f;
        mTexRight = 1.0f;
        mTexTop = 1.0f;
        mTexBottom = 0.0f;
    }
    
    SpriteRenderable::~SpriteRenderable()
    {
        
    }
    
    void SpriteRenderable::setElementUVCoordinate(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top)
    {
        mTexLeft = left;
        mTexRight = right;
        mTexBottom = bottom;
        mTexTop = top;
    }
    
    void SpriteRenderable::setElementPixelPositions(GLuint left, GLuint right, GLuint bottom, GLuint top)
    {
        std::shared_ptr<TextureAsset> texAsset = (ResourceMap::getInstance())->retrieveAsset<TextureAsset>(getTexturePath());
        
        GLuint imageW = (texAsset->getTextureInfo()).width;
        GLuint imageH = (texAsset->getTextureInfo()).height;
        
        mTexLeft = (GLfloat)left / (GLfloat)imageW;
        mTexRight = (GLfloat)right / (GLfloat)imageW;
        mTexBottom = (GLfloat)bottom / (GLfloat)imageH;
        mTexTop = (GLfloat)top / (GLfloat)imageH;
    }
    
    std::vector<GLfloat> SpriteRenderable::getElementUVCoordinateArray()
    {
        std::vector<GLfloat> retval =
        {
            mTexRight, mTexTop,
            mTexLeft, mTexTop,
            mTexRight, mTexBottom,
            mTexLeft, mTexBottom
        };
        return retval;
    }
    
    void SpriteRenderable::draw(glm::mat4 vpMatrix)
    {
        // set the current texture coordinate
        std::shared_ptr<SpriteShader> shader =
        std::dynamic_pointer_cast<SpriteShader>(getShader());
        shader->setTextureCoordinate(getElementUVCoordinateArray());
        
        TextureRenderable::draw(vpMatrix);
    }
}// namespace gEngine