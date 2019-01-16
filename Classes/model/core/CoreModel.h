//
// Created by tung on 16/01/2019.
//

#ifndef SPACEGAME_COREMODEL_H
#define SPACEGAME_COREMODEL_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class CoreModel {
protected:
    Sprite *mSprite;
    SimpleAudioEngine *mAudio;
    Size mVisibleSize;
};

#endif //SPACEGAME_COREMODEL_H
