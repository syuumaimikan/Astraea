#pragma once
#include "DxLib.h"
#include "vector"
#include "string"

#define PI 3.1415926535f

#define white GetColor(255,255,255)

constexpr int GAME_AREA_X_MAX = 1315;
constexpr int GAME_AREA_Y_MAX = 1046;
constexpr int GAME_AREA_X_MIN = 32;
constexpr int GAME_AREA_Y_MIN = 16;
constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;
constexpr int FPS = 60;
constexpr int fontCount = 61;
constexpr int MENU_2_NUM = 7;
constexpr int BACKGROUNDIMG = 5;
constexpr int DIFFICULT_NUM = 4;
constexpr int MAX_BULLET = 20;
constexpr int MAX_ENEMY = 500;
constexpr int IMG_ENEMY_BULLET = 5;
constexpr int IMG_ENEMY_MAX = 5;
constexpr const char* tempFontPath1 = "MS Mincho";
constexpr const char* tempFontPath2 = "Bahnschrift SemiBold";
constexpr const char* tempFontPath3 = "LogoTypeGothicCondense.otf";

extern int fontSizes[fontCount];

extern int fontHandle_a_anti[fontCount];
extern int fontHandle_a_anti_edge[fontCount];

extern int fontHandle_b_anti[fontCount];
extern int fontHandle_b_anti_edge[fontCount];

extern int imgPL, imgBL, imgMenu,imgTitle, imgLoad;
extern int num;
extern int key_down;
extern int key_up;

extern float fsin[360], fcos[360];

extern int difficult;

extern int selectse;
extern int okse;
extern int shootse;

extern std::vector<std::string> menu_2;
extern std::vector<int> backgrounds;
extern std::vector<int> imgEnemy;
extern std::vector<std::string> difficultset;
extern std::vector<int> imgEbullet;

extern bool endtrig;
extern int distance;
extern int progress;
extern bool compset;

extern bool over;

extern int stage;

extern int score;
extern int hiscore;

extern float power;

extern void init(float num1[], float num2[]);

extern void drawImage(double x, double y, int image, bool rota , float angle);
extern int random(int low, int high);
extern struct OBJECT {
    double x, y;        // Position
    double v, vxd, vyd, vx, vy;   // Velocity
    double t;           // Bezier curve progress (0 <= t <= 1)
    float angle;
    double tmp;         // Temporary velocity
    double targetX, targetY; // Target position for bezier
    int waitTime;       // Wait time
    bool slowMode;      // Slow mode flag
    int state;          // Object state
    int pattern;        // Movement pattern
    int image;          // Image ID
    int wid, hei;       // Width and height
    int hp;             // Hitpoints
    int maxhp;             // Hitpoints
    int timer;          // Timer
    int range;
    int damage;
    int phase;
    bool invincible;
    bool automode;
    bool wait;
    int shootInterval;       // ’eŠÛ‚ð”­ŽË‚·‚éŠÔŠu (ƒ~ƒŠ•b’PˆÊ)
    int nextShootTime;       // ŽŸ‚É”­ŽË‰Â”\‚ÈŽžŠÔ
    int maxShots;
    int maxShots1;            // ”­ŽË‰Â”\‚ÈÅ‘å‰ñ”
    int maxShots2;
    int maxShots3;
    int maxShots4;
    int shotCount;           // Šù‚É”­ŽË‚µ‚½’eŠÛ‚Ì‰ñ”
    int remain;
};

extern struct OBJECT enemy[MAX_ENEMY];
extern struct OBJECT boss;
extern struct OBJECT player;
extern struct OBJECT bullet[MAX_BULLET];

extern enum EnemyState { ENE_IDLE,ENE_BULLET, ENE_ZAKO1, ENE_ZAKO2, ENE_ZAKO3, ENE_ZAKO4, ENE_ZAKO5,ENE_MINIBOSS_1, ENE_BOSS };
extern enum BulletState { BULLET_NORM, BULLET_LASER, BULLET_RADIAL, BULLET_N_WAY_60, BULLET_N_WAY_90 };