#include<stdlib.h>
#include<stdio.h>


void selectionSort(int dizi[], int dizi_eleman)
{
	for (int i = 0; i < dizi_eleman; i++)
	{
		int min = dizi[i], indis = i;
		for (int j = i; j < dizi_eleman; j++) //dizide iþlem görülen indisi dahil etme
		{
			if (dizi[j] < dizi[i] && dizi[j] < min) //dizinin elemaný seçilen elemandan VE min elemandanda küçükse
			{
				min = dizi[j]; //küçük elemaný min deðiþkenine aktar
				indis = j; //dizideki yeri(indis)
			}
		}
		int swap = dizi[i]; //seçilen elemaný swap deðiþkenine aktar
		dizi[i] = min; //min deðiþkenindeki elemaný dizideki yerine taþý
		dizi[indis] = swap; //swap deðiþkenindeki elemaný en küçük elemanýn bulunduðu indise taþý
	}
}

int main(void)
{
	int *dizi, eleman; //*dizi pointer kullanarak boyut alýnabilir
	printf("Kac eleman girilecek> ");
	scanf("%d", &eleman);
	dizi = (int*)malloc((eleman * sizeof(int))); //malloc ile diziyi yeniden boyutlandýrmak

	for (int i = 0; i < eleman; i++) //elemanlarý diziye aktarmak
	{
		printf("Dizinin %d.elamani=", i + 1);
		scanf("%d", &dizi[i]); //dizi eleman giriþi
	}
	printf("\n%d Elemanli Dizi SelectionSort Siralama: ", eleman);

	selectionSort(dizi, eleman);
	for (int i = 0; i < eleman; i++) printf("%d  ", dizi[i]); //dizi eleman yazdýrmak
	printf("\n\n");

	system("Pause");
	return 0;
}
