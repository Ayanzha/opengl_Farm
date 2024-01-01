#include "Wall.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include "texture.h"


Wall::Wall()
{
}
void Wall :: buildWall(int x,int y,int z,int width,int high,int depth,int image,int count){
	//back
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(x, y, z);
	glTexCoord2d(1+count,0);
	glVertex3f(x+width, y, z);
	glTexCoord2d(1+count,1+count);
	glVertex3f(x+width, y+high, z);
	glTexCoord2d(0, 1+count);
	glVertex3f(x, y+high, z);
	
	
	glEnd();
	  
}

void Wall :: buildWallUp(int x,int y,int z,int width,int high,int depth,int image,int count){
	//up
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(x, y, z);
	glTexCoord2d(1+count,0);
	glVertex3f(x+width, y, z);
	glTexCoord2d(1+count,1+count);
	glVertex3f(x+width, y, z+depth);
	glTexCoord2d(0, 1+count);
	glVertex3f(x, y, z+depth);
	
	
	glEnd();
	  
}

 
 
Wall::~Wall(void)
{
}
