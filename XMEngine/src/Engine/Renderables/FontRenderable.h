//
//  FontRenderable.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/12.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef FontRenderable_hpp
#define FontRenderable_hpp

#include <iostream>
#include "SpriteRenderable.h"
#include "EngineFonts.h"


namespace gEngine{
    
class FontRenderable: public Renderable
{
public:
    FontRenderable(std::string aString);
    virtual ~FontRenderable();
    virtual void draw(std::shared_ptr<const Camera> aCamera);
    std::string getText();
    void setText(std::string text);
    std::string getFont();
    void setFont(std::string font);
    virtual void setColor(std::vector<GLfloat> c);
    virtual std::vector<GLfloat> getColor();
    void setTextHeight(GLfloat h);
private:
    std::string mFont;
    std::shared_ptr<SpriteRenderable> OneCharRenderable;
    std::string mText;
};
    
}// namespace gEngine

#endif /* FontRenderable_hpp */