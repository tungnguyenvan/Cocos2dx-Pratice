#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

using namespace cocos2d;

class Background {
private:
	Sprite *mBackground;
public:
	Background();
	~Background();
	Sprite *GetBackground();
	void RunAction();
};

#endif //!__BACKGROUND_H__