#pragma once
#include "Wall.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include "texture.h"
class Wall
{
public:
	Wall();
	void  buildWall(int x,int y,int z,int width,int high,int depth,int image,int count);
	void  buildWallUp(int x,int y,int z,int width,int high,int depth,int image,int count);


	~Wall(void);

};

