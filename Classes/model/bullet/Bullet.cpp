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

    mBullet = Sprite::create("laserRed01.png");
    mBullet->setPosition(POSITION_DEFAULT_BULLET);

    this->SetInvisible();
    layer->addChild(mBullet);
}

Bullet::~Bullet() {

}

Vec2 Bullet::GetLocation() {
    return  mBullet->getPosition();
}

void Bullet::RunBullet(Vec2 location) {
    mAudio->playEffect(BULLET_SOUND, false);
    mBullet->setPosition(location);
    this->SetVisible();

    auto moveTo = MoveBy::create(BULLET_MOVE_TIME, Vec2(0, mVisibleSize.height - mBullet->getContentSize().height - 200));
    auto callback = CallFunc::create([=](){
        this->OnMoveFinish();
    });
    mAction = Sequence::create(moveTo, callback, nullptr);

    mBullet->runAction(mAction);
}

void Bullet::SetVisible() {
    mBullet->setVisible(true);
}

void Bullet::SetInvisible() {
    mBullet->setVisible(false);
}

void Bullet::OnMoveFinish() {
    this->SetInvisible();
    mBullet->setPosition(POSITION_DEFAULT_BULLET);
    mBullet->stopAction(mAction);
}

Rect Bullet::GetBoundingBox() {
    return mBullet->getBoundingBox();
}