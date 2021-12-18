//Arraylerde Stack,pop,push fonksiyonlarý

#include <stdlib.h>
#include <stdio.h>

int * dizi; //dinamik bir dizi oluþturduk.
int boyut=2;
int tepe=0;  //en üstteki elemaný tutar.

void push(int a){
	if(tepe>=boyut){
		int * dizi2=(int*)malloc(sizeof(int)*boyut*2);
		for(int i=0;i<=boyut;i++){
			dizi2[i]=dizi[i];
		}
		dizi=dizi2;
		boyut=boyut*2;
		dizi[tepe]=a; //elemanlarý diziye yerleþtirme
		tepe=tepe+1;
		}
	}
}
int pop(){ 
	if(tepe<=boyut/4){  //boyutu küçülttük
		int * dizi2=(int*)malloc(sizeof(int)*boyut/2)
		for(int i=0;i<boyut/2;i++){
			dizi2[i]=dizi[i];
		}
		dizi=dizi2;
		boyut=boyut/2;
		return dizi[--tepe]; //en son gireni yani en üstteki elemaný döndürdül.
		}
	}

