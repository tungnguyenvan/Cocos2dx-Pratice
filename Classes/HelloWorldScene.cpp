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

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    /******************** create Map ************************************/
    HelloWorld::createMap();

    /******************** create sprite ************************************/
    HelloWorld::createSprite();

    /******************** Particle created ************************************/
    HelloWorld::createParticle();

    /******************** Particle default ************************************/
    HelloWorld::createParticleDefault();

    /******************** Create Event ************************************/
    HelloWorld::createEventListener();

    return true;
}

void HelloWorld::createMap() {
    mTileMap = new TMXTiledMap();
    mTileMap->initWithTMXFile("untitled.tmx");
    mBackground = mTileMap->getLayer("Tile Layer 1");
    this->addChild(mTileMap);
}

void HelloWorld::createSprite() {
    auto objectGroup = mTileMap->getObjectGroup("object");
    if (objectGroup == nullptr){
        CCLOG("tile map has no objects object layer");
        return;
    }
    auto spawnpoint = objectGroup->getObject("point");
    int x = spawnpoint.at("x").asInt();
    int y = spawnpoint.at("y").asInt();
    CCLOG("%d\t%d", x, y);
    mPlayer = Sprite::create("luf (1).png");
    mPlayer->setPosition(Vec2(x, y));
    this->addChild(mPlayer);
    /* Create follow sprite */
    //auto follow = Follow::create(mPlayer);
    //this->runAction(follow);
    this->setViewPointCenter(mPlayer->getPosition());
}

void HelloWorld::createParticle() {
    auto particleSystem = ParticleSystemQuad::create("particle_texture.plist");
    particleSystem->setScale(0.3);
    particleSystem->setPosition(Vec2(150, 150));
    this->addChild(particleSystem);
}

void HelloWorld::createParticleDefault() {
    auto particleEffect = ParticleRain::create();
    this->addChild(particleEffect);
}

void HelloWorld::createEventListener() {
    mEventListener = EventListenerTouchOneByOne::create();
    mEventListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBeganEvent, this);
    mEventListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMovedEvent, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mEventListener, this);
}

void HelloWorld::setViewPointCenter(Vec2 position) {
    Size size = Director::getInstance()->getWinSize();

    int x = MAX(position.x, size.width / 2);
    int y = MAX(position.y, size.height / 2);
    x = MIN(x, (mTileMap->getMapSize().width * mTileMap->getContentSize().width) - size.width / 2);
    y = MIN(y, (mTileMap->getMapSize().height * mTileMap->getContentSize().height) - size.height / 2);

    auto actualPosition = Vec2(x, y);
    auto centerOfView = Vec2(size.width / 2, size.height / 2);
    auto viewPoint = ccpSub(centerOfView, actualPosition);
    this->setPosition(viewPoint);
}

bool HelloWorld::onTouchBeganEvent(Touch *touch, Event *event) {
    CCLOG("Touch");
    return true;
}

void HelloWorld::onTouchMovedEvent(Touch *touch, Event *event) {
    CCLOG("MOVE");
}