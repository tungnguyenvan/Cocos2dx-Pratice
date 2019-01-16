//
// Created by tung on 16/01/2019.
//

#ifndef SPACEGAME_ENDGAME_H
#define SPACEGAME_ENDGAME_H

#include "cocos2d.h"
#include "model/background/Background.h"

using namespace cocos2d;

class EndGame : public Scene {
private:
    int mScore;
    Size mVisibleSize;
    Background *mBackground;
    Label *mLbNameGame;

public:
    static cocos2d::Scene* createScene(int score);
    virtual bool init();
    CREATE_FUNC(EndGame);
};

#endif //SPACEGAME_ENDGAME_H
