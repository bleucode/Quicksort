#include <stdlib.h>
#include <stdio.h>
#define MAX 20

void intercambio(int vector[],int i, int j);
void quicksort(int vector[],int izq, int der); 
void imprimeVector(int vector[],int elem);

int main(){
 	int vector[MAX]={0};
 	int numElem, i;
 	
 	printf("Cuantos elementos tiene el arreglo? ");
 	scanf("%d", &numElem);
 	
 	for(i=0; i<numElem; i++){
 		printf("\n Elemento ");
 		scanf("%d", &vector[i]);
 	}
 	
 	quicksort( vector, 0, numElem -1 );
 	imprimeVector( vector, numElem );
 	
 	return 0;
 }
 
void intercambio(int vector[],int i, int j){
	int aux;
	aux = vector[i];
	vector[i] = vector[j];
	vector[j] = aux; 

	
}

void quicksort(int vector[],int izq, int der){
	int i;
	int j;
	int pivote;
	i = izq;
	j = der;
	pivote = vector[(i+j)/2]; /*se obtiene el pivote*/
	
	while(i<=j){
		while( vector[i] < pivote ) {
			i++;
		}
		while(vector[j] > pivote ){
			j--;
		}
		if(i<=j){
			intercambio(vector, i, j);
			i++;
			j--;
		}
	}
	
	if(izq<j){
		quicksort(vector, izq, j);
	}
	if(i<der){
		quicksort(vector, i, der);
	}
}

void imprimeVector(int vector[],int elem){
	int i;
	printf("\n Vector ordenado\n");
	
	for(i=0; i<elem; i++){
		printf("[%d]", vector[i]);
	}
}
