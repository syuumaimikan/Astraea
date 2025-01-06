#pragma once

#include "GameTask.h"
#include "GameSceneChanger.h"

//�V�[���̊��N���X�B
class GameBaseScene : public GameTask {

protected:
    int gImageHandle;                //�摜�n���h���i�[�p�ϐ�
    GameSceneChanger* gSceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X

public:
    GameBaseScene(GameSceneChanger* changer);
    virtual ~GameBaseScene() {}
    virtual void Initialize() override {}    //�������������I�[�o�[���C�h�B
    virtual void Finalize() override;        //�I���������I�[�o�[���C�h�B
    virtual void Update() override {}        //�X�V�������I�[�o�[���C�h�B
    virtual void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
};