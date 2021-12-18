#include <stdlib.h>
#include <stdio.h>

struct dugum {
	int x;
	dugum*next;
};
typedef dugum node;

void bastir(node*r){
	node*iter=r;
	printf("%d\n",iter->x);   //bunu dýþarda yapmamýzýn nedeni bir seferlik yapmasaydým alttaki döngüye hiç girmezdi
	iter=iter->next;        //çünkü iteri roota eþitledik.
	
	while(iter!=r){
		printf("%d\n",iter->x);
		iter=iter->next;
	}	
	 
}

void ekle(node*r,int x){
	node*iter=r;
	while(iter->next!=r){
		iter=iter->next;
	}
	iter->next=(node*)malloc(sizeof(node));
	iter->next->x=x;
	iter->next->next=r;
}

node* eklesirali(node*r,int x){
	node*iter=r;
	if(r==NULL){  //linklist boþsa
		r=(node*)malloc(sizeof(node));
		r->x=x;
		r->next=r; //buraya dikkat burda dairesel baðlý liste oluþturduk.
		return r;
	}
	else if(r->x>x){ //ilk elemanýn deðiþmesi girilen deðerin ilk elemandan küçük olma durumu
		node*temp=(node*)malloc(sizeof(node));
		temp->next=r;
		temp->x=x;
		node * iter=r;
		while(iter->next!=r){
			iter=iter->next;
		}
		iter->next=temp;
		return temp;

}
	else{ //araya ekleme
		node*iter=r;
		while(iter->next!=r && iter->next->x<x){
			iter=iter->next;
		}
		node*temp=(node*)malloc(sizeof(node));
		temp->next=iter->next;
		iter->next=temp;
		temp->x=x;
		return r;
	
	}      }

node*sil(node*r,int x){
	node*temp;
	node*iter=r;
	if(r->x==x){ //baþtan silme
	
		while(iter->next!=r){  
			iter=iter->next;
		}
		iter->next=r->next;
		free(r);
		return iter->next;}
	while(iter->next!=r && iter->next->x!=x){
		iter=iter->next;
	}
	if(iter->next==r){ //sayý bulunamama durumu
		printf("sayý bulunamadý");
		return r;
	}
	else{//aradan eleman silme durumu
		temp=iter->next;
		iter->next=iter->next->next;
		free(temp);
		return r;
	}	
}

int main(){
	node *root;
	root=NULL;
	root=eklesirali(root,10);
	root=eklesirali(root,100);
	root=eklesirali(root,1);
	root=eklesirali(root,150);
	root=eklesirali(root,170);
	root=eklesirali(root,160);
	bastir(root);
	ekle(root,20);
	bastir(root);
	root=sil(root,1);
	root=sil(root,150);
	bastir(root);		
	
}
