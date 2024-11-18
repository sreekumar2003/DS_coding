#include <stdio.h>
void AUB(int a[10],int b[10]);
int find(int a[10],int b[10]);
int unionAB[20];
void main()
{
	int a[10]={1,2,3,4,5};
	int b[10]={6,7,8,9,10};
	int i,j,parent;
	
	printf("Set A\n\t");
	for(i=0;i<5;++i)
		printf("%d  ",a[i]);
	printf("\nSet B\n\t");
	for(i=0;i<5;++i)
		printf("%d  ",b[i]);
	printf("\nUnion of A and B\n\t");
	AUB(a,b);
	parent=find(a,b);
	if(parent==a[0])
		printf("Found in set A");
	else if(parent==b[0])
		printf("Found in set B");
	else
		printf("Not Found");

	
}

void AUB(int a[10],int b[10])
{
	int i,j;
	i=0;
	for(j=0;j<5;++j)
	{
		unionAB[i]=a[j];
		printf("%d  ",unionAB[i]);
		i++;
	}
	for(j=0;j<5;++j)
	{
		unionAB[i]=b[j];
		printf("%d  ",unionAB[i]);
		i++;
	}
}
int find(int a[10],int b[10])
{
	int parent=999,num,i;
	printf("\nEnter the number to be searched\n");
	scanf("%d",&num);
	for(i=0;i<5;++i)
	{
		if(a[i]==num)
		{
			parent=a[0];
		}
		else if(b[i]==num)
		{
			parent=b[0];
		}
	}
	return parent;
}
