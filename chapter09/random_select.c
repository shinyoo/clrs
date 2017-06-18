int random_partition(int[] a, int l, int r) {
	int i, j, x, tmp;
	// randomize the pivot selection
	i = (int) ((r - l) * rand() + l);
	tmp = a[r];
	a[r] = a[i];
	a[i] = tmp;
	x = a[r];
	for (i = l - 1, j = l; j < r; j ++) {
		if (a[j] < x) {
			i ++;
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}

	a[r] = a[i + 1];
	a[i + 1] = x;

	return i + 1

}

int random_select(int[] a, int l, int r, int i) {
	int m, k;
	if (l == r) {
		return a[l];
	}

	m = random_partition(a, l, r);

	k = m - l + 1;    //include the pivot!
	if (i == k) {
		return a[m];
	} else if (i < k) {
		//note the "shrink" of the array
		return random_select(a, l, m - 1, i);
	} else {
		//note the "shrink" of the array
		return random_select(a, m + 1, r, i - k);
	}

}