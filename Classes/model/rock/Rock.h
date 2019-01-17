//
// Created by tung on 15/01/2019.
//

#ifndef SPACEGAME_ROCK_H
#define SPACEGAME_ROCK_H

#include "cocos2d.h"
#include "model/core/CoreModel.h"

using namespace cocos2d;

class Rock : private CoreModel {
private:
    Sprite *mSpriteEffort;
    Vector<SpriteFrame*> mSpriteFrames;
    Vector<SpriteFrame*> mSpriteFramesEffort;
    RepeatForever *mAnimation;
    RepeatForever *mAnimationEffort;
    Sequence *mAction;
    Sequence *mActionEffort;
    float mRandomTime;
    bool mAlive = false;

    Rock();

public:
    Rock(Scene *layer);
    ~Rock();

    /**
     * @return Vec2 : location of Rock
     */
    Vec2 GetLocation();

    /**
     * Call Rock fall
     */
    void Fall();

    /**
     * Set rock visible when Rock in top
     */
    void SetVisible();

    /**
     * Set rock inVisible when Rock in bottom
     */
    void SetInVisible();

    /**
     * this function will call when action of rock run finish
     */
    void OnFallFinish();

    Rect GetBoundingBox();

    /**
     * Get status alive of die
     * @return bool
     */
    bool GetAlive();

    void EffortFinish();

    /**
     * Rock effort when collision rock and bullet
     */
    void OnEffort(Scene *layer);

    /**
     * Create sprite Rock effort and animation Rock effort
     * @param layer
     */
    void CreateRockEffort(Scene *layer);
};

#endif //SPACEGAME_ROCK_H
