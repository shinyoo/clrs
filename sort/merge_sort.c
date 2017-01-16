/**
 * sub progress of merge_sort: merge 2 sorted arrays into one sorted array
 * @param a array
 * @param p array1's starting index
 * @param q array1's ending index(included)
 * @param r array2's ending index
 */
void merge(int a[], int p, int q, int r){
	int n1, n2, i, j, k;
	n1 = q - p + 1;			//p...q
	n2 = r - q;				//q+1...r


	// initialize 2 new arrays
	int L[n1], R[n2];
	for(i = 0; i < n1; ++ i){
		L[i] = a[p + i];
	}
	for(j = 0; j < n2; ++ j){
		R[j] = a[q + j + 1];
	}


	//start comparison in pair
	i = j = 0;	
	for(k = p; k <= r; k ++){
		if(i < n1 && j >= n2){ 
			a[k] = L[i ++];
		}
		else if(j < n2 && i >= n1){
			a[k] = R[j ++];
		}
		else if(L[i] < R[j]){
			a[k] = L[i ++];
		}
		else if(L[i] >= R[j]){
			a[k] = R[j ++];
		}
	}


}

/**
 * [merge_sort description]
 * @param a array to sort
 * @param i starting index for sort
 * @param j ending index for sort
 */
void merge_sort(int a[], int i, int j){
	
	if(j > i){
	//1. divide into 2 parts
		int key = (j + i) / 2;

	//2. sort each part
		merge_sort(a, i, key);
		merge_sort(a, key + 1, j);
   
	//3. merge sorted parts	
		merge(a, i, key, j);
	}

}
