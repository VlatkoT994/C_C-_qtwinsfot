#include<stdio.h>
void sort(int arr[], int size);
float getMedian(int arr[], int size);
void print(int arr[], int size);
float getAvg(int arr[], int size);
void histogram(const int arr[], int size);
int main() {
	float median;
	float avg;
	int arr[] = { 2,3,1,5,1,2,6,5,1,12,1,12,1,3 };
	sort(arr, 14);
	print(arr, 14);
	median = getMedian(arr, 14);
	avg = getAvg(arr, 14);
	printf(" \n median is: %f \n", median);
	printf("\n average is %f \n", avg);
	histogram(arr, 14);
	return 0;
}
void sort(int arr[], int size) {
	int temp;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
float getMedian(int arr[], int size) {
	if (size % 2 == 0)
		return (float)(arr[size / 2] + arr[size / 2 - 1 ]) / 2;
	return (float)arr[size / 2];
}
float getAvg(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) 
		sum += arr[i];
	return (float)sum / size;
}
void histogram(int arr[], int size) {
	int current = -1;
	printf("%3s%15s", "Vrednost", "Histogram");
	for (int i = 0; i < size; i++) {
		if (arr[i] != current) {
			current = arr[i];
			printf("\n%3d%15c", current,'*');
		}
		else
		{
			printf("%c", '*');
		}
	}
}
void print(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}