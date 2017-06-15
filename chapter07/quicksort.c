void quicksort(int[] a, int l, int r) {
	int i;
	if (l < r) {
		i = partition(a, l, r);
		quicksort(a, l, i - 1);
		quicksort(a, i + 1, r);
	}
}


int partition(int[] a, int l, int r) {
	int i, j, x, tmp;
	x = a[r];   //randomize the selection of pivot to make a better distribution of input
	// for example
	// x = a[(int) ((r - l) * rand() + l)]
	i = l - 1;
	for (j = l; j < r; j ++) {
		if (a[j] <= x) {
			i ++;
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	a[r] = a[i + 1];
	a[i + 1] = x;
	return i + 1;
}