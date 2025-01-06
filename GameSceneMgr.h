#pragma once

#include "GameSceneChanger.h"
#include "GameBaseScene.h"

class GameSceneMgr : public GameSceneChanger, GameTask {

private:
    GameBaseScene* mScene;    //シーン管理変数
    gScene mNextScene;    //次のシーン管理変数
public:
    GameSceneMgr();
    void Initialize() override;//初期化
    void Finalize() override;//終了処理
    void Update() override;//更新
    void Draw() override;//描画

    // 引数 nextScene にシーンを変更する
    void GChangeScene(gScene NextScene) override;

};