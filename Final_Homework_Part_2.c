#include <stdio.h>
#include <stdlib.h>

void main() {
	int sum=0;
	int rowSize,columnSize,i,j,a,b;
	
	printf("Enter the size of Row and Column value of F Matrix: \n");
	scanf("%d%d",&rowSize,&columnSize);
	int F[rowSize][columnSize],V[3][3],G[rowSize][columnSize];
	//F and G Matrix
	for(i = 0; i < rowSize; i++){
		for(j = 0; j < rowSize; j++){
			F[i][j] = rand()%255;
			G[i][j] = F[i][j];
		}
	}
	printf("\n********************F Matrix********************\n");
	for(i = 0; i < rowSize; i++){
		for(j = 0; j < rowSize; j++){
			printf("[%d]\t", F[i][j]);
		}
		printf("\n\n");
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("Enter the V[%d][%d]: ", i, j);
			scanf("%d", &V[i][j]);
		}
	}
	printf("\n********************V Matrix********************\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("[%d]\t",V[i][j]);
		}
		printf("\n\n");
	}
	
	int midPointR,midPointC;
	
	for(midPointR = 0; midPointR < rowSize; midPointR++){
		for(midPointC = 0; midPointC < columnSize; midPointC++){
			for(i = midPointR - 1,a = 0; a < 3; a++,i++){
				for(j = midPointC - 1,b = 0; b < 3; b++,j++){
					if(i >= 0 && j >= 0 && i < rowSize && j < columnSize){
						sum = F[i][j] * V[a][b] + sum;
					}
				}
			}
			//for Part 1
			if(midPointR > 0 && midPointR < rowSize - 1 && midPointC > 0 && midPointC < columnSize - 1){			
				G[midPointR][midPointC] = sum;
			}
			sum = 0;		
		}
	}
	printf("\n********************G Matrix********************\n");
	for(i = 0; i < rowSize; i++){
		for(j = 0;j < columnSize; j++){
			printf("[%d]\t", G[i][j]);
		}
		printf("\n\n");
	}
}
