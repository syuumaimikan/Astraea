#pragma once

typedef enum {
    eScene_Load,
    eScene_Title,
    eScene_Menu,    //メニュー画面
    eScene_Game,    //ゲーム画面
    eScene_Config,  //設定画面
    eScene_Credits,
    eScene_Music,
    eScene_History,
    eScene_None,    //無し
} eScene;

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
    virtual ~ISceneChanger() = 0;
    virtual void ChangeScene(eScene NextScene) = 0;//指定シーンに変更する
};