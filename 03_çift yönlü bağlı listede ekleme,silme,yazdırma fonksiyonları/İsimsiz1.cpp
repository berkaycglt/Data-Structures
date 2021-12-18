#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int x;
	dugum*next;
	dugum*prev;
};
typedef dugum node;

void bastir(node*r){
	while(r!=NULL){ //yani ba�l� listemde eleman varsa
		printf("%d\n",r);
		r=r->next;
	}	
}
node*eklesirali(node*r,int x){
	if(r==NULL){ //linklist bo�sa
		r=(node*)malloc(sizeof(node)); //ilk kutuyu olu�turduk
		r->x=x;
		r->next=NULL;    
		r->prev=NULL;      //ilk kutunun previ nulld�r.
		return r;	
}
	else if(r->x>x){  //girilen de�erin ilk elemandan k���k olma durumu
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
		if(temp->next!=NULL){ //bu �art� yazmam�z�n nedeni eklenicek eleman sondaysa nexti null de�er i�erir bundan dolay� previ olmaz.e�er sonda de�ilse previni ba�la dedik.
			temp->next->prev=temp;  
		}
		return r;
		
	}
}

node *sil(node*r,int x){
	node*iter=r;
	node*temp;
	if(r->x==x){ //ba�tan silme
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
		if(iter->next==NULL){ //sona kadar gelip say�y� bulamad�ysa
			printf("say� bulunamad�");
		}
		else{
			temp=iter->next;
			iter->next=iter->next->next;
			free(temp);
			if(iter->next!=NULL){ //sondaki eleman�n previ olmuca��ndan bu �art� yazd�k
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
