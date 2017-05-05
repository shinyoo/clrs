#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}


void insertion_sort(int arr[], int n)
{
	int key;
	for(int i = 1, int j; i < n; i ++){
		k = arr[i];
		j = i - 1;
		while(j > -1 && a[j] > key){
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
	}
}

void insertion_sort_reverse(int arr[], int n)
{
	int key;
	for(int i = 1, int j; i < n; i ++){
		k = arr[i];
		j = i - 1;
		while(j > -1 && a[j] < key){
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
	}
}