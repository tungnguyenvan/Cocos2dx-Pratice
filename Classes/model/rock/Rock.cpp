//
// Created by tung on 15/01/2019.
//

#include "util/Definition.h"
#include "model/rock/Rock.h"
#include "cocos2d.h"

using namespace cocos2d;

Rock::Rock() {

}

Rock::Rock(Scene *layer) {
    mVisibleSize = Director::getInstance()->getVisibleSize();
    mRandomTime = RandomHelper::random_real(ROCK_MIN_FALL_TIME, ROCK_MAX_FALL_TIME);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ROCK_PLIST_FILE_PATH);
    mSpriteFrames = Rock::GetSpriteFrame(FORMAT_ROCK_NAME, 15);
    mSprite = Sprite::createWithSpriteFrame(mSpriteFrames.front());
    mSprite->setPosition(Vec2(0, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));
    mAnimation = this->GetAnimation();
    mSprite->runAction(mAnimation);

    Rock::SetInVisible();
    layer->addChild(mSprite);
}

void Rock::Fall() {
    this->SetVisible();

    int x = RandomHelper::random_int(0, (int) mVisibleSize.width);
    mSprite->setPosition(Vec2(x, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));

    auto fall = MoveTo::create(mSprite->getContentSize().width * mRandomTime,
                               Vec2(x, - mSprite->getContentSize().height));

    auto callbackFallSuccess = CallFunc::create([=](){
       Rock::OnFallFinish();
    });

    mAction = Sequence::create(fall, callbackFallSuccess, nullptr);
    mSprite->runAction(mAction);
}

Vec2 Rock::GetLocation() {
    return mSprite->getPosition();
}

void Rock::SetVisible() {
    mSprite->setVisible(true);
}

void Rock::SetInVisible() {
    mSprite->setVisible(false);
}

Vector<SpriteFrame*> Rock::GetSpriteFrame(const char *preFix, int count) {
    auto spritecache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> spriteFrames;
    char str[100];
    for (int i = 1; i <= count; i++) {
        sprintf(str, preFix, i);
        spriteFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }

    return spriteFrames;
}

RepeatForever* Rock::GetAnimation() {
    auto animation = Animation::createWithSpriteFrames(mSpriteFrames, mRandomTime * 0.7);
    auto rep = RepeatForever::create(Animate::create(animation));
    return rep;
}

void Rock::OnFallFinish() {
    this->SetInVisible();
    mSprite->setPosition(Vec2(0, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));
    mSprite->stopAction(mAction);
}

Rect Rock::GetBoundingBox() {
    return mSprite->getBoundingBox();
}