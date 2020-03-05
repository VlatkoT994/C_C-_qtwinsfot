#include <stdio.h>

void main() {
	// 1
	int num1;
	int num2;
	printf("vnesi prv broj:");
	scanf_s("%d",&num1);
	printf("vnesi vtor broj:");
	scanf_s("%d",&num2);
	if (num1 > num2)
		printf("%d e pogolem od %d\n", num1, num2);
	else
	{
		if (num2 > num1)
			printf("%d e pogolem od %d\n", num2, num1);
		else
			printf("broevite se ednakvi\n;");
	};
	//2
	printf("vnesi prv broj:");
	scanf_s("%d", &num1);
	printf("vnesi vtor broj:");
	scanf_s("%d", &num2);
	if (num1 % 2 == 0)
		printf("%d e paren\n", num1);
	else
		printf("%d e neparen\n", num1);
	if (num2 % 2 == 0)
		printf("%d e paren\n", num2);
	else
		printf("%d e neparen\n", num2);
	//3
	printf("%d\n", '\n'); //ja prikazuva nivnata ASCII vrednost
	//4
	printf("Rezultatot e %d\n", 7.0 / 22.0);
	//5
	float radius;
	printf("vnesi radius na krug");
	scanf_s("%f", &radius);
	printf("plostinata na krugot e %f, a negoviot prametar e %f\n", 3.14 *radius* radius, 3.14 * 2 * radius);
	//6 scanf nikako ne mi raboti za char
	//7
	float data[5];
	float total;
	float average;
	data[0] = 34.0;
	data[1] = 27.0;
	data[2] = 45.0;
	data[3] = 82.0;
	data[4] = 22.0;
	total = data[0] + data[1] + data[2] + data[3] + data[4];
	average = total / 5.0;
	printf("Vkupno %.3f, Sredna vrednost %.3f\n", total, average);
	//8
	int x = 0;
	x += 1;
	x++;
	++x;
	x = x + 1;
	
}
