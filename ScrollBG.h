#ifndef SCROLLBG_H
#define SCROLLBG_H

#include <DxLib.h>

class ScrollBackground {
private:
    int bgY;      // �w�i��Y���W
    int floorY;   // ����Y���W
    int wallY;    // �ǂ�Y���W

public:
    // �R���X�g���N�^
    ScrollBackground();

    // �w�i���X�N���[���`��
    void draw(int stnum) const;
    void update(int spd);
    // �w�i�����Z�b�g
    void reset();
};

#endif // SCROLLBG_H