#pragma once

#include "BaseScene.h"

//メニュー画面クラス
class Menu : public BaseScene {
private:
    bool hit;
public:
    Menu(ISceneChanger* changer);
    void Initialize() override;    //初期化処理をオーバーライド。
    //void Finalize() override ;        //終了処理をオーバーライド。
    void Update() override;        //更新処理をオーバーライド。
    void Draw() override;            //描画処理をオーバーライド。

};