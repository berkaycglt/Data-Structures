#include<stdlib.h>
#include<stdio.h>
#define MAX 50

void insertionsort(int arr[],int size){
	int i,j;
	int eleman;
	for(i=1;i<size;i++){
		eleman=arr[i];
		while(j>=0 && arr[j]>eleman){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=eleman;
		
	}

}

int main(){
	int array[MAX],size;
	int i;
	printf("kaç elemanlý");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		scanf("%d",&array[i]);
	}
	insertionsort(array,size);
	for(i=0;i<size;i++){
		printf("%d",array[i]);
	}
	return 0;
}

