//
// Created by tung on 15/01/2019.
//

#ifndef SPACEGAME_ROCK_H
#define SPACEGAME_ROCK_H

#include "cocos2d.h"
#include "model/core/CoreModel.h"

using namespace cocos2d;

class Rock : public CoreModel {
private:
    Sprite *mSpriteEffort;
    Vector<SpriteFrame*> mSpriteFrames;
    Vector<SpriteFrame*> mSpriteFramesEffort;
    RepeatForever *mAnimation;
    RepeatForever *mAnimationEffort;
    float mRandomTime;

    Rock();

public:
    Rock(Scene *layer);
    ~Rock();

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

    virtual void Init();
    virtual void Update();
};

#endif //SPACEGAME_ROCK_H
