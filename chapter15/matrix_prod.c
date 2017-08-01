#define MAX 32767 

struct array {
	int length, *array;
}

typedef struct array array;

struct array_pair {
	array *a, *b;
}

typedef struct array_pair array_pair;

array_pair matrix_chain_order(array *p) {
	int n = p->length - 1;
	int m[n][n], s[n][n];
	int i, l, j, k, q;
	for (i = 0; i <= n; i ++) {
		m[i][i] = 0
	}
	for (l = 2; l <= n; l ++) {	//l is the length of the chain
		for (i = 0; i <= n - l; i ++) {
			j = i + l - 1;
			m[i][j] = MAX;
			for (k = i; k < j; k ++) {
				q = m[i][k] + m[k + 1][j] + p->array[i - 1] * p->array[k] * p->array[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}

			}
		} 
	}

	return (array_pair) {.a = &m, .b = &s};

}