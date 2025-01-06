#ifndef FADETEXT_H
#define FADETEXT_H

#include <string>

class FadeText {
private:
    std::string text;     // 表示するテキスト
    int textWidth, textHeight;
    int fx, fy;             // テキストの描画位置
    int color;            // テキストの色
    int fadespeed;        // フェード速度
    int fontIndex;        // フォントインデックス
    int alpha;            // アルファ値
    int fadeDirection;    // フェード方向 (1: フェードイン, -1: フェードアウト)
    bool showText;        // テキストを表示するかどうか

public:
    // コンストラクタ
    FadeText(const std::string& text, int areaWidth, int areaHeight, int color, int fadespeed, int fontIndex);

    // テキストを更新
    void update();

    // テキストを描画
    void draw() const;

    // テキスト表示を開始
    void start();

    // テキスト表示状態を取得
    bool isShowing() const;
};

#endif // FADETEXT_H