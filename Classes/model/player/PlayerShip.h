/*********************************
 *
 * Created by tung on 15/01/2019.
 *
*********************************/

#ifndef SPACEGAME_PLAYERSHIP_H
#define SPACEGAME_PLAYERSHIP_H

#include "model/bullet/Bullet.h"
#include "cocos2d.h"
#include <string>
#include <vector>
#include "AudioEngine.h"
#include "model/core/CoreModel.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

class PlayerShip : public CoreModel {
private:
    EventListenerTouchOneByOne *mEvent;
    vector<Bullet*> mBullets;
    int mIndexBullet;
    int mFrameShootBullet;
    PlayerShip();

    /**
     * Create list 20 bullet
     */
    void CreateBullets(Scene *layer);

    /**
     * Shoot one bullet on frame
     */
    void Shoot();

public:
    PlayerShip(Scene *layer, string namePath);
    ~PlayerShip();

    /**
     * Move game play from bottom screen to location default
     */
    void FirstMoveGamePlay(Scene *layer);

    /**
     * creat event onTouch onMove onTouchEnd for gameplay
     */
     void CreateEventForGamePlay(Scene *layer);

    /**
     * Event on Touch began
     * @param touch
     * @param event
     * @return
     */
    bool onTouchBegan(Touch *touch, Event *event);

    /**
     * Event on Touch move
     * @param touch
     * @param event
     */
    void onTouchMoved(Touch *touch, Event *event);

    /**
     * Event on Touch Ended
     * @param touch
     * @param event
     */
    void onTouchEnded(Touch *touch, Event *event);

    /**
     * function check collision player an bullet
     * @param rock
     * @return true : is collision
     * @return false : not collision
     */
    bool CheckCollisionWidthRock(Rect rectRock);

    /**
     * unction check collision rock and bullet
     * @param rock
     * @return true : is collision
     * @return false : not collision
     */
    bool CheckCollisionBulletAndRock(Rect rectRock);

    virtual void Init();
    virtual void Update();
};

#endif //SPACEGAME_PLAYERSHIP_H
