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
    layer->addChild(mSprite, Z_ORDER_BULLET);
}

Bullet::~Bullet() {

}

void Bullet::Init() {
    SetAlive(false);
}

void Bullet::Update() {
    if (IsAlive()) {
        mSprite->setPosition(Vec2(GetLocation().x, GetLocation().y + SHOOT_BULLET_STEP));
        if (GetLocation().y >= SCREEN_H - mVisibleSize.height / 2){
            SetAlive(false);
        }
    }
}

void Bullet::UpdateLocationPlayer(Vec2 location) {
    if (!IsAlive()) {
        mSprite->setPosition(location);
    }
}