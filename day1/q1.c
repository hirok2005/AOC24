#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int q1() {
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

  for (int i = 0; i < lines; i++) {
    fscanf(inp, "%d %d", &l1[i], &l2[i]);
  }

  qsort(l1, lines, sizeof(int), comp);
  qsort(l2, lines, sizeof(int), comp);
  int res = 0;
  for (int i = 0; i < lines; i++) {
    res += abs(l1[i] - l2[i]);
  }
  return res;
}

int main() {
  printf("%d\n", q1());
  return 0;
}
