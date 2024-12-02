#include <stdio.h>
#include <stdlib.h>

int q2() {
  FILE *inp = fopen("./input1.txt", "r");
  if (inp == NULL) {
    return -1;
  }

  int lines = 0;
  char ch;

  while ((ch = fgetc(inp)) != EOF) {
    if (ch == '\n') {
      lines++;
    }
  }

  fseek(inp, 0, SEEK_SET);
  int *l1 = malloc(sizeof(int) * lines);
  int *l2 = malloc(sizeof(int) * lines);
  int max = 0;

  for (int i = 0; i < lines; i++) {
    fscanf(inp, "%d %d", &l1[i], &l2[i]);
    if (max < l1[i]) {
      max = l1[i];
    }
  }

  // horrible but dont want to create a map
  int *counter = calloc(max + 1, sizeof(int));
  for (int i = 0; i < lines; i++) {
    if (l2[i] <= max) {
      counter[l2[i]]++;
    }
  }
  int res = 0;
  for (int i = 0; i < lines; i++) {
    res += l1[i] * counter[l1[i]];
  }
  return res;
}

int main() {
  printf("%d\n", q2());
  return 0;
}
