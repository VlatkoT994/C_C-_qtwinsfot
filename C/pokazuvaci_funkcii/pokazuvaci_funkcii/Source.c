# include<stdio.h>
void pecatiNiza(int niza[][5], int brUcenici);
void max(int niza[][5], int brUcenici);
void min(int niza[][5], int brUcenici);
void prosek(int niza[][5], int brUcenici);


int main() {
	void (*obrabotiOceni[4])(int niza[][5], int brUcenici) = { pecatiNiza,max,min,prosek };
	int oceni[3][5] = { {1,3,4,2,4},{2,3,4,3,3},{2,3,4,4,4} };
	int izbor;
	printf("Vnesi izbor: ");
	scanf_s("%d", &izbor);
	while (izbor != 4) {
		if (izbor < 0 || izbor > 4) {
			printf("nepostoecka komanda, vnesi nov izbor:");
			scanf_s("%d", &izbor);
			continue;
		}
		obrabotiOceni[izbor](oceni, 3);
		printf("Vnesi nov izbor:");
		scanf_s("%d", &izbor);

	}
}

void pecatiNiza(int niza[][5], int brUcenici) {
	for (int i = 0; i < brUcenici; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%3d", niza[i][j]);
		}
		printf("\n");
	}
}
void max(int niza[][5], int brUcenici) {
	int maximum = 0;
	for (int i = 0; i < brUcenici; i++) {
		for (int j = 0; j < 5; j++) {
			if (niza[i][j] > maximum)
				maximum = niza[i][j];
		}
	}
	printf("najgolemata ocena e: %d \n", maximum);
}
void min(int niza[][5], int brUcenici) {
	int minimum = 5;
	for (int i = 0; i < brUcenici; i++) {
		for (int j = 0; j < 5; j++) {
			if (niza[i][j]<minimum)
				minimum = niza[i][j];
		}
	}
	printf("najmalata ocena e: %d \n", minimum);
}
void prosek(int niza[][5], int brUcenici) {
	for (int i = 0; i < brUcenici; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++)
			sum += niza[i][j];
		printf("Prosekot na ucenik %d e %f \n", i + 1, (float)sum/5);
	}
}