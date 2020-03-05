#include <stdio.h>
#include <math.h>
int main() {
	//1
	int sum = 0;
	for (int number = 2; number <= 100; sum += number, number += 2);
	printf("%d \n", sum);
	//2
	double amount;            
	double principal = 1000.0; 
	double rate = .05;         
	int year;                 
	printf("%4s%25s\n", "Godina", "Vrednost na depozitot");
	for (year = 1; year <= 10; year++) {
		amount = principal * pow(1.0 + rate, year);
		printf("%-10d%-25.2f\n", year, amount);
	}



	//3
	int a, b, c;
	for (a = 1; a <= 100; a++)
	{
		for (b = a; a <= 100; b++)
		{
			for (c = b; c <= 100; c++)
			{
				if (a * a + b * b == c * c)
				{
					printf("%d, %d, %d \n", a, b, c);
					break;
				}
				else if (a * a + b * b < c * c)
					break;
			}
			if (a * a + b * b > 100 * 100)
				break;
		}
	}
	//4
	int num;
	char digits[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int i;
	int j;
	printf("vnesi broj pomal od 4000 \n");
	scanf_s("%d", &num);
	int pointer = 6;
	if (num >= 1000) {
		for (j = 0; j < num / 1000; j++)
			printf("M");
		num -= j * 1000;
	}
	for (i = 1000; i > 1;pointer-=2,i/=5)
	{
		if (num >= i - i / 10)
		{
			printf("%c%c", digits[pointer-2], digits[pointer]);
			num -= i - i / 10;
		}
		if (num >= i / 2)
		{
			printf("%c", digits[pointer - 1]);
			num -= i / 2;
		}
		i /= 2;
		if (num >= i - i / 5)
		{
			printf("%c%c", digits[pointer-2], digits[pointer - 1]);
			num -= i - i / 5;
		}
		if (num >= i / 5)
		{
			for (j = 0; j < num / (i / 5); j++)
				printf("%c", digits[pointer - 2]);
			num -= j *(i / 5);
		}
		
	}
	/*if (num >= 900) {
		printf("CM");
		num -= 900;
	};
	if (num >= 500) {
		printf("D");
		num -= 500;
	}
	if (num >= 400) {
		printf("CD");
		num -= 400;
	};
	if (num >= 100)
	{
		for (i = 0; i < num / 100; i++)
			printf("C");
		num -= i * 100;
	}
	if (num >= 90 ){
		printf("XC");
		num -= 90;
	}
	if (num >= 50) {
		printf("L");
		num -= 50;
	}
	if (num >= 40){
		printf("XL");
		num -= 40;
	}
	if (num >= 10) {
		for (i = 0; i < num / 10; i++)
			printf("X");
		num -= i * 10;
	}
	if (num == 9) {
		printf("IX");
		num = 0;
	}
	if (num >= 5) {
		printf("V");
		num -= 5;
	}
	if (num == 4) {
		printf("IV");
		num = 0;
	}
	if (num > 0)
	{
		for (i = 0; i < num; i++)
			printf("I");
	}
	*/
	printf("\n");
	for (int counter = 1; counter <= 100; counter++) {
		if (counter % 3 == 0)
			continue;
		printf("%d ne e delliv so 3 \n", counter);
	}
	
	

	return 0;
}