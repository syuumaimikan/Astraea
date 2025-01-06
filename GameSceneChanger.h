#pragma once

typedef enum {
    gScene_Set,
    gScene_Stage1,
    gScene_Stage2,
    gScene_Stage3,
    gScene_Stage4,
    gScene_Stage5,
    gScene_Stage6,
    gScene_StageEX,

    gScene_None,    //����
} gScene;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class GameSceneChanger {
public:
    virtual ~GameSceneChanger() = 0;
    virtual void GChangeScene(gScene NextScene) = 0;//�w��V�[���ɕύX����
};