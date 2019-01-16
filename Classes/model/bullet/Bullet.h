//
// Created by tung on 15/01/2019.
//

#ifndef SPACEGAME_BULLET_H
#define SPACEGAME_BULLET_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "model/core/CoreModel.h"

using namespace cocos2d;
using namespace CocosDenshion;

class Bullet : private CoreModel {
private:
    Sequence *mAction;
    bool mAlive = false;
    Bullet();

public:
    Bullet(Scene *layer);
    ~Bullet();
    Vec2 GetLocation();
    void RunBullet(Vec2);
    void SetVisible();
    void SetInvisible();
    void OnMoveFinish();
    Rect GetBoundingBox();
    bool GetAlive();
};

#endif //SPACEGAME_BULLET_H
