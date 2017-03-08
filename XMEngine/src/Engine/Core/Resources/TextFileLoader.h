//
//  TextFileLoader.hpp
//  XMEngine
//
//  Created by thezzk on 17/2/24.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef TextFileLoader_hpp
#define TextFileLoader_hpp

#include "iostream"

#include "SingletonBase.h"
#include "ResourceMap.h"
namespace gEngine {

    
    
class TextFileLoader: public SingletonBase<TextFileLoader>
{
    
public:
    friend SingletonBase<TextFileLoader>;
    
    enum eTextFileType
    {
        E_XML_FILE = 0,
        E_TEXT_FILE = 1
    };
    void loadTextFile(std::string fileName, eTextFileType fileType);
    void unloadTextFile(std::string fileName);
private:
    //Singleton pattern support
    TextFileLoader(){};
    TextFileLoader(const TextFileLoader&){}
    TextFileLoader &operator=(const TextFileLoader&);
    
    
};
    
} //namespace gEngine

#endif /* TextFileLoader_hpp */
