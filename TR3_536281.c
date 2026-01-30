#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int x[200] = {0};
  int y, i;

  while (1) {
    printf("Digite um número (0 a 5000): ");
    scanf("%d", &y);

    if (y == -1) break;

    x[y/32] = x[y/32] | (1 << (y % 32));
  }

  for (i = 0; i <= 5000; i++) {
    if ((x[i/32] >> i) & 1) {
      printf("%d\n", i);
    }
  }

  return 0;
}
