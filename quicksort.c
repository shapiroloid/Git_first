#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insert_automatic(int vet[], int n);
void quickSort( int vet[], int , int );
int partition( int *vet, int , int );

int main(){
	int x, i, *vet, qtd;
	printf("Enter the size of the vector\n");
	scanf("%d", &qtd);
	vet=(int *)calloc(qtd, sizeof(int));
	if (vet == NULL){
		printf("Unallocated memory space\n");
	}
	insert_automatic(vet,qtd);

	quickSort(vet, 0, qtd);
	system("cls");

	for (i=0; i<qtd; i++){
		printf(" %d", vet[i]);
		printf("\n");
	}
	free(vet);
}
//insert_automatic - generates values ​​for the array
void insert_automatic(int vet[], int n){
	int i, j=0, x;
	srand(time(NULL));
    for(i=0; i<n; i++){
    	vet[i] = rand()%n;
	}
}
//quickSort - partitions the array into two parts
//and we have the position of the pivo within the array
//and then we call quickSort recursively
void quickSort( int *vet, int esq, int qtd ){
   int pivot;
   if (esq < qtd){
      pivot = partition(vet, esq, qtd);
      quickSort( vet, esq, pivot);
      quickSort(vet, pivot+1, qtd);
   }
}

int partition( int *A, int esq, int qtd ){
   int x,i,j,aux;
   x = A[esq];
   i = esq - 1;
   j = qtd + 1;
   while(i < j){
       do {
	   	j--; 
	   }while(A[j] > x );
      do {
	   	i++; 
	   }while(A[i] < x );
      
      if (i < j){
         aux = A[i];
         A[i] = A[j];
         A[j] = aux;
      }else{
         return j;
      }  	
   }
}