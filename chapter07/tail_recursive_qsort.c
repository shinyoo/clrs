void tail_recursive_qsort(int[] a, int l, int r) {
	while (l < r) {
		q = partition(a, l, r);
		tail_recursive_qsort(a, l, r - 1);
		l = r + 1;
	}
}


int partition(int[] a, int l, int r) {
	int x = a[r];
	int i, j, tmp;

	for (i = l - 1, j = l; j < r; j ++) {
		if (a[j] < x) {
			i ++;
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}
	//move pivot to its proper position
	a[r] = a[i + 1];
	a[i + 1] = x;
	return i + 1;
}