#pragma once

#include "GameTask.h"
#include "GameSceneChanger.h"

//シーンの基底クラス。
class GameBaseScene : public GameTask {

protected:
    int gImageHandle;                //画像ハンドル格納用変数
    GameSceneChanger* gSceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス

public:
    GameBaseScene(GameSceneChanger* changer);
    virtual ~GameBaseScene() {}
    virtual void Initialize() override {}    //初期化処理をオーバーライド。
    virtual void Finalize() override;        //終了処理をオーバーライド。
    virtual void Update() override {}        //更新処理をオーバーライド。
    virtual void Draw() override;            //描画処理をオーバーライド。
};