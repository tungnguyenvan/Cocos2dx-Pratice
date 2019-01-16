//
// Created by tung on 15/01/2019.
//

#ifndef SPACEGAME_BULLET_H
#define SPACEGAME_BULLET_H

#include "cocos2d.h"

using namespace cocos2d;

class Bullet {
private:
    Size mVisibleSize;
    ParticleSystemQuad *mBullet;
    Sequence *mAction;
    Bullet();

public:
    Bullet(Scene *layer);
    ~Bullet();
    Vec2 GetLocation();
    void RunBullet(Vec2);
    void SetVisible();
    void SetInvisible();
    void OnMoveFinish();
};

#endif //SPACEGAME_BULLET_H
