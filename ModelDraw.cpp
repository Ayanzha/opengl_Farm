#include "ModelDraw.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include"Model_3DS.h"
#include "texture.h"


ModelDraw::ModelDraw(void)
{
}

void ModelDraw::drawModelFlowers(Model_3DS model ){
	 
	model.pos.x = 63 ;
	model.pos.y = 2;
	model.pos.z = 35;
	model.scale = 0.007;//ÕÃ„
	model.Draw();

}
void ModelDraw::drawModelTrees(Model_3DS model ){
	model.pos.x = 110 ;
	model.pos.y = 0.2;
	model.pos.z = 0;
	model.scale = 1.5;
	model.Draw();
}

void ModelDraw::drawModelbirds(Model_3DS model ){
	model.pos.x =-75 ;
	model.pos.y =10;
	model.pos.z =-25;
	model.scale =6;
	model.Draw();

}
void ModelDraw::drawModelSmallhous(Model_3DS model ){
	model.pos.x = -12 ;
	model.pos.y = 0.1;
	model.pos.z = 11;
	model.scale =0.9; 
	model.Draw();

}
void ModelDraw::drawModelPool(Model_3DS model ){
	model.pos.x =60 ; 
	model.pos.y = 0.8;
	model.pos.z = 60;
	model.scale =0.29; 
	model.Draw();
}
void ModelDraw::drawModelFarm(Model_3DS model ){
	model.pos.x =59 ;
	model.pos.y =5.5;
	model.pos.z =10;
	model.scale =0.007; 
	model.Draw();
}
void ModelDraw::drawModelgrass(Model_3DS model ){
	model.pos.x =-10 ;
	model.pos.y = 0.9;
	model.pos.z = 85;
	model.scale =0.6; 
	model.Draw();
}
void ModelDraw::drawModelWall(Model_3DS model ){
	model.pos.x =-8.5 ;
	model.pos.y =0.4;
	model.pos.z = 85;
	model.scale =0.7; 
	model.Draw();
}
void ModelDraw::drawModelchair(Model_3DS model ){
	model.pos.x =80 ;//0,50
	model.pos.y = 0.8;
	model.pos.z = 50;
	model.scale =0.006; 
	model.Draw();
}
void ModelDraw::drawModelcarwood(Model_3DS model ){
	model.pos.x = -10 ;
	model.pos.y = 0.3;
	model.pos.z = -5;
	model.scale =0.4;//0.005
	model.Draw();
}
void ModelDraw::drawModelcarnissan(Model_3DS model ){
	model.pos.x = 105 ;
	model.pos.y = 0.4;
	model.pos.z = -5;
	model.scale =0.09;//0.005
	model.Draw();
}
void ModelDraw::drawModelcarJeep(Model_3DS model ){
	model.pos.x = 92 ;
	model.pos.y =3.5;
	model.pos.z = -5;
	model.scale =0.13; 
	model.Draw();
}
void ModelDraw::drawModeldoor(Model_3DS model ){
	model.pos.x = 64.2 ;
	model.pos.y =0.9;
	model.pos.z = 84;
	model.scale =1.2; 
	model.Draw();
}
void ModelDraw::drawModelwheel(Model_3DS model ){
	model.pos.x = -10 ;
	model.pos.y =0.6;
	model.pos.z = 25;
	model.scale =0.1; 
	model.Draw();
}
void ModelDraw::drawModelfork(Model_3DS model ){
	model.pos.x =10 ;
	model.pos.y =0.6;
	model.pos.z = 8;
	model.scale =0.015; 
	model.Draw();
}
ModelDraw::~ModelDraw(void)
{
}
 
