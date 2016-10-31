#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int end,ct=0,i,n,j;
	scanf("%d",&n);
	long long int a[n];
	long long int max=-1;
	long long int k;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>max)
			max=a[i];
	}
	while(max)
	{
		ct++;
		max/=10;
	}
	int num[10][n];
	for(i=0;i<10;i++)
		for(j=0;j<n;j++)
			num[i][j]=0;
	int count[10];
	for(i=0;i<10;i++)
		count[i]=0;
	for(int y=0;y<ct;y++)
	{
		for(i=0;i<n;i++)
		{
			k=a[i];
			end=(k/(long long int)pow(10,y))%10;
			num[end][count[end]]=a[i];
			count[end]++;
		}
		k=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<count[i];j++)
				a[k++]=num[i][j];
		}
		for(i=0;i<10;i++)
			count[i]=0;
	}
	for(i=0;i<n;i++)
		printf("%lld ",a[i]);
	printf("\n");
	return 0;
} 
