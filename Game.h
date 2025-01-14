#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"

// ゲーム画面クラス
class Game : public BaseScene {
public:
    Game(ISceneChanger* changer);    // コンストラクタ
    void Initialize() override;     // 初期化処理をオーバーライド
    void Update() override;         // 更新処理をオーバーライド
    void Draw() override;           // 描画処理をオーバーライド
    void DrawBoard();
};
