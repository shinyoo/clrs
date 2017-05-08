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

//practice 2.1.2
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


//practice 2.3.4
void insertion_sort_recursive(int arr[], int n)
{
    if(n == 0){
        return;
    }
	int i, j, cur = arr[n - 1];
	//1. 对前n-1个元素排序
	insertion_sort_recursive(arr, n - 1);
	//2. 插入第n个元素到正确位置
	//2.1 从左往右的比较前n-1个元素, 找到位置
	for(i = 0, j = n - 1; i < n - 1; i ++){
		if(arr[i] > arr[n - 1]){
			j = i;
			break;
		}
	}
	//2.2 从该位置开始挪动其它数
	for(i = n - 1; i > j; i --)	{
		arr[i] = arr[i - 1];
	}
	arr[j] = cur;
}