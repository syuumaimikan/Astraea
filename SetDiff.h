#pragma once

#include "GameBaseScene.h"

//�ݒ��ʃN���X
class SetDiff : public GameBaseScene {
private:
    bool hit;
public:
    SetDiff(GameSceneChanger* changer);
    void Initialize() override;
    //void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
    void handleMenuInput(int maxNum);
};