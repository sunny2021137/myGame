#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

int x, y;	//玩家位置 
int high, width;	//遊戲畫面尺寸 
int dx1, dy1;	//敵人1位置 
int dx2, dy2;

//隱藏光標
void hideCursor()	 
{
	CONSOLE_CURSOR_INFO cursor_info={1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//光標移到(x,y)
void gotoxy(int x, int y)	
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle, pos);
}

//數據初始化 
void startup()
{
	high=18;
	width=30;
	
	x=high/2;
	y=width/2;
	
	dx1=high-2;
	dy1=rand()%width;
	dx2=high-2;
	dy2=rand()%width;
	hideCursor();
}

//顯示畫面 
void show()
{
	gotoxy(0,0);	//清屏
	for(int i=0; i<high; i++)
	{
		for(int j=0; j<width; j++)
		{
			if((i==x)&&(j==y))	//人的位置 
				printf("我");
			else if((i==dx1)&&(j==dy1))
				printf("敵");
			else if((i==dx2)&&(j==dy2))
				printf("敵");	
			else
				printf("  ");
		}
		printf("\n");
	}
}

//與用戶無關的輸入
void updateWithoutInput()
{
	static int speed=0;
	if(speed<20) speed++;	//調慢遊戲運行速度 
	else
	{
		if(speed==20)
		{
			if(x<dx1) dx1--; 
			else if(x>dx1) dx1++;

			if(y<dy1) dy1--;
			else if(y>dy1) dy1++;
			
			if(x<dx2) dx2--;
			else if(x>dx2) dx2++;
			
			if(x<dy2) dy2--;
			else if(x>dy2) dy2++;
			
			speed=0;
		}
		if((dx1==x && dy1==y) || (dx1==x && dy1==y))
		{
			printf("ㄚㄚㄚ輸了!!!");
			exit(0);
		}
	}
 }
 
 //與用戶有關的輸入
void updateWithInput()
{
	char input;
	if(_kbhit())
	{
		input=_getch();
		switch(input)
		{
			case 's':
				if(x<=high-2) x++;
				break;
			case 'w':
				if(x>=1) x--;
				break;
			case 'a':
				if(y>=1) y--;
				break;
			case 'd':
				if(y<=width-2) y++;
				break;
			default:
				x=x;
				y=y;
		}
	}
 }
int main()
{
	startup();
	while(1)
	{
		show();
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
} 
