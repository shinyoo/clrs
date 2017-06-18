// find the maximum element in an array
int find_max(int[] a, int n) {
	int max = a[0], i = 0;
	for (i = 1; i < n; i ++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}



typedef struct {
	int min, max;
} max_min;

// find max and min simultaneously
max_min find_max_min(int[] a, int n) {
	int min, max, i, cur_min, cur_max;
	//compare 2 one time
	if (n % 2) {
		min = max = a[0];
		i = 1;
	} else {
		min = a[0] > a[1]? a[1]: a[0];
		max = min == a[0]? a[1]: a[0];
		i = 3;
	}

	for (; i < n - 1; i ++) {
		if (a[i] > a[i + 1]) {
			cur_max = a[i];
			cur_min = a[i + 1];
		}
		if (cur_min < min) {
			min = cur_min;
		}
		if (cur_max > max) {
			max = cur_max;
		}
	}

}