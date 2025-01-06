#pragma once

#include "GameBaseScene.h"
#include "Fadetxt.h"

//設定画面クラス
class Stage1 : public GameBaseScene {

public:
    FadeText* fadeText;
    FadeText* fadeText2;
    // Add b as a member variable
    int b;
    Stage1(GameSceneChanger* changer);
    void Initialize() override;    //初期化処理をオーバーライド。
    //void Finalize() override;        //終了処理をオーバーライド。
    void Update() override;        //更新処理をオーバーライド。
    void Draw() override;            //描画処理をオーバーライド。

};