#include <stdio.h>

int main() {
	int mesec;
	printf("vnesi go mesecot so negoviot reden broj:");
	scanf_s("%d", &mesec);
	switch (mesec) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf("ima 31 den \n");
	case 4:
	case 6:
	case 9:
	case 11:
		printf("ima 30 dena \n");
	case 2:
		printf("29 vo prestapni, a vo obicni 28 \n");
	default:
		printf("nema takov mesec");
	}

	return 0;
}