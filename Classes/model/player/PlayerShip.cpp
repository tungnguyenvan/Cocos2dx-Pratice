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
using namespace CocosDenshion;

Vec2 mOldLocation;

PlayerShip::PlayerShip() {

}

PlayerShip::PlayerShip(Scene *layer, string namePath) : CoreModel(){
    mIndexBullet = 0;
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SHEET_PLAYER_SHIP_PLIST, SHEET_PLAYER_SHIP_IMAGE);
    mAudio = SimpleAudioEngine::getInstance();

    mSprite = Sprite::createWithSpriteFrameName(namePath);
    mSprite->setPosition(Vec2(mVisibleSize.width * 0.5, -mVisibleSize.height * 0.2));
    mSprite->setScale(SCALE_PLAYER_SHIP);
    layer->addChild(mSprite, Z_ORDER_PLAYER);

    this->FirstMoveGamePlay(layer);
    this->CreateBullets(layer);
    mAudio->playEffect(GAMEPLAY_SOUND, true);
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
}

bool PlayerShip::onTouchBegan(Touch *touch, Event *event) {
    mOldLocation = touch->getLocation();
    return true;
}

void PlayerShip::onTouchMoved(Touch *touch, Event *event) {
    auto gamePlayLocation = mSprite->getPosition();
    auto newTouch = touch->getLocation();
    auto spriteSize = mSprite->getContentSize();

    float spriteLocationX = gamePlayLocation.x - (mOldLocation.x - newTouch.x);
    float spriteLocationY = gamePlayLocation.y - (mOldLocation.y - newTouch.y);

    if (spriteLocationX >= spriteSize.width / 4 && spriteLocationX <= mVisibleSize.width - spriteSize.width / 4
        && spriteLocationY >= spriteSize.height / 3 && spriteLocationY <= mVisibleSize.height - spriteSize.height / 3) {

        mSprite->setPosition(Vec2(gamePlayLocation.x - (mOldLocation.x - newTouch.x),
                                  gamePlayLocation.y - (mOldLocation.y - newTouch.y)));
    }

    mOldLocation = newTouch;
}

void PlayerShip::onTouchEnded(Touch *touch, Event *event) {

}

void PlayerShip::CreateBullets(Scene *layer) {
    for (int i = 0; i < SIZE_LIST_BULLETS; i++) {
        Bullet *b = new Bullet(layer);
        b->Init();
        mBullets.push_back(b);
    }
}

void PlayerShip::Shoot() {
    if (!mBullets.at(mIndexBullet)->IsAlive())
    {
        mBullets.at(mIndexBullet)->SetAlive(true);
    }
    ++mIndexBullet;

    if (mIndexBullet >= SIZE_LIST_BULLETS) mIndexBullet = 0;
}

bool PlayerShip::CheckCollisionWidthRock(Rect rectRock) {
    Rect rectPlayer = this->GetBoundingBox();

    rectPlayer.size.width -= 45;
    rectPlayer.size.height -= 45;

    rectRock.size.width -= REDUCT_SIZE_RECT_ROCK;
    rectRock.size.height -= REDUCT_SIZE_RECT_ROCK;

    if (rectPlayer.intersectsRect(rectRock))
        return true;

    return false;
}

bool PlayerShip::CheckCollisionBulletAndRock(Rect rectRock) {
    rectRock.size.width -= REDUCT_SIZE_RECT_ROCK;
    rectRock.size.height -= REDUCT_SIZE_RECT_ROCK;

    for (int i = 0; i < mBullets.size(); i++){
        if (mBullets.at(i)->IsAlive()) {
            Rect rectBullet = mBullets.at(i)->GetBoundingBox();
            if (rectBullet.intersectsRect(rectRock)) {
                //mBullets.at(i)->SetAlive(false);
                return true;
            }
        }
    }
    return false;
}

void PlayerShip::Init(){
    mIndexBullet = 0;
    mFrameShootBullet = 0;
}

void PlayerShip::Update() {
    for (int i = 0; i < mBullets.size(); i++){
        mBullets.at(i)->UpdateLocationPlayer(mSprite->getPosition());
        mBullets.at(i)->Update();
    }

    mFrameShootBullet++;
    if (mFrameShootBullet % 4 == 0){
        Shoot();
    }
}