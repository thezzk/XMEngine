//
//  SpriteRenderable.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/7.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SpriteRenderable_hpp
#define SpriteRenderable_hpp

#include <iostream>

#include "TextureRenderable.h"
namespace gEngine{
    
    class SpriteRenderable: public TextureRenderable
    {
    public:
        enum
        {
            SPRITE_LEFT = 2,
            SPRITE_RIGHT = 0,
            SPRITE_TOP = 1,
            SPRITE_BOTTOM = 5
        };
        SpriteRenderable(std::string mTexturePath);
        virtual ~SpriteRenderable();
        void setElementUVCoordinate(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top);
        void setElementPixelPositions(GLuint left, GLuint right, GLuint bottom, GLuint top);
        std::vector<GLfloat> getElementUVCoordinateArray();
        virtual void draw(glm::mat4 vpMatrix);
    private:
        GLfloat mTexLeft;
        GLfloat mTexRight;
        GLfloat mTexBottom;
        GLfloat mTexTop;
        
    };
    
}// namespace gEngine

#endif /* SpriteRenderable_hpp */
