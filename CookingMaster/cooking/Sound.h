#pragma once
constexpr int SENUM = 11;
enum TYPE
{

	appear,			//音符出現音0
	carrot,			//ニンジン1
	onion,			//タマネギ2
	broccoli,		//ブロッコリー3
	cabbage,		//キャベツ4
	tomato,			//トマト5
	potato,			//ジャガイモ6
	mouse,			//ネズミ7
	grill,			//焼く8
	bell,			//入店音（ベル）9
	bell2,			//退勤音10

};


class Sound 
{
private:

	
	bool   flag;

public:

	TYPE se_type;
	int  SE[SENUM];
	int  BGM;
	bool Initialize();
	void SetBGM(const TCHAR *FileName);	//BGMとして使いたいファイルのパスを指定
	int  PlayBGM_BACK();				//BGMをバックグラウンド再生（ループなし）
	int  PlayBGM_LOOP();				//BGMをループ再生
	void InitBGM();						//現在格納されているBGMデータを解放し、再生フラグの再セット
	void PlaySE(int);					//enum型でIDを指定
	void Fin();							//全データ開放

};