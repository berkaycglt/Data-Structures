//ikili arama a�a�lar�
//ikili arama a�a�lar�nda silme,ekleme,dola�ma,bulma,max,min fonksiyonlar�

#include <stdlib.h>
#include <stdio.h>


struct n{
	int data;
	n * sag;
	n * sol;
};
typedef n node;

node * ekle(node*agac,int x){ //agaca veri ekleme fonksiyonu
	if(agac==NULL){  //agac�m�z bo�sa ilk kutuyu olu�turduk
		node*root=(node*)malloc(sizeof(node));
		root->data=x;
		root->sag=NULL;
		root->sol=NULL;
		return root;
	}
	else if(agac->data<x){//b�y�kse sa�a ekleme i�lemini yapt�m bu sa�a ekleme i�lemini s�rekli yap�ca��m i�in fonksiyon i�inde yapt�m
		agac->sag=ekle(agac->sag,x); //burda agac�n sa��n� bir aga� gibi d���nd�k
		return agac;
	}
	else{
		agac->sol=ekle(agac->sol,x); //agac�n solunu ayr� bir aga� gibi d���nd�k.
		return agac;
	}
}

void dolas(node*agac){ //yazd�rma fonksiyonu
	if(agac==NULL){//aga� bo� mu?
		return;
	}
	else{  //agac�n b�l�mlerini kademe kademe yazd�r�caz
		dolas(agac->sag);  //burda infix �eklinde dola�t�k istersek bu d�zeni prefix veya posifix yapabiliriz.
		printf("%d",agac->data); //node orta de�er
		dolas(agac->sol); //sa� �ocuk
	} 
}

int bul(node*agac,int aranan){ //aranan de�eri bulma fonksiyonu
	if(agac==NULL){           //ilk ba�ta agac kapsaml� yakla�t�k
		return -1;
	}
	if(agac->data==aranan){
		return 1;
	}
	if(bul(agac->sag,aranan)==1){   //sonra agac�n k�s�mlar�n� agac gibi g�r�p bul fonksiyonunu kulland�k.
		return 1;	
	}
	if(bul(agac->sol,aranan)==1){
		return 1;
	}
	return -1;
}

int max(node*agac){ //max de�er bulma fonksiyonu
	while(agac->sag!=NULL){ //max de�er a�ac�n en sa��ndaki de�erdir
		agac=agac->sag;
	}
	return agac->data;
}
int min(node*agac){ //min de�er bulma fonksiyonu
	while(agac->sol!=NULL){ //min de�er a�ac�n en solundaki de�erdir
		agac=agac->sol;
	}
	return agac->data;
}

node * sil(node*agac,int x){//S�LME FONKS�YONU
	if(agac==NULL){//AGA� BO�SA
		return NULL;
	}
	if(agac->data==x){//arad���m de�eri bulduysam
		//bu s�rada d���m�n alt�nda �ocuk var m� yok mu ona bakmal�y�z.
		if(agac->sag==NULL && agac->sol==NULL){//S�LMEK �STED���M D���M YAPRAK D���MSE
			return NULL;
		}
		else if(agac->sag!=NULL){
			agac->data=min(agac->sag);
			agac->sag=sil(agac->sag,min(agac->sag));//�ocuklu olan bir d���mde sa� taraf�n min de�erini silinen de�er yerine koydum ve eski yerini sildim
			return agac;
		}
		else{
			agac->data=max(agac->sol); //�zel durumdur agac�n sa��nda eleman yoksa agac�n solundaki max eleman� silincek de�er yerine koyar.
			agac->sol=sil(agac->sol,max(agac->sol)); //max de�erinin eski yerini sildik.
			return agac;
		}}
	if(agac->data<x){ //arad���m de�eri bulamad�ysam ve arad���m de�erden b�y�kse sa��na bak
		agac->sag=sil(agac->sag,x);
		return agac;
		
	}
	else{
		agac->sol=sil(agac->sol,x);
		return agac;
	}
	}
		

int main()
{
	node*agac=NULL;
	agac=ekle(agac,12);
	agac=ekle(agac,14);
	agac=ekle(agac,2);
	agac=ekle(agac,8);
	agac=ekle(agac,25);
	dolas(agac);
	printf("\naradigimiz deger var mi? = %d\n",bul(agac,222));
	printf("max deger = %d\n",max(agac));
	printf("minimum de�er = %d\n",min(agac));
	agac=sil(agac,25);
	dolas(agac);

}
