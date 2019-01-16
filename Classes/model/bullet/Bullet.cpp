//
// Created by tung on 15/01/2019.
//

#include "util/Definition.h"
#include "model/bullet/Bullet.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Bullet::Bullet() {

}

Bullet::Bullet(Scene *layer) {
    mAudio = SimpleAudioEngine::getInstance();
    mVisibleSize = Director::getInstance()->getVisibleSize();

    mSprite = Sprite::create("laserRed01.png");
    mSprite->setPosition(POSITION_DEFAULT_BULLET);

    this->SetInvisible();
    layer->addChild(mSprite);
}

Bullet::~Bullet() {

}

Vec2 Bullet::GetLocation() {
    return  mSprite->getPosition();
}

void Bullet::RunBullet(Vec2 location) {
    mAlive = true;
    mAudio->playEffect(BULLET_SOUND, false);
    mSprite->setPosition(location);
    this->SetVisible();

    auto moveTo = MoveBy::create(BULLET_MOVE_TIME, Vec2(0, mVisibleSize.height - mSprite->getContentSize().height - 200));
    auto callback = CallFunc::create([=](){
        this->OnMoveFinish();
    });
    mAction = Sequence::create(moveTo, callback, nullptr);

    mSprite->runAction(mAction);
}

void Bullet::SetVisible() {
    mSprite->setVisible(true);
}

void Bullet::SetInvisible() {
    mSprite->setVisible(false);
}

void Bullet::OnMoveFinish() {
    mAlive = false;
    this->SetInvisible();
    mSprite->setPosition(POSITION_DEFAULT_BULLET);
    mSprite->stopAction(mAction);
}

Rect Bullet::GetBoundingBox() {
    return mSprite->getBoundingBox();
}

bool Bullet::GetAlive() {
    return mAlive;
}