//
//  SpriteAnimateRenderable.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/9.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SpriteAnimateRenderable_hpp
#define SpriteAnimateRenderable_hpp

#include <iostream>

#include "SpriteRenderable.h"


namespace gEngine{
    
class SpriteAnimateRenderable: public SpriteRenderable
{
public:
    enum
    {
        ANIMATE_RIGHT = 0,
        ANIMATE_LEFT = 1,
        ANIMATE_SWING = 2
    };
    SpriteAnimateRenderable(std::string mTexturePath);
    void setAnimationType(int animationType);
    void setSpriteSequence(GLuint topPixel, GLuint leftPixel, GLuint elmWidthInPixel, GLuint elmHeightInPixel, int numElements, GLfloat wPaddingInPixel);
    
    void setAnimationInterval(int tickInterval);
    void incAnimationInterval(int deltaInterval);
    void updateAnimation();
    
private:
    void initAnimation();
    void setSpriteElement();
    
    GLfloat mFirstElmLeft; // first element's left edge in UV coord, that's where the anim begin
    GLfloat mElmTop;
    GLfloat mElmWidth;
    GLfloat mElmHeight;
    GLfloat mWidthPadding; // the width of gap between two anim element
    int mNumElems;
    int mAnimationType;
    int mUpdateInterval; //number of update calls before advancing animation
    int mCurrentAnimAdvance;
    int mCurrentElm;
    int mCurrentTick;
};
    
}// namespace gEngine

#endif /* SpriteAnimateRenderable_hpp */

