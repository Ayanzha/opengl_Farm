#include "InitFarm.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "Wall.h"
#include "Model_3DS.h"
#include "ModelDraw.h"
#include "texture.h"
bool	key[256];			// Array Used For The Keyboard Routine

Wall wall;
ModelDraw modelDraw;
float angle=0,move=-5;
InitFarm::InitFarm(void)
{
}


void InitFarm::sky(int sky_Texture,int sky_Textureup,int count )
{
	glPushMatrix();
	glPushMatrix();
	wall.buildWall(-25,-0.2,-25,150,150 ,0,sky_Texture,0);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(-100,0,0);
	wall.buildWall(-25,-0.2,-25,150,125.2 ,0,sky_Texture,0);
	glPopMatrix();
	glPushMatrix();
	glRotatef(180, 0.0f,  1.0f, 0.0f);
	glTranslatef(-100,0,-100);
	wall.buildWall(-25,-0.2,-25,150,125.2 ,0,sky_Texture,0);
	glPopMatrix(); 
	glPushMatrix();
	glTranslatef(90,0,0);
	glRotatef(-90, 0.0f,  0.0f,1.0f);
	wall.buildWallUp(-25,30,-25,150,0 ,150,sky_Textureup,0);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	wall.buildWallUp(-25,25,-25,150,0 ,150,sky_Textureup,0);
	glPopMatrix();
}
void InitFarm::erth(int Erth_Texture,int count)
{
	glPushMatrix();
	wall.buildWallUp(-25,-0.2,-25,150,0 ,150,Erth_Texture,count);
	glPopMatrix();
}
void InitFarm::street(int street_Texture,int road_Texture,int count)
{
	glPushMatrix();
	wall.buildWallUp(110, 0.01,-20,-100,0 ,40,street_Texture,count);
	glPopMatrix();
	glPushMatrix();
	wall.buildWallUp(140, 0.01,100,-200,0 ,20,road_Texture,0);
	glPopMatrix();

}
void InitFarm::drawModel(Model_3DS flower,Model_3DS tree,Model_3DS bird,
						 Model_3DS hous,Model_3DS Farm,Model_3DS pool,
						 Model_3DS grass,Model_3DS wall,Model_3DS carW,
						 Model_3DS chair,Model_3DS nissan,Model_3DS jeep,
						 Model_3DS carmove,Model_3DS door,Model_3DS wheel,
						 Model_3DS forklift){
	glPushMatrix();
	modelDraw.drawModelFlowers(flower);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4,0,0);
	modelDraw.drawModelFlowers(flower);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelSmallhous(hous);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelFarm(Farm);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelPool(pool);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelcarwood(carW);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelchair(chair);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelcarnissan(nissan);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelcarJeep(jeep);
	glPopMatrix();
	glPushMatrix();
	modelDraw.drawModelwheel(wheel);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, +1, 0);
	modelDraw.drawModelfork(forklift);
	glPopMatrix();
	movebirds( bird );
	movecars(carmove );
	allTrees(tree);
	allgrass(grass);
	allWall(wall);
	//allDoor(door);

}
void InitFarm::movebirds(Model_3DS model ){
	glPushMatrix();
	glRotated(angle, 0, +1, 0);
	angle += 1;
	modelDraw.drawModelbirds(model);
	glTranslatef(-1,0,0);
	modelDraw.drawModelbirds(model);
	glTranslatef(-1,0,1);
	modelDraw.drawModelbirds(model);
	glTranslatef(-1.4,0,1.4);
	modelDraw.drawModelbirds(model);
	glPopMatrix();
}
void InitFarm::allTrees(Model_3DS model2 ){
	//trees
	glPushMatrix();
	modelDraw.drawModelTrees(model2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-30, 0,0);
	modelDraw.drawModelTrees(model2);
	glPopMatrix();
	glPushMatrix();
	for (int i= 0; i <5; i++)
	{int  k=25;
	glTranslatef(0 ,0, k);
	modelDraw.drawModelTrees(model2);
	k+=12;
	}
	glPopMatrix();
	
}
void InitFarm::allgrass(Model_3DS model ){
	//grass
	glPushMatrix();
	for (int i= 0; i <5; i++)
	{int  k=-10;
	glTranslatef(0,0,k);
	modelDraw.drawModelgrass(model);
	k-=10;
	}
	glPopMatrix(); 

}
void InitFarm::allWall(Model_3DS model ){
	//walls
	glPushMatrix();
	modelDraw.drawModelWall(model);
	for (int i= 0; i < 6; i++)
	{ 
	glTranslatef(10,0,0);
	modelDraw.drawModelWall(model);
	}
	glTranslatef(12,0,0);
	for (int i= 0; i <5; i++)
	{int  k=+10;
	glTranslatef(k,0,0);
	modelDraw.drawModelWall(model);
	k+=10;
	}

	glPopMatrix(); 

}
void InitFarm::movecars(Model_3DS model ){
	glPushMatrix();
	glTranslatef(move, 0,0);
	move +=-0.8;
	model.pos.x =113 ;
	model.pos.y =0.5;
	model.pos.z =-130;
	model.scale =2; 
	glRotated(-90, 0, +1, 0);
	model.Draw();
	if(move<=-200){
	move =0;
	}
	glPopMatrix();
 
}
void InitFarm::allDoor(Model_3DS model ){
	//door
	glPushMatrix();
	modelDraw.drawModeldoor(model);
	int  k=-4.2;
	glTranslatef(k,0,0);
	modelDraw.drawModeldoor(model);
	glPopMatrix();
	

}
