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
#include "SFML/Audio.hpp"
#include "unistd.h"
#include "SoundAsset.h"
using namespace std;



int main( void )
{
    
    /*gEngine::SoundAssets soundAssets("assets/sounds/BGClip.wav");
    soundAssets.getSound().play();
    while(1){}*/
    
    std::shared_ptr<MyGame> newGame(new MyGame());
    (gEngine::Core::getInstance())->initializeEngineCore(newGame);
    
    
}