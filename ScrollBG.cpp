#include "ScrollBG.h"
#include "Define.h"

// コンストラクタ
ScrollBackground::ScrollBackground()
    : bgY(0), floorY(0), wallY(0) {}

// 背景をリセット
void ScrollBackground::reset() {
    bgY = 0;
    floorY = 0;
    wallY = 0;
}

// 背景を更新
void ScrollBackground::update(int spd) {
    // 背景のスクロール更新
    bgY = (bgY + spd) % GAME_AREA_Y_MAX;

    // 床のスクロール更新
    floorY = (floorY + spd * 2) % 120;

    // 壁のスクロール更新
    wallY = (wallY + spd * 4) % 240;
}

// 背景を描画
void ScrollBackground::draw(int stnum) const {
    // 背景描画（ゲームエリア内背景のみスクロール）
    DrawGraph(GAME_AREA_X_MIN, GAME_AREA_Y_MIN + bgY - GAME_AREA_Y_MAX, backgrounds[stnum], FALSE);
    DrawGraph(GAME_AREA_X_MIN, GAME_AREA_Y_MIN + bgY, backgrounds[stnum], FALSE);

    // 床の描画
    for (int i = -1; i < 6; i++) {
        DrawGraph(GAME_AREA_X_MIN + 210, GAME_AREA_Y_MIN + floorY + i * 120, backgrounds[stnum + 1], TRUE);
    }

    // 壁の描画
    DrawGraph(GAME_AREA_Y_MIN, GAME_AREA_Y_MIN + wallY - 240, backgrounds[stnum + 2], TRUE);
    DrawGraph(GAME_AREA_X_MAX - 300, GAME_AREA_Y_MIN + wallY - 240, backgrounds[stnum + 3], TRUE);
}
