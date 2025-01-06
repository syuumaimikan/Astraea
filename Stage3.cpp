#include "Stage3.h"
#include "DxLib.h"

Stage3::Stage3(GameSceneChanger* changer) : GameBaseScene(changer) {
}

//������
void Stage3::Initialize() {
    gImageHandle = LoadGraph("images/Scene_Config.png");    //�摜�̃��[�h
}

//�X�V
void Stage3::Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        gSceneChanger->GChangeScene(gScene_Stage2);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Stage3::Draw() {
    GameBaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawString(0, 0, "�ݒ��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}