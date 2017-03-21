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
using namespace std;



int main( void )
{
    /*sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("assets/sounds/BlueLevel_cue.wav"))
        return -1;
    
    
    sf::Sound sound;
    sound.setBuffer(buffer);
    

    while(1)
    {
        sound.play();
    }*/
   
    
    std::shared_ptr<MyGame> newGame(new MyGame());
    (gEngine::Core::getInstance())->initializeEngineCore(newGame);
}