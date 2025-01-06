#include "Title.h"
#include "DxLib.h"
#include "Define.h"

Title::Title(ISceneChanger* changer) : BaseScene(changer), hit(false) {
}

//������
void Title::Initialize() {
}

//�X�V
void Title::Update() {
    if (CheckHitKeyAll() != 0 && !hit) {
        PlaySoundMem(okse, DX_PLAYTYPE_BACK);
        hit = true;  // Set the flag immediately after playing the sound
    }

    if (hit && CheckSoundMem(okse) == 0) {  // Wait for the sound to finish
        mSceneChanger->ChangeScene(eScene_Menu);  // Change the scene
        hit = false;  // Reset the flag to allow for future interactions
    }
}

//�`��
void Title::Draw() {
    BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawGraph(0, 0, imgTitle, FALSE);
    const char* text = "Place Any Key";
    int DrawWidth = GetDrawStringWidthToHandle(text, strlen(text), fontHandle_a_anti[40]);
    DrawStringToHandle((WIDTH - DrawWidth) / 2, HEIGHT -130, text, GetColor(255, 255, 255), fontHandle_a_anti[40]);
}