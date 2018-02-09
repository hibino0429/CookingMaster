#pragma once
#include "Sound.h"
class Title : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;

	int a;		//透過率
	bool startFlag;	//フェードアウトフラグ(開始)
	bool endFlag;
	Sound sound;
	struct POS
	{
		void SetPOS(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
		float x, y;
	};
	enum SELECT
	{
		Start,
		End
	};
	struct TitleObj
	{
		POS pos;
		SELECT select;
		int handle;
		float angle;
	};
	TitleObj logo;
	TitleObj back;
	TitleObj cursor;
	TitleObj s_button;
	TitleObj e_button;

	float speed;
	float cycle;
	float shake;
};

