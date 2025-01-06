#include "DxLib.h"
#include "SceneMgr.h"
#include "Define.h"
#include "Key.h"

void Finalize();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    SetOutApplicationLogValidFlag(FALSE);
    SetWindowText("Starry Adventure");
    ChangeWindowMode(FALSE);
    DxLib_Init(); 
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(WIDTH, HEIGHT, 32);
    SetBackgroundColor(0, 0, 0);
    SetUseCharCodeFormat(DX_CHARCODEFORMAT_SHIFTJIS);

    SceneMgr sceneMgr;
    sceneMgr.Initialize();
    init(fsin, fcos);

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {//画面更新 & メッセージ処理 & 画面消去
        if (endtrig) break;
        sceneMgr.Update();  //更新
        sceneMgr.Draw();    //描画
    }
    Finalize();
    sceneMgr.Finalize();

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}

void Finalize() {
    DeleteGraph(imgBL);
    DeleteGraph(imgMenu);
    DeleteGraph(imgPL);

    DeleteSoundMem(shootse);
    DeleteSoundMem(selectse);
    DeleteSoundMem(okse);

    for (int image : backgrounds) {
        DeleteGraph(image);
    }
    for (int image : imgEnemy) {
        DeleteGraph(image);
    }
    for (int i = 0; i < fontCount; i++) {
        DeleteFontToHandle(fontHandle_a_anti[i]);
        DeleteFontToHandle(fontHandle_a_anti_edge[i]);
        DeleteFontToHandle(fontHandle_b_anti[i]);
        DeleteFontToHandle(fontHandle_b_anti_edge[i]);
    }
}