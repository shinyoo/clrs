void binary_add(int a[], int b[], int c[], int n)
{
	int i = 0, carry = 0;
	int tmp;

	while(i < n){
		tmp = a[i] + b[i] + carry;
		c[i] = tmp % 2 ;
		carry = tmp / 2;
		i ++;
	}

	//last digit
	c[i] = carry;


}