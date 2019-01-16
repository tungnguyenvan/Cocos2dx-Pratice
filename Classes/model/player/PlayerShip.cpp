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

PlayerShip::PlayerShip() {

}

PlayerShip::PlayerShip(Scene *layer, string namePath) {
    mVisibleSize = Director::getInstance()->getVisibleSize();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SHEET_PLAYER_SHIP_PLIST, SHEET_PLAYER_SHIP_IMAGE);

    mGamePlay = Sprite::createWithSpriteFrameName(namePath);
    mGamePlay->setPosition(Vec2(mVisibleSize.width * 0.5, -mVisibleSize.height * 0.2));
    mGamePlay->setScale(SCALE_PLAYER_SHIP);
    layer->addChild(mGamePlay);

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
    mGamePlay->runAction(sqe);
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
    mGamePlay->runAction(rp);
}

bool PlayerShip::onTouchBegan(Touch *touch, Event *event) {
    if (mGamePlay->getBoundingBox().containsPoint(
            mGamePlay->getParent()->convertToNodeSpace(touch->getLocation()))){
        return true;
    }
    return false;
}

void PlayerShip::onTouchMoved(Touch *touch, Event *event) {
    mGamePlay->setPosition(touch->getLocation());
}

void PlayerShip::onTouchEnded(Touch *touch, Event *event) {

}

void PlayerShip::CreateBullets(Scene *layer) {
    for (int i = 0; i < SIZE_LIST_BULLETS; i++) {
        mBullets.push_back(new Bullet(layer));
    }
}

void PlayerShip::Shoot() {
    mBullets.at(mIndexBullet)->RunBullet(mGamePlay->getPosition());
    ++mIndexBullet;

    if (mIndexBullet >= SIZE_LIST_BULLETS) mIndexBullet = 0;
}