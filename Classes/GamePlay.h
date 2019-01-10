#ifndef __GAME_PLAY_H__
#define __GAME_PLAY_H__

#include "cocos2d.h"
#include <vector>
using namespace std;
using namespace cocos2d;

class GamePlay {
private:
	cocos2d::Sprite * mGamePlay;
	Vector<SpriteFrame*> animationFrames;
public:
	GamePlay();
	virtual ~GamePlay();
	cocos2d::Sprite *GetGamePlay();
	void Run();
	void SetPosition(float x, float y);
	Vector<SpriteFrame*> getAnnimation(const char *prefix, int count);
};
#endif !__GAME_PLAY_H__