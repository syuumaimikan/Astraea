#include "Stage3.h"
#include "DxLib.h"

Stage3::Stage3(GameSceneChanger* changer) : GameBaseScene(changer) {
}

//初期化
void Stage3::Initialize() {
    gImageHandle = LoadGraph("images/Scene_Config.png");    //画像のロード
}

//更新
void Stage3::Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        gSceneChanger->GChangeScene(gScene_Stage2);//シーンをメニューに変更
    }
}

//描画
void Stage3::Draw() {
    GameBaseScene::Draw();//親クラスの描画メソッドを呼ぶ
    DrawString(0, 0, "設定画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}