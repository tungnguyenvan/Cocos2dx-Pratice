/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "util/Definition.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "model/player/PlayerShip.h"
#include "model/rock/Rock.h"
#include "scene/endgame/EndGame.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    //init variable
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    mIndexRocks = 0;
    mScore = 0;

    mBackground = new Background(this);
    this->CreateRocks();
    mPlayer = new PlayerShip(this, PLAYER_SHIP_BLUE_1);

    this->schedule(schedule_selector(HelloWorld::FallTheRock), ROCK_FALL_TIME);
    this->scheduleUpdate();

    //create label score
    mLabelScore = Label::createWithTTF(std::to_string(mScore), FONT_PATH, 100);
    mLabelScore->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.8));
    this->addChild(mLabelScore);

    return true;
}

void HelloWorld::CreateRocks() {
    for (int i = 0; i < SIZE_LIST_ROCKS; i++){
        mRocks.push_back(new Rock(this));
    }
}

void HelloWorld::FallTheRock(float) {
    if (mRocks.at(mIndexRocks)->GetAlive() == false) mRocks.at(mIndexRocks)->Fall();
    ++mIndexRocks;

    if (mIndexRocks >= SIZE_LIST_ROCKS) mIndexRocks = 0;
}

void HelloWorld::update(float){
    for (int i = 0; i < mRocks.size(); ++i) {
        if (mRocks.at(i)->GetAlive()) {
            //check collision bullet and rock
            if (mPlayer->CheckCollisionBulletAndRock(mRocks.at(i)->GetBoundingBox())) {
                mRocks.at(i)->OnEffort(this);
                mScore++;
                mLabelScore->setString(std::to_string(mScore));
            }

            //check collision player and rock
            if (mPlayer->CheckCollisionWidthRock(mRocks.at(i)->GetBoundingBox())) {
                auto endScene = EndGame::createScene(mScore);
                Director::getInstance()->replaceScene(endScene);
            }
        }
    }
}
