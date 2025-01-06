#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"

// �Q�[����ʃN���X
class Game : public BaseScene {
public:
    Game(ISceneChanger* changer);    // �R���X�g���N�^
    void Initialize() override;     // �������������I�[�o�[���C�h
    void Update() override;         // �X�V�������I�[�o�[���C�h
    void Draw() override;           // �`�揈�����I�[�o�[���C�h
    void DrawBoard();
};
