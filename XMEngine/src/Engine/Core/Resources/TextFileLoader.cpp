//
//  TextFileLoader.cpp
//  XMEngine
//
//  Created by thezzk on 17/2/24.
//  Copyright © 2017年 thezzk. All rights reserved.
//
#include "fstream"
//#include "thread"

#include "TextFileLoader.h"
#include "TextAsset.h"
#include "XMLAsset.h"


namespace gEngine{
    
    void TextFileLoader::loadTextFileTask(std::string fileName, gEngine::TextFileLoader::eTextFileType fileType)
    {
        std::string textContent;
        std::ifstream textStream(fileName, std::ios::in);
        if(textStream.is_open())
        {
            std::string line = "";
            while(getline(textStream, line))
            {
                textContent += "\n" + line;
            }
            textStream.close();
        }
        else
        {
            std::cout<<"Impossible to open "<<fileName<<" ,Is the directory right?"<<std::endl;
        }
        
        if(fileType == E_TEXT_FILE)
        {
            std::shared_ptr<Asset> fileContent(new TextAsset(textContent));
            (ResourceMap::getInstance())->asyncLoadCompleted(fileName, fileContent);
        }
        else if(fileType == E_XML_FILE)
        {
            std::shared_ptr<Asset> fileContent(new XMLAsset(textContent));
            (ResourceMap::getInstance())->asyncLoadCompleted(fileName, fileContent);
        }
        
    }

    void TextFileLoader::loadTextFile(std::string fileName, eTextFileType fileType)
    {
        
        if(!((ResourceMap::getInstance())->isAssetLoaded(fileName)))
        {
            (ResourceMap::getInstance())->asyncLoadRequest(fileName);
            loadTextFileTask(fileName, fileType);
        }
                
    }
    
    void TextFileLoader::unloadTextFile(std::string fileName)
    {
        (ResourceMap::getInstance())->unloadAsset(fileName);
    }
    
} //namespace gEngine