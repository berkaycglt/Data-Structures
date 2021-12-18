#include <stdlib.h>
#include <stdio.h>

struct dugum {  //burda düðümümðüzü ve içinde barýndýrdýklarýný tanýmladýk.
	int x;
	dugum*next;
};
typedef dugum node;


void bastir(node*r){ //baðlý listeyi ekrana yazdýrma fonksiyonu
	while(r!=NULL){    //eleman varsa
		printf("%d\n",r->x);
		r=r->next;
		}	
	}

	
void ekle(node*r,int x){    //tek yönlü baðlý listeye sona elemen ekleme fonksiyonu
	while(r->next!=NULL){  //bu þart çok önemli nulla gelmeden durmalýyýz
		r=r->next;
		
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;
	
}

node * eklesirali(node*r,int x){  //tek yönlü baðlý listeye sýralý eleman ekleme fonksiyonu
	if(r==NULL){ //eleman yoksa
		r=(node*)malloc(sizeof(node));
		r->x=x;
		r->next=NULL;
		return r;
	}
	else if(r->x>x) {//ilk elemandan küçükse þartý,root deðiþir,baþlangýçtan önceye ekleme
		node * temp;
		temp=(node*)malloc(sizeof(node));
		temp->x=x;
		temp->next=r;
		return temp;
}
	   //sona ekleme veya araya bir yere ekleme
	   //araya eklemedeki önemli þart araya eklenicek yerden bir önceki düðümde durmalýyýz.
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

node * sil(node*r,int x){ //tek yönlü baðlý listeden eleman silme fonksiyonu
	node*temp;
	node*iter=r;
	if(r->x=x){ //silmek istediðimiz eleman ilk deðerse
		temp=r;
		r=r->next;
		free(temp);
		return r;
	
	}
	while(iter->next!=NULL && iter->next->x!=x){  //sona gelene kadar ve aradýðým sayýyý bulana kadar git.
		iter=iter->next;
	}
	if(iter->next==NULL){         //silmek istediðimiz deðer baðlý listede yoksa
		printf("Sayý bulunamadý");
		return r;
	}
	else{           //aradaki deðeri silme iþlemi
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
