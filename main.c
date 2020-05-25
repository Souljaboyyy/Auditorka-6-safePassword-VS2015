#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int checkPassword(char* mass,int kolvo) {
	int i = 0, flag[4] = { 0 },rate =1,average = 0;
	if (kolvo < 8)
		return rate;
	for (i; i < kolvo; i++)
		if (((int)mass[i] > 96) && ((int)mass[i] < 123))
			flag[0]++;
		else
			if (((int)mass[i] > 64) && ((int)mass[i] < 91))
				flag[1]++;
			else
				if (((int)mass[i] > 47) && ((int)mass[i] < 58))
					flag[2]++;
				else
					flag[3]++;
	for (i = 0; i < 4; i++)
		if (flag[i] > 0)
			average++;
	if (average == 1)
		return rate;
	else 
		if ((kolvo < 15) && (average < 3))
		rate = 2;
	else
		 if (average == 3)
			rate = 3;
		else
			rate = 4;


		return rate;
}

int main() {
	char* pass;
	int i=0, x, y=2,n;
	printf("Input your password lenght (4-20) : \n");
	scanf_s("%d", &n);
	pass = (char*)malloc(sizeof(char)*n);
	for (i; i < n; i++)
		pass[i] = ' ';
	i = 0;
	while (i < n) {
		x = i;
		gotoxy(x, y);
		pass[i] = getch();
		if (pass[i] == '\b') {
			if (i > 0) {
				pass[i - 1] = ' ';
				i -= 1;
				gotoxy(i, y);
				printf("%c", pass[i]);
			}
		}
		else
		{
			printf("*");
			++i;
		}
			
	}
	printf("\n");
	for (i = 0; i < n; i++)
	printf("%c", pass[i]);
	printf("\nWould you like to check your password ? Y or N\n");
	char Y;
	scanf_s("%c", &Y);
	scanf_s("%c", &Y);
	if (Y == 'Y') {
		i = checkPassword(pass, n);
		if (i == 1)
			printf("Bad password\n");
		else
			if (i == 2)
				printf("This is nice password,but not good enought \n");
			else
				if (i == 3)
					printf("Awesome password\n");
				else
					printf("Incredible!!!\n");
	}
	free(pass);
	printf("\n");
	
	system("pause");
	return 0;
}