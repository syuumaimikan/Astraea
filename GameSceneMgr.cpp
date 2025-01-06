#include "DxLib.h"
#include "GameSceneMgr.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "SetDiff.h"
#include "Define.h"

GameSceneMgr::GameSceneMgr() :
    mNextScene(gScene_None) //���̃V�[���Ǘ��ϐ�
{
    mScene = (GameBaseScene*) new SetDiff(this);
}

//������
void GameSceneMgr::Initialize() {
    mScene->Initialize();
}

//�I������
void GameSceneMgr::Finalize() {
    mScene->Finalize();
}

//�X�V
void GameSceneMgr::Update() {
    if (mNextScene != gScene_None) {    //���̃V�[�����Z�b�g����Ă�����
        mScene->Finalize();//���݂̃V�[���̏I�����������s
        delete mScene;
        switch (mNextScene) {       //�V�[���ɂ���ď����𕪊�
        case gScene_Set:
            mScene = (GameBaseScene*) new SetDiff(this);
            break;//�ȉ���
        case gScene_Stage1:      
            mScene = (GameBaseScene*) new Stage1(this); 
            break;//�ȉ���
        case gScene_Stage2:
            mScene = (GameBaseScene*) new Stage2(this);
            break;
        case gScene_Stage3:
            mScene = (GameBaseScene*) new Stage3(this);
            break;
        }
        mNextScene = gScene_None;    //���̃V�[�������N���A
        mScene->Initialize();    //�V�[����������
    }
    if (!over)mScene->Update(); //�V�[���̍X�V
}

//�`��
void GameSceneMgr::Draw() {
    mScene->Draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void GameSceneMgr::GChangeScene(gScene NextScene) {
    mNextScene = NextScene;    //���̃V�[�����Z�b�g����
}