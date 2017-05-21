//practice 4.1.2
typedef struct arr_info{
	int left;
	int right;
	int sum;
} arr_info;

arr_info find_max_subarray_naive(int a[], int n) {
	arr_info res;
	int sum, tmp_sum, i, j, l, r;

/**
 *  inner invariant loop provides the fact/outer invariant loop that: before the loop start, sum, l, r correspond to the max subarray from a cluster of a[0~n-1] ..... a[i-1~n]
 *  1. init: before the loop, sum=a[i], l=r=i and implicitly we hava j=i=0(try move the line 25 init to 16, because they're equal!) so sum is the max from a empty cluster a[0~0]...a[-1~j]
 *  2. maintain: we have premise that: sum,l,r correspond to max from cluster of a[0~j]..a[i-1~j] before line 26, and after the inner loop, sum,l,r correspond to max subarray from cluster of a[0~j]..a[i~j], and with i ++, before next loop we still have the invariant loop
 *  3. termination: when loop ends, sum is the max subarray from cluster of a[0~n-1]...a[n-1~n-1], every possible combination has been checked, so now sum, l, r correspond to max subarray of a!
 */
	for (l = i = 0, sum = a[i]; i < n; i ++, l = i) {
		tmp_sum = 0;
		/*
		*  invariant loop: before the loop, sum,i,r correspond to the max subarray in a[i~j], tmp_sum corresponds to the cumulative sum from a[i] to a[j-1]
		*  1. init: before the loop a[i~j]=a[i~i] and sum=a[i] l=r=i, tmp_sum=a[i] is the cumulative sum from a[i] to a[j-1]
		*  2. maintain: tmp_sum was a[i] to a[j-1] now plus a[j] becomes a[i]~a[j] sum; and 20-22 make sure sum, r, l is the max from a[i~j]
		*  3. termination: when the loop ends, sum, l, r correspond to the max subarray from a[i~n]
		*
		*/
		for (r = j = i; j < n; j ++) {
			tmp_sum += a[j];
			if (tmp_sum > sum) {
				sum = tmp_sum;
				l = i;
				r = j;
			}
		}
	}
}