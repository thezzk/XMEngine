//
//  TextAsset.hpp
//  XMEngine
//
//  Created by thezzk on 17/2/25.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef TextAsset_hpp
#define TextAsset_hpp

#include "Asset.h"

namespace gEngine{
    
class TextAsset:public Asset
{
public:
    TextAsset();
    TextAsset(std::string text);
    ~TextAsset();
    std::string getTextContent();
    void setTextContent(std::string text);
private:
    std::string textContent;
};

} //namespace gEngine

#endif /* TextAsset_hpp */
