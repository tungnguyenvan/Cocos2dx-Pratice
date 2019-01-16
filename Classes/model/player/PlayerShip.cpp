/*********************************
 *
 * Created by tung on 15/01/2019.
 *
*********************************/

#include <iostream>
#include "util/Definition.h"
#include "PlayerShip.h"
#include "cocos2d.h"
#include "model/bullet/Bullet.h"
#include <string>

using namespace cocos2d;
using namespace std;

Vec2 mOldLocation;

PlayerShip::PlayerShip() {

}

PlayerShip::PlayerShip(Scene *layer, string namePath) {
    mVisibleSize = Director::getInstance()->getVisibleSize();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SHEET_PLAYER_SHIP_PLIST, SHEET_PLAYER_SHIP_IMAGE);

    mSprite = Sprite::createWithSpriteFrameName(namePath);
    mSprite->setPosition(Vec2(mVisibleSize.width * 0.5, -mVisibleSize.height * 0.2));
    mSprite->setScale(SCALE_PLAYER_SHIP);
    layer->addChild(mSprite);

    this->FirstMoveGamePlay(layer);
    this->CreateBullets(layer);
}

PlayerShip::~PlayerShip() {

}

void PlayerShip::FirstMoveGamePlay(Scene *layer) {
    auto moveGamePlay = MoveTo::create(PLAYER_MOVE_TIME, Vec2(mVisibleSize.width * 0.5, mVisibleSize.height * 0.2));
    auto callback = CallFunc::create([=](){
        PlayerShip::CreateEventForGamePlay(layer);
    });
    auto sqe = Sequence::create(moveGamePlay, callback, nullptr);
    mSprite->runAction(sqe);
}

void PlayerShip::CreateEventForGamePlay(Scene *layer) {
    mEvent = EventListenerTouchOneByOne::create();
    mEvent->setSwallowTouches(true);
    mEvent->onTouchBegan = CC_CALLBACK_2(PlayerShip::onTouchBegan, this);
    mEvent->onTouchMoved = CC_CALLBACK_2(PlayerShip::onTouchMoved, this);
    mEvent->onTouchEnded = CC_CALLBACK_2(PlayerShip::onTouchEnded, this);
    layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mEvent, layer);

    auto call = CallFunc::create([=](){
       this->Shoot();
    });
    auto rp = RepeatForever::create(Sequence::create(DelayTime::create(SHOOT_BULLET_TIME), call, nullptr));
    mSprite->runAction(rp);
}

bool PlayerShip::onTouchBegan(Touch *touch, Event *event) {
    mOldLocation = touch->getLocation();
    return true;
}

void PlayerShip::onTouchMoved(Touch *touch, Event *event) {
    auto gamePlayLocation = mSprite->getPosition();
    auto newTouch = touch->getLocation();
    mSprite->setPosition(Vec2(gamePlayLocation.x - (mOldLocation.x - newTouch.x),
            gamePlayLocation.y - (mOldLocation.y - newTouch.y)));
    mOldLocation = newTouch;

}

void PlayerShip::onTouchEnded(Touch *touch, Event *event) {

}

void PlayerShip::CreateBullets(Scene *layer) {
    for (int i = 0; i < SIZE_LIST_BULLETS; i++) {
        mBullets.push_back(new Bullet(layer));
    }
}

void PlayerShip::Shoot() {
    mBullets.at(mIndexBullet)->RunBullet(mSprite->getPosition());
    ++mIndexBullet;

    if (mIndexBullet >= SIZE_LIST_BULLETS) mIndexBullet = 0;
}

bool PlayerShip::CheckCollisionWidthRock(Rect rectRock) {
    Rect rectPlayer = mSprite->getBoundingBox();
    if (rectPlayer.intersectsRect(rectRock))
        return true;

    return false;
}

bool PlayerShip::CheckCollisionBulletAndRock(Rect rectRock) {
    rectRock.size.width -= REDUCT_SIZE_RECT_ROCK;
    rectRock.size.height -= REDUCT_SIZE_RECT_ROCK;

    for (int i = 0; i < mBullets.size(); i++){
        Rect rectBullet = mBullets.at(i)->GetBoundingBox();
        if (rectBullet.intersectsRect(rectRock)) {
            mBullets[i]->OnMoveFinish();
            return true;
        }
    }
    return false;
}