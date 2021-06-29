#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int x=1,y=1; //小球座標 
	int v_x=1,v_y=1;	//位移(斜下) 
	int i=0,j=0;
	while(1)
	{
	    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//第二個值0表示隱藏光標 
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
        system("cls");	//清屏(為了顯示下次畫面) 
		if(x>=20||x<1)	//超出寬 
		{
			v_x*=-1;	//x反向, y不變(反彈)
			printf("\a");	//發出聲音 
		}
		if(y>=25||y<1)
		{
			v_y*=-1;
			printf("\a");
		}

		for(i=0;i<x&&x<20;i++)
        {
			printf("\n");
		}
		for(j=0;j<y&&y<25;j++){
			printf("  ");
		}
		x+=v_x;	//下次x
		y+=v_y;	//下次y 
		printf("O\n");
        Sleep(0.01);

	}

	return 0;
}
