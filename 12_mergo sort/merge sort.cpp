#include<stdlib.h>
#include<stdio.h>

//böl ve birleþtir fonksiyonlarý yazýcaz böl fonksiyonunun içinde birleþtir fonksiyonu recursive olarak çalýþacak.

int a[]={7,1,5,3,2,4,8,0}
int b[8];

void bol(int bas,int  son){
	if(bas<son){
		int orta=(bas+son)/2; 
		bol(bas,orta);
		bol(orta+1,son);
		birlestir(bas,orta,son);
	
	//iki parçaya böldük baþtan ortaya kadar ve ortadan sona kadar.
	}
	
} 

void birlestir(int bas,int orta,int son){
	for(i=bas;i<=son;i++){
		b[i]=a[i];
	}
	i=bas;
	j=orta+1;
	k=bas;
	while(i<=orta && j<=son){
		if(b[i]<=b[j]){
			a[k++]=b[i++];
		}
		else{
			a[k++]=b[j++];
		}
	}
	while(i<=orta){
		a[k++]=b[i++];
	}
}

int main(){
	bol(0,7);
	for(int i=0;i<7;i++){
		printf("%d",a[i]);
	}
	return 0;
}
