#include "GameBaseScene.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"

Player ply;
Enemy enm;

GameBaseScene::GameBaseScene(GameSceneChanger* changer) :
    gImageHandle(0) {
    gSceneChanger = changer;
}

void GameBaseScene::Finalize() {
    DeleteGraph(gImageHandle);
}

void GameBaseScene::Draw() {
    ply.DrawBullet();
    ply.drawpl();
    enm.drawEnemy();
}