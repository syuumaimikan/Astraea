#include "Fadetxt.h"
#include <DxLib.h>
#include "Define.h"

// コンストラクタ
FadeText::FadeText(const std::string& text, int areaWidth, int areaHeight, int color, int fadespeed, int fontIndex)
    : text(text), color(color), fadespeed(fadespeed), fontIndex(fontIndex),
    alpha(0), fadeDirection(1), showText(true) {
    // フォントハンドルを取得
    int fontHandle = fontHandle_a_anti[fontIndex];

    // 文字の幅と高さを取得
    textWidth = GetDrawStringWidthToHandle(text.c_str(), strlen(text.c_str()), fontHandle_a_anti[fontIndex]);
    textHeight = GetFontSizeToHandle(fontHandle);
    // 画面の中央位置を計算
    fx = areaWidth - textWidth / 2;
    fy = areaHeight - textHeight;
}

// テキストを更新
void FadeText::update() {
    if (showText) {
        alpha += fadeDirection * fadespeed;
        if (alpha >= 255) {
            alpha = 255;
            fadeDirection = -1; // フェードアウトに切り替え
        }
        else if (alpha <= 0) {
            alpha = 0;
            showText = false;   // テキスト表示終了
        }
    }
}

// テキストを描画
void FadeText::draw() const {
    if (showText) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        DrawStringToHandle(fx, fy, text.c_str(), color, fontHandle_a_anti[fontIndex]);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

// テキスト表示を開始
void FadeText::start() {
    showText = true;
    alpha = 0;
    fadeDirection = 1; // フェードインから開始
}

// テキスト表示状態を取得
bool FadeText::isShowing() const {
    return showText;
}
