#include <stdio.h>
#include <stdlib.h>

int** allocateMemory(int n){
    int** a;
    a = (int**)malloc(n*sizeof(int*));
    int i;
    for(i = 0; i<n; i++){
        *(a+i)= (int*)malloc(n*sizeof(int));
    }
    return a;
}

void input(int **a, int n){
	int i,j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            scanf("%d",*(a+i)+j);
        }
    }
}

void output(int **a, int n){
	int i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
}

int** sumOfTwoMatrix(int **a, int **b, int n){
    int** c;
    c = allocateMemory(n);
    int i,j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            *(*(c+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);
        }
    }
    return c;
}

int** multiplyTwoMatrix(int **a, int **b, int n){
    int** c;
    c = allocateMemory(n);
    int i,j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            *(*(c+i)+j) = 0;
            int k = 0;
            while(k<n){
                *(*(c+i)+j) += (*(*(a+i)+k)) * (*(*(b+k)+j));
                k++;
            }
        }
    }
    return c;
}

void free_mem(int **a, int n){
	int i;
    for(i = 0; i<n; i++){
        free(a[i]);
    }
    free(a);
}

int main()
{
    int n;
    scanf("%d", &n);
    int **a, **b, **sum, **multiply;
    a = allocateMemory(n);
    b = allocateMemory(n);
    input(a, n);
    input(b, n);
    sum = sumOfTwoMatrix(a, b, n);
    output(sum, n);
    multiply = multiplyTwoMatrix(a, b, n);
    output(multiply, n);
    free_mem(a, n);
    free_mem(b, n);
    free_mem(sum, n);
    free_mem(multiply, n);
    return 0;
}
