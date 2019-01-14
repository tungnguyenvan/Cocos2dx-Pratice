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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Scene
{
private:
    TMXTiledMap *mTileMap;
    TMXLayer *mBackground;
    Sprite *mPlayer;
    TMXLayer *mMeta;
    TMXLayer *mForeGround;
    EventListenerTouchOneByOne *mEventListener;
public:
    static cocos2d::Scene* createScene();

    /**
     * Event Moved
     * @param touch
     * @param event
     */
    void onTouchMovedEvent(Touch *touch, Event *event);

    /**
     * Event touch
     * @param touch
     * @param event
     * @return
     */
    bool onTouchBeganEvent(Touch *touch, Event *event);

    /**
     * Listener ended touch
     * @param touch
     * @param event
     */
    void onTouchEndedEvent(Touch *touch, Event *event);

    /**
     * init view on Scene
     * @return
     */
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    /**
     * Create map on scene
     */
    void createMap();

    /**
     * Create sprite and add to scene in spawnPoint
     */
    void createSprite();

    /**
     * create Particle custom
     */
    void createParticle();

    /**
     * Particle in system cocos2d
     */
    void createParticleDefault();

    /**
     * Create event touch, moved
     */
    void createEventListener();

    /**
     * set Sprite on spawnPoint
     */
    void setViewPointCenter(Vec2);

    /**
     * @param vec2
     */
    void setPlayerPosition(Vec2);

    /**
     *
     * @param vec2
     * @return
     */
    Vec2 tileCoordForPosition(Vec2);
};

#endif // __HELLOWORLD_SCENE_H__
