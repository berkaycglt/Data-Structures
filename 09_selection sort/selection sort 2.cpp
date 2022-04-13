#include<stdlib.h>
#include<stdio.h>
#define MAX 50

void selectionsort(int arr[],int size){ //parametre olarak bir dizi ve dizinin boyutunu alýr.
	int i,j;
	int minimumindex;
	for(i=0;i<size;i++){
		minimumindex=i;
		for(j=i+1;j<size;j++){ //dizinin elemanlarýný karþýlaþtýrýcaz.
			if(arr[j]<arr[minimumindex]){
				minimumindex=j;
			}
			
		}
		int temp=arr[i];  //deðiþtirme iþlemi yaptýk yukardaki þarta uyarsa deðiþtirir uymazsa ayný kalýr.
		arr[i]=arr[minimumindex];
		arr[minimumindex]=temp;
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
	selectionsort(array,size);
	for(i=0;i<size;i++){
		printf("%d",array[i]);
	}
	return 0;
}

