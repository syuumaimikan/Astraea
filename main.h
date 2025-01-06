#ifndef MAIN_H
#define MAIN_H
#define _USE_MATH_DEFINES

#include "DxLib.h"
#include <string>
#include <vector>

// Game Window Settings
constexpr int GAME_AREA_X_MAX = 1500;
constexpr int GAME_AREA_Y_MAX = 1000;
constexpr int GAME_AREA_X_MIN = 80;
constexpr int GAME_AREA_Y_MIN = 80;
constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;
constexpr int FPS = 60;
constexpr int IMG_ENEMY_MAX = 10;
constexpr int BACKGROUNDIMG = 40;
constexpr int STAGE_SOUND_NUN = 18;
constexpr int MENU_2_NUM = 7;
constexpr int DIFFICULT_NUM = 4;
constexpr int ENEMY_MAX = 50;
constexpr int MAX_BULLET = 20;
constexpr int RADIUS = 300;

// Game Scenes
enum Scene { TITLE, MENU, GAME, EXGAME, HISTORY, MUSICROOM, OPTION, CREDITS, QUIT };
enum EnemyState { ENE_IDLE, ENE_BULLET, ENE_ZAKO1, ENE_ZAKO2, ENE_ZAKO3, ENE_ZAKO4, ENE_ZAKO5, ENE_BOSS };

// Global Variables
extern bool endtrig;
extern int imgPL, imgBL, imgMenu;
extern std::vector<int> backgrounds;
extern std::vector<int> backgrounds_soft;
extern std::vector<int> imgEnemy;
extern std::vector<int> stBGM;
extern std::vector<std::string> menu_2;
extern std::vector<std::string> difficultset;
extern int imgEXPL, imgIT;
extern int GOver, seExpl, seItem, seShot;
extern int scene;
extern int timer;
extern int currentStage;

// Objects
struct OBJECT {
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
    int timer;          // Timer
    int range;
};

// Fade Text Structure
struct FadeText {
    int alpha;          // Alpha value (0-255)
    int fadeDirection;  // Fade direction (1: fade in, -1: fade out)
    bool showText;      // Display flag
};

// Function Declarations
void particle(void);
void setBullet(void);
void moveBullet(void);
float bezier(float t, float p0, float p1, float p2);
int gpUpdateKey();
int setEnemy(int x, int y, int target_x, int target_y, int vx, int vy, int ptn, int img, int sld, bool target);
void moveEnemy(void);
void reset(int& variable);
void createFonts(void);
void scrollBG(int stnum, int spd);
void Init(void);
void fadetxt(FadeText& fade, const char* text, int x, int y, int color, int fadespeed, int fontIndex);
void update(void);
void drawImage(double x, double y, int image);
void moveplayer(void);
void DrawPlayer(int imgHandle);
void onSceneChange();
void loadResources();
void freeResources();
void changeScene(int nextScene);
void titleScene();
void menuScene();
void ClampPlayerPosition();
void credits();
void gameScene();
void quitScene();
void DrawBoard();
void playCurrentStage();
void playStageOne();
void spawnStageOneEnemies();
void changeStageMusic();
void handleMenuInput(int maxNum);
void showDifficultySelection();
#endif // MAIN_H