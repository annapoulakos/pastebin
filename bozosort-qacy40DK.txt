void swap(int &a[])
{
	int len = sizeof(a)/sizeof(a[0]);
	int i = rand() % len;
	int j = i; while(j==i) j = rand()%len;
	a[i] ^= a[j] ^= a[i] ^= a[j];
}

bool inOrder(int a[])
{
	int len = sizeof(a)/sizeof(a[0]);
	for(int i = 1, i < len; ++i)
		if (a[i-1]>a[i])
		{
			swap(a);
			return inOrder(a);
		}
	return true;
}
