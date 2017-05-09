//practice 2.3.5
int binary_search(int a[], int l, int r, int v)
{
	if(l > r){
		return -1;
	}

	int mid = (l + r) / 2;

	if(v == a[mid]){
		return mid;
	}
	if(v < a[mid]){
		return binary_search(a, l, mid - 1, v);
	}
	else{
		return binary_search(a, mid + 1, r, v);
	}

}