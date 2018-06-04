#pragma once
//シーン管理部クラス
#include "Scene.h"
#include <stack>

class SceneManeger
{
protected:
	static SceneManeger* instance;
	Scene* currentScene = nullptr;


private:

public:
	explicit SceneManeger() {}
	virtual ~SceneManeger() { }

	static void DestroyThis()
	{
		if (instance != nullptr)
		{
			delete instance;		//シーンのメモリを解放
		}

	}

	static SceneManeger* GetInstance()
	{
		if (!instance)
		{
			instance = new SceneManeger();		//インスタンスが空なら新しいシーンを登録
			atexit(DestroyThis);					//プログラムが終了するときに実行される
		}
		return instance;
	}

	//シーンの追加
	//引数は呼び出したいシーンのポインタ
	//メインループ前に呼び出すか、ChangeSceneで指定したシーンを追加する
	//シーンの初期化が正しく行われているならtrue
	bool InsertScene(Scene* s_)
	{
		if (s_ && !s_->Initialize())
		{
			return false;
		}
		currentScene = s_;
		return true;
	}

	//シーンの切り替え
	//引数にシーン名をnewで指定する
	//PullSceneとPushSceneが行われる
	bool ChangeScene(Scene* s_)
	{
		if (currentScene != nullptr) {
			currentScene->Finalize();
			delete currentScene;
			currentScene = nullptr;
		}
		return InsertScene(s_);
	}

	//現在映しているシーンを参照する
	//メインループに書くべき処理
	//主に更新処理、描画処理を参照する
	Scene* GetCurrentScene() const
	{
		return currentScene;
	}

};