#include <stdio.h>

int main() {
	//1
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
		printf("nema takov mesec \n");
	}
	// dokolku nema break; go izvrsuva site naredbi posle prviot pat koga kje bide ispolnet uslovot
	//2,3
	int brojNaUcenici;
	int counter = 0;
	int total = 0;
	int grade;
	printf("vnesi broj na ucenici");
	scanf_s("%d", &brojNaUcenici);
	while (counter < brojNaUcenici) {
		printf("vnesi ocena");
		scanf_s("%d", &grade);
		total += grade;
		counter++;
	}
	printf("srednata vrednost za klasot e %.3f\n", (float)total / brojNaUcenici);
	//4
	int sum = 0;
	counter = 1;
	while (counter < 11) {
		sum += counter;
		counter++;
	}
	printf("zbirot na broevite od eden do deset e:%d \n", sum);
	//5
	int product = 1;
	counter = 0;
	int num;
	while (counter < 10)
	{
		printf("vnesi broj");
		scanf_s("%d", &num);
		product *= num;
		counter++;
	}
	printf("proizvodot na broevite e %d \n", product);
	//6
	sum = 0;
	num = 0;
	do {
		sum += num;
		printf("vnesi broj, ili -1 ako sakas da prestane: ");
		scanf_s("%d", &num);
	} while (num != -1);
	printf("sumata na vesenite broevi e %d \n", sum);
	//7
	sum = 0;
	char controller = 'd';
	while (controller == 'd') {
		printf("Vnesi broj: ");
		scanf_s("%d", &num);
		sum += num;
		printf("Ushte? (d/n)");
		scanf_s(" %c", &controller);
	}
	printf("sumata e: %d\n", sum);
	//8
	float vkupnoCena = 0.0;
	int proizvodBroj = 0;
	while (proizvodBroj != -1)
	{
		printf("vnesi broj na proizvod: ");
		scanf_s("%d", &proizvodBroj);
		switch (proizvodBroj) {
		case 1:
			vkupnoCena += 50.5;
			break;
		case 2:
			vkupnoCena += 45.6;
			break;
		case 3:
			vkupnoCena += 32.8;
			break;
		case 4:
			vkupnoCena += 65.3;
			break;
		case 5:
			vkupnoCena += 20.0;
			break;
		default:
			printf("ne postoi takov proizvod\n");
		}
	}
	printf("vkupnata cena e %f: \n", vkupnoCena);
	//9
	float promet;
	printf("vnesi promet vo evra (-1 za kraj): ");
	scanf_s("%f", &promet);
	while (promet != -1.0) {
		printf("Platata e : %f\n", 200 + promet * 0.09);
		printf("vnesi promet vo evra (-1 za kraj): ");
		scanf_s("%f", &promet);
	}

	return 0;
}