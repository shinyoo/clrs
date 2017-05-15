int merge_sort_count(int a[], int l, int r)
{
	int count = 0;

	if(l < r){
		int mid = (l + r) / 2;
		count += merge_sort_count(a, l, mid);
		count += merge_sort_count(a, mid + 1, r);
		count += merge(a, l, mid, r);
	}
	return count;
}


int merge(int a[], int l, int mid, int r)
{
	int i, j, k, la[mid-l+1], ra[r-mid], count = 0;
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
			if(la[i] <= ra[j]){
				a[k] = la[i];
				i ++;
			}
			else{
				a[k] = ra[j];
				j ++;
				//因为在la中比i大的数(在i之后的数)也一定比当前的ra[j]大, 所以对于ra[j], 共有mid-l+1-i个inversions(在i之后的数加上i自身=mid - l + 1 - i)
				count += mid - l + 1 - i;
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
	return count;

}