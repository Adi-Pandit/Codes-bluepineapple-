#include<stdio.h>

void MatrixMultiplication(int Am, int An, int Bm, int Bn, int MatrixA[][An], int MatrixB[][Bn], int ExpectedResult[Am][Bn])
{
	if(An==Bm)
	{
		int i,j,k;
		int Mul[Am][Bn];

		printf("\nTest Case : ");
		printf("\nMatrix A:\n");
		for(i=0; i<Am; i++)
		{
			for(j=0; j<An; j++)
			{
				printf("%d ",MatrixA[i][j]);
			}
			printf("\n");
		}

		printf("\nMatrix B:\n");
		for(i=0; i<Bm; i++)
		{
			for(j=0; j<Bn; j++)
			{
				printf("%d ",MatrixB[i][j]);
			}
			printf("\n");
		}

		for(i=0; i<Am; i++)
		{
			for(j=0; j<An; j++)
			{
				Mul[i][j] = 0;
				for(k=0; k<Bn; k++)
				{
					Mul[i][j] += MatrixA[i][k]*MatrixB[k][j]; 
				}
			}
		}

		printf("\nMatrix Multiplication:\n");
		for(i=0; i<Am; i++)
		{
			for(j=0; j<Bn; j++)
			{
				printf("%d ",Mul[i][j]);
				//printf("%d ",ExpectedResult[i][j]);
			}
			printf("\n");
		}

		int flag=0;
		for(i=0; i<Am; i++)
		{
			for(j=0; j<Bn; j++)
			{
				if(Mul[i][j]!=ExpectedResult[i][j])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("\nTest Case Successful\n");
		else	
			printf("\nTest Case Unsuccessful\n");
	}
	else
	{
		printf("Matrix multiplication is not possible");
	}
}

/*void MatrixMultiplication(int Am, int An, int Bm, int Bn, int MatrixA[][An], int MatrixB[][Bn], int ExpectedResult[Am][Bn])
{
	int i,j;
	
	MatrixMultiplication(Am,An,Bm,Bn,MatrixA,MatrixB)
}*/

int main()
{
	int i,j,k;

	for(k=2; k<=4; k++)
	{
		int MatrixA[k][k];
		int MatrixB[k][k];
		//int ExpectedResult[k][k];
		for(i=0; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				MatrixA[i][j]=i+j+1;
			}
		}
		for(i=0; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				MatrixB[i][j]=i+j+2;
			}
		}
		if(k==2)
		{
			int ExpectedResult1[2][2] = {{8,11},{13,18}};
			MatrixMultiplication(k, k, k, k, MatrixA, MatrixB, ExpectedResult1);
		}
		else if(k==3)
		{
			int ExpectedResult2[3][3] = {{20,26,32},{29,38,47},{38,50,62}};
			MatrixMultiplication(k, k, k, k, MatrixA, MatrixB, ExpectedResult2);
		}
		else if(k==4)
		{
			int ExpectedResult3[4][4] = {{40,50,60,70},{54,68,82,96},{68,86,104,122},{82,104,126,148}};
			MatrixMultiplication(k, k, k, k, MatrixA, MatrixB, ExpectedResult3);
		}
	}
}

