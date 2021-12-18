#include <stdlib.h>
#include <stdio.h>

struct n{
	int x;
	n*next;
};
typedef n node;

node*root=NULL; //global olarak tan�mlamal�y�z.

void bastir(node*r){
	while(r!=NULL){
		printf("%d\n",r->x);
		r=r->next;
	}
	
}
void enqueue(int x){ //linlistin sonuna eleman ekler.
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->x=x;
		root->next=NULL;
		
	}
	else{
		node*iter=root;
		while(iter->next!=NULL){
			iter=iter->next;
			
		}
		iter->next=(node*)malloc(sizeof(node));
		iter->next->x=x;
		iter->next->next=NULL;
		
	}
}

int dequeue(){ //linklistin ba��ndan eleman� siler ve d�nd�r�r
	if(root==NULL){//linlist bo�sa
		printf("linklist bo�1");
		return -1;
		
}
	else{
		node*temp=root;
		int rvalue=root->x; //silinecek de�eri tuttuk.
		root=root->next;
		free(temp);
		return rvalue;
	}
}


int main(){
	
	for(int i=0;i<20;i++){
		enqueue(i*10);
	}
	bastir(root);
	dequeue();
	bastir(root);
	
	
	
}
