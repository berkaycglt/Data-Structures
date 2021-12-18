#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int x;
	dugum*next;
	dugum*prev;
};
typedef dugum node;

void bastir(node*r){
	while(r!=NULL){ //yani baðlý listemde eleman varsa
		printf("%d\n",r);
		r=r->next;
	}	
}
node*eklesirali(node*r,int x){
	if(r==NULL){ //linklist boþsa
		r=(node*)malloc(sizeof(node)); //ilk kutuyu oluþturduk
		r->x=x;
		r->next=NULL;    
		r->prev=NULL;      //ilk kutunun previ nulldýr.
		return r;	
}
	else if(r->x>x){  //girilen deðerin ilk elemandan küçük olma durumu
		node * temp=(node*)malloc(sizeof(node));
		temp->x=x;
		temp->next=r;
		r->prev=temp;
		temp->prev=NULL;
		return temp;
		
	}
	else{ //sona veya araya ekleme
		node*iter=r;
		while(iter->next!=NULL && iter->next->x<x){
			iter=iter->next;
		}
		node * temp=(node*)malloc(sizeof(node));
		temp->x=x;
		temp->next=iter->next;
		iter->next=temp;
		temp->prev=iter;
		if(temp->next!=NULL){ //bu þartý yazmamýzýn nedeni eklenicek eleman sondaysa nexti null deðer içerir bundan dolayý previ olmaz.eðer sonda deðilse previni baðla dedik.
			temp->next->prev=temp;  
		}
		return r;
		
	}
}

node *sil(node*r,int x){
	node*iter=r;
	node*temp;
	if(r->x==x){ //baþtan silme
		temp=r;
		r=r->next;
		free(temp);
		r->next->prev=NULL;
		return r;
	}
	else{
		while(iter->next!=NULL && iter->next->x!=x){ //sondan veya aradan silme
			iter=iter->next;
		}
		if(iter->next==NULL){ //sona kadar gelip sayýyý bulamadýysa
			printf("sayý bulunamadý");
		}
		else{
			temp=iter->next;
			iter->next=iter->next->next;
			free(temp);
			if(iter->next!=NULL){ //sondaki elemanýn previ olmucaðýndan bu þartý yazdýk
				iter->next->prev=iter;
				return r;
			}
			
		}
	}
}

int main(){
	node *root;
	root=NULL;
	root=eklesirali(root,10);
	root=eklesirali(root,20);
	root=eklesirali(root,100);
	root=eklesirali(root,0);
	root=eklesirali(root,1);
	root=eklesirali(root,140);
	root=eklesirali(root,130);
	bastir(root);
}
