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
using namespace std;


int main( void )
{
    MyGame newGame;
    (gEngine::Core::getInstance())->initializeEngineCore(newGame);
}