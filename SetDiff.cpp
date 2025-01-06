#include "SetDiff.h"
#include "DxLib.h"
#include "Define.h"
#include "Key.h"

SetDiff::SetDiff(GameSceneChanger * changer) : GameBaseScene(changer),hit(false) {
}

//初期化
void SetDiff::Initialize() {
    difficultset[0] = "Easy";
    difficultset[1] = "Normal";
    difficultset[2] = "Hard";
    difficultset[3] = "Cosmotic";
}

//更新
void SetDiff::Update() {
    if (Key[KEY_INPUT_DOWN] == 1) {
        key_down++;
        PlaySoundMem(selectse, DX_PLAYTYPE_BACK);
    }
    if (Key[KEY_INPUT_DOWN] != 1) {
        key_down = 0;
    }
    if (key_down == 1) num++;
    if (Key[KEY_INPUT_UP] == 1) {
        key_up++;
        PlaySoundMem(selectse, DX_PLAYTYPE_BACK);
    }
    if (Key[KEY_INPUT_UP] != 1) {
        key_up = 0;
    }
    if (key_up == 1) num--;
    if (Key[KEY_INPUT_RETURN] == 1&&!hit) { //Escキーが押されていたら
        hit = true;
        PlaySoundMem(okse, DX_PLAYTYPE_BACK);
        difficult = num;
    }
    if (hit && CheckSoundMem(okse) == 0) {
        hit = false;
        gSceneChanger->GChangeScene(gScene_Stage1);//シーンをメニューに変更
        compset = true;
    }
}

//描画
void SetDiff::Draw() {
    DrawStringToHandle(100, 100, "Set Difficulty", white, fontHandle_a_anti_edge[60]);
    for (int i = 0; i < DIFFICULT_NUM; i++) {
        DrawStringToHandle(i * 5 + 100, 200 + i * 70, difficultset[i].c_str(), GetColor(255, 255, 255), fontHandle_a_anti[60]);
    }
    handleMenuInput(DIFFICULT_NUM);
}

void SetDiff::handleMenuInput(int maxNum) {
    if (num < 0) num = maxNum - 1;
    if (num >= maxNum) num = 0;
    DrawStringToHandle(100 + num * 5, 200 + num * 70, difficultset[num].c_str(), GetColor(255, 255, 0), fontHandle_a_anti[60]);
}