#include "Usingheaders.h"
#define PI 3.141592654

bool Result::Initialize()
{
	a = 0;
	flag = false;
	timeCnt = 0;
	bghandle = LoadGraph("./Graph/result.png");
	sound.SetBGM("./Sound/grill.ogg");
	Rcarrot = LoadGraph("./Graph/Rcarrot.png");
	Rcabbage = LoadGraph("./Graph/Rcabbage.png");
	Rpotato = LoadGraph("./Graph/Rpotato.png");
	Rtomato = LoadGraph("./Graph/Rtomato.png");
	Rtomato2 = LoadGraph("./Graph/Rtomato2.png");
	Rbrory = LoadGraph("./Graph/Rbrory.png");
	Ronion = LoadGraph("./Graph/Ronion.png");

	pos_initilize();

	if (bghandle == -1)
	{
		return false;
	}
	return true;
}


void Result::Update()
{
	sound.PlayBGM_BACK();
	timeCnt++;

	if (a <= 255)
	{
		a += 3;
	}
	if (a >= 255)
	{
		
	}
	for (int i = 0; i < scoreAni(); ++i)
	{
		TimeAni(food[i], i);	//一定時間がなったかチェック
		if (food[i].flag == true)
		{
			PutAni(food[i]);	//easingアニメーションで描く
		}
	}

	if (Key(KEY_INPUT_Z) == 1)
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
		SceneManeger::GetInstance()->ChangeScene(new Title);
		Score() = 0;
	}
}

void Result::Draw()
{
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);		//ブレンドモードαを設定
	DrawGraph(0, 0, bghandle, true);

	for (int i = 0; i < scoreAni(); ++i)
	{
		if (food[i].flag == true)
			switch (food[i].pos.pic)
			{
			case 0:  DrawRotaGraphF(food[i].pos.x, food[i].pos.y, 1.0, food[i].pos.rotate, Rcabbage, true); break;
			case 1:  DrawRotaGraphF(food[i].pos.x, food[i].pos.y, 1.0, food[i].pos.rotate, Rpotato, true); break;
			case 2:  DrawRotaGraphF(food[i].pos.x, food[i].pos.y, 1.0, food[i].pos.rotate, Rtomato, true); break;
			case 3:  DrawRotaGraphF(food[i].pos.x, food[i].pos.y, 1.0, food[i].pos.rotate, Rbrory, true); break;
			case 4:  DrawRotaGraphF(food[i].pos.x, food[i].pos.y, 1.0, food[i].pos.rotate, Rcarrot, true); break;
			case 5:  DrawRotaGraphF(food[i].pos.x, food[i].pos.y, 1.0, food[i].pos.rotate, Ronion, true); break;
			case 6:  DrawRotaGraphF(food[i].pos.x, food[i].pos.y, 1.0, food[i].pos.rotate, Rtomato2, true); break;
			}
	}
}

void Result::Finalize()
{
	for (int i = 0; i < scoreAni(); i++)
	{
		DeleteGraph(food[i].pic);
	}
	InitGraph();
	InitSoundMem();
}

void Result::pos_initilize()
{
	//x, y, 到着座標(y)、画像の回転、画像の番号
	food[0].pos.SetPOS_R(438, -150, 118, 0.0, 0);
	food[1].pos.SetPOS_R(437, -150, 430, PI*1.2, 0);
	food[2].pos.SetPOS_R(400, -150, 200, PI/6,3);
	food[3].pos.SetPOS_R(600, -150, 300, PI/3,0);
	food[4].pos.SetPOS_R(580, -150, 230, PI*1.5, 2);
	food[5].pos.SetPOS_R(600, -150, 150, PI/2, 4);
	food[6].pos.SetPOS_R(320, -150, 220, 0.0, 1);
	food[7].pos.SetPOS_R(520, -150, 310, PI/4, 5);
	food[8].pos.SetPOS_R(550, -150, 360, PI*1.4 , 0);
	food[9].pos.SetPOS_R(337, -150, 305, PI*1.4, 6);
	food[10].pos.SetPOS_R(392, -150, 362, PI*1.6, 3);
	food[11].pos.SetPOS_R(607, -150, 267, PI*1.2, 5);
	food[12].pos.SetPOS_R(453, -150, 295, PI*1.5, 4);
	food[13].pos.SetPOS_R(495, -150, 225, PI*1.2, 0);
	food[14].pos.SetPOS_R(558, -150, 440, PI / 3, 2);
	food[15].pos.SetPOS_R(542, -150, 106, 0.0, 1);
	food[16].pos.SetPOS_R(314, -150, 200, PI /4*3, 0);
	food[17].pos.SetPOS_R(510, -150, 150, PI*1.8, 6);
	food[18].pos.SetPOS_R(612, -150, 342, PI / 4, 3);
	food[19].pos.SetPOS_R(431, -150, 454, 0.0, 4);
	food[20].pos.SetPOS_R(357, -150, 237, 0.0, 5);
	food[21].pos.SetPOS_R(583, -150, 407, PI*0.7, 0);
	food[22].pos.SetPOS_R(356, -150, 141, 0.0, 4);
	food[23].pos.SetPOS_R(525, -150, 422, 0.0, 3);
	food[24].pos.SetPOS_R(637, -150, 197, 0.0, 1);
	food[25].pos.SetPOS_R(646, -150, 269, 0.0, 4);
	food[26].pos.SetPOS_R(583, -150, 235, PI/6, 3);
	food[27].pos.SetPOS_R(425, -150, 323, PI *1.8, 0);
	food[28].pos.SetPOS_R(401, -150, 260, PI *1.8, 3);
	food[29].pos.SetPOS_R(618, -150, 382, 0.0, 1);
	food[30].pos.SetPOS_R(541, -150, 335, 0.0, 5);
	food[31].pos.SetPOS_R(446, -150, 335, PI *1.5, 2);
	food[32].pos.SetPOS_R(447, -150, 149, 0.0, 1);
}

void Result::PutAni(Food& f) 
{
	f.pos.y = f.anim.BounceOut(f.anim.Time(10), 0, f.pos.arrival - 0, 10.f);   //easingアニメーション
}

void Result::TimeAni(Food& f, int n)
{
	if (timeCnt % ((10*n)+100) == 0) //（タイムカウント％（フレーム数＊順番））＋ディレイ
	{
		f.flag = true;
	}
}

int Result::scoreAni()
{
	if (Score() >= 100 && Score() < 200)		//スコアを受けて
	{
		return 21;								//表す画像の個数を返す
	}
	if (Score() >= 200)
	{
		return 33;
	}
	return 10;
}
