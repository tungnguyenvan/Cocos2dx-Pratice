//
// Created by tung on 15/01/2019.
//

#include "util/Definition.h"
#include "model/rock/Rock.h"
#include "cocos2d.h"
#include "util/spriteframe/UtilSpriteFrames.h"

using namespace cocos2d;

Rock::Rock() {

}

Rock::Rock(Scene *layer) {
    mVisibleSize = Director::getInstance()->getVisibleSize();
    mRandomTime = RandomHelper::random_real(ROCK_MIN_FALL_TIME, ROCK_MAX_FALL_TIME);

    int randType =  RandomHelper::random_int(1, 2);
    if (randType == 1) {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ROCK_1_PLIST_FILE_PATH);
        mSpriteFrames = UtilSpriteFrames::GetSpriteFrame(FORMAT_1_ROCK_NAME, 15);
    }else {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ROCK_2_PLIST_FILE_PATH);
        mSpriteFrames = UtilSpriteFrames::GetSpriteFrame(FORMAT_2_ROCK_NAME, 15);
    }

    mAnimation = UtilSpriteFrames::GetAnimationRepeatForever(mSpriteFrames, mRandomTime * 1.2);
    mSprite = Sprite::createWithSpriteFrame(mSpriteFrames.front());
    if (randType == 2) mSprite->setScale(0.5);
    mSprite->setPosition(Vec2(0, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));
    mSprite->runAction(mAnimation);

    this->CreateRockEffort(layer);
    layer->addChild(mSprite, Z_ORDER_ROCK);
}

void Rock::OnEffort(Scene *layer) {
    auto callback = CallFunc::create([=](){
        Rock::EffortFinish();
    });
    mSpriteEffort->runAction(Sequence::create(
                    DelayTime::create(ROCK_EFFORT_FRAME_TIME * ROCK_EFFORT_TOTAL_FRAME), callback, nullptr));

    mSpriteEffort->setPosition(Rock::GetLocation());
    mSpriteEffort->setVisible(true);
}

void Rock::EffortFinish() {
    mSpriteEffort->setVisible(false);
}

void Rock::CreateRockEffort(Scene *layer) {
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ROCK_EFFORT_PLIST_FILE_PATH);
    mSpriteFramesEffort = UtilSpriteFrames::GetSpriteFrame(FORMAT_EFFORT_ROCK_NAME, ROCK_EFFORT_TOTAL_FRAME);
    mAnimationEffort = UtilSpriteFrames::GetAnimationRepeatForever(mSpriteFramesEffort, ROCK_EFFORT_FRAME_TIME);
    mSpriteEffort = Sprite::createWithSpriteFrame(mSpriteFramesEffort.front());

    mSpriteEffort->runAction(mAnimationEffort);
    mSpriteEffort->setVisible(false);
    layer->addChild(mSpriteEffort, Z_ORDER_EFFORT);
}

void Rock::Init() {
    SetAlive(false);
}

void Rock::Update() {
    if (IsAlive()){
        mSprite->setPosition(Vec2(GetLocation().x, GetLocation().y - 3));
        if (GetLocation().y <= -mSprite->getContentSize().height){
            SetAlive(false);
        }
    }else {
        int x = RandomHelper::random_int((int)(mSprite->getContentSize().width / 1.5), (int) (mVisibleSize.width -
        mSprite->getContentSize().width / 2));
        mSprite->setPosition(Vec2(x, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));
    }
}