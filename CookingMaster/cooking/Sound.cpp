#include "Usingheaders.h"
 
bool Sound::Initialize()
{
	
	SE[appear]   = LoadSoundMem("./Sound/appear.ogg");
	SE[carrot]   = LoadSoundMem("./Sound/carrot.ogg");
	SE[onion]    = LoadSoundMem("./Sound/onion.ogg");
	SE[broccoli] = LoadSoundMem("./Sound/broccoli.ogg");
	SE[cabbage]  = LoadSoundMem("./Sound/cabbage.ogg");
	SE[tomato]   = LoadSoundMem("./Sound/tomato.ogg");
	SE[potato]   = LoadSoundMem("./Sound/potato.ogg");
	SE[mouse]    = LoadSoundMem("./Sound/cabbage.ogg");
	SE[grill]    = LoadSoundMem("./Sound/grill.ogg");
	SE[bell]     = LoadSoundMem("./Sound/EnterShop.ogg");
	SE[bell2]    = LoadSoundMem("./Sound/Thankyou.ogg");
	BGM = LoadSoundMem("./Sound/Let'sCooking.wav");


	flag = true;
	
	for (int i = 0; i < SENUM; ++i)
	{
		if (SE[i] == -1 || BGM == -1)
		{
			return false;
		}
	}
	return true;
}
//BGM処理は本当はこうするべきだった....↓マスターアップ時に修正する予定
void Sound::SetBGM(const TCHAR *FileName)
{
	BGM = LoadSoundMem(FileName);
	flag = true;
}
void Sound::InitBGM()
{
	DeleteSoundMem(BGM);
	flag = true;

}
int Sound::PlayBGM_BACK()
{
	if (flag == true)
	{
		ChangeVolumeSoundMem(255 * 90 / 100, BGM);
		PlaySoundMem(BGM, DX_PLAYTYPE_BACK);
		flag = false;
	}
	return BGM;
}
int Sound::PlayBGM_LOOP()
{
	if (flag == true)
	{
		ChangeVolumeSoundMem(255 * 90 / 100, BGM);
		PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
		flag = false;
	}
	return BGM;
}
void Sound::PlaySE(int type)
{
	switch (type)
	{
	
	case carrot:      PlaySoundMem(SE[carrot],		 DX_PLAYTYPE_BACK);	break;
	case onion:       PlaySoundMem(SE[onion],		 DX_PLAYTYPE_BACK);	break;
	case broccoli:    PlaySoundMem(SE[broccoli],	 DX_PLAYTYPE_BACK);	break;
	case cabbage:     PlaySoundMem(SE[cabbage],		 DX_PLAYTYPE_BACK);	break;
	case tomato:      PlaySoundMem(SE[tomato],		 DX_PLAYTYPE_BACK);	break;
	case potato:	  PlaySoundMem(SE[potato],		 DX_PLAYTYPE_BACK);	break;
	case mouse:       PlaySoundMem(SE[mouse],		 DX_PLAYTYPE_BACK);	break;
	case grill:		  PlaySoundMem(SE[grill],		 DX_PLAYTYPE_BACK);	break;
	case bell:		  PlaySoundMem(SE[bell],		 DX_PLAYTYPE_BACK);	break;
	case bell2:		  PlaySoundMem(SE[bell2],        DX_PLAYTYPE_BACK);	break;
	case appear:	  PlaySoundMem(SE[appear],		 DX_PLAYTYPE_BACK);	break;
					  
	}				  	  
}			

void Sound::Fin()	  
{					  
	for (int i = 0; i < SENUM; ++i)
	{
		DeleteSoundMem(SE[i]);
	}
	DeleteSoundMem(BGM);

}