#pragma once

#include "GameSceneChanger.h"
#include "GameBaseScene.h"

class GameSceneMgr : public GameSceneChanger, GameTask {

private:
    GameBaseScene* mScene;    //�V�[���Ǘ��ϐ�
    gScene mNextScene;    //���̃V�[���Ǘ��ϐ�
public:
    GameSceneMgr();
    void Initialize() override;//������
    void Finalize() override;//�I������
    void Update() override;//�X�V
    void Draw() override;//�`��

    // ���� nextScene �ɃV�[����ύX����
    void GChangeScene(gScene NextScene) override;

};