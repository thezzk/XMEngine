//
//  XMLAsset.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/10.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "XMLAsset.h"

namespace gEngine{
    XMLAsset::XMLAsset()
    {
    }
    
    XMLAsset::XMLAsset(std::string xmlText)
    {
        xmlDoc.Parse(xmlText.c_str());
    }
    
    XMLAsset::~XMLAsset()
    {
        
    }
    
    int XMLAsset::setXMLDoc(std::string xmlStr)
    {
        xmlDoc.Parse(xmlStr.c_str());
        return xmlDoc.ErrorID();
    }
    
    const tinyxml2::XMLDocument& XMLAsset::getXMLDoc()
    {
        return xmlDoc;
    }
}