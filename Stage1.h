#pragma once

#include "GameBaseScene.h"
#include "Fadetxt.h"

//�ݒ��ʃN���X
class Stage1 : public GameBaseScene {

public:
    FadeText* fadeText;
    FadeText* fadeText2;
    // Add b as a member variable
    int b;
    Stage1(GameSceneChanger* changer);
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    //void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B

};