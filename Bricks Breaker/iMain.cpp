/*
MD. ASHIKUZZ ZAMAN (ASHIK)
ID: 220119
DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING
Pabna University of Science and Technology
*/
#include<iostream>
#include<string>
#include "iGraphics.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 650

int paddle_x = 425, paddle_y = 15;
int ball_x = 475, ball_y = 34;
//int brick_x = 10, brick_y = 1200;

int dx = 10, dy = 10;
int bricks[10][31], i, j;
int bg_x=0, bg_y=0;

int themeImage;

bool gamestart = false;
bool level = false;
bool start = false;
bool how_to_play = false;
bool gameover = false;
char score[100]="0",highscore[10]="3100";
char levels[10] = "1";
int SCORE = 0,LEVELS=0;
int speed = 50;
int life = 3 ,go1,go2,go3,lifepic;
int levelimage, bg, bg1, bg2, bg3,bbk,playb,htp,about,sc,gv,resume,pause,htpr,close,mm,mr,nm,aboutme,winner;
char name[100];
int nameindex = 0;
bool namet = false;
bool me = false;
bool dl = true;
bool win = false;


void LoadThemeImage()
{
	themeImage = iLoadImage("Theme\\t4.png");
	levelimage = iLoadImage("Theme\\level.png");
	bg = iLoadImage("Theme\\t3.png");
	bg1 = iLoadImage("Theme\\bg1.png");
	bg2 = iLoadImage("Theme\\bg2.png");
	bg3 = iLoadImage("Theme\\bg3.png");
	go1 = iLoadImage("Theme\\gover.png");
	go2 = iLoadImage("Theme\\ggov.png");
	go3 = iLoadImage("Theme\\go3.png");
	lifepic = iLoadImage("Theme\\life.png");
	bbk = iLoadImage("menu\\bbk.png");
	playb = iLoadImage("menu\\1.png");
	htp = iLoadImage("menu\\2.png");
	about = iLoadImage("menu\\3.png");
	sc = iLoadImage("menu\\score.png");
	gv = iLoadImage("menu\\gmov.png");
	resume = iLoadImage("menu\\resume.png");
	pause = iLoadImage("menu\\pause.png");
	htpr = iLoadImage("menu\\htpr.png");
	close = iLoadImage("menu\\close.png");
	mm = iLoadImage("menu\\manu.png");
	mr = iLoadImage("menu\\menur.png");
	nm = iLoadImage("menu\\nm.png");
	aboutme = iLoadImage("menu\\about.png");
	winner = iLoadImage("menu\\winner.png");
}
/*
MD. ASHIKUZZ ZAMAN (ASHIK)
ID: 220119
DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING
Pabna University of Science and Technology
*/

void brick(){
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 31; j++) {
			bricks[i][j] = 1;
		}
	}
}


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	if (!gamestart){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, themeImage);
		iShowImage(300, 530,600, 120, bbk);
		iShowImage(500, 400, 200, 100, playb);
		iShowImage(400, 280, 400, 100, htp);
		iShowImage(500, 160, 200, 100, about);

		if (me){
			iShowImage(0,0,SCREEN_WIDTH,SCREEN_HEIGHT, aboutme);
			iShowImage(1100, 600, 100, 50, close);
		}

		if (how_to_play){
			iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, htpr);
			iShowImage(1100,600,100,50,close);
		}

	}
	if (gamestart && dl)	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, nm);
		iSetColor(255, 255, 0);
		iText(SCREEN_WIDTH - 250, 530, name, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (gamestart && namet)
	{
		//iShowImage(bg_x, bg_y, SCREEN_WIDTH, SCREEN_HEIGHT, bg3);
		//iShowImage(bg_x + SCREEN_WIDTH, bg_y, SCREEN_WIDTH, SCREEN_HEIGHT, bg3);
		iShowImage(0, 0, SCREEN_WIDTH-255, SCREEN_HEIGHT, bg3);
		iSetColor(0, 255, 0);
		iRectangle(10, 10, SCREEN_WIDTH - 255, SCREEN_HEIGHT - 20);
		iSetColor(255, 0, 0);
		iRectangle(5, 5, SCREEN_WIDTH - 245, SCREEN_HEIGHT - 10);
		iSetColor(0, 255, 0);
		iRectangle(SCREEN_WIDTH - 235, 10, 220, SCREEN_HEIGHT - 20);
		iSetColor(255, 0, 0);
		iRectangle(SCREEN_WIDTH - 240, 5, 230, SCREEN_HEIGHT - 10);
		iSetColor(255, 255, 255);
		iFilledRectangle(paddle_x, paddle_y, 100, 11);
		iSetColor(255, 255, 0);

		iFilledCircle(ball_x, ball_y, 8);

		iSetColor(255,255,0);
		iText(SCREEN_WIDTH - 225, 560, "Resume   Pause   Menu", GLUT_BITMAP_9_BY_15);
		iShowImage(SCREEN_WIDTH - 210, 590, 30, 30, resume);
		iShowImage(SCREEN_WIDTH - 130, 590, 30, 30, pause);
		iShowImage(SCREEN_WIDTH - 70, 585, 35, 35, mm);
		//iRectangle(SCREEN_WIDTH -230,550,110,90);
		//iRectangle(SCREEN_WIDTH - 120, 550, 100, 90);

		iText(SCREEN_WIDTH - 150, 510, "Life", GLUT_BITMAP_TIMES_ROMAN_24);
		for (int l = 0; l < life;l++)
		iShowImage(l*30+(SCREEN_WIDTH-160),465 ,20,20, lifepic);

		iText(SCREEN_WIDTH - 180, 410, "Player Name", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(SCREEN_WIDTH - 160, 365, name , GLUT_BITMAP_TIMES_ROMAN_24);	  //enter name
		iText(SCREEN_WIDTH - 150, 310, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(SCREEN_WIDTH - 150, 265, score, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(SCREEN_WIDTH - 150, 210, "Level", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(SCREEN_WIDTH - 135, 165, levels, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(SCREEN_WIDTH - 180, 110, "High Score", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(SCREEN_WIDTH - 150, 65, highscore, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(0, 200, 200);
		iRectangle(SCREEN_WIDTH - 230, 450, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 350, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 250, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 150, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 50, 210, 50);

		

		for (i = 0; i <10; i++) {
			for (j = 0; j < 31; j++) {
				if (bricks[i][j] == 1) {
					if (j%2==0)
					iSetColor(255,0 , 255);
					else
					iSetColor(255, 255, 0);
					iFilledRectangle((j * 30) + 25, (i * 25) + 390, 15, 10);
					iSetColor(255, 255, 0);
					iRectangle((j * 30) + 24, (i * 25) + 389, 17, 12);
				}
			}
		}

		

		/*
		MD. ASHIKUZZ ZAMAN (ASHIK)
		ID: 220119
		DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING
		Pabna University of Science and Technology
		*/

	}
	
	if (life == 0){
		gameover = true;
	}
	if (gameover) {
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, go1);
		//iShowImage(400, 265, 500, 120, gv);
		iSetColor(255, 255, 0);
		//iShowImage(500, 150, 300, 100, sc);
		iText(550, 620, "YOUR SCORE: ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(750, 620, score, GLUT_BITMAP_TIMES_ROMAN_24);
		//iSetColor(0, 255, 255);
		//iRectangle(600, 105, 120, 40);
		iShowImage(620, 15, 80, 80, mr);
	}

	if (SCORE==3100){
		win = true;
	}

	if (win)	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, winner);
		gamestart = false;
		start = false;

	}

	
}


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		//iShowImage(500, 400, 200, 100, playb);  playbuttoon
		if (mx >= 500 && mx <= 700 && my >= 400 && my <= 500)
			gamestart = true;
		/*iText(SCREEN_WIDTH - 225, 560, "Resume   Pause   Menu", GLUT_BITMAP_9_BY_15);
		iShowImage(SCREEN_WIDTH - 210, 590, 30, 30, resume);
		iShowImage(SCREEN_WIDTH - 130, 590, 30, 30, pause);
		iShowImage(SCREEN_WIDTH - 70, 585, 35, 35, mm);*/
		if (mx >= (SCREEN_WIDTH - 210) && mx <= (SCREEN_WIDTH - 210)+30 && my >= 590 && my <= 620 && !start && gamestart)
			start = true;
		if (mx >= (SCREEN_WIDTH - 130) && mx <= (SCREEN_WIDTH - 130)+30 && my >= 590 && my <= 620 && start)
			start = false;
		if (mx >= (SCREEN_WIDTH - 70) && mx <= (SCREEN_WIDTH - 70) + 35 && my >= 585 && my <= 620){
			gamestart = false;
			gameover = false;
			life = 3;
			SCORE = 0;
			_itoa_s(SCORE, score, 10);
			brick();
			
		}
		//iShowImage(400, 280, 400, 100, htp);
		if (mx >= 400 && mx <= 800 && my >= 280 && my <= 380)
			how_to_play = true;

		//iShowImage(1100,600,100,50,close);
		if (mx >= 1100 && mx <= 1200 && my >= 600 && my <= 650)
			how_to_play = false;
		/*
		MD. ASHIKUZZ ZAMAN (ASHIK)
		ID: 220119
		DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING
		Pabna University of Science and Technology
		*/
		//iShowImage(500, 160, 200, 100, about);
		if (mx >= 500 && mx <= 500+200 && my >= 160 && my <= 160+100)
			me =true;
		if (mx >= 1100 && mx <= 1200 && my >= 600 && my <= 650)
			me = false;

		//iShowImage(620, 15, 80,80, mr);
		if (mx >= 620 && mx <= 700 && my >= 15 && my <= 95)	{
			gamestart = false;
			gameover = false;
			life = 3;
			SCORE = 0;
			_itoa_s(SCORE, score, 10);
			brick();

			
		}
			
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	
	if (key == 'r')
	{
		start = true;
	}
	if (key == ' ')
	{
		start = false;
	}
	if (key == 13) {
		namet = true;
		dl = false;
	}
		
	if (gamestart && !namet) {
		if (key != '\b'){
			name[nameindex] = key;
			nameindex++;
			name[nameindex] = '\0';
		}

		else {
			if (nameindex <= 0)
				nameindex = 0;
			else
				nameindex--;
			name[nameindex] = '\0';
		}
		
	}
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (start) {


		if (key == GLUT_KEY_RIGHT)
		{
			if (paddle_x <= SCREEN_WIDTH - 340) 
				paddle_x += 72;
			if (paddle_x > SCREEN_WIDTH - 355)
				paddle_x = SCREEN_WIDTH - 355;
			
		}
		if (key == GLUT_KEY_LEFT)
		{
			if (paddle_x >= 24)
				paddle_x -= 72;
			if (paddle_x < 10)
				paddle_x = 10;
		}

	}
	if (key == GLUT_KEY_UP)
	{
		if (!start)
			start = true;

	}
}

void change(){
	if (start){
		ball_x += dx;
		ball_y += dy;
		
	
		if (ball_x >= paddle_x - 4 && ball_x <= paddle_x+104 && ball_y <= paddle_y+34-11)// && ball_y >= paddle_y
			dy = -dy;

		for (i = 0; i < 10; i++) {
			for (j = 0; j < 31; j++) {
				if (bricks[i][j] == 1) {		 //iFilledRectangle((j * 30) + 25, (i * 25) + 390, 15, 10); ball= radius 8
					if (ball_x >= j * 30 + 21 && ball_x <= j * 30 + 44 && ball_y >= i * 25 + 386 && ball_y <= i * 25 + 404) {
						bricks[i][j] = 0;
						SCORE+=10;
						if (SCORE >= 1000){
							speed = 15;
							LEVELS=2;
							_itoa_s(LEVELS, levels, 10);
						}
							
						if (SCORE >= 2000){
							speed = 10;
							LEVELS = 3;
							_itoa_s(LEVELS, levels, 10);
						}
							
						_itoa_s(SCORE, score, 10);
						
						dy = -dy;
					}
				}
			}
		}

		if (ball_x >= 919 || ball_x <= 19)
			dx = -dx;
		if (ball_y >= 644)// || ball_y <= -150
			dy = -dy;
		if (ball_y < 34){
			
			
			paddle_x = 425;
			paddle_y = 15;
			ball_x = 475;
			ball_y = 34;
			dx = 10;
			dy = 10;
			start = false;
			life--;
		}

	}
}


void cgbg(){
	bg_x -= 10;
	if (bg_x <= -SCREEN_WIDTH)
		bg_x = 0;
}
int main()
{
	
	iSetTimer(speed, change);
	iSetTimer(100,cgbg);
	///srand((unsigned)time(NULL));
	iInitialize(SCREEN_WIDTH, SCREEN_HEIGHT, "Brick Breaker");
	LoadThemeImage();
	//if (gamestart)
	brick();
	iStart();
	return 0;
}