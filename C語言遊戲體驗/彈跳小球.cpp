#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int x=1,y=1; //�p�y�y�� 
	int v_x=1,v_y=1;	//�첾(�פU) 
	int i=0,j=0;
	while(1)
	{
	    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//�ĤG�ӭ�0������å��� 
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
        system("cls");	//�M��(���F��ܤU���e��) 
		if(x>=20||x<1)	//�W�X�e 
		{
			v_x*=-1;	//x�ϦV, y����(�ϼu)
			printf("\a");	//�o�X�n�� 
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
		x+=v_x;	//�U��x
		y+=v_y;	//�U��y 
		printf("O\n");
        Sleep(0.01);

	}

	return 0;
}
