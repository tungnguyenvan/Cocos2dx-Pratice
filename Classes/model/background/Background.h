/**********************************
 *
 * Created by tung on 15/01/2019.
 * Crate background to screen
 *
 **********************************/

#ifndef SPACEGAME_BACKGROUND_H
#define SPACEGAME_BACKGROUND_H

#include "cocos2d.h"

using namespace cocos2d;

class Background {
private:
    /**
     * Size of screen
     */
    Size mVisibleSize;

    Background();

    /**
     * Check background fulled screen
     * @param background : 1 Sprite
     * @return true : is full
     * @return false : not full
     */
    bool CheckBackgroundFullScreen(Sprite *background);

public:
    Background(Scene *layer);
    ~Background();
};

#endif //SPACEGAME_BACKGROUND_H
