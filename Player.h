#pragma once
#ifndef PLAYER
#define PLAYER

extern struct OBJECT player;

class Player {
private:
	int alpha=255, add = -12;
public:
	void DrawBullet();
	void moveBullet(void);
	void move();
	void drawpl() const;
	void setBullet();
};

#endif