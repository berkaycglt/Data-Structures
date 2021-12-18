#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int data;
	dugum*next;
};
typedef dugum node;

void top(node*r){  //stackin en üstündekini döndürme
	if(r==NULL){ 
		printf("stack boþtur");
	}
	printf("%d\n",r->data);
}

node*push(node*r,int x){ //stackin en üstüne eleman ekleme
	if(r==NULL){//linklist boþsa
		r=(node*)malloc(sizeof(node));
		r->data=x;
		r->next=NULL;
		return r;
	}
	node * iter=r;  //baþa ekleme
	node*temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=r;
	return temp;
	
}
node*pop(node*r){ //stackin en üstünden eleman silme
	if(r==NULL){  //STACK BOÞSA
		printf("Stack boþ");
		return r;
		
	}
	node*temp=r;  //BAÞTAN SÝLME
	r=r->next;
	free(temp);
	return r;
}


void bastir(node*r){
	while(r!=NULL){
		printf("%d\n",r->data);
		r=r->next;
	}
}
int main(){
	node*root=NULL;
	root=push(root,10);
	root=push(root,20);
	root=push(root,30);
	root=push(root,60);
	root=push(root,70);
	top(root);
	root=pop(root);
	bastir(root);

	


}
