#include "Player.h"
#include "Define.h"

void Player::move() {
    static int oldSpcKey = 0;
    static int countSpcKey = 0;

    // 斜め移動用の速度調整係数
    const float DIAGONAL_ADJUST = 1.414f;

    int vx = 0, vy = 0; // プレイヤーの速度
    if (player.invincible)add = -12;
    if (player.automode) {
        alpha += add;
        if (alpha <= 0) {
            // プレイヤーを画面中央下にリスポーン
            player.x = (GAME_AREA_X_MIN + GAME_AREA_X_MAX) / 2;
            player.y = GAME_AREA_Y_MAX;
            player.invincible = false;
            add = 0;
            alpha = 255;
            if (player.remain <= 0)over = true;
        }
        if (alpha == 255) {
            player.y -= 2;
            if (player.y <= GAME_AREA_Y_MAX - 100) {
                player.y = GAME_AREA_Y_MAX - 100;
                player.automode = false;
            }
        }
    }
    else {
        // 移動キー入力処理
        if (CheckHitKey(KEY_INPUT_UP)) vy -= player.vy;
        if (CheckHitKey(KEY_INPUT_DOWN)) vy += player.vy;
        if (CheckHitKey(KEY_INPUT_LEFT)) vx -= player.vx;
        if (CheckHitKey(KEY_INPUT_RIGHT)) vx += player.vx;

        // 斜め移動時の速度調整
        if (vx != 0 && vy != 0) {
            vx /= DIAGONAL_ADJUST;
            vy /= DIAGONAL_ADJUST;
        }

        // スロー移動処理
        if (CheckHitKey(KEY_INPUT_LSHIFT)) {
            player.slowMode = 1;
            vx /= 2;
            vy /= 2;
        }
        else {
            player.slowMode = 0;
        }
    }

    // プレイヤー位置更新
    player.x += vx;
    player.y += vy;

    // 弾発射処理
    if (CheckHitKey(KEY_INPUT_X)) {
        PlaySoundMem(shootse, DX_PLAYTYPE_BACK);
        if (oldSpcKey == 0 || countSpcKey % 2 == 0) {
            setBullet();
        }
        countSpcKey++;
    }
    else {
        countSpcKey = 0;
    }
    oldSpcKey = CheckHitKey(KEY_INPUT_X);

    // プレイヤー位置の制限
    if (player.x < GAME_AREA_X_MIN + 30) player.x = GAME_AREA_X_MIN + 30;
    if (player.x > GAME_AREA_X_MAX - 30) player.x = GAME_AREA_X_MAX - 30;
    if (player.y < GAME_AREA_Y_MIN + 30) player.y = GAME_AREA_Y_MIN + 30;
    if (player.y > GAME_AREA_Y_MAX - 38) player.y = GAME_AREA_Y_MAX - 38;

    // 無敵時間の減少
    if (player.timer > 0 && !player.automode) {
        player.timer--;
    }
}

void Player::drawpl() const {
    if (player.remain > 0) {
        if (player.automode) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawImage(player.x, player.y, imgPL, false, 0);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
        else if (player.timer % 4 < 2) {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            drawImage(player.x, player.y, imgPL, false, 0);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }

        if (player.slowMode && !player.automode) {
            DrawCircle(player.x, player.y, player.range, white, 1);
        }
    }
}

void Player::moveBullet() {
    for (int i = 0; i < MAX_BULLET; i++) {
        if (bullet[i].state == 0) continue;

        bullet[i].x += bullet[i].vx;
        bullet[i].y += bullet[i].vy;

        // 画面外の弾の処理
        if (bullet[i].y < -200) {
            bullet[i].state = 0;
        }
    }
}

void Player::DrawBullet() {
    for (int i = 0; i < MAX_BULLET; i++) {
        if (bullet[i].state == 0) continue;

        drawImage(bullet[i].x, bullet[i].y, imgBL, false, 0);
        DrawCircle(bullet[i].x, bullet[i].y, bullet[i].range, white);
    }
}

void Player::setBullet() {
    for (int i = 0; i < MAX_BULLET; i++) {
        if (bullet[i].state == 0) {
            bullet[i].x = player.x;
            bullet[i].y = player.y - 20;
            bullet[i].vx = 0;
            bullet[i].vy = -40;
            bullet[i].state = 1;
            bullet[i].damage = 1;

            // 弾の当たり判定範囲の計算
            GetGraphSize(bullet[i].image, &bullet[i].wid, &bullet[i].hei);
            bullet[i].range = (bullet[i].wid / 2 + bullet[i].hei / 2) / 2;
            break;
        }
    }
}
