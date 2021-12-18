
#include <stdlib.h>
#include <stdio.h>

int * dizi=NULL;
int sira=0,sirabasi=0,boyut=2;

void enque(int x){ //ekleme fonksiyonu
	
	if(dizi==NULL){//D�Z� BO�SA
		dizi=(int*)malloc(sizeof(int)*2);
		}
	if(sira>=boyut){ //e�er dizi dolduysa
		boyut*=2;
		int * dizi2=(int*)malloc(sizeof(int)*boyut); //eski dizinin 2 kat� kadar b�y�kl�kte dizi olu�turduk.
		for(int i=0;i=boyut/2;i++){ //eski dizideki elemanlar boyutun yar�s� kadar oldu�undan 
			dizi2[i]=dizi[i];
	}
		free(dizi);
		dizi=dizi2;
		
		}                  
	dizi[sira]=x;
	sira=sira+1;
		
		}
		
int deque(){ //silme i�lemi kuyruktaki ilk eleman� siler
	if(sira==sirabasi){  //kuyruk bo�sa
		printf("kuyruk bo�");
		return -1;
		}
	
	if(sira-sirabasi<=boyut/4){//diziyi k���ltme i�lemi sira-siraba�� bize eleman say�s�n� verir
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

void toparla(){ //kuyru�un ba��ndaki elaman silindi�inden kuyru�un ba��nda bo�luk olu�ur bu bo�lu�a geride kalan elemanlar� kayd�rma fonksiyonudur.
	
	if(sirabasi==0){
		return;//bir�ey d�nd�rme
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
	
	
	
	


