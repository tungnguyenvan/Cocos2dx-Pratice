//
// Created by tung on 15/01/2019.
//

#ifndef SPACEGAME_DEFINITION_H
#define SPACEGAME_DEFINITION_H

#define GAME_NAME "Space game"
#define SCREEN_W 480
#define SCREEN_H 800
#define FPS 40

#define BACKGROUND_PATH_PURPLE "background/purple.png"

#define SHEET_PLAYER_SHIP_IMAGE "playerShip.png"
#define SHEET_PLAYER_SHIP_PLIST "playerShip.plist"
#define PLAYER_SHIP_GREEN_1 "playerShip1_green.png"
#define PLAYER_SHIP_GREEN_2 "playerShip2_green.png"
#define PLAYER_SHIP_GREEN_3 "playerShip3_green.png"
#define PLAYER_SHIP_BLUE_1 "playerShip1_blue.png"
#define PLAYER_SHIP_BLUE_2 "playerShip2_blue.png"
#define PLAYER_SHIP_BLUE_3 "playerShip3_blue.png"
#define PLAYER_SHIP_RED_1 "playerShip1_red.png"
#define PLAYER_SHIP_RED_2 "playerShip2_red.png"
#define PLAYER_SHIP_RED_3 "playerShip3_red.png"
#define PLAYER_SHIP_OGRANGE_1 "playerShip1_orange.png"
#define PLAYER_SHIP_OGRANGE_2 "playerShip2_orange.png"
#define PLAYER_SHIP_OGRANGE_3 "playerShip3_orange.png"
#define PLAYER_MOVE_TIME 0.7
#define SCALE_PLAYER_SHIP 0.7
#define GAMEPLAY_SOUND "sound/sfx8.wav"
#define GAMEPLAY_SOUND_DIE "sound/sfx5.wav"

#define ROCK_1_PLIST_FILE_PATH "rock/rock1/rock1.plist"
#define ROCK_2_PLIST_FILE_PATH "rock/rock2/rock2.plist"
#define ROCK_EFFORT_PLIST_FILE_PATH "effort/effort.plist"
#define FORMAT_1_ROCK_NAME "a1(%d).png"
#define FORMAT_2_ROCK_NAME "a3(%d).png"
#define FORMAT_EFFORT_ROCK_NAME "frame_%d_delay-0.07s.png"
#define ADD_MORE_HEIGHT_SCREEN 50
#define ROCK_MIN_FALL_TIME 0.03
#define ROCK_MAX_FALL_TIME 0.07
#define SIZE_LIST_ROCKS 100
#define REDUCT_SIZE_RECT_ROCK 32.5
#define ROCK_EFFORT_FRAME_TIME 0.02
#define ROCK_EFFORT_TOTAL_FRAME 28

#define SHOOT_BULLET_STEP 5
#define SIZE_LIST_BULLETS 100
#define POSITION_DEFAULT_BULLET Vec2(-100, -100)
#define BULLET_SOUND "sound/sfx1.wav"

#define FONT_PATH "font/BoyzRGrossNF.ttf"
#define FONT_SIZE_LABLE_NAME_GAME 100

#define Z_ORDER_BACKGROUND 0
#define Z_ORDER_BULLET 1
#define Z_ORDER_ROCK 2
#define Z_ORDER_EFFORT 3
#define Z_ORDER_PLAYER 4
#define Z_ORDER_SCORE 5

#endif //SPACEGAME_DEFINITION_H