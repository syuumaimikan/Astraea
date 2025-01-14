#include "History.h"
#include <DxLib.h>

History::History(ISceneChanger* changer) : BaseScene(changer) {
}

//初期化
void History::Initialize() {
    mImageHandle = LoadGraph("images/Scene_Menu.png");    //画像のロード
}

//更新
void History::Update() {
    if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
        mSceneChanger->ChangeScene(eScene_Game);//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {//Cキーが押されていたら
        mSceneChanger->ChangeScene(eScene_Config);//シーンを設定画面に変更
    }
}

//描画
void History::Draw() {
    BaseScene::Draw();//親クラスの描画メソッドを呼ぶ
    DrawString(0, 0, "メaaa画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
    DrawString(0, 40, "Cキーを押すと　設定画面に進みます。", GetColor(255, 255, 255));
}

