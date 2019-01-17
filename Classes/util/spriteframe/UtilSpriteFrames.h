//
// Created by tung on 17/01/2019.
//

#ifndef SPACEGAME_UTILSPRITEFRAMES_H
#define SPACEGAME_UTILSPRITEFRAMES_H

#include "cocos2d.h"

using namespace cocos2d;

class UtilSpriteFrames {

public:
    static Vector<SpriteFrame*> GetSpriteFrame(const char *format, int count);
    static RepeatForever *GetAnimationRepeatForever(Vector<SpriteFrame*> spriteFrames, float timeDelayOneFrame);
};

#endif //SPACEGAME_UTILSPRITEFRAMES_H
