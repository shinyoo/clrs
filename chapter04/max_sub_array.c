typedef struct arr_info{
	int left;
	int right;
	int sum;
} arr_info;

arr_info find_max_subarray(int a[], int l, int r)
{
	arr_info res, left, right, cross;
	int mid = (l + r) / 2;

	//base case
	if (l == r) {
		res.left = l;
		res.right = r;
		res.sum = a[l];
		return res;
	}

	left = find_max_subarray(a, l, mid);
	right = find_max_subarray(a, mid + 1, r);
	cross = find_max_cross_subarray(a, l, r);

	if (left >= right && left >= cross) {
		return left;
	}
	else if (right >= left && right >= cross) {
		return right;
	}
	else {
		return cross;
	}
}


arr_info find_max_cross_subarray(int a[], int l, int r) {
	arr_info res;
	int mid = (l + r) / 2;
	int lsum=a[mid], rsum=a[mid + 1];
	int i, li, ri;

	for (i = mid - 1, sum = lsum, li = mid; i >= l; i --) {
		sum += a[i];
		if (sum >= lsum) {
			lsum += a[i];
			li = i;
		}
	}
	for (i = mid + 2, sum = rsum, ri = mid + 1; i <= r; i ++) {
		sum += a[i];
		if (sum >= rsum) {
			rsum = sum;
			ri = i;
		}
	}
	res.left = li;
	res.right = ri;
	res.sum = lsum + rsum;
	return res;

}