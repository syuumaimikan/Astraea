#pragma once
#include "BaseScene.h"

class MusicRoom : public BaseScene {
public:
    MusicRoom(ISceneChanger* changer);
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    //void Finalize() override ;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B

};