void counting_sort(int[] a, int[] b, int n, int k) {
	int c[k];
	int i;

	//init the temp array
	for (i = 0; i < k; i ++) {
		c[i] = 0;
	}

	// make c[x] contain the number of elements equal to x
	for (i = 0; i < n; i ++) {
		c[a[i]] = c[a[i]] + 1;
	}

	// make c[x] contain the number of elements less than or equal to x
	for (i = 1; i < k; i ++) {
		c[i] = c[i] + c[i - 1];
	}


	// !note the following loop i, in such order can the elements with same value still be in relatively correc order!
	for (i = n - 1; i > -1; i --) {
		b[c[a[i]]] = a[i];
		c[a[i]] --;
	}
}