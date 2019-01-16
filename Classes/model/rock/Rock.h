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
    Vector<SpriteFrame*> mSpriteFrames;
    RepeatForever *mAnimation;
    Sequence *mAction;
    float mRandomTime;
    bool mAlive = false;

    Rock();

    /**
     * Get list sprite
     * @param preFix
     * @param count
     * @return
     */
    Vector<SpriteFrame*> GetSpriteFrame(const char *preFix, int count);

    RepeatForever* GetAnimation();

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

    bool GetAlive();
};

#endif //SPACEGAME_ROCK_H
