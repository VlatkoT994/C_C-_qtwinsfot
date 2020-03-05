#include <stdio.h>
int srednaTemperatura(int temps[], int size);
int mappirajProsti(int niza[], int size);
int eProst(int broj);
int ePalindrom(char zbor[], int size);
void selekciskoSortiranjeIterativno(int arr[], int size);
void printaj(int arr[], int size);
void selekciskoSortiranjeRekurzija(int arr[], int size, int start);
int main() {
	int niza[10];
	int nizaZaSort[6] = { 2,5,1,7,6,4 };
	selekciskoSortiranjeRekurzija(nizaZaSort,6,0);
	printaj(nizaZaSort, 6);
	for (int i = 0; i < 10; i++)
		niza[i] = 1;
	mappirajProsti(niza, 10);
	printf("prosti broevi od 1 do %d se: ", 9);
	for (int i = 0; i < 10; i++) {
		if (niza[i] == 0)
			printf("%d, ", i);
	}
	printf("\n%d\n", ePalindrom("kalabalak", 9));
	return 0;

}
//1
int srednaTemperatura(int temps[], int size)
{
	int zbir = 0;
	for (int i = 0; i < size; i++)
		zbir += temps[i];
	return zbir / size;
}
//2
int mappirajProsti(int niza[],int size) {
	for (int i = 0; i < size; i++) {
		if (eProst(i)==1)
			niza[i] = 0;
	}
}

int eProst(int broj)
{
	if (broj < 2)
		return 0;
	for (int i = 2; i < broj; i++)
		if (broj % i == 0)
			return 0;
	return 1;
}
//3
int ePalindrom(char zbor[], int size) {
	
	int middle = size / 2;
	for (int i = 0; i <= middle; i++)
		if (zbor[i] != zbor[size - i -1])
			return 0;
	return 1;
}
//4 ne razbiram shto se bara tocno
//5
void selekciskoSortiranjeIterativno(int arr[], int size) {
	int j;
	int temp;
	int minIndex;
	for (int i = 0; i < size - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void selekciskoSortiranjeRekurzija(int arr[], int size,int start) {
	int minIndex = start;
	int temp;
	for (int i = start + 1; i < size;i++)
		if (arr[i]<arr[minIndex])
			minIndex = i;
	temp = arr[start];
	arr[start] = arr[minIndex];
	arr[minIndex] = temp;
	if (size - start > 1)
		selekciskoSortiranjeRekurzija(arr, size, start + 1);

}	

void printaj(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}
