#pragma once

#include "GameBaseScene.h"

//�ݒ��ʃN���X
class Stage2 : public GameBaseScene {

public:
    Stage2(GameSceneChanger* changer);
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    //void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B

};