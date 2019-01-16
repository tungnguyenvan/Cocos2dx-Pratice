//
// Created by tung on 15/01/2019.
//

#include "util/Definition.h"
#include "model/bullet/Bullet.h"
#include "cocos2d.h"

using namespace cocos2d;

Bullet::Bullet() {

}

Bullet::Bullet(Scene *layer) {
    mVisibleSize = Director::getInstance()->getVisibleSize();
    mBullet = ParticleSystemQuad::create("bullet.plist");
    mBullet->setScale(0.1);
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
    mBullet->setPosition(location);
    this->SetVisible();

    auto moveTo = MoveTo::create(BULLET_MOVE_TIME, Vec2(location.x, mVisibleSize.height + mBullet->getContentSize().height));
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