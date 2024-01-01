/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "camera.h"
#include "texture.h"
#include"Model_3DS.h"
#include "InitFarm.h"
#include "ModelDraw.h"
//#include <gl\glaux.h>		// Header File For The Glaux Library
int main() { return 0; }
using namespace std;
HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default
Camera cam;
InitFarm farm;
//ModelDraw modelDraw;

Model_3DS  Flowers,Tree,Farm,birds,Car,Smallhous,Wall,grass
	,Pool,chair,nissan,jeep,carmove,door,WheelBarrow,forklift;
int sky_Texture,sky_Textureup,Erth_Texture,street_Textureup,road_Texture;
bool start=false;
void translate_cam() {
	if (!start) {
		cam.Position.x = 63;
		cam.Position.y = 3;
		cam.Position.z = 125;
		start = true;
	}

	if (keys['W'])//front
	{
		cam.MoveForward(0.5);


	}
	if (keys['S'])//back
	{
		cam.MoveForward(-0.5);


	}
	if (keys[VK_UP])//up
	{
		cam.RotateX(+0.3);

	}
	if (keys[VK_DOWN])//down
	{
		cam.RotateX(-0.3);
	}
	if (keys['D'])//right
	{
		cam.RotateY(-4);

	}
	if (keys['A'])//left
	{
		cam.RotateY(4);

	}
	if (keys['E'])//up
	{
		cam.MoveUpward(0.5);
	}
	if (keys['Q'])//down
	{
		cam.MoveUpward(-0.5);
	}



	cam.Render();
}


LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
	{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_TEXTURE_2D);
	Flowers = Model_3DS();
	Tree= Model_3DS();
	Car= Model_3DS();
	Wall= Model_3DS();
	Farm= Model_3DS();
	grass= Model_3DS();
	Pool= Model_3DS();
	chair= Model_3DS();
	door= Model_3DS();
	WheelBarrow= Model_3DS();
	Smallhous= Model_3DS(); 
	birds= Model_3DS(); 
	jeep= Model_3DS(); 
	carmove= Model_3DS(); 
	forklift= Model_3DS(); 
	nissan= Model_3DS();
	nissan.Load("Models/nissan.3DS");
	forklift.Load("Models/lawnmower1-2.3DS");
	carmove.Load("Models/Car1.3ds");//forklift.3ds
	WheelBarrow.Load("Models/Wheel Barrow.3DS");//Wheel Barrow.3DS
	jeep.Load("Models/Fiat_Punto.3ds");//Fiat_Punto.3ds
	Tree.Load("Models/Tree1.3ds");
	door.Load("Models/Inside door.3ds");
	grass.Load("Models/grass-block.3DS");
	Flowers.Load("Models/Flowers_vase .3ds");
	Car.Load("Models/oil-truck_3ds.3ds") ;
	Farm.Load("Models/house062.3ds"); 
	Smallhous.Load("Models/fachwerk40T.3ds"); 
	Wall.Load( "Models/Wall.3ds"); 
	birds.Load("Models/DOVE.3DS");
	Pool.Load("Models/Pool05.3DS");
	chair.Load("Models/chair.3ds");
	sky_Texture = LoadTexture("Image/back1.bmp" ); 
	sky_Textureup = LoadTexture("Image/back11.bmp" ); 
	Erth_Texture = LoadTexture("Image/grass.bmp" ); 
	street_Textureup = LoadTexture("Image/street.bmp" );
	road_Texture = LoadTexture("Image/road.bmp" );
	glPushMatrix();
	birds.Materials[0].tex.Load("Image/DOVE.JPG");//⁄Ì‰
	birds.Materials[1].tex.Load("Image/bark_loo.bmp");//Ã”„
	glPopMatrix();
	glPushMatrix();
	Flowers.Materials[0].tex.Load("Image/roof.bmp");//”ÿ·
	Flowers.Materials[1].tex.Load("Image/red.bmp");//Ê—œ
	glPopMatrix();
	glPushMatrix();
	Tree.Materials[0].tex.Load("Image/bark_loo.bmp");//Ã–⁄
	Tree.Materials[1].tex.Load("Image/bark_loo.bmp");//«€’«‰
	Tree.Materials[2].tex.Load("Image/bark_loo.bmp");
	Tree.Materials[4].tex.Load("Image/green.bmp");//Ê—ﬁ
	glPopMatrix();
	glPushMatrix();//⁄—»…
	WheelBarrow.Materials[0].tex.Load("Image/do1.bmp");
	WheelBarrow.Materials[1].tex.Load("Image/black.bmp");
	WheelBarrow.Materials[2].tex.Load("Image/red.bmp");
	WheelBarrow.Materials[3].tex.Load("Image/do1.bmp");
	WheelBarrow.Materials[4].tex.Load("Image/do1.bmp");
	WheelBarrow.Materials[5].tex.Load("Image/grass.bmp");

	glPopMatrix();
	glPushMatrix();
	nissan.Materials[0].tex.Load("Image/tyl.bmp");
	nissan.Materials[3].tex.Load("Image/backcc.bmp");
	nissan.Materials[1].tex.Load("Image/water1.bmp");
	nissan.Materials[2].tex.Load("Image/black.bmp");
	nissan.Materials[4].tex.Load("Image/black.bmp");
	nissan.Materials[5].tex.Load("Image/black.bmp");
	nissan.Materials[6].tex.Load("Image/water1.bmp");
	nissan.Materials[7].tex.Load("Image/black.bmp");
	nissan.Materials[8].tex.Load("Image/backcc.bmp");
	nissan.Materials[9].tex.Load("Image/backcc.bmp");
	nissan.Materials[10].tex.Load("Image/front_light.bmp");
	nissan.Materials[11].tex.Load("Image/red.bmp");
	nissan.Materials[12].tex.Load("Image/red.bmp");
	nissan.Materials[13].tex.Load("Image/red.bmp");
	nissan.Materials[14].tex.Load("Image/black.bmp");
	nissan.Materials[15].tex.Load("Image/black.bmp");
	nissan.Materials[16].tex.Load("Image/red.bmp");
	nissan.Materials[17].tex.Load("Image/red.bmp");
	nissan.Materials[18].tex.Load("Image/black.bmp");
	nissan.Materials[19].tex.Load("Image/black.bmp");
	nissan.Materials[20].tex.Load("Image/black.bmp");
	nissan.Materials[21].tex.Load("Image/black.bmp");
	nissan.Materials[22].tex.Load("Image/black.bmp");
	nissan.Materials[23].tex.Load("Image/backcc.bmp");
	nissan.Materials[24].tex.Load("Image/black.bmp");
	nissan.Materials[25].tex.Load("Image/black.bmp");
	nissan.Materials[26].tex.Load("Image/black.bmp");
	nissan.Materials[27].tex.Load("Image/do1.bmp");
	nissan.Materials[28].tex.Load("Image/backcc.bmp");
	nissan.Materials[29].tex.Load("Image/do1.bmp");

	//nissan.Materials[4].tex.Load("Image/tabel.bmp");
	jeep.Materials[3].tex.Load("Image/fiat_logo.bmp");
	jeep.Materials[0].tex.Load("Image/black.bmp");
	jeep.Materials[1].tex.Load("Image/do1.bmp");
	jeep.Materials[2].tex.Load("Image/do1.bmp");
	jeep.Materials[4].tex.Load("Image/do1.bmp");
	jeep.Materials[5].tex.Load("Image/black.bmp");
	jeep.Materials[6].tex.Load("Image/black.bmp");
	jeep.Materials[7].tex.Load("Image/black.bmp");
	jeep.Materials[8].tex.Load("Image/black.bmp");
	jeep.Materials[9].tex.Load("Image/white.bmp");//
	jeep.Materials[10].tex.Load("Image/tablica.bmp");
	jeep.Materials[11].tex.Load("Image/black.bmp");
	jeep.Materials[12].tex.Load("Image/water1.bmp");
	jeep.Materials[13].tex.Load("Image/black.bmp");
	glPopMatrix();
	carmove.Materials[1].tex.Load("Image/black.bmp");
	carmove.Materials[2].tex.Load("Image/red.bmp");
	carmove.Materials[3].tex.Load("Image/front_light.bmp");
	carmove.Materials[4].tex.Load("Image/do1.bmp");
	carmove.Materials[5].tex.Load("Image/black.bmp");
	carmove.Materials[6].tex.Load("Image/do1.bmp");
	carmove.Materials[7].tex.Load("Image/water1.bmp");
	carmove.Materials[10].tex.Load("Image/water1.bmp");
	glPushMatrix();
	glPopMatrix();
	door.Materials[0].tex.Load("Image/do1.bmp");
	door.Materials[1].tex.Load("Image/do1.bmp");
	door.Materials[2].tex.Load("Image/white.bmp");
	//door.Materials[4].tex.Load("Image/grass.bmp");
	glPushMatrix();
	Car.Materials[1].tex.Load("Image/grass.bmp");
	Car.Materials[2].tex.Load("Image/wood.bmp");
	Car.Materials[3].tex.Load("Image/grass.bmp");
	Car.Materials[4].tex.Load("Image/grass.bmp");
	glPopMatrix();
	glPushMatrix();
	forklift.Materials[0].tex.Load("Image/black.bmp");
	forklift.Materials[1].tex.Load("Image/black.bmp");
	forklift.Materials[2].tex.Load("Image/red.bmp");
	forklift.Materials[3].tex.Load("Image/black.bmp");
	forklift.Materials[4].tex.Load("Image/red.bmp");
	forklift.Materials[5].tex.Load("Image/do1.bmp");
	forklift.Materials[6].tex.Load("Image/do1.bmp");
	forklift.Materials[8].tex.Load("Image/do1.bmp");
	forklift.Materials[9].tex.Load("Image/do1.bmp");
	forklift.Materials[10].tex.Load("Image/black.bmp");
	forklift.Materials[7].tex.Load("Image/black.bmp");
	forklift.Materials[11].tex.Load("Image/do1.bmp");
	forklift.Materials[12].tex.Load("Image/black.bmp");
	forklift.Materials[13].tex.Load("Image/do1.bmp");
	forklift.Materials[14].tex.Load("Image/black.bmp");
	forklift.Materials[15].tex.Load("Image/do1.bmp");


	glPopMatrix();
	Smallhous.Materials[0].tex.Load("Image/wall11.bmp");
	Smallhous.Materials[1].tex.Load("Image/wall2.bmp");
	Smallhous.Materials[2].tex.Load("Image/wall2.bmp");
	Smallhous.Materials[3].tex.Load("Image/wall2.bmp");
	Smallhous.Materials[4].tex.Load("Image/wall2.bmp");
	Smallhous.Materials[5].tex.Load("Image/stroh_3.bmp");
	Smallhous.Materials[6].tex.Load("Image/wall2.bmp");
	Smallhous.Materials[7].tex.Load("Image/wall2.bmp");
	Smallhous.Materials[8].tex.Load("Image/wall2.bmp");
	Smallhous.Materials[9].tex.Load("Image/wall2.bmp");
	glPopMatrix();
	glPushMatrix();
	Farm.Materials[0].tex.Load("Image/roof.bmp");
	Farm.Materials[1].tex.Load("Image/wall8.bmp");
	Farm.Materials[2].tex.Load("Image/wall2.bmp");
	Farm.Materials[3].tex.Load("Image/street.bmp");
	Farm.Materials[4].tex.Load("Image/wall8.bmp");
	Farm.Materials[5].tex.Load("Image/re.bmp");
	Farm.Materials[6].tex.Load("Image/water3.bmp");
	Farm.Materials[7].tex.Load("Image/bark_loo.bmp");
	Farm.Materials[8].tex.Load("Image/wall2.bmp");
	Farm.Materials[9].tex.Load("Image/black.bmp");
	glPopMatrix();
	glPushMatrix();
	Wall.Materials[0].tex.Load("Image/wall6.bmp");
	glPopMatrix();
	glPushMatrix();
	grass.Materials[3].tex.Load("Image/grass1.bmp");
	glPopMatrix();
	glPushMatrix();
	Pool.Materials[0].tex.Load("Image/street.bmp");
	Pool.Materials[1].tex.Load("Image/street.bmp");
	Pool.Materials[2].tex.Load("Image/do1.bmp");
	Pool.Materials[3].tex.Load("Image/street.bmp");
	Pool.Materials[4].tex.Load("Image/water1.bmp");
	Pool.Materials[5].tex.Load("Image/water1.bmp");
	glPopMatrix();
	glPushMatrix();
	chair.Materials[2].tex.Load("Image/water1.bmp");
	chair.Materials[3].tex.Load("Image/do1.bmp");
	glPopMatrix();
	return TRUE;										// Initialization Went OK
}
void doorMov(Model_3DS door_,int  k){
	glPushMatrix();
	if (keys['O'])//down
	{
	glTranslatef(k,0,0);
	farm.allDoor(door_);
	}else
	farm.allDoor(door_);
	glPopMatrix();} 
int  k=8;
void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
	translate_cam();
	glPushMatrix();
	doorMov(door,k);
	farm.drawModel(Flowers,Tree,birds,Smallhous,
					Farm,Pool,grass,Wall,Car,chair,nissan,
					jeep,carmove,door,WheelBarrow,forklift);
	farm.erth(Erth_Texture,6);
	farm.sky(sky_Textureup,sky_Textureup,0);
	farm.street(street_Textureup,road_Texture,5);
	glPopMatrix();




    glFlush();											// Done Drawing The Quad	

    //DO NOT REMOVE THIS
	SwapBuffers(hDC);			
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_PAINT: 
			DrawGLScene();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
	
		case WM_TIMER:
			DrawGLScene();
			return 0;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Madhat NeHe Template",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer=SetTimer(hWnd,0,50,(TIMERPROC) NULL);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
	}

	return 0;

}
