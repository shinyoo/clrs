#define PARENT(i) (((i) - 1) / 2)
#define LEFT(i) (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)

typedef struct {
	int n;
	int[] array;
	int hn;
} array;

void max_heapify(array a, int i) {
	int l = LEFT(i);
	int r = RIGHT(i);
	int max, tmp;
	if (l <= a.hn && a.array[i] < a.array[l]) {
		max = l;
	}
	else {
		max = i;
	}

	if (r <= a.hn && a.array[max] < a.array[r]) {
		max = r;
	}

	if (max != i) {
		tmp = a.array[max];
		a.array[max] = a.array[i];
		a.array[i] = tmp;
		max_heapify(a, max);
	}
}


void build_max_heap(array a) {
	int i;
	a.hn = a.n;
	for (i = a.n / 2; i >= 0; i --) {
		max_heapify(a, i);
	}
}


void heap_sort(array a) {
	int i, tmp;
	build_max_heap(a);
	for (i = a.n; i >= 1; i --) {
		tmp = a.array[i];
		a.array[0] = a.array[i];
		a.hn --;
		max_heapify(a, 0);
	}
}