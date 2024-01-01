#pragma once
#include "Model_3DS.h"

class InitFarm
{
public:
	InitFarm(void);
	void bullding();
	void sky(int sky_Texture,int sky_Textureup,int count);
	void erth(int erth_Texture,int count);
	void street(int street_Texture,int road_Texture,int count);
	void movebirds(Model_3DS model );
	void movecars(Model_3DS model );
	void drawModel(Model_3DS flower,Model_3DS tree,Model_3DS bird,
					Model_3DS hous,Model_3DS Farm,Model_3DS pool,
					Model_3DS grass,Model_3DS wall,Model_3DS carW,
					Model_3DS chair,Model_3DS nissan,Model_3DS jeep,
					Model_3DS carmove,Model_3DS door,Model_3DS wheel,
					Model_3DS forklift);
	void allTrees(Model_3DS model);
	void allgrass(Model_3DS model);
	void allWall(Model_3DS model);
	void allDoor(Model_3DS model);




};

