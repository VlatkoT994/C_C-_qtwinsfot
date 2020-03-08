#include<stdio.h>
unsigned poStepenOdDva(unsigned broj, int stepen);
unsigned prevrtiBitovi(unsigned broj);
void pecatiBitovi(unsigned broj);
int misterija(unsigned bitovi);
int main() {
	unsigned start = 1565468;
	pecatiBitovi(start);
	unsigned prevrten = prevrtiBitovi(start);
	pecatiBitovi(prevrten);
	unsigned x;
	for (int i = 0; i < 30; i++) {
		printf("Vnesi cel broj: ");
		scanf_s("%u", &x);
		printf("Rezultatot e %d\n", misterija(x));
	}
	return 0;
}
void pecatiBitovi(unsigned broj) {
	unsigned mask = 1 << 31;
	for (int brojac = 1; brojac <= 32; brojac++) {
		printf("%c", (mask & broj ? '1' : '0'));
		if (brojac % 8 == 0)
			printf(" ");
		mask >>= 1;
	}
	printf("\n");
}
//1
unsigned poStepenOdDva(unsigned broj, int stepen) {
	return broj << stepen;
}
//2
unsigned prevrtiBitovi(unsigned broj) {
	int result = 0;
	unsigned mask = 1;
	for (int brojac = 31; brojac >= 0; brojac--) {
		if (broj & mask) {
			result += (1 << brojac);
			}
		mask <<= 1;	
	}
	return result;
}
//3
int misterija(unsigned bitovi)
{
	unsigned i;
	unsigned maska = 1 << 31;
	unsigned total = 0;

	for (i = 1; i <= 32; i++, bitovi <<= 1) {
		if ((bitovi & maska) == maska) {
			total++;
		}
	}
	return !(total % 2) ? 1 : 0;
}
// dali ima paren broj na 1 vo negovata binarna forma??