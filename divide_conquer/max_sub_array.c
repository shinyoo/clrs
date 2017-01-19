/**
 * define a struct for return value
 */
typedef struct{
	int l, r, sum;
} array_info;

/**
 * find the max subarray which cross the middle index
 * @param  a the array
 * @param  l left index
 * @param  m middle index
 * @param  r right index
 * @return   the max cross subarray info
 */
array_info find_max_cross_array(int a[], int l, int m, int r){
	int sum, lsum, rsum, li, ri, i;

	for(i = m, sum = 0, lsum = a[m] - 1; i >= l; -- i){
		sum += a[i];
		if(sum > lsum){
			lsum = sum;
			li = i;
		}
	}

	for(i = m + 1, sum = 0, rsum = a[m+1] - 1; i <= r; ++ i){
		sum += a[i];
		if(sum > rsum){
			rsum = sum;
			ri = i;
		}
	}

	return (array_info) { 
		.l = li,
		.r = ri,
		.sum = lsum + rsum
	};
}


/**
 * find the maximum continuous subarray
 * @param  a array
 * @param  l left index
 * @param  r right index
 * @return   the max subarray info
 */
array_info find_max_subarray(int a[], int l, int r){
	if(r > l){
		//1. divide array into 2 parts
		int mid = (l + r) / 2;
		array_info L, R, M, tmp;
		//2. find each part's max_subarray
		L = find_max_subarray(a, l, mid);
		R = find_max_subarray(a, mid + 1, r);
		M = find_max_cross_array(a, l, mid, r);

		if(L.sum >= R.sum && L.sum >= M.sum){
			return L;
		}
		else if(R.sum >= L.sum && R.sum >= M.sum){
			return R;
		}
		else{
			return M;
		}


	}
	else{
		return (array_info) {
			.l = l,
			.r = r,
			.sum = a[l]
		};
	}

}