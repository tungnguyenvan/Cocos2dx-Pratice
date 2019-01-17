//
// Created by tung on 17/01/2019.
//

#include "cocos2d.h"
#include "UtilSpriteFrames.h"

using namespace cocos2d;

Vector<SpriteFrame*> UtilSpriteFrames::GetSpriteFrame(const char *format, int count) {
    auto spritecache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> spriteFrames;
    char str[100];
    for (int i = 1; i <= count; i++) {
        sprintf(str, format, i);
        spriteFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }

    return spriteFrames;
}

RepeatForever* UtilSpriteFrames::GetAnimationRepeatForever(Vector<SpriteFrame*> spriteFrames, float timeDelayOneFrame) {
    auto animation = Animation::createWithSpriteFrames(spriteFrames, timeDelayOneFrame);
    auto rep = RepeatForever::create(Animate::create(animation));
    return rep;
}
