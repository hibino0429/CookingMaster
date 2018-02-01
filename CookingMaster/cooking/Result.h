#pragma once
#include "easing.hpp"
class Result : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;

	struct POS_R
	{
		void SetPOS_R(float x, float y, float arrival, double rotate, int pic)
		{
			this->x = x;
			this->y = y;
			this->arrival = arrival;
			this->rotate = rotate;
			this->pic = pic;
		}
		float x, y, arrival; double rotate; int pic;
	};
	struct INIT_E
	{
		void initialize_E(int x, int y, int appear)
		{
			this->x = x;
			this->y = y;
			this->appear = appear;
		}
		int x, y, appear;
	};

	int a;
	Sound sound;


	int timeCnt;
	int foodNum;
	enum Eff_Score
	{
		Bad, Good, Great,
	};
	Eff_Score eff_score;

	struct Food
	{
		int pic;
		Easing anim;
		bool flag;
		POS_R pos;
	};
	int Rcabbage, Rpotato, Rtomato, Rbrory, Rcarrot, Ronion, Rtomato2;	//‰æ‘œ


	struct Effusion
	{
		int bg;
		bool flag;
		float aniCnt;
		INIT_E init;
		int pic[3];
	};

	Food food[33];
	Effusion eff[2];

	int score_pic[3];
	float score_scale;


	void pos_initilize();
	void PutAni(Food& f);
	void TimeAni(Food& f, int n);
	int judgeScore();

	void DrawFood(Food& f);
	void DrawScore();
	void AppearEffusion(Effusion& e);
	void DrawEffusion(Effusion& e);


private:
	int bghandle;
	bool flag;
};