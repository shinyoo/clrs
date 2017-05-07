void merge_sort(int a[], int l, int r)
{

	if(l < r){
		int mid = (l + r) / 2;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}


void merge(int a[], int l, int mid, int r)
{
	int i, j, k, la[mid-l+1], ra[r-mid];
	//TODO 也许可以用malloc()和strcpy()来实现快速的数组复制?
	//普通方法复制数组
	//mind the tricky index boundaries!!
	for(i = 0; i <= mid - l; i ++){
		la[i] = a[l + i];
	}
	for(j = 0; j < r - mid; j ++){
		ra[j] = a[j + mid + 1];
	}

	//合并左右数组到a中
	for(i = j = 0, k = l; k <= r; k ++){
		//mind the tricky index boundaries!!
		if(i <= mid - l && j < r - mid){
			if(la[i] < ra[j]){
				a[k] = la[i];
				i ++;
			}
			else{
				a[k] = ra[j];
				j ++;
			}
		}
		else if(i > mid - l){
			a[k] = ra[j];
			j ++;			
		}
		else{
			a[k] = la[i];
			i ++;			
		}
	}

}

	