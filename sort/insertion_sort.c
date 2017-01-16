/**
 * @author zanxingyu
 *
 * insertion sort
 * @param a array
 * @param n array length
 */
void insertion_sort(int a[], int n){
	
	int i, j, cur;

	for(i = 1; i < n; ++ i){	//pointer from left to right
		cur = a[i];
		j = i - 1;

		while(j > -1 && a[j] > cur){	//pointer from right to left
			a[j + 1] = a[j];
			j --;
		}

		a[j + 1] = cur;
	}

}

