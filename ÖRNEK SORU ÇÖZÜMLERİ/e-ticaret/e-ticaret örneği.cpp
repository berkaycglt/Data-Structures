
#include<stdio.h>
#include<stdlib.h>
//linked list olacak.
int toplam_siparis_sayisi = 0;
struct siradakiler{
	int siparis_fiyati;//büyükten küçüðe doðru eklenecek. (büyük en baþa gelecek.)
	int eklenme_sirasi;//en fazla sayida eklenmiþ ve min 3 kere ertelenmiþ bir sipariþ kuyruktan önce çýkarýlacak
	struct siradakiler* next;
	
};
struct siradakiler* head = NULL;
struct siradakiler* siparis_al(struct siradakiler* sira,int siparis_fiyati);
void siparis_teslim_et(struct siradakiler* siradan_cikarilacak_kisi);
void kuyruktakiler(struct siradakiler* sira);


int main(){
	head = siparis_al(head, 10);
	head = siparis_al(head, 1000);
	head = siparis_al(head, 9);
	head = siparis_al(head, 1400);
	head = siparis_al(head, 16);	
	head = siparis_al(head, 4000);
	head = siparis_al(head, 15);
	head = siparis_al(head, 40000);
	
	kuyruktakiler(head);
}

struct siradakiler* siparis_al(struct siradakiler* sira,int siparis_fiyati){
	
	struct siradakiler* new_person = NULL;//eklenecek kiþi için yeni bir ptr oluþturduk
	new_person = (struct siradakiler*)malloc(sizeof(struct siradakiler));//hafýzadan yer ayýrdýk
	//kiþinin sýra numarasý  sipariþi vb gerekli bilgileri girdik
	new_person->siparis_fiyati = siparis_fiyati;
	new_person->eklenme_sirasi = ++toplam_siparis_sayisi;
	new_person->next = NULL;
	struct siradakiler* temp = sira;
	
	if(temp == NULL){//sira boþ ilk eleman eklenecek
		return new_person;
	}
	if(temp->siparis_fiyati < siparis_fiyati){//sirada bir kiþi var yeni eklenecek kiþinin sipariþi önceden sýrada bekleyenden daha fazla olduðu için öne eklenecek
		new_person->next = temp;
		temp = new_person;
		return temp;
	}
	
	while(temp->next != NULL && temp->next->siparis_fiyati > siparis_fiyati){
		temp = temp->next;
	}
	
	new_person->next = temp->next;
	temp->next = new_person;
	return sira;
}
	
		



void kuyruktakiler(struct siradakiler* sira){
	int i = 0;
	while(sira != NULL){
		printf("%d) kisi id = %d , siparis tutari = %d\n",++i,sira->eklenme_sirasi,sira->siparis_fiyati);
		sira = sira->next;
	}
}

