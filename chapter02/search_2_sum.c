#include "binary_search.c"
#include "merge_sort.c"


int binary_search(int a[], int l, int r, int v);
void merge_sort(int a[], int l, int r);
void merge(int a[], int l, int mid, int r);

// find if there are 2 numbers in a that sum up to v
int search_2_sum(int a[], int n, int v)
{
	int i, tmp;
	//theta(n*lgn)
	merge_sort(a, 0, n - 1);
	for(i = 0; i < n; i ++){
		//theta(lgn)
		tmp = binary_search(a, 0, n - 1, v - a[i]);
		if(tmp != -1 && tmp != i){
			return 1;
		}
	}
	return -1;
}