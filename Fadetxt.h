#ifndef FADETEXT_H
#define FADETEXT_H

#include <string>

class FadeText {
private:
    std::string text;     // �\������e�L�X�g
    int textWidth, textHeight;
    int fx, fy;             // �e�L�X�g�̕`��ʒu
    int color;            // �e�L�X�g�̐F
    int fadespeed;        // �t�F�[�h���x
    int fontIndex;        // �t�H���g�C���f�b�N�X
    int alpha;            // �A���t�@�l
    int fadeDirection;    // �t�F�[�h���� (1: �t�F�[�h�C��, -1: �t�F�[�h�A�E�g)
    bool showText;        // �e�L�X�g��\�����邩�ǂ���

public:
    // �R���X�g���N�^
    FadeText(const std::string& text, int areaWidth, int areaHeight, int color, int fadespeed, int fontIndex);

    // �e�L�X�g���X�V
    void update();

    // �e�L�X�g��`��
    void draw() const;

    // �e�L�X�g�\�����J�n
    void start();

    // �e�L�X�g�\����Ԃ��擾
    bool isShowing() const;
};

#endif // FADETEXT_H