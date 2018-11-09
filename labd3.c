#include <stdio.h>
#include <math.h>
int main(void){
	int size;
	//запитую довжину множин
	printf("Input size of arrays: ");
	scanf("%d", &size);
	int array1[size]; 
	int array2[size];
	//зчитую множини
	int i;
	for (i=0; i<size; i++)
	{
		printf("1stArray[%d]=", i);
		scanf("%d", &array1[i]);
	}
	printf("\n");
	for (i=0; i<size; i++)
	{
		printf("2ndArray[%d]=", i);
		scanf("%d", &array2[i]);
	}
	//формую матрицю відношення
	int array3[size][size];
	int j;
	for (i=0; i<size; i++)
	{
		for (j=0; j<size; j++)
		{
			if ((5*array1[i]-array2[j])>3)
			{
				array3[i][j]=1;
			}
			else
			{
				array3[i][j]=0;
			}
		}
	}
	//виводжу матрицю 
	printf("The matrix is:\n");
	for (i=0; i<size; i++)
	{
		printf("(");
		for (j=0; j<size; j++)
		{
			printf("%d ", array3[i][j]);
		}
		printf("\b)\n");
	}
	//визначаю рефлексивність
	int refl=0;
	for (i=0; i<size; i++)
	{
		if (array3[i][i]==1)
		{
			refl++;
		}
	}
	if (refl==size)
	{
		printf("\nRelation is reflexive");
	}
	else if (refl<size && refl>0)
	{
		printf("\nRelation is not reflexive");
	}
	else if (refl==0)
	{
		printf("\nRelation is antireflexive");
	}
	//визначаю симетричність.
	int symm=0;
	for (i=0; i<size; i++)
	{
		for (j=0; j<size; j++)
		{
			if (array3[i][j]==array3[j][i])
			{
				symm++;
			}
		}
	}
	if (symm==pow(size,2))
	{
		printf("\nRelation is symmetric");
	}
	else if (symm<pow(size,2) && symm>size)
	{
		printf("\nRelation is not symmetric");
	}
	else if (symm==size)
	{
		printf("\nRelation is antisymmetric");
	}
	//визначаю транзитивність.
	int m=1,n=1,k;
	for (i=0; i<size; i++)
	{
		for (j=0; j<size; j++)
		{
			for (k=0; k<size; k++)
			{
				if (i!=j && j!=k && i!=k)
				{
				 if (array3[i][j]==1 && array3[j][k]==1 && array3[i][k]==0)
				 {
				 	m=0;
				 }
				 else if (array3[i][j]==1 && array3[j][k]==1 && array3[i][k]==1)
				 {
				 	n=0;
				 }
				}
			}
		}
	}
	if (m==1)
	{
		printf ("\nRelation is transitive");
	}
	else if (n==1)
	{
		printf ("\nRelation is antitranzitive");
	}
	else 
	{
		printf ("\nRelation is not tranzitive");
	}
	return 0;
}
