#ifndef LOADSCENE_H
#define LOADSCENE_H

#include "BaseScene.h"
#include <vector>

class LoadScene : public BaseScene {
private:
    std::vector<int> resourceHandles;  // リソースハンドルリスト
    int progress;                      // 読み込み進捗
    int totalResources;                // 総リソース数
    bool loadingComplete;              // 読み込み完了フラグ
    int frameCount;                    // ロード画面アニメーション用カウンタ

public:
    LoadScene(ISceneChanger* changer);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    bool IsLoadingComplete() const;    // 読み込み完了状態を取得
};

#endif // LOADSCENE_H
