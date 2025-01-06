#include "Define.h"
#include <math.h>
#include <random>

int fontSizes[fontCount];

int fontHandle_a_anti[fontCount];
int fontHandle_a_anti_edge[fontCount];

int fontHandle_b_anti[fontCount];
int fontHandle_b_anti_edge[fontCount];

int imgPL, imgBL, imgMenu, imgTitle, imgLoad;
int num = 0;
int key_down = 0;
int key_up = 0;
int difficult = 0;

std::vector<std::string> menu_2(MENU_2_NUM);
std::vector<int> backgrounds(BACKGROUNDIMG);
std::vector<int> imgEnemy(IMG_ENEMY_MAX);
std::vector<int> imgEbullet(IMG_ENEMY_BULLET);
std::vector<std::string> difficultset(DIFFICULT_NUM);

bool endtrig = false;
bool compset = false;
int distance = 0;
int progress = 0;
int stage = 0;

int selectse;
int okse;
int shootse;

int score = 0;
int hiscore = 0;

float power = 0.0;

bool over = false;

float fsin[360], fcos[360];

struct OBJECT enemy[MAX_ENEMY];
struct OBJECT boss;
struct OBJECT player;
struct OBJECT bullet[MAX_BULLET];

void init(float num1[], float num2[]) {
    for (int i = 0; i < 360; i++) {

        num1[i] = (float)sin(i * PI / 180);

        num2[i] = (float)cos(i * PI / 180);

    }

}
std::default_random_engine gen;

int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

void drawImage(double x, double y, int image, bool rota, float angle) {
    int w, h;
    GetGraphSize(image, &w, &h);
    if (rota) DrawRotaGraph(x, y, 1, angle, image, TRUE);
    else DrawGraph(x - w / static_cast<double>(2), y - h / static_cast<double>(2), image, TRUE);
}