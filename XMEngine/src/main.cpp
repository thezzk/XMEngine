// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include "MyGame.h"
#include "EngineCore.h"
#include "TimeUtil.h"
#include "iostream"

//test use
#include "ResourceMap.h"
#include "TextFileLoader.h"
#include "TextAsset.h"
#include "XMLAsset.h"
#include "tinyxml2.h"
#include "SceneFileParser.h"
#include "sstream"
#include "vector"
using namespace std;

void callbackfoo()
{
    cout<<"are you ok"<<endl;
    gEngine::SceneFileParser mSceneFileFarser("assets/scene.xml");
    gEngine::XmlElmListType x = mSceneFileFarser.getElm("Square");
    vector<int> colorArray;
    colorArray = gEngine::SceneFileParser::xmlStringSplit<int>(x[0]->Attribute("Color"));
    for(int i=0; i<colorArray.size(); i++)
    {
        cout<<colorArray[i]<<endl;
    }
}

int main( void )
{
   
    
     MyGame newGame;
    (gEngine::Core::getInstance())->initializeEngineCore(newGame);
}