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
    bool mAlive;

public:
    CoreModel();

    /**
     * get location sprite on screen
     * @return Vec2
     */
    Vec2 GetLocation();

    /**
     * Get BoundingBox of bullet do check collision
     * @return
     */
    Rect GetBoundingBox();

    /**
     * Get status alive of die
     * @return bool
     */
    bool IsAlive();

    /**
     * Set alive for sprite and visible or invisible
     */
    void SetAlive(bool);

    virtual void Init() = 0;
    virtual void Update() = 0;
};

#endif //SPACEGAME_COREMODEL_H
