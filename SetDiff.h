#pragma once

#include "GameBaseScene.h"

//設定画面クラス
class SetDiff : public GameBaseScene {
private:
    bool hit;
public:
    SetDiff(GameSceneChanger* changer);
    void Initialize() override;
    //void Finalize() override;        //終了処理をオーバーライド。
    void Update() override;        //更新処理をオーバーライド。
    void Draw() override;            //描画処理をオーバーライド。
    void handleMenuInput(int maxNum);
};