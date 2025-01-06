#include "Menu.h"
#include "DxLib.h"
#include "Define.h"
#include "Key.h"

Menu::Menu(ISceneChanger* changer) : BaseScene(changer), hit(false) {
}
//初期化
void Menu::Initialize() {
    menu_2[0] = "Play";
    menu_2[1] = "EX Stage";
    menu_2[2] = "History";
    menu_2[3] = "Music Room";
    menu_2[4] = "Option";
    menu_2[5] = "Credits";
    menu_2[6] = "Quit";
}

//更新
void Menu::Update() {
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
    if (num < 0)num = 6;
    if (num > 6)num = 0;
    if (Key[KEY_INPUT_RETURN] == 1 && !hit) {
        hit = true;
        PlaySoundMem(okse, DX_PLAYTYPE_BACK);
    }
    if (hit && CheckSoundMem(okse) == 0) {  // 効果音が終了したらシーン変更
        switch (num) {
        case 0: mSceneChanger->ChangeScene(eScene_Game); break;
        case 1: mSceneChanger->ChangeScene(eScene_Game); break;  // EXステージ
        case 2: mSceneChanger->ChangeScene(eScene_History); break;
        case 3: mSceneChanger->ChangeScene(eScene_Music); break;
        case 4: mSceneChanger->ChangeScene(eScene_Config); break;
        case 5: mSceneChanger->ChangeScene(eScene_Credits); break;
        case 6: endtrig = true; break;  // ゲーム終了
        }
        hit = false;  // リセット
    }
}

//描画
void Menu::Draw() {
    BaseScene::Draw();//親クラスの描画メソッドを呼ぶ
    DrawGraph(0, 0, imgMenu, FALSE);
    for (int i = 0; i < MENU_2_NUM; i++) {
        DrawStringToHandle(i * 5 + GAME_AREA_X_MAX+200, 500 + i * 70, menu_2[i].c_str(), GetColor(255, 255, 255), fontHandle_a_anti[60]);
    }
    DrawStringToHandle(GAME_AREA_X_MAX + 200 + num * 5, 500 + num * 70, menu_2[num].c_str(), GetColor(255, 255, 0), fontHandle_a_anti[60]);
}

