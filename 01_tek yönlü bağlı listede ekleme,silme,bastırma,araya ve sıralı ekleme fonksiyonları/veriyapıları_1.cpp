#include <stdlib.h>
#include <stdio.h>

struct dugum {  //burda d���m�m��z� ve i�inde bar�nd�rd�klar�n� tan�mlad�k.
	int x;
	dugum*next;
};
typedef dugum node;


void bastir(node*r){ //ba�l� listeyi ekrana yazd�rma fonksiyonu
	while(r!=NULL){    //eleman varsa
		printf("%d\n",r->x);
		r=r->next;
		}	
	}

	
void ekle(node*r,int x){    //tek y�nl� ba�l� listeye sona elemen ekleme fonksiyonu
	while(r->next!=NULL){  //bu �art �ok �nemli nulla gelmeden durmal�y�z
		r=r->next;
		
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;
	
}

node * eklesirali(node*r,int x){  //tek y�nl� ba�l� listeye s�ral� eleman ekleme fonksiyonu
	if(r==NULL){ //eleman yoksa
		r=(node*)malloc(sizeof(node));
		r->x=x;
		r->next=NULL;
		return r;
	}
	else if(r->x>x) {//ilk elemandan k���kse �art�,root de�i�ir,ba�lang��tan �nceye ekleme
		node * temp;
		temp=(node*)malloc(sizeof(node));
		temp->x=x;
		temp->next=r;
		return temp;
}
	   //sona ekleme veya araya bir yere ekleme
	   //araya eklemedeki �nemli �art araya eklenicek yerden bir �nceki d���mde durmal�y�z.
	else{    
		node * iter=r;
		while(iter->next!=NULL && iter->next->x<x){
			iter=iter->next;
		}
		node * temp=(node*)malloc(sizeof(node));
		temp->next=iter->next;
		iter->next=temp;
		temp->x=x;
		return r;	
	}
						
	}

node * sil(node*r,int x){ //tek y�nl� ba�l� listeden eleman silme fonksiyonu
	node*temp;
	node*iter=r;
	if(r->x=x){ //silmek istedi�imiz eleman ilk de�erse
		temp=r;
		r=r->next;
		free(temp);
		return r;
	
	}
	while(iter->next!=NULL && iter->next->x!=x){  //sona gelene kadar ve arad���m say�y� bulana kadar git.
		iter=iter->next;
	}
	if(iter->next==NULL){         //silmek istedi�imiz de�er ba�l� listede yoksa
		printf("Say� bulunamad�");
		return r;
	}
	else{           //aradaki de�eri silme i�lemi
		temp=iter->next;
		iter->next=iter->next->next;
		free(temp);
		return r;
		}}

	
				
 int main(){
 	node *root;
 	root=NULL;
 	root=eklesirali(root,10);
 	root=eklesirali(root,50);
 	root=eklesirali(root,100);
    root=eklesirali(root,70);
    root=eklesirali(root,80);
    root=eklesirali(root,14);
    root=eklesirali(root,12);
    root=eklesirali(root,1);
	bastir(root);
	root=sil(root,1);
	bastir(root);
	ekle(root,111);
	bastir(root);
	
 }
