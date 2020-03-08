#include<stdio.h>
#include <stdlib.h>
#include<time.h>
void meshaj(int wDeck[][13]);
void deli(int raka[][2], int wDeck[][13], const char* wFace[], const char* wSuit[]);
void printMat(int mat[][13]);
void printRaka(int mat[][2]);
void sortHand(int raka[][2]);
int handValue(int raka[][2]);

int main() {
	int raka1[5][2];
	int raka2[5][2];
	const char* boja[4] = { "Srce","Karo","List","Detelina" };
	const char* brojka[13] = { "As","Dva","tri","Chetiri","pet","Shest","Sedum","Osum","Devet","Deset","Dzandar","Dama","Pop" };
	int spil[4][13] = { 0 };
	srand(time(0));
	meshaj(spil);
	deli(raka1,spil, brojka, boja);
	sortHand(raka1);
	printRaka(raka1);
	printf("\n");
	deli(raka2, spil, brojka, boja);
	sortHand(raka2);
	printRaka(raka2);
	printf("\n");
	int igrac1 = handValue(raka1);
	int igrac2 = handValue(raka2);
	if (igrac1 > igrac2)
		printf("igrac1 pobedi");
	else if (igrac1 < igrac2)
		printf("igrac 2 pobedi");
	else
		printf("nereseno");
	return 0;

	// mi dava nekogas error stack arround the variable raka was corrupted, ne razbiram zasto
}

void meshaj(int wDeck[][13]) {
	int row;
	int collumn;
	for (int i = 1; i < 53; i++) {
		do {
			row = rand() % 4;
			collumn = rand() % 13;
		} while (wDeck[row][collumn] != 0);
		wDeck[row][collumn] = i;
	}
}
void deli(int raka[5][2], int wDeck[][13], const char* wFace[], const char* wSuit[]) {
	int brojac = 0;
	static int brKarta = 1;
	while (brojac < 5) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				if (wDeck[i][j] == brKarta) {
					raka[brojac][0] = i;
					raka[brojac][1] = j;
					brojac++;
					brKarta++;
					break;
				}
			}
		}

	}
}
void printMat(int mat[][13]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
void printRaka(int mat[][2]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
void sortHand(int raka[][2]) {
	int tempBoja;
	int tempBroj;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
		{
			if (raka[j][1] > raka[j + 1][1]) {
				tempBroj = raka[j][1];
				tempBoja = raka[j][0];
				raka[j][1] = raka[j + 1][1];
				raka[j][0] = raka[j + 1][0];
				raka[j + 1][1] = tempBroj;
				raka[j + 1][0] = tempBoja;
			}
		}
	}
}
int handValue(int raka[][2]) {
	int counterNum = 0;
	int par = 0;
	int skala = 0;
	int tri = 0;
	int cet = 0;
	int boja = 0;
	for (int i = 0; i < 4; i++) {
		if (raka[i][0] == raka[i + 1][0])
			boja++;
		if (raka[i][1] == (raka[i + 1][1] - 1))
			skala++;
		if (raka[i][1] == raka[i + 1][1])
			counterNum++;
		else {
			switch (counterNum) {
			case 1:
				par++;
				break;
			case 2:
				tri++;
				break;
			case 3:
				cet++;
				break;		
			}
			counterNum = 0;
		}

	}
	if ((boja == 4) && (skala == 4))
		return 8;
	else if (cet == 1)
		return 7;
	else if (boja == 4)
		return 6;
	else if (tri == 1 && par == 1)
		return 5;
	else if (skala == 4)
		return 4;
	else if (tri == 1)
		return 3;
	else if (par == 2)
		return 2;
	else if (par == 1)
		return 1;
	else
		return 0;
	
}
