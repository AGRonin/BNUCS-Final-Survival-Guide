#include <stdio.h>
#include <stdlib.h>

int is_prime(int k)
{	int i=0;
	for (i=2; i<=k/2; i++)
	{ if (k%i==0) break;}
	if (i>k/2)  return 1;
	else return 0;
}

int list_primes_ln(int k)
{
	int count=0;
	for (int i=2; i<=k; i++)
		if (is_prime(i)) {count++; printf("%d ",i);}
	printf("\nThat's all %d primes less than %d!\n",count, k);
}

int store_primes_ln(int k,int prms[])
{
        int count=0;
        for (int i=2; i<=k; i++)
                if (is_prime(i)) prms[count++] = i;
}

int fact(int n,int prms[],int num_prms,int k)
{
	int res = 1;
	int mi[65];
	for (int i=0;i<65;i++) mi[i]=0;
	for (int i=0;i<65;i++)
	{
		while (n % prms[i]==0) {n=n/prms[i]; mi[i]++;}
	}
	for (int i=0; i<65; i++)
	{
		if (mi[i]>=k)
		for (int j=0;j<mi[i];j++) res=res*prms[i];
	}

	return res;
}


int main(void)
{
	int rows=0;
	int n = 2400;
	int k = 0;
	int prms[65];
	store_primes_ln(316,prms);
	scanf("%d", &rows);
	for(int i=0; i<rows; i++)
	{
		scanf("%d%d", &n,&k);
		printf("%d\n",fact(n,prms,65,k));
	}
	return 0;
}
