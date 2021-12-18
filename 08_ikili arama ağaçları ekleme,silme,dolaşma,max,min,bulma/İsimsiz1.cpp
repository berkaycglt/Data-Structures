//ikili arama aðaçlarý
//ikili arama aðaçlarýnda silme,ekleme,dolaþma,bulma,max,min fonksiyonlarý

#include <stdlib.h>
#include <stdio.h>


struct n{
	int data;
	n * sag;
	n * sol;
};
typedef n node;

node * ekle(node*agac,int x){ //agaca veri ekleme fonksiyonu
	if(agac==NULL){  //agacýmýz boþsa ilk kutuyu oluþturduk
		node*root=(node*)malloc(sizeof(node));
		root->data=x;
		root->sag=NULL;
		root->sol=NULL;
		return root;
	}
	else if(agac->data<x){//büyükse saða ekleme iþlemini yaptým bu saða ekleme iþlemini sürekli yapýcaðým için fonksiyon içinde yaptým
		agac->sag=ekle(agac->sag,x); //burda agacýn saðýný bir agaç gibi düþündük
		return agac;
	}
	else{
		agac->sol=ekle(agac->sol,x); //agacýn solunu ayrý bir agaç gibi düþündük.
		return agac;
	}
}

void dolas(node*agac){ //yazdýrma fonksiyonu
	if(agac==NULL){//agaç boþ mu?
		return;
	}
	else{  //agacýn bölümlerini kademe kademe yazdýrýcaz
		dolas(agac->sag);  //burda infix þeklinde dolaþtýk istersek bu düzeni prefix veya posifix yapabiliriz.
		printf("%d",agac->data); //node orta deðer
		dolas(agac->sol); //sað çocuk
	} 
}

int bul(node*agac,int aranan){ //aranan deðeri bulma fonksiyonu
	if(agac==NULL){           //ilk baþta agac kapsamlý yaklaþtýk
		return -1;
	}
	if(agac->data==aranan){
		return 1;
	}
	if(bul(agac->sag,aranan)==1){   //sonra agacýn kýsýmlarýný agac gibi görüp bul fonksiyonunu kullandýk.
		return 1;	
	}
	if(bul(agac->sol,aranan)==1){
		return 1;
	}
	return -1;
}

int max(node*agac){ //max deðer bulma fonksiyonu
	while(agac->sag!=NULL){ //max deðer aðacýn en saðýndaki deðerdir
		agac=agac->sag;
	}
	return agac->data;
}
int min(node*agac){ //min deðer bulma fonksiyonu
	while(agac->sol!=NULL){ //min deðer aðacýn en solundaki deðerdir
		agac=agac->sol;
	}
	return agac->data;
}

node * sil(node*agac,int x){//SÝLME FONKSÝYONU
	if(agac==NULL){//AGAÇ BOÞSA
		return NULL;
	}
	if(agac->data==x){//aradýðým deðeri bulduysam
		//bu sýrada düðümün altýnda çocuk var mý yok mu ona bakmalýyýz.
		if(agac->sag==NULL && agac->sol==NULL){//SÝLMEK ÝSTEDÝÐÝM DÜÐÜM YAPRAK DÜÐÜMSE
			return NULL;
		}
		else if(agac->sag!=NULL){
			agac->data=min(agac->sag);
			agac->sag=sil(agac->sag,min(agac->sag));//çocuklu olan bir düðümde sað tarafýn min deðerini silinen deðer yerine koydum ve eski yerini sildim
			return agac;
		}
		else{
			agac->data=max(agac->sol); //özel durumdur agacýn saðýnda eleman yoksa agacýn solundaki max elemaný silincek deðer yerine koyar.
			agac->sol=sil(agac->sol,max(agac->sol)); //max deðerinin eski yerini sildik.
			return agac;
		}}
	if(agac->data<x){ //aradýðým deðeri bulamadýysam ve aradýðým deðerden büyükse saðýna bak
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
	printf("minimum deðer = %d\n",min(agac));
	agac=sil(agac,25);
	dolas(agac);

}
