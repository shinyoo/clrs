void selection_sort(int a[], int n)
{
	int i = 0, j, k, min;

	while(i < n - 1){
		min = a[i];
		k = i;
		j = i + 1;
		while(j < n){
			if(a[j] < min){
				min = a[j];
				k = j;
			}
			j ++;
		}
		a[k] = a[i];
		a[i] = min;
		i ++;
	}
}
