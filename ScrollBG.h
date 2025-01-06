#ifndef SCROLLBG_H
#define SCROLLBG_H

#include <DxLib.h>

class ScrollBackground {
private:
    int bgY;      // 背景のY座標
    int floorY;   // 床のY座標
    int wallY;    // 壁のY座標

public:
    // コンストラクタ
    ScrollBackground();

    // 背景をスクロール描画
    void draw(int stnum) const;
    void update(int spd);
    // 背景をリセット
    void reset();
};

#endif // SCROLLBG_H