//
//  SpriteAnimateRenderable.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/9.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "SpriteAnimateRenderable.h"
#include "DefaultResources.h"
#include "TextureAsset.h"

namespace gEngine{
    
    SpriteAnimateRenderable::SpriteAnimateRenderable(std::string mTexturePath): SpriteRenderable(mTexturePath)
    {
        Renderable::setShader((DefaultResources::getInstance())->getSpriteShader());
        
        //Info on the sprite element
        mFirstElmLeft = 0.0f; // First element's left edge in UV coord
        mElmTop = 1.0f;
        mElmWidth = 1.0f;
        mElmHeight = 1.0f;
        mWidthPadding = 0.0f;
        mNumElems = 1;
        
        // per animation settings
        mAnimationType = ANIMATE_RIGHT;
        mUpdateInterval = 1;
        
        // current animation state
        mCurrentAnimAdvance = -1;
        mCurrentElm = 0;
        mCurrentTick = 0;
        initAnimation();
    }
    
    void SpriteAnimateRenderable::setAnimationType(int animationType)
    {
        
        mAnimationType = animationType;
        mCurrentAnimAdvance = -1;
        mCurrentElm = 0;
        initAnimation();
    }
    
    void SpriteAnimateRenderable::setSpriteSequence(GLuint topPixel, GLuint leftPixel, GLuint elmWidthInPixel, GLuint elmHeightInPixel, int numElements, GLfloat wPaddingInPixel)
    {
        std::shared_ptr<TextureAsset> texAsset = (ResourceMap::getInstance())->retrieveAsset<TextureAsset>(getTexturePath());
        // entire image width, height
        GLuint imageW = (texAsset->getTextureInfo()).width;
        GLuint imageH = (texAsset->getTextureInfo()).height;
        
        mNumElems = numElements;
        mFirstElmLeft = (GLfloat)leftPixel / (GLfloat)imageW;
        mElmTop = (GLfloat)topPixel / (GLfloat)imageH;
        mElmWidth = (GLfloat)elmWidthInPixel / (GLfloat)imageW;
        mElmHeight = (GLfloat)elmHeightInPixel / (GLfloat)imageH;
        mWidthPadding = (GLfloat)wPaddingInPixel / (GLfloat)imageW;
        initAnimation();
    }
    
    void SpriteAnimateRenderable::setAnimationInterval(int tickInterval)
    {
        mUpdateInterval = tickInterval;
    }
    
    void SpriteAnimateRenderable::incAnimationInterval(int deltaInterval)
    {
        mUpdateInterval += deltaInterval;
    }
    
    void SpriteAnimateRenderable::updateAnimation()
    {
        mCurrentTick++;
        if(mCurrentTick >= mUpdateInterval)
        {
            mCurrentTick = 0;
            mCurrentElm += mCurrentAnimAdvance;
            if((mCurrentElm >= 0) && (mCurrentElm < mNumElems))
            {
                setSpriteElement();
            }
            else
            {
                initAnimation();
            }
        }
    }
    
    void SpriteAnimateRenderable::initAnimation()
    {
        mCurrentTick = 0;
        if(mAnimationType == ANIMATE_RIGHT)
        {
            mCurrentElm = 0;
            mCurrentAnimAdvance = 1;
        }
        else if(mAnimationType == ANIMATE_SWING)
        {
            mCurrentAnimAdvance = -1 * mCurrentAnimAdvance;
            mCurrentElm += 2 * mCurrentAnimAdvance;
        }
        else if(mAnimationType == ANIMATE_LEFT)
        {
            mCurrentElm = mNumElems - 1;
            mCurrentAnimAdvance = -1;
        }
        setSpriteElement();
    }
    
    void SpriteAnimateRenderable::setSpriteElement()
    {
        GLfloat left = mFirstElmLeft + (mCurrentElm * (mElmWidth + mWidthPadding));
        SpriteRenderable::setElementUVCoordinate(left, left + mElmWidth, mElmTop - mElmHeight, mElmTop);
    }
    
    
    
}// namespace gEngine