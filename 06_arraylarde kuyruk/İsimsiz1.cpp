
#include <stdlib.h>
#include <stdio.h>

int * dizi=NULL;
int sira=0,sirabasi=0,boyut=2;

void enque(int x){ //ekleme fonksiyonu
	
	if(dizi==NULL){//DÝZÝ BOÞSA
		dizi=(int*)malloc(sizeof(int)*2);
		}
	if(sira>=boyut){ //eðer dizi dolduysa
		boyut*=2;
		int * dizi2=(int*)malloc(sizeof(int)*boyut); //eski dizinin 2 katý kadar büyüklükte dizi oluþturduk.
		for(int i=0;i=boyut/2;i++){ //eski dizideki elemanlar boyutun yarýsý kadar olduðundan 
			dizi2[i]=dizi[i];
	}
		free(dizi);
		dizi=dizi2;
		
		}                  
	dizi[sira]=x;
	sira=sira+1;
		
		}
		
int deque(){ //silme iþlemi kuyruktaki ilk elemaný siler
	if(sira==sirabasi){  //kuyruk boþsa
		printf("kuyruk boþ");
		return -1;
		}
	
	if(sira-sirabasi<=boyut/4){//diziyi küçültme iþlemi sira-sirabaþý bize eleman sayýsýný verir
		int*dizi2=(int*)malloc(sizeof(int)*boyut/2);
		for(int i=0;i<sira-sirabasi;i++){
			dizi2[i]=dizi[sirabasi+i];
		}
		sirabasi=0;
		sira=sira-sirabasi;
		boyut=boyut/2;
		free(dizi);
		dizi=dizi2;
		 
	
	}
	return dizi[sirabasi++];
	
	
	}

void toparla(){ //kuyruðun baþýndaki elaman silindiðinden kuyruðun baþýnda boþluk oluþur bu boþluða geride kalan elemanlarý kaydýrma fonksiyonudur.
	
	if(sirabasi==0){
		return;//birþey döndürme
	}
	else{
		for(int i=0;i<boyut;i++){
			dizi[i]=dizi[i+sirabasi];
		}
		sira=sira-sirabasi;
		sirabasi=0;
	}
}

int main(){
	enque(10);
	enque(20);
	enque(30);
	enque(40);
	deque();
}
	
	
	
	


