/***************************************
* Created by tung on 15/01/2019.
***************************************/

#include "util/Definition.h"
#include "Background.h"
#include "cocos2d.h"

using namespace cocos2d;

Background::Background() {

}

Background::Background(Scene *layer) {
    mVisibleSize = layer->getContentSize();

    Sprite* background = Sprite::create(BACKGROUND_PATH_PURPLE);
    background->setAnchorPoint(Vec2(0, 0));
    layer->addChild(background, Z_ORDER_BACKGROUND);

    Sprite* currentBackground = Sprite::create(BACKGROUND_PATH_PURPLE);
    auto backgroundSize = background->getContentSize();
    while (!Background::CheckBackgroundFullScreen(currentBackground))
    {
        auto currentPosition = currentBackground->getPosition();
        Sprite* background = Sprite::create(BACKGROUND_PATH_PURPLE);
        background->setAnchorPoint(Vec2(0, 0));
        if (currentPosition.x + backgroundSize.width <= mVisibleSize.width) {
            background->setPosition(Vec2(currentPosition.x + backgroundSize.width, currentPosition.y));
        }
        else if (currentPosition.y + backgroundSize.height <= mVisibleSize.height) {
            if (currentPosition.x + backgroundSize.width >= mVisibleSize.width) {
                currentBackground->setPosition(Vec2(0, currentBackground->getPosition().y));
                currentPosition = currentBackground->getPosition();
            }
            background->setPosition(Vec2(currentPosition.x, currentPosition.y + backgroundSize.height));
        }

        currentBackground->setPosition(background->getPosition());

        layer->addChild(background, Z_ORDER_BACKGROUND);
    }
}

bool Background::CheckBackgroundFullScreen(Sprite *background){
    auto backgroundContentSize = background->getContentSize();
    auto backgroundPosition = background->getPosition();

    if (backgroundPosition.x + backgroundContentSize.width >= mVisibleSize.width
        && backgroundPosition.y + backgroundContentSize.height >= mVisibleSize.height)
        return true;

    return false;
}

Background::~Background() {

}
