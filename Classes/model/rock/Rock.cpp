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

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("rock1.plist");
    mSpriteFrames = Rock::GetSpriteFrame("a1(%d).png", 15);
    mAnimation = this->GetAnimation();
    mRock = Sprite::createWithSpriteFrame(mSpriteFrames.front());
    mRock->setPosition(Vec2(0, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));

    Rock::SetInVisible();
    layer->addChild(mRock);
}

void Rock::Fall() {
    this->SetVisible();

    int x = RandomHelper::random_int((int) (mRock->getContentSize().width / 2),
            (int) (mVisibleSize.width - mRock->getContentSize().width / 2));
    mRock->setPosition(Vec2(x, mVisibleSize.height - ADD_MORE_HEIGHT_SCREEN));

    auto fall = MoveTo::create(mRock->getContentSize().width * ROCK_FALL_TIME,
                               Vec2(x, - mRock->getContentSize().height));

    auto callbackFallSuccess = CallFunc::create([=](){
       Rock::OnFallFinish();
    });

    mAction = Sequence::create(fall, callbackFallSuccess, nullptr);
    mRock->runAction(mAnimation);
    mRock->runAction(mAction);
}

Vec2 Rock::GetLocation() {
    return mRock->getPosition();
}

void Rock::SetVisible() {
    mRock->setVisible(true);
}

void Rock::SetInVisible() {
    mRock->setVisible(false);
}

Vector<SpriteFrame*> Rock::GetSpriteFrame(const char *preFix, int count) {
    auto spritecache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> spriteFrames;
    char str[100];
    for (int i = 1; i <= count; i++) {
        sprintf(str, preFix, i);
        CCLOG(str);
        spriteFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }

    return spriteFrames;
}

RepeatForever* Rock::GetAnimation() {
    auto animation = Animation::createWithSpriteFrames(mSpriteFrames, 0.1);
    auto rep = RepeatForever::create(Animate::create(animation));
    return rep;
}

void Rock::OnFallFinish() {
    this->SetInVisible();
    mRock->setPosition(Vec2(0, mVisibleSize.height + ADD_MORE_HEIGHT_SCREEN));
    mRock->stopAction(mAction);
}