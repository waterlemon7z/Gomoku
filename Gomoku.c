
/*Gomoku 1.0     by DARK-Lemon7z     */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define SIZE 20

void BoardVOID(int arr_chGomoku[][20]);
int ChooseINT(int arr_chGomoku[][20], int iTurn);
int Rock5INT(int arr_Gomoku[][20], int iTurn);


int main()
{
	int iTurn = 0;
	int iResult;
	iResult = 100;
	system("mode con cols=100 lines=50");
	int arr_iGomoku[20][20] = { ' ' }; //Gomoku's playable spaces
	while (1)
	{
		BoardVOID(arr_iGomoku);//Pass arr_chGomoku to BoardVOID Function
		iTurn = ChooseINT(arr_iGomoku, iTurn);//Choose X and Y coordinates
		iResult = Rock5INT(arr_iGomoku, iTurn);//Save iResult that Rock5INT's return value
		if (iResult == 0)//If iResult's return value is 1 break while
			continue;
		else
			break;
	}
	BoardVOID(arr_iGomoku);//last board print
	if (iTurn == 1)
		printf("player O is winner!\n");
	else
		printf("player X is winner!\n");
	system("pause");
	return 0;
}

/*
* name   : BoardVOID
* date   : 2019.02.04
* author : DARK-Lemon7z
* arg    : void
* return      : void
* description : Show Gomoku's Board
*/
void BoardVOID(int arr_iGomoku[][20])
{
	int i, n;//i for iY, n for iX
	system("cls");
	printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20\n");//For show X coordinates
	printf("   ---------------------------------------------------------------------------------\n");
	for (i = 0; i < SIZE; i++)
	{
		if (i < 9)//For show Y coordinates
			printf("%d  ", i + 1);
		else
			printf("%d ", i + 1);

		for (n = 0; n < SIZE; n++)//Show Gomoku status
		{
			printf("| %c ", arr_iGomoku[i][n]);
		}

		printf("|\n");
		printf("   ---------------------------------------------------------------------------------\n");
	}
}

/*
* name   : ChooseINT
* date   : 2019.02.04
* author : DARK-Lemon7z
* arg    : int
* return      : int - Return value that player's turn
* description : Return value that O or X at arr_Gomoku array
*/
int ChooseINT(int arr_iGomoku[][20], int iTurn)
{
	unsigned int iX, iY;//Gomoku's X and Y coordinates
	printf("Choose your X and Y coordinates :");
	scanf("%d %d", &iX, &iY);//scan X and Y coordinates
	if (iX > 20 || iY > 20)
		return iTurn;
	else if (arr_iGomoku[iY-1][iX-1] == 'O' || arr_iGomoku[iY-1][iX-1] == 'X')//Distinguish O or X to return.
		return iTurn;

 	if (iTurn == 0)
	{
		arr_iGomoku[iY - 1][iX - 1] = 'O';
		iTurn++;
	}
	else
	{
		arr_iGomoku[iY - 1][iX - 1] = 'X';
		iTurn--;
	}
	return iTurn;
}

/*
* name   : Rock5INT
* date   : 2019.02.04
* author : DARK-Lemon7z
* arg    : int
* return      : int - Return value that to end the game or not
* description : Return value that 0 or 1 to finish the game
*/
int Rock5INT(int arr_Gomoku[][20], int iTurn)
{
	int i, n, p, iCheck;//i and n for X and Y coordinates. p is for check rocks. iCheck is for Checking win or loose
	char chOorX;//It notices O or X's turn.
	iCheck = 0;//When It is 5, finish the game
	if (iTurn == 1)
		chOorX = 'O';
	else
		chOorX = 'X';
	
	for (i = 0; i < SIZE; i++)//increase Y coordinate and check.
	{
		for (n = 0; n < SIZE; n++)//increase X coordinate and check
		{
			if (arr_Gomoku[i][n] == chOorX)
			{
				iCheck++;
				for (p = 1; p < 5; p++)
				{
					if (n + p >= 20)
						break;
					else if (arr_Gomoku[i][n + p] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
						iCheck = 1;
						break;
				}
				if (iCheck == 5)
					return 1;
				for (p = 1; p < 5; p++)
				{
					if (n - p <= -1)
						break;
					else if (arr_Gomoku[i][n - p] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
					{
						iCheck = 1;
						break;
					}
				}
				if (iCheck == 5)
					return 1;
				for (p = 1; p < 5; p++)
				{
					if (i + p >= 20)
						break;
					else if (arr_Gomoku[i + p][n] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
					{
						iCheck = 1;
						break;
					}
				}
				if (iCheck == 5)
					return 1;
				for (p = 1; p < 5; p++)
				{
					if (i + p <=-1)
						break;
					else if (arr_Gomoku[i + p][n] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
					{
						iCheck = 1;
						break;
					}
				}
				if (iCheck == 5)
					return 1;
				for (p = 1; p < 5; p++)
				{
					if (i + p >= 20 || n + p >= 20)
						break;
					else if (arr_Gomoku[i + p][n + p] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
					{
						iCheck = 1;
						break;
					}
				}
				if (iCheck == 5)
					return 1;
				for (p = 1; p < 5; p++)
				{
					if (i + p >= 20 || n - p <= -1)
						break;
					else if (arr_Gomoku[i + p][n - p] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
					{
						iCheck = 1;
						break;
					}
				}
				if (iCheck == 5)
					return 1;
				for (p = 1; p < 5; p++)
				{
					if (i - p <= -1 || n + p >= 20)
						break;
					else if (arr_Gomoku[i - p][n + p] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
					{
						iCheck = 1;
						break;
					}
				}
				if (iCheck == 5)
					return 1;
				for (p = 1; p < 5; p++)
				{
					if (i - p <= -1 || n - p <= -1)
						break;
					else if (arr_Gomoku[i + p][n] == chOorX)
					{
						iCheck++;
						continue;
					}
					else
					{
						iCheck = 1;
						break;
					}
				}
				if (iCheck == 5)
					return 1;

			}
		}
	}
	return 0;
}