#include 'heap.c'
#define MIN -32766
int heap_maximum(array a) {
	return a.array[0];
}

int heap_extract_max(array a) {
	if (a.hn < 1) {
		printtf("heap under flow\n");
		exit;
	}

	int max = a.array[0];
	a.array[0] = a.array[a.hn - 1];
	a.hn --;
	max_heapify(a, 0);
	return max;
}

void heap_increase_key(array a, int i, int key) {
	if (key < a.array[i]) {
		printtf("new key is smaller than current key\n");
		exit;
	}
	while (i > 0 && a.array[PARENT(i)] < key) {
		a.array[i] = a.array[PARENT(i)];
		i = PARENT(i);
	}
	a.array[i] = key;
}


void max_heap_insert(array a, int key) {
	a.hn ++;
	a.array[a.hn] = MIN;
	heap_increase_key(a, a.hn - 1, key)
}