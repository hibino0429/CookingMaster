#include "Usingheaders.h"
#define PI 3.141592654

bool Result::Initialize()
{
	a = 0;
	flag = false;
	timeCnt = 0;
	foodNum = judgeScore();

	bghandle = LoadGraph("./Graph/result.png");
	sound.SetBGM("./Sound/grill.ogg");
	Rcarrot = LoadGraph("./Graph/Rcarrot.png");
	Rcabbage = LoadGraph("./Graph/Rcabbage.png");
	Rpotato = LoadGraph("./Graph/Rpotato.png");
	Rtomato = LoadGraph("./Graph/Rtomato.png");
	Rtomato2 = LoadGraph("./Graph/Rtomato2.png");
	Rbrory = LoadGraph("./Graph/Rbrory.png");
	Ronion = LoadGraph("./Graph/Ronion.png");

	LoadDivGraph("./Graph/effusion1_2.png", 3, 3, 1, 469,281, eff[0].pic);
	LoadDivGraph("./Graph/effusion2.png", 3, 3, 1, 190, 235, eff[1].pic);
	eff[0].init.initialize_E(236, 358, 300);
	eff[1].init.initialize_E(730, 380, 350);

	LoadDivGraph("./Graph/score.png", 3,1,3, 598, 203, score_pic);
	score_scale = 5.0f;


	pos_initilize();
	for (int i = 0; i < 2; i++)
	{
		eff[i].aniCnt = 0.0f;
		eff[i].flag = false;
	}

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

	for (int i = 0; i < foodNum; ++i)
	{
		TimeAni(food[i], i);	//一定時間がなったかチェック
		if (food[i].flag == true)
		{
			PutAni(food[i]);	//easingアニメーションで描く
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		AppearEffusion(eff[i]);
	}

	if (timeCnt >= (foodNum * 10) + 400) {
		if (Key(KEY_INPUT_Z) == 1)
		{
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
			SceneManeger::GetInstance()->ChangeScene(new Title);
			Score() = 0;
		}
	}

}

void Result::Draw()
{
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);		//ブレンドモードαを設定
	DrawGraph(0, 0, bghandle, true);

	for (int i = 0; i < foodNum; ++i)
	{
		DrawFood(food[i]);
	}
	
	DrawScore();
	
	for (int i = 0; i < 2; ++i)
	{
		DrawEffusion(eff[i]);
	}
}

void Result::Finalize()
{
	for (int i = 0; i < foodNum; i++)
	{
		DeleteGraph(food[i].pic);
	}
	InitGraph();
	InitSoundMem();
}

void Result::pos_initilize()
{
	//x, y, 到着座標(y)、画像の回転、画像の番号
	food[0].pos.SetPOS_R(438, 0, 118, 0.0, 0);
	food[1].pos.SetPOS_R(437, 0, 430, PI*1.2, 0);
	food[2].pos.SetPOS_R(400, 0, 200, PI/6,3);
	food[3].pos.SetPOS_R(600, 0, 300, PI/3,0);
	food[4].pos.SetPOS_R(580, 0, 230, PI*1.5, 2);
	food[5].pos.SetPOS_R(600, 0, 150, PI/2, 4);
	food[6].pos.SetPOS_R(320, 0, 220, 0.0, 1);
	food[7].pos.SetPOS_R(520, 0, 310, PI/4, 5);
	food[8].pos.SetPOS_R(550, 0, 360, PI*1.4 , 0);
	food[9].pos.SetPOS_R(337, 0, 305, PI*1.4, 6);
	food[10].pos.SetPOS_R(392, 0, 362, PI*1.6, 3);
	food[11].pos.SetPOS_R(607, 0, 267, PI*1.2, 5);
	food[12].pos.SetPOS_R(453, 0, 295, PI*1.5, 4);
	food[13].pos.SetPOS_R(495, 0, 225, PI*1.2, 0);
	food[14].pos.SetPOS_R(558, 0, 440, PI / 3, 2);
	food[15].pos.SetPOS_R(542, 0, 106, 0.0, 1);
	food[16].pos.SetPOS_R(314, 0, 200, PI /4*3, 0);
	food[17].pos.SetPOS_R(510, 0, 150, PI*1.8, 6);
	food[18].pos.SetPOS_R(612, 0, 342, PI / 4, 3);
	food[19].pos.SetPOS_R(431, 0, 454, 0.0, 4);
	food[20].pos.SetPOS_R(357, 0, 237, 0.0, 5);
	food[21].pos.SetPOS_R(583, 0, 407, PI*0.7, 0);
	food[22].pos.SetPOS_R(356, 0, 141, 0.0, 4);
	food[23].pos.SetPOS_R(525, 0, 422, 0.0, 3);
	food[24].pos.SetPOS_R(637, 0, 197, 0.0, 1);
	food[25].pos.SetPOS_R(646, 0, 269, 0.0, 4);
	food[26].pos.SetPOS_R(583, 0, 235, PI/6, 3);
	food[27].pos.SetPOS_R(425, 0, 323, PI *1.8, 0);
	food[28].pos.SetPOS_R(401, 0, 260, PI *1.8, 3);
	food[29].pos.SetPOS_R(618, 0, 382, 0.0, 1);
	food[30].pos.SetPOS_R(541, 0, 335, 0.0, 5);
	food[31].pos.SetPOS_R(446, 0, 335, PI *1.5, 2);
	food[32].pos.SetPOS_R(447, 0, 149, 0.0, 1);
}
int Result::judgeScore()
{
	if (Score() >= 100 && Score() < 200)		//スコアを受けて
	{
		eff_score = Good;
		return 21;								//表す画像の個数を返す
	}
	if (Score() >= 200)
	{
		eff_score = Great;
		return 33;
	}
	eff_score = Bad;
	return 10;
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

void Result::DrawFood(Food& f)
{
	if (f.flag == true)
		switch (f.pos.pic)
		{
		case 0:  DrawRotaGraphF(f.pos.x, f.pos.y, 1.0, f.pos.rotate, Rcabbage, true); break;
		case 1:  DrawRotaGraphF(f.pos.x, f.pos.y, 1.0, f.pos.rotate, Rpotato, true); break;
		case 2:  DrawRotaGraphF(f.pos.x, f.pos.y, 1.0, f.pos.rotate, Rtomato, true); break;
		case 3:  DrawRotaGraphF(f.pos.x, f.pos.y, 1.0, f.pos.rotate, Rbrory, true); break;
		case 4:  DrawRotaGraphF(f.pos.x, f.pos.y, 1.0, f.pos.rotate, Rcarrot, true); break;
		case 5:  DrawRotaGraphF(f.pos.x, f.pos.y, 1.0, f.pos.rotate, Ronion, true); break;
		case 6:  DrawRotaGraphF(f.pos.x, f.pos.y, 1.0, f.pos.rotate, Rtomato2, true); break;
		}
}
void Result::DrawScore()
{
	if (timeCnt >= (foodNum * 10) + 200) {
		if (score_scale >= 1.0f)
		{
			score_scale -= 0.1f;
		}
		switch (eff_score)
		{
		case 0:  DrawRotaGraph(480, 150, score_scale, 0.0, score_pic[eff_score], true); break; //Bad
		case 1:  DrawRotaGraph(480, 150, score_scale, 0.0, score_pic[eff_score], true); break; //Good
		case 2:  DrawRotaGraph(480, 150, score_scale, 0.0, score_pic[eff_score], true); break; //Great
		}

	}
}
void Result::AppearEffusion(Effusion& e)
{
	if (timeCnt >= (foodNum * 10) + e.init.appear) {
		e.flag = true;
	}
}
void Result::DrawEffusion(Effusion& e)
{
	if (e.flag == true) {
		if (e.aniCnt <= 1.0f) {
			e.aniCnt += 0.1f;
		}
		switch (eff_score)
		{
		case 0:  DrawRotaGraph(e.init.x, e.init.y, e.aniCnt, 0.0, e.pic[0], true); break; //Bad
		case 1:  DrawRotaGraph(e.init.x, e.init.y, e.aniCnt, 0.0, e.pic[1], true); break; //Good
		case 2:  DrawRotaGraph(e.init.x, e.init.y, e.aniCnt, 0.0, e.pic[2], true); break; //Great
		}
		
	}
}