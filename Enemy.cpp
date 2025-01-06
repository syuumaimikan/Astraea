#include "Enemy.h"
#include "Define.h"
#include "DxLib.h"
#include "Player.h"

#include <thread>
#include <chrono>
#include <cmath>

void Enemy::moveEnemy() {
    int currentTime = GetNowCount(); // ÉtÉåÅ[ÉÄÇ≤Ç∆ÇÃåªç›éûä‘ÇéÊìæ

    for (int i = 0; i < MAX_ENEMY; i++) {
        if (enemy[i].state == 0) continue;

        Playerwith(i);
        handleBullet(i);

        updateEnemyPosition(i);
        processEnemyPattern(i, currentTime);

        if (isOutOfBounds(enemy[i])) {
            enemy[i].state = 0;
        }
    }
}

void Enemy::Playerwith(int i) {
    if (player.timer == 0) {
        int dx = player.x - enemy[i].x;
        int dy = player.y - enemy[i].y;
        int range = player.range + enemy[i].range;
        if (dx * dx + dy * dy < range * range) {
            player.hp -= enemy[i].damage;
            player.timer = FPS * 2;
            player.automode = true;
            player.invincible = true;
            player.remain -= 1;
        }
    }
}

void Enemy::handleBullet(int i) {
    if (enemy[i].hp > 0 && !enemy[i].invincible) {
        for (int j = 0; j < MAX_BULLET; j++) {
            if (bullet[j].state == 0) continue;

            int dx = abs(static_cast<int>(enemy[i].x - bullet[j].x));
            int dy = abs(static_cast<int>(enemy[i].y - bullet[j].y));

            if (dx < enemy[i].wid / 2 && dy < enemy[i].hei / 2) {
                bullet[j].state = 0;
                enemy[i].hp -= bullet[j].damage;

                if (enemy[i].hp <= 0) {
                    enemy[i].state = 0;
                    updateScoreBasedOnPattern(enemy[i].pattern);
                }
            }
        }
    }
}

void Enemy::updateEnemyPosition(int i) {
    if (!enemy[i].slowMode) {
        enemy[i].x += enemy[i].vx;
        enemy[i].y += enemy[i].vy;
    }
}

void Enemy::processEnemyPattern(int i, int currentTime) {
    switch (enemy[i].pattern) {
    case ENE_IDLE:
        enemy[i].slowMode = 1;
        break;

    case ENE_BULLET:
        enemy[i].invincible = true;
        enemy[i].x += enemy[i].vx;
        enemy[i].y += enemy[i].vy;
        break;

    case ENE_ZAKO1:
        processZako1(i, currentTime);
        break;

    case ENE_ZAKO2:
    case ENE_ZAKO3:
    case ENE_ZAKO4:
        processZakoCommon(i);
        break;

    case ENE_MINIBOSS_1:
        processMiniBoss(i, currentTime);
        break;

    default:
        break;
    }
}

void Enemy::processZako1(int i, int currentTime) {
    if (enemy[i].y >= 300) {
        enemy[i].timer++;
        enemy[i].y = 300;
    }
    if (enemy[i].timer > 0) {
        if (enemy[i].shotCount < enemy[i].maxShots && enemy[i].nextShootTime <= currentTime) {
            float dx = player.x - enemy[i].x;
            float dy = player.y - enemy[i].y;
            enemy[i].angle = atan2f(dy, dx);

            spawnBullet(enemy[i].x, enemy[i].y, enemy[i].angle, 6, imgEnemy[1], 10, BULLET_NORM, 1, 1, 1, 1);
            enemy[i].shotCount++;
            enemy[i].nextShootTime = currentTime + enemy[i].shootInterval;
        }
    }
    if (enemy[i].timer >= FPS / 2) {
        enemy[i].vy = -3;
        enemy[i].vx = (enemy[i].x > static_cast<double>((GAME_AREA_X_MAX - GAME_AREA_X_MIN)) / 2) ? 6 : -6;
    }
}

void Enemy::processZakoCommon(int i) {
    if (enemy[i].y >= 300) {
        enemy[i].timer++;
        enemy[i].y = 300;
        if (enemy[i].timer == 1) {
            spawnBullet(enemy[i].x, enemy[i].y, 0, 2, imgEbullet[0], 10, BULLET_RADIAL, 6, 12, 18, 32);
        }
    }
    if (enemy[i].timer >= FPS / 2) {
        enemy[i].vy = -3;
        enemy[i].vx = (enemy[i].x > static_cast<double>((GAME_AREA_X_MAX - GAME_AREA_X_MIN)) / 2) ? 6 : -6;
    }
}

void Enemy::processMiniBoss(int i, int currentTime) {
    if (enemy[i].tmp == 0) {
        player.wait = true;
        boss.maxhp = enemy[i].hp;
        boss.phase = 1;
        enemy[i].tmp = 1;
        enemy[i].invincible = true;
    }
    if (enemy[i].invincible) {
        boss.hp += 5;
        if (boss.hp > boss.maxhp) {
            enemy[i].invincible = false;
        }
    }
    else {
        boss.hp = enemy[i].hp;
    }

    if (enemy[i].y >= 300) {
        enemy[i].y = 300;
        if (!enemy[i].invincible) {
            enemy[i].timer++;
        }
    }
    if (enemy[i].timer > 0 && enemy[i].nextShootTime <= currentTime) {
        if (boss.phase == 1) {
            spawnBullet(enemy[i].x, enemy[i].y, 0, 3, imgEbullet[0], 10, BULLET_RADIAL, 12, 24, 39, 64);
        }
        else if (boss.phase == 2) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    spawnBullet(GAME_AREA_X_MIN + 200 + 100 * i, GAME_AREA_Y_MIN + 200 + 100 * j, 0, 3, imgEbullet[0], 10, BULLET_RADIAL, 3, 7, 11, 23);
                }
            }
        }
        enemy[i].nextShootTime = currentTime + enemy[i].shootInterval;
    }
}

void Enemy::updateScoreBasedOnPattern(int pattern) {
    switch (pattern) {
    case ENE_BOSS:
        score += 20;
        break;
    case ENE_MINIBOSS_1:
        player.wait = false;
        score += 10;
        break;
    default:
        score += 5;
        break;
    }
}

bool Enemy::isOutOfBounds(const OBJECT& enemy) const {
    return (enemy.x < -200 || enemy.x > WIDTH + 200 || enemy.y < -200 || enemy.y > HEIGHT + 200);
}
void Enemy::spawnBullet(double x, double y, float angle, int speed, int image, int damage, int pattern, int amount1, int amount2, int amount3, int amount4) {
    // Determine bullet count based on difficulty
    int bulletCount = 0;
    switch (difficult) {
    case 0: bulletCount = amount1; break;
    case 1: bulletCount = amount2; break;
    case 2: bulletCount = amount3; break;
    case 3: bulletCount = amount4; break;
    default: bulletCount = 1; break; // Default to at least 1 bullet
    }

    if (bulletCount <= 0 || speed <= 0) return; // Invalid parameters, exit early

    switch (pattern) {
    case BULLET_NORM:
        setEnemy(x, y, cos(angle) * speed, sin(angle) * speed, angle, ENE_BULLET, image, 0, damage, 0, 0, 0, 0, 0);
        break;

    case BULLET_LASER:
        // Placeholder: Implement laser logic, e.g., continuous straight shot
        break;

    case BULLET_RADIAL:
        for (int i = 0; i < bulletCount; i++) {
            float angleOffset = (2 * PI / bulletCount) * i; // Radial angle offset
            float bulletAngle = fmod(angle + angleOffset, 2 * PI);
            double bulletVx = cos(bulletAngle) * speed;
            double bulletVy = sin(bulletAngle) * speed;

            setEnemy(x, y, bulletVx, bulletVy, bulletAngle, ENE_BULLET, image, 0, damage, 0, 0,0,0,0);
        }
        break;

    case BULLET_N_WAY_60: {
        float spread = DX_PI_F / 3.0f; // î≠éÀäpìxîÕàÕ (ó·: 60ìx)
        float startAngle = angle - spread / 2.0f; // N-WAY íeÇÃäJénäpìx (íÜêSÇäÓèÄ)

        for (int i = 0; i < bulletCount; i++) {
            // íeä€ÇÃî≠éÀäpìxÇåvéZ
            float bulletAngle = startAngle + (spread / max(1, bulletCount - 1)) * i;

            // íeä€ÇÃë¨ìxÉxÉNÉgÉãÇåvéZ
            float bulletVx = cosf(bulletAngle) * speed;
            float bulletVy = sinf(bulletAngle) * speed;

            // íeÇê∂ê¨
            setEnemy(x, y, bulletVx, bulletVy, bulletAngle, ENE_BULLET, image, 0, damage, 0, 0,0,0,0);
        }
    } break;
    case BULLET_N_WAY_90: {
        float spread = DX_PI_F / 2.0f; // î≠éÀäpìxîÕàÕ (ó·: 90ìx)
        float startAngle = angle - spread / 2.0f; // N-WAY íeÇÃäJénäpìx (íÜêSÇäÓèÄ)

        for (int i = 0; i < bulletCount; i++) {
            // íeä€ÇÃî≠éÀäpìxÇåvéZ
            float bulletAngle = startAngle + (spread / max(1, bulletCount - 1)) * i;

            // íeä€ÇÃë¨ìxÉxÉNÉgÉãÇåvéZ
            float bulletVx = cosf(bulletAngle) * speed;
            float bulletVy = sinf(bulletAngle) * speed;

            // íeÇê∂ê¨
            setEnemy(x, y, bulletVx, bulletVy, bulletAngle, ENE_BULLET, image, 0, damage, 0, 0, 0, 0, 0);
        }
    } break;
    default:
        // Unhandled pattern
        break;
    }
}
int Enemy::setEnemy(double x, double y, double vx, double vy, float angle, int pattern, int image, int hp, int damage, float shotinterval, int shotcount1, int shotcount2, int shotcount3, int shotcount4) {
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (enemy[i].state == 0) {
			enemy[i].invincible = false;
			enemy[i].state = 1;
			enemy[i].x = x;
			enemy[i].y = y;
			enemy[i].vx = vx;
			enemy[i].vy = vy;
			enemy[i].angle = angle;
			enemy[i].image = image;
			enemy[i].hp = hp;  // ÉXÉeÅ[ÉWàÀë∂ÉçÉWÉbÉNÇäOïîÇ≈åvéZ
			enemy[i].damage = damage;
			enemy[i].pattern = pattern;
            enemy[i].shootInterval = shotinterval*1000; // 1000É~Éäïb (1ïb) Ç≤Ç∆Ç…î≠éÀ
            enemy[i].nextShootTime = GetNowCount() + enemy[i].shootInterval;
			enemy[i].slowMode = 0;
            enemy[i].shotCount = 0;
            enemy[i].timer = 0;
            enemy[i].tmp = 0;
			GetGraphSize(enemy[i].image, &enemy[i].wid, &enemy[i].hei);
            enemy[i].range = (enemy[i].wid / static_cast<double>(2) + enemy[i].hei / static_cast<double>(2)) / 3.5;
            switch (difficult)
            {
            case 0:enemy[i].maxShots = shotcount1; break;
            case 1:enemy[i].maxShots = shotcount2; break;
            case 2:enemy[i].maxShots = shotcount3; break;
            case 3:enemy[i].maxShots = shotcount4; break;
            default:
                break;
            }
            return i;
		}
	}
	return -1;
}

void Enemy::drawEnemy() {
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (enemy[i].state == 0)continue;
		drawImage(enemy[i].x, enemy[i].y, enemy[i].image, true, enemy[i].angle);
        DrawCircle(enemy[i].x, enemy[i].y, enemy[i].range, white);
	}
}