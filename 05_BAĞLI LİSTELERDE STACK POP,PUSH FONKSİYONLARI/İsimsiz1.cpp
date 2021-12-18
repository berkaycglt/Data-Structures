#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int data;
	dugum*next;
};
typedef dugum node;

void top(node*r){  //stackin en �st�ndekini d�nd�rme
	if(r==NULL){ 
		printf("stack bo�tur");
	}
	printf("%d\n",r->data);
}

node*push(node*r,int x){ //stackin en �st�ne eleman ekleme
	if(r==NULL){//linklist bo�sa
		r=(node*)malloc(sizeof(node));
		r->data=x;
		r->next=NULL;
		return r;
	}
	node * iter=r;  //ba�a ekleme
	node*temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=r;
	return temp;
	
}
node*pop(node*r){ //stackin en �st�nden eleman silme
	if(r==NULL){  //STACK BO�SA
		printf("Stack bo�");
		return r;
		
	}
	node*temp=r;  //BA�TAN S�LME
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
