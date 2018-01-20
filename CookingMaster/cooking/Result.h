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
	int a;
	Sound sound;



	int timeCnt;

	struct Food
	{
		int pic;
		Easing anim;
		bool flag;
		POS_R pos;
	};
	int Rcabbage, Rpotato, Rtomato, Rbrory, Rcarrot, Ronion, Rtomato2;

	Food food[33];

	void pos_initilize();
	void PutAni(Food& f);
	void TimeAni(Food& f, int n);
	int scoreAni();

private:
	int bghandle;

	bool flag;
};