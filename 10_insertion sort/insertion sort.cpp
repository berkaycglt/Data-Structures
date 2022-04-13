#include <stdio.h>

int main()
{
  int n, dizi[100], x, y, t;

  printf("LUTFEN DIZI ELEMAN SAYISINI GIRINIZ\n");
  scanf("%d", &n);

  printf("%d ELEMANA AIT DEGERLERI GIRINIZ\n", n);

  for (x = 0; x < n; x++) {
    scanf("%d", &dizi[x]);
  }

  for (x = 1 ; x <= n - 1; x++) {
    y = x;

    while ( y > 0 && dizi[y] < dizi[y-1]) {
      t          = dizi[y];
      dizi[y]   = dizi[y-1];
      dizi[y-1] = t;

      y--;
    }
  }

  printf("ARTAN SIRAYA GORE LISTELEME:\n");

  for (x = 0; x <= n - 1; x++) {
    printf("%d\n", dizi[x]);
  }

  return 0;
}
