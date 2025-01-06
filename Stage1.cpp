#include "Stage1.h"
#include "DxLib.h"
#include "Fadetxt.h"
#include "ScrollBG.h"
#include "Enemy.h"
#include "Define.h"

Stage1::Stage1(GameSceneChanger* changer) : GameBaseScene(changer),b(0),fadeText(),fadeText2() {
}

ScrollBackground ScrollBG;
Enemy ene;

//初期化
void Stage1::Initialize() {
    distance = FPS * 180;
    stage = 1;
    progress = 0;
    int b = GetDrawStringWidthToHandle("宵の始まり", strlen("宵の始まり"), fontHandle_a_anti[60]);

    fadeText = new FadeText(
        "Stage1",
        (GAME_AREA_X_MAX - GAME_AREA_X_MIN) / 2 - 200, // エリアの中央の X 座標
        (GAME_AREA_Y_MAX - GAME_AREA_Y_MIN) / 2 - 100, // エリアの中央の Y 座標
        white,
        2,
        50
    );
    fadeText2 = new FadeText(
        "宵の始まり",
        (GAME_AREA_X_MAX - GAME_AREA_X_MIN) / 2, // エリアの中央の X 座標
        (GAME_AREA_Y_MAX - GAME_AREA_Y_MIN) / 2, // エリアの中央の Y 座標
        white,
        2,
        60
    );
}

//更新
void Stage1::Update() {
    ScrollBG.update(2);
    if (fadeText) fadeText->update();
    if (fadeText2) fadeText2->update();

    if (!player.wait) {
        if (distance > 0) distance--;
        if (distance % 60 == 1) {
            progress++;
            if (progress > 3) {
                int x = random(GAME_AREA_X_MIN + 100, GAME_AREA_X_MAX - 100);
                ene.setEnemy(x, -100, 0, 10, 0, ENE_ZAKO4, imgEnemy[3], 10, 1, 1, 1, 1, 1, 1);
            }
            if (7 > progress && progress > 3) {
                int x = GAME_AREA_X_MIN + 200;
                for (int i = 0; i < 5; i++) {
                    ene.setEnemy(x + 200 * i, -100, 0, 10, 0, ENE_ZAKO1, imgEnemy[ENE_ZAKO1], 10, 1, 0.1, 1, 3, 5, 7);
                }
            }
            if (13 >= progress && progress > 7) {
                int x = random(GAME_AREA_X_MIN + 100, GAME_AREA_X_MAX - 100);
                ene.setEnemy(x, -100, 0, 10, 0, ENE_ZAKO2, imgEnemy[ENE_ZAKO2], 20, 0, 0, 0, 0, 0, 0);
            }
            if (18 >= progress && progress > 15) {
                int x = GAME_AREA_X_MIN + 200;
                for (int i = 0; i < 10; i++) {
                    ene.setEnemy(x + 100 * i, -100, 0, 10, 0, ENE_ZAKO3, imgEnemy[ENE_ZAKO1], 20, 1, 0.1, 1, 3, 5, 7);
                }
            }
            if (21 >= progress && progress > 20) {
                ene.setEnemy((GAME_AREA_X_MAX - GAME_AREA_X_MIN) / 2, -100, 0, 10, 0, ENE_MINIBOSS_1, imgEnemy[ENE_ZAKO2], 600, 10, 0.5, 1, 1, 1, 1);
            }
        }
    }
}

//描画
void Stage1::Draw() {
    ScrollBG.draw(0);
    GameBaseScene::Draw();
    if (fadeText) fadeText->draw();
    if (fadeText2) fadeText2->draw();
}