#include "DxLib.h"
#include "LoadScene.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Credits.h"
#include "MusicRoom.h"
#include "Title.h"
#include "History.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() :
    mNextScene(eScene_None) //���̃V�[���Ǘ��ϐ�
{
    mScene = (BaseScene*) new LoadScene(this);
}

//������
void SceneMgr::Initialize() {
    mScene->Initialize();
}

//�I������
void SceneMgr::Finalize() {
    mScene->Finalize();
}

//�X�V
void SceneMgr::Update() {
    if (mNextScene != eScene_None) {    //���̃V�[�����Z�b�g����Ă�����
        mScene->Finalize();//���݂̃V�[���̏I�����������s
        delete mScene;
        switch (mNextScene) {       //�V�[���ɂ���ď����𕪊�
        case eScene_Load:
            mScene = (BaseScene*) new LoadScene(this);
            break;
        case eScene_Title:
            mScene = (BaseScene*) new Title(this);
            break;
        case eScene_Menu:        //���̉�ʂ����j���[�Ȃ�
            mScene = (BaseScene*) new Menu(this);   //���j���[��ʂ̃C���X�^���X�𐶐�����
            break;//�ȉ���
        case eScene_Game:
            mScene = (BaseScene*) new Game(this);
            break;
        case eScene_Config:
            mScene = (BaseScene*) new Config(this);
            break;
        case eScene_Music:
            mScene = (BaseScene*) new MusicRoom(this);
            break;
        case eScene_Credits:
            mScene = (BaseScene*) new Credits(this);
            break;
        case eScene_History:
            mScene = (BaseScene*) new History(this);
            break;
        }
        mNextScene = eScene_None;    //���̃V�[�������N���A
        mScene->Initialize();    //�V�[����������
    }
    mScene->Update(); //�V�[���̍X�V
}

//�`��
void SceneMgr::Draw() {
    mScene->Draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::ChangeScene(eScene NextScene) {
    mNextScene = NextScene;    //���̃V�[�����Z�b�g����
}