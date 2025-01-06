#ifndef LOADSCENE_H
#define LOADSCENE_H

#include "BaseScene.h"
#include <vector>

class LoadScene : public BaseScene {
private:
    std::vector<int> resourceHandles;  // ���\�[�X�n���h�����X�g
    int progress;                      // �ǂݍ��ݐi��
    int totalResources;                // �����\�[�X��
    bool loadingComplete;              // �ǂݍ��݊����t���O
    int frameCount;                    // ���[�h��ʃA�j���[�V�����p�J�E���^

public:
    LoadScene(ISceneChanger* changer);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    bool IsLoadingComplete() const;    // �ǂݍ��݊�����Ԃ��擾
};

#endif // LOADSCENE_H
