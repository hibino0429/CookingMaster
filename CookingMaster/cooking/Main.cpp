#include "Usingheaders.h"
#include <memory>
#define _CRTDBG_MAP_ALLOC
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define malloc(X) _malloc_dbg(X, _CLIENT_BLOCK, __FILE__, __LINE__)xpand(p, s)         _expand_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
void message_box()
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("フルスクリーンモードで起動しますか？"),
		TEXT("スクリーン設定"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag == IDNO)
		ChangeWindowMode(TRUE);
}
extern const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//ログ消し
	SetOutApplicationLogValidFlag(FALSE);
	//ウインドウタイトルを変更
	SetMainWindowText("CookingMaster");
	//画面サイズ変更
	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	//ウィンドウモード変更と初期化と裏画面設定
	 message_box(), SetWindowIconID(222), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	
	auto manager = SceneManeger::GetInstance();

	//最初に映るシーン
#ifdef _DEBUG
	manager->InsertScene(new Result);
#else
	manager->InsertScene(new Title);
#endif 

	

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();
		manager->GetCurrentScene()->Update();
		manager->GetCurrentScene()->Draw();
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			manager->GetCurrentScene()->Finalize();
			break;
		}
	}
	manager->GetCurrentScene()->Finalize();
	delete manager->GetCurrentScene();
    DxLib_End();
    return 0;
}
//=================================================================================================================
//*************************************************************************************************************************************************=
//************バグメモ(リリース時のみ。ゲームプレイ自体には今のところ問題は感じられない（ちゃんと音も再生され、画像も表示されているように見える）)												  *=
//************スローされた時に中断しないように設定し、プレイは続行できるようにしている。が、シーン切り替え時に落ちるときがある																		      *=
//*************************************************************************************************************************************************=
//=================================================================================================================
//============================================以下がその内容のコピー=======================================================
//=================================================================================================================
//ハンドルされない例外が 0x77C3FD18 (ntdll.dll) で発生しました(cooking.exe 内): 0xC0000005:																										                             *=
//場所 0x00000026 の読み取り中にアクセス違反が発生しました。(シーン移行後のサウンドかプレイヤーの初期化処理内で発生する。※必ずではない)																 *=
//ハンドルされない例外が 0x77CDA849 (ntdll.dll) で発生しました(cooking.exe 内): 0xC0000374:																																	 *=
//ヒープは壊れています。 (パラメーター: 0x77D15910)。(切るアニメーション中かフェードイン時にエスケープで終了したときまれに発生)																			 *=
//0x77C3FD18 (ntdll.dll) で例外がスローされました (cooking.exe 内): 0xC0000005: 場所 0x90031801 の読み取り中にアクセス違反が発生しました																 *=
//SceneManager.h3の5,63行目でも発生																																																					 *=
//発生するときとしないときがある....																																																						 *=
//=================================================================================================================
//=================================================================================================================

//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
//★★★★★★★★★★★★★★修正★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
//0xC0000005エラーは、SE配列の要素をすべて初期化していなかったことが原因である可能性が高い->余計な要素を消した												  ★
//0xC0000374エラーは、エスケープで終了した場合に解放処理を呼んでいなかった																		                              ★
//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★