#include <stdio.h>
#include <stdlib.h>
const int num_primes = 9592;

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
	//printf("\nThat's all %d primes less than %d!\n",count, k);
}

int store_primes_ln(int k,int prms[])
{
        int count=0;
        for (int i=2; i<=k; i++)
                if (is_prime(i)) prms[count++] = i;
}

long long fact(long long n,int prms[],int num_prms,int k)
{
	long long res = 1;
	int mi[num_prms];
	//printf("============%lli   %d  %d  ==== \n", n, prms[0], mi[0]);
	for (int i=0;i<num_prms;i++) mi[i]=0;

	for (int i=0;i<num_prms;i++)
	{
		while ((n % prms[i]) == 0) {n=n/prms[i]; mi[i]++; }
	}
 	for (int i=0; i<num_prms; i++)
	{
		if (mi[i]>=k)
		for (int j=0;j<mi[i];j++) {res=res*prms[i];}
		//if (mi[i]>0)
		//printf(" %d^%d * ",prms[i],mi[i]);
	}
	//printf(" \n");
	return res;
}


int main(void)
{
	int rows=0;
	long long n = 0;
	int k = 0;
	int prms[num_primes];
	store_primes_ln(100000,prms);
	scanf("%d", &rows);
	for(int i=0; i<rows; i++)
	{
		scanf("%lld%d", &n,&k);
		printf("%lld\n",fact(n,prms,num_primes,k));
	}

	return 0;
}
