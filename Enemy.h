#include "Define.h"
#pragma once
#ifndef ENEMY
#define ENEMY

class Enemy {
public:
	void moveEnemy();
	void processZakoCommon(int i);
	void processMiniBoss(int i, int currentTime);
	void updateScoreBasedOnPattern(int pattern);
	bool isOutOfBounds(const OBJECT& enemy) const;
	void spawnBullet(double x, double y, float angle, int speed, int image, int damage, int pattern, int amount1, int amount2, int amount3, int amount4);
	int setEnemy(double x, double y, double vx, double vy, float angle, int pattern, int image, int hp, int damage, float shotinterval, int shotcount1, int shotcount2, int shotcount3, int shotcount4);
	void drawEnemy();
	void Playerwith(int i);
	void handleBullet(int i);
	void updateEnemyPosition(int i);
	void processEnemyPattern(int i, int currentTime);
	void processZako1(int i, int currentTime);
};

#endif