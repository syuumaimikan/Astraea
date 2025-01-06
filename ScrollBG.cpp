#include "ScrollBG.h"
#include "Define.h"

// �R���X�g���N�^
ScrollBackground::ScrollBackground()
    : bgY(0), floorY(0), wallY(0) {}

// �w�i�����Z�b�g
void ScrollBackground::reset() {
    bgY = 0;
    floorY = 0;
    wallY = 0;
}

// �w�i���X�V
void ScrollBackground::update(int spd) {
    // �w�i�̃X�N���[���X�V
    bgY = (bgY + spd) % GAME_AREA_Y_MAX;

    // ���̃X�N���[���X�V
    floorY = (floorY + spd * 2) % 120;

    // �ǂ̃X�N���[���X�V
    wallY = (wallY + spd * 4) % 240;
}

// �w�i��`��
void ScrollBackground::draw(int stnum) const {
    // �w�i�`��i�Q�[���G���A���w�i�̂݃X�N���[���j
    DrawGraph(GAME_AREA_X_MIN, GAME_AREA_Y_MIN + bgY - GAME_AREA_Y_MAX, backgrounds[stnum], FALSE);
    DrawGraph(GAME_AREA_X_MIN, GAME_AREA_Y_MIN + bgY, backgrounds[stnum], FALSE);

    // ���̕`��
    for (int i = -1; i < 6; i++) {
        DrawGraph(GAME_AREA_X_MIN + 210, GAME_AREA_Y_MIN + floorY + i * 120, backgrounds[stnum + 1], TRUE);
    }

    // �ǂ̕`��
    DrawGraph(GAME_AREA_Y_MIN, GAME_AREA_Y_MIN + wallY - 240, backgrounds[stnum + 2], TRUE);
    DrawGraph(GAME_AREA_X_MAX - 300, GAME_AREA_Y_MIN + wallY - 240, backgrounds[stnum + 3], TRUE);
}
