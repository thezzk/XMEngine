//
//  EngineFonts.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/11.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef EngineFonts_hpp
#define EngineFonts_hpp

#include <iostream>

#include "SingletonBase.h"
#include "FontAsset.h"

namespace  gEngine{
    
class Fonts:public SingletonBase<Fonts>
{
public:
    friend SingletonBase<Fonts>;
    
    typedef struct
    {
        GLfloat mTexCoordLeft;
        GLfloat mTexCoordRight;
        GLfloat mTexCoordBottom;
        GLfloat mTexCoordTop;
        GLfloat mCharWidth;
        GLfloat mCharHeight;
        GLfloat mCharWidthOffset;
        GLfloat mCharHeightOffset;
        GLfloat mCharAspectRation;
    }CharacterInfo;
    void loadFont(std::string fontName);
    void unloadFont(std::string fontName);
    CharacterInfo getCharInfo(std::string fontName, char aChar);
private:
    //Singleton pattern support
    Fonts(){}
    Fonts(const Fonts&){}
    Fonts &operator=(const Fonts&);
    
    void storeLoadedFont(std::string fontInfoSourceString);
    
};
    
}// namespace gEngine

#endif /* EngineFonts_hpp */
