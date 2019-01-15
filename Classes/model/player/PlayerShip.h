/*********************************
 *
 * Created by tung on 15/01/2019.
 *
*********************************/

#ifndef SPACEGAME_PLAYERSHIP_H
#define SPACEGAME_PLAYERSHIP_H

#include "cocos2d.h"
#include <string>

using namespace cocos2d;
using namespace std;

class PlayerShip {
private:
    Size mVisibleSize;
    Sprite *mGamePlay;
    EventListenerTouchOneByOne *mEvent;
    Scene *layer;
    PlayerShip();

public:
    PlayerShip(Scene *layer, string namePath);
    ~PlayerShip();

    /**
     * Move game play from bottom screen to location default
     */
    void FirstMoveGamePlay();

    /**
     * creat event onTouch onMove onTouchEnd for gameplay
     */
     void CreateEventForGamePlay();

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


};

#endif //SPACEGAME_PLAYERSHIP_H
