#include <math.h>
#define MIN -32766


//plain solution for rod cutting
int cut_rod(int p[], int n) {
	int i, q;
	if (n == 0) {
		return 0;
	}
	q = MIN;
	for (i = 1; i <= n; i ++) {
		q = max(q, p[i] + cut_rod(p, n - i));
	}
	return q;
}


//DP with memoization (top -> bottom)
int cut_rod_memo(int p[], int n) {
	int r[n + 1], i;
	r[0] = 0;
	for (i = 1; i <= n; i ++) {
		r[i] = MIN;
	}
	return cut_rod_memo_aux(p, n, r);
}

int cut_rod_memo_aux(int p[], int n, int r[]) {
	int i, q;
	if (r[n] >= 0) {
		return r[n];
	}
	if (n == 0) {
		q = 0;
	}
	for (i = 1; i < n; i ++) {
		q = max(q, p[i] + cut_rod_memo_aux(p, n - i, r));
	}
	r[n] = q;
	return r[n];
}


int cut_rod_bottom_up(int p[], int n) {
	int i, j, q, r[n + 1];
	r[0] = 0;
	for (j = 1; j <= n; j ++) {
		q = MIN;
		for (i = 1; i <= j; i ++) {
			q = max(q, p[i] + r[j - i]);
		}
		r[j] = q;
	}
	return r[n];
}


struct cut_solution{
	int n;
	int *r, int *s;
};


struct cut_solution cut_rod_bottom_up_with_sol(int p[], int n) {
	int i, j, q, r[n + 1], s[n + 1];
	r[0] = 0;
	s[0] = 0;
	for (j = 1; j <= n; j ++) {
		q = MIN;
		for (i = 1; i <= j; i ++) {
			if (q < p[i] + r[j - i]) {
				q = r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	return (struct cut_solution) {.n = n, .r = &r, .s = &s};
}

