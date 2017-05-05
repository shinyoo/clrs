int linear_search(int a[], int n, int v)
{
    int i = 0;
    while(a[i] != v && i < n){
      i ++;
    }

    if(i == n){
      return -1;
    }

    return i;
}