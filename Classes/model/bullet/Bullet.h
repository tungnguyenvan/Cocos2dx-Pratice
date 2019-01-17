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

    /**
     * get location sprite on screen
     * @return Vec2
     */
    Vec2 GetLocation();

    /**
     * On action bullet run from player to top screen
     */
    void RunBullet(Vec2);

    /**
     * Set visible of bullet
     */
    void SetVisible();

    /**
     * Set invisible of bullet
     */
    void SetInvisible();

    /**
     * function implement when bullet run to top screen
     */
    void OnMoveFinish();

    /**
     * Get BoundingBox of bullet do check collision
     * @return
     */
    Rect GetBoundingBox();

    /**
     * Get status alive of bullet
     * @return
     */
    bool GetAlive();
};

#endif //SPACEGAME_BULLET_H
