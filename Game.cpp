#include "Game.h"
#include "DxLib.h"
#include "GameSceneMgr.h"
#include "Define.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
#include <iomanip>
#include <sstream>

Game::Game(ISceneChanger* changer) : BaseScene(changer) {
}

GameSceneMgr gsceneMgr;
Player pl;
Enemy enem;

//初期化
void Game::Initialize() {
    gsceneMgr.Initialize();
    player.x = static_cast<double>((GAME_AREA_X_MAX - GAME_AREA_X_MIN)) / 2;
    player.y = static_cast<double>((GAME_AREA_Y_MAX - GAME_AREA_Y_MIN)) / 1.3;
    player.v = 10.0f;
    player.tmp = player.v;
    player.vx = player.v;
    player.vy = player.v;
    player.slowMode = false;
    player.hp = 1;
    player.timer = 0;
    player.invincible = false;
    player.range = 3;
    player.remain = 3;
    player.automode = false;
    player.wait = false;
    ChangeVolumeSoundMem(128, shootse);
}

//更新
void Game::Update() {
    gsceneMgr.Update();
    if (compset && !over) {
        score++;
        pl.moveBullet();
        pl.move();
        enem.moveEnemy();
    }
}

//描画
void Game::Draw() {
    gsceneMgr.Draw();
    if (compset) {
        DrawBoard();
    }
    if (over) {
        std::string text = "GAME OVER";
        int strsize = GetDrawStringWidthToHandle(text.c_str(), text.size(), fontHandle_a_anti[60]);
        DrawStringToHandle((GAME_AREA_X_MAX + GAME_AREA_X_MIN) / 2 - strsize / 2, (GAME_AREA_Y_MAX + GAME_AREA_Y_MIN) / 2, text.c_str(), white, fontHandle_a_anti[60]);
    }
}

void Game::DrawBoard() {
    // 枠線（ボードの枠を描画）
    DrawRectGraph(0, 0, 0, 0, WIDTH, GAME_AREA_Y_MIN, backgrounds[4], TRUE);
    DrawRectGraph(0, 0, 0, 0, GAME_AREA_X_MIN, HEIGHT, backgrounds[4], TRUE);
    DrawRectGraph(0, GAME_AREA_Y_MAX, 0, GAME_AREA_Y_MAX, WIDTH, HEIGHT - GAME_AREA_Y_MAX, backgrounds[4], TRUE);
    DrawRectGraph(GAME_AREA_X_MAX, GAME_AREA_Y_MIN, GAME_AREA_X_MAX, GAME_AREA_Y_MIN, WIDTH, HEIGHT, backgrounds[4], TRUE);
    DrawBox(GAME_AREA_X_MIN, GAME_AREA_Y_MIN, GAME_AREA_X_MAX, GAME_AREA_Y_MAX, GetColor(255, 255, 255), FALSE);  // 左・上・右・下枠線
    DrawBox(GAME_AREA_X_MAX, GAME_AREA_Y_MIN, WIDTH, GAME_AREA_Y_MAX, GetColor(255, 255, 255), FALSE);

    std::string text = difficultset[difficult];
    int strsize = GetDrawStringWidthToHandle(text.c_str(), text.size(), fontHandle_a_anti_edge[60]);
    DrawStringToHandle(GAME_AREA_X_MAX + 300 - strsize / 2, GAME_AREA_Y_MIN + 25, text.c_str(), white, fontHandle_b_anti_edge[60]);

    DrawStringToHandle(GAME_AREA_X_MAX + 25, GAME_AREA_Y_MIN + 130, "HiScore", white, fontHandle_a_anti_edge[40]);
    std::ostringstream hss;
    hss << std::setw(8) << std::setfill('0') << hiscore;
    DrawStringToHandle(GAME_AREA_X_MAX + 250, GAME_AREA_Y_MIN + 130, hss.str().c_str(), white, fontHandle_a_anti_edge[50]);

    DrawStringToHandle(GAME_AREA_X_MAX + 25, GAME_AREA_Y_MIN + 200, "Score", white, fontHandle_a_anti_edge[40]);
    std::ostringstream ss;
    ss << std::setw(8) << std::setfill('0') << score;
    DrawStringToHandle(GAME_AREA_X_MAX + 250, GAME_AREA_Y_MIN + 200, ss.str().c_str(), white, fontHandle_a_anti_edge[50]);

    DrawStringToHandle(GAME_AREA_X_MAX + 25, GAME_AREA_Y_MIN + 300, "Player", white, fontHandle_a_anti_edge[40]);
    // 情報エリアの表示内容（固定）
    for (int i = 0; i < player.remain; i++) {
        DrawStringToHandle(GAME_AREA_X_MAX + 250 + 40 * i, GAME_AREA_Y_MIN + 300, "★", white, fontHandle_a_anti_edge[40]);
    }
    int integerPart = static_cast<int>(power);
    float fractionalPart = power - integerPart;
    DrawStringToHandle(GAME_AREA_X_MAX + 25, GAME_AREA_Y_MIN + 370, "Power", white, fontHandle_a_anti_edge[40]);
    DrawFormatStringToHandle(GAME_AREA_X_MAX + 250, GAME_AREA_Y_MIN + 370, white, fontHandle_a_anti_edge[40], "%d", integerPart);
    DrawFormatStringToHandle(GAME_AREA_X_MAX + 280, GAME_AREA_Y_MIN + 390, white, fontHandle_a_anti_edge[20], ".%02d", static_cast<int>(fractionalPart * 100));

    if (player.wait) {
        int barX = GAME_AREA_X_MIN + 25;     // HPバーのX座標
        int barY = GAME_AREA_Y_MIN + 50;    // HPバーのY座標
        int barWidth = 500;                 // HPバーの幅
        int barHeight = 20;                 // HPバーの高さ
        DrawBox(barX, barY, barX + barWidth, barY + barHeight, GetColor(128, 128, 128), TRUE);

        // HPに応じたバー (赤色)
        if (boss.hp > 0) {
            int hpBarWidth = static_cast<int>((static_cast<float>(boss.hp) / boss.maxhp) * barWidth);
            DrawBox(barX, barY, barX + hpBarWidth, barY + barHeight, GetColor(255, 0, 0), TRUE);
            if (boss.hp > boss.maxhp / 5 * 4) {
                boss.phase = 1;
            }
            else if (boss.hp > boss.maxhp / 5 * 3) {
                boss.phase = 2;
            }
            else if (boss.hp > boss.maxhp / 5 * 2) {
                boss.phase = 3;
            }
            else if (boss.hp > boss.maxhp / 5 * 1) {
                boss.phase = 4;
            }
            else {
                boss.phase = 5;
            }
        }
        
        // 境界線 (白色)
        DrawBox(barX - 1, barY - 1, barX + barWidth + 1, barY + barHeight + 1, GetColor(255, 255, 255), FALSE);

        // HP数値の表示
        std::ostringstream hpText;
        hpText << boss.hp << " / " << boss.maxhp;
        int textWidth = GetDrawStringWidthToHandle(hpText.str().c_str(), hpText.str().size(), fontHandle_a_anti_edge[30]);
        DrawStringToHandle(barX + (barWidth - textWidth) / 2, barY + 25, hpText.str().c_str(), white, fontHandle_a_anti_edge[30]);
    }
}