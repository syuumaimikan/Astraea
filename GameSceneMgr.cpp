#include "DxLib.h"
#include "GameSceneMgr.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "SetDiff.h"
#include "Define.h"

GameSceneMgr::GameSceneMgr() :
    mNextScene(gScene_None) //次のシーン管理変数
{
    mScene = (GameBaseScene*) new SetDiff(this);
}

//初期化
void GameSceneMgr::Initialize() {
    mScene->Initialize();
}

//終了処理
void GameSceneMgr::Finalize() {
    mScene->Finalize();
}

//更新
void GameSceneMgr::Update() {
    if (mNextScene != gScene_None) {    //次のシーンがセットされていたら
        mScene->Finalize();//現在のシーンの終了処理を実行
        delete mScene;
        switch (mNextScene) {       //シーンによって処理を分岐
        case gScene_Set:
            mScene = (GameBaseScene*) new SetDiff(this);
            break;//以下略
        case gScene_Stage1:      
            mScene = (GameBaseScene*) new Stage1(this); 
            break;//以下略
        case gScene_Stage2:
            mScene = (GameBaseScene*) new Stage2(this);
            break;
        case gScene_Stage3:
            mScene = (GameBaseScene*) new Stage3(this);
            break;
        }
        mNextScene = gScene_None;    //次のシーン情報をクリア
        mScene->Initialize();    //シーンを初期化
    }
    if (!over)mScene->Update(); //シーンの更新
}

//描画
void GameSceneMgr::Draw() {
    mScene->Draw(); //シーンの描画
}

// 引数 nextScene にシーンを変更する
void GameSceneMgr::GChangeScene(gScene NextScene) {
    mNextScene = NextScene;    //次のシーンをセットする
}