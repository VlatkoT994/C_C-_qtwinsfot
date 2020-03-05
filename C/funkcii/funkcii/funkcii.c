#include <stdio.h>

int paren(int broj);
int vreme(int casovi, int minuti, int sekundi);
int obratno(int broj);
int nzd(int broj1, int broj2);
int fib(int broj);
int rekNzd(int broj1, int broj2, int brojac);
void dzvezdi(int broj);
int main() {
	printf("%d %d\n", paren(2), paren(3));
	printf("%d \n", vreme(11, 59, 45));
	printf("%d\n", obratno(12345));
	printf("%d\n", nzd(7, 8));
	printf("%d\n", fib(5));
	printf("%d\n", rekNzd(12, 18, 12));
	dzvezdi(5);
	
	return 0;
}
int paren(int broj) {
	if (broj % 2 == 0)
		return 1;
	return 0;
}
int vreme(int casovi, int minuti, int sekundi) {
	int result = 0;
	result += 60 - sekundi;
	if (sekundi > 0)
		minuti++;
	result += (60 - minuti) * 60;
	if (minuti > 0)
		casovi++;
	result += 60 * (12 - casovi);
	return result;
}
int obratno(int broj) {
	int res = 0;
	int temp;
	int brojac = 10;
	int brojCifri = 1;
	while(broj/(brojCifri *10) >= 1){
		brojCifri *= 10;
	}
	while (broj > 0) {
		temp = broj % brojac;
		res += temp * brojCifri;
		broj = (broj - temp) / 10;
		brojCifri /= 10;
	}
	return res;
}
int nzd(int broj1, int broj2) {
	int result = 1;
	int brojac = 1;
	while (brojac <= broj1 && brojac <= broj2) {
		if (broj1 % brojac == 0 && broj2 % brojac == 0)
			result = brojac;
		brojac++;
	}
	return result;
}
int fib(int broj) {
	int cur = 1;
	int last = 1;
	int brojac = 3;
	int temp;
	while (brojac <= broj) {
		temp = cur;
		cur = cur + last;
		last = temp;
		brojac++;
	}
	return cur;
}
int rekNzd(int broj1, int broj2, int brojac) {
	if (broj1 % brojac == 0 && broj2 % brojac == 0)
		return brojac;
	return rekNzd(broj1, broj2, brojac - 1);
}
void dzvezdi(int broj) {
	for (int i = 0; i < broj; i++)
		printf("*");
	printf("\n");
	if (broj > 1)
		dzvezdi(broj - 1);
}