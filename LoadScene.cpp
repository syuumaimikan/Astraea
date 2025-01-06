#include "LoadScene.h"
#include "DxLib.h"
#include "Define.h"

LoadScene::LoadScene(ISceneChanger* changer)
    : BaseScene(changer), progress(0), totalResources(0), loadingComplete(false), frameCount(0) {
}

void LoadScene::Initialize() {
    // �񓯊��ǂݍ��݂�L����
    SetUseASyncLoadFlag(TRUE);

    // �ǂݍ��ރ��\�[�X���w��
    resourceHandles.clear();
    imgTitle = LoadGraph("images/title.png");    //�摜�̃��[�h
    resourceHandles.push_back(imgTitle);
    imgMenu = LoadGraph("images/menu.png");    //�摜�̃��[�h
    resourceHandles.push_back(imgMenu);
    selectse = LoadSoundMem("sounds/select.mp3");
    resourceHandles.push_back(selectse);
    okse = LoadSoundMem("sounds/ok.mp3");
    resourceHandles.push_back(okse);

    imgEbullet[0] = LoadGraph("images/ebullet1.png");

    for (int i = 0; i < fontCount; i++) {
        fontSizes[i] = i;
        fontHandle_a_anti[i] = CreateFontToHandle(tempFontPath1, fontSizes[i], 3, DX_FONTTYPE_ANTIALIASING);
        resourceHandles.push_back(fontHandle_a_anti[i]);

        fontHandle_a_anti_edge[i] = CreateFontToHandle(tempFontPath1, fontSizes[i], 3, DX_FONTTYPE_ANTIALIASING_EDGE);
        resourceHandles.push_back(fontHandle_a_anti_edge[i]);

        fontHandle_b_anti[i] = CreateFontToHandle(tempFontPath2, fontSizes[i], 3, DX_FONTTYPE_ANTIALIASING);
        resourceHandles.push_back(fontHandle_b_anti[i]);

        fontHandle_b_anti_edge[i] = CreateFontToHandle(tempFontPath2, fontSizes[i], 3, DX_FONTTYPE_ANTIALIASING_EDGE);
        resourceHandles.push_back(fontHandle_b_anti_edge[i]);
    }

    imgPL = LoadGraph("images/player.png");
    resourceHandles.push_back(imgPL);
    imgBL = LoadGraph("images/bullet.png");
    resourceHandles.push_back(imgBL);

    shootse = LoadSoundMem("sounds/shoot.wav");
    resourceHandles.push_back(shootse);

    for (int i = 0; i < BACKGROUNDIMG; i++) {
        std::string imgFilename = "images/image" + std::to_string(i) + ".png";
        backgrounds[i] = LoadGraph(imgFilename.c_str());
        resourceHandles.push_back(backgrounds[i]);
    }
    for (int i = 0; i < IMG_ENEMY_MAX; i++) {
        std::string EimgFilename = "images/Eimage" + std::to_string(i) + ".png";
        imgEnemy[i] = LoadGraph(EimgFilename.c_str());
        resourceHandles.push_back(imgEnemy[i]);
    }

    totalResources = static_cast<int>(resourceHandles.size());
    loadingComplete = false;
    frameCount = 0;
}

void LoadScene::Update() {
    frameCount++;

    // �񓯊��ǂݍ��݂̐i�����m�F
    progress = 0;
    for (int handle : resourceHandles) {
        if (CheckHandleASyncLoad(handle) == FALSE) {  // �ǂݍ��݊����ς�
            progress++;
        }
    }

    // �S���\�[�X���ǂݍ��݊����������m�F
    if (progress == totalResources) {
        loadingComplete = true;
        SetUseASyncLoadFlag(FALSE);  // �񓯊��ǂݍ��݂𖳌���
        mSceneChanger->ChangeScene(eScene_Title);  // ���̃V�[����
    }
}

void LoadScene::Draw() {
    // �w�i�̕`��


    // ���[�f�B���O�o�[�̕`��
    int barWidth = 600; // ���[�f�B���O�o�[�̕�
    int barHeight = 30; // ���[�f�B���O�o�[�̍���
    int barX = (WIDTH - barWidth) / 2;
    int barY = (HEIGHT - barHeight) / 2;

    // �g��
    DrawBox(barX, barY, barX + barWidth, barY + barHeight, GetColor(255, 255, 255), FALSE);

    // �ǂݍ��ݗ��ɉ������i���o�[
    int filledWidth = static_cast<int>((static_cast<float>(progress) / totalResources) * barWidth);
    DrawBox(barX, barY, barX + filledWidth, barY + barHeight, GetColor(94, 3, 3), TRUE);

    // ���[�f�B���O�e�L�X�g�̕`��
    DrawFormatString(barX, barY - 50, GetColor(255, 255, 255), "Loading... %d%%", (progress * 100) / totalResources);
}

bool LoadScene::IsLoadingComplete() const {
    return loadingComplete;
}
