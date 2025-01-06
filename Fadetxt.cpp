#include "Fadetxt.h"
#include <DxLib.h>
#include "Define.h"

// �R���X�g���N�^
FadeText::FadeText(const std::string& text, int areaWidth, int areaHeight, int color, int fadespeed, int fontIndex)
    : text(text), color(color), fadespeed(fadespeed), fontIndex(fontIndex),
    alpha(0), fadeDirection(1), showText(true) {
    // �t�H���g�n���h�����擾
    int fontHandle = fontHandle_a_anti[fontIndex];

    // �����̕��ƍ������擾
    textWidth = GetDrawStringWidthToHandle(text.c_str(), strlen(text.c_str()), fontHandle_a_anti[fontIndex]);
    textHeight = GetFontSizeToHandle(fontHandle);
    // ��ʂ̒����ʒu���v�Z
    fx = areaWidth - textWidth / 2;
    fy = areaHeight - textHeight;
}

// �e�L�X�g���X�V
void FadeText::update() {
    if (showText) {
        alpha += fadeDirection * fadespeed;
        if (alpha >= 255) {
            alpha = 255;
            fadeDirection = -1; // �t�F�[�h�A�E�g�ɐ؂�ւ�
        }
        else if (alpha <= 0) {
            alpha = 0;
            showText = false;   // �e�L�X�g�\���I��
        }
    }
}

// �e�L�X�g��`��
void FadeText::draw() const {
    if (showText) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        DrawStringToHandle(fx, fy, text.c_str(), color, fontHandle_a_anti[fontIndex]);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

// �e�L�X�g�\�����J�n
void FadeText::start() {
    showText = true;
    alpha = 0;
    fadeDirection = 1; // �t�F�[�h�C������J�n
}

// �e�L�X�g�\����Ԃ��擾
bool FadeText::isShowing() const {
    return showText;
}
