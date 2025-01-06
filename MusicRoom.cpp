#include "MusicRoom.h"
#include <DxLib.h>

MusicRoom::MusicRoom(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void MusicRoom::Initialize() {
    mImageHandle = LoadGraph("images/Scene_Menu.png");    //�摜�̃��[�h
}

//�X�V
void MusicRoom::Update() {
    if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
        mSceneChanger->ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {//C�L�[��������Ă�����
        mSceneChanger->ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
    }
}

//�`��
void MusicRoom::Draw() {
    BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
    DrawString(0, 0, "��aaa��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
    DrawString(0, 40, "C�L�[�������Ɓ@�ݒ��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

