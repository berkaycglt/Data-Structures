#include<stdlib.h>
#include<stdio.h>


void selectionSort(int dizi[], int dizi_eleman)
{
	for (int i = 0; i < dizi_eleman; i++)
	{
		int min = dizi[i], indis = i;
		for (int j = i; j < dizi_eleman; j++) //dizide i�lem g�r�len indisi dahil etme
		{
			if (dizi[j] < dizi[i] && dizi[j] < min) //dizinin eleman� se�ilen elemandan VE min elemandanda k���kse
			{
				min = dizi[j]; //k���k eleman� min de�i�kenine aktar
				indis = j; //dizideki yeri(indis)
			}
		}
		int swap = dizi[i]; //se�ilen eleman� swap de�i�kenine aktar
		dizi[i] = min; //min de�i�kenindeki eleman� dizideki yerine ta��
		dizi[indis] = swap; //swap de�i�kenindeki eleman� en k���k eleman�n bulundu�u indise ta��
	}
}

int main(void)
{
	int *dizi, eleman; //*dizi pointer kullanarak boyut al�nabilir
	printf("Kac eleman girilecek> ");
	scanf("%d", &eleman);
	dizi = (int*)malloc((eleman * sizeof(int))); //malloc ile diziyi yeniden boyutland�rmak

	for (int i = 0; i < eleman; i++) //elemanlar� diziye aktarmak
	{
		printf("Dizinin %d.elamani=", i + 1);
		scanf("%d", &dizi[i]); //dizi eleman giri�i
	}
	printf("\n%d Elemanli Dizi SelectionSort Siralama: ", eleman);

	selectionSort(dizi, eleman);
	for (int i = 0; i < eleman; i++) printf("%d  ", dizi[i]); //dizi eleman yazd�rmak
	printf("\n\n");

	system("Pause");
	return 0;
}
