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

class Bullet : public CoreModel {
private:
    Sequence *mAction;
    Bullet();

public:
    Bullet(Scene *layer);

    ~Bullet();

    /**
     * Player send location to bullet
     */
    void UpdateLocationPlayer(Vec2);

    /**
     * initialize value
     */
    virtual void Init();

    virtual void Update();
};

#endif //SPACEGAME_BULLET_H
