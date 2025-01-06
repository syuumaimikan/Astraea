#include "Stage2.h"
#include "DxLib.h"

Stage2::Stage2(GameSceneChanger* changer) : GameBaseScene(changer) {
}

//������
void Stage2::Initialize() {
    gImageHandle = LoadGraph("images/Scene_Config.png");    //�摜�̃��[�h
}

//�X�V
void Stage2::Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        gSceneChanger->GChangeScene(gScene_Stage2);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Stage2::Draw() {
    GameBaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawString(0, 0, "�ݒ��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}