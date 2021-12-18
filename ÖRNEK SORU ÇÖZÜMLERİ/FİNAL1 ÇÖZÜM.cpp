#include <stdlib.h>
#include <stdio.h>

struct n{
	int x;
	n*sa�;
	n*sol;
};
typedef n node;
void dolas(node*agac){
	if(agac==NULL){
		return;
	}
	else{
		dolas(agac->sol);
		printf("%d",agac->data);
		dolas(agac->sa�);
	}
}
node * ekle(node*agac,int x){
	if(agac==NULL){
		node*root=(node*)malloc(sizeof(node));
		root->x=x;
		root->sa�=NULL;
		root->sol=NULL;
		return root;
	}
	else if(agac->x>x){
		agac->sol=ekle(agac->sol,x);
		return agac;
	}
	else{
		agac->sa�=ekle(agac->sa�,x);
		return agac;
	}
}
int min(node*agac){
	while(agac->sol!=NULL	){
		agac=agac->sol;
	}
	return agac->data;
}
int max(node*agac){
	while(agac->sa�!=NULL){
		agac=agac->sa�;
	}
	return agac->data;
}
node * sil(node*agac,int x){
	if(agac==NULL){
		return NULL;
	}
	if(agac->data==x){
		if(agac->sa�==NULL && agac->sol==NULL){
			return NULL;
		}
		else if(agac->sa�!=NULL){
			agac->data=min(agac->sa�);
			agac->sa�=sil(agac->sa�,min(agac->sa�));
			return agac;
		}
		else{
			agac->data=max(agac->sol);
			agac->sol=sil(agac->sol,max(agac->sol));
			return agac;
		}
	}}

int main(){
	node*agac=NULL;
	agac=ekle(agac,44);
	agac=ekle(agac,33);
	agac=ekle(agac,22);
	agac=ekle(agac,26);
	agac=ekle(agac,24);
	agac=ekle(agac,11);
	agac=ekle(agac,1);
	dolas(agac);
	agac=sil(agac,24);
	agac=sil(agac,11);
	agac=sil(agac,1);
	printf("\n\n\n");
	dolas(agac);
	
	
	return 0;
}
