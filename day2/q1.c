#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char BUFF_SIZE = 100;

int q1() {
  FILE *inp = fopen("./input1.txt", "r");
  if (inp == NULL) {
    return -1;
  }
  char buffer[BUFF_SIZE];
  int res = 0;
  while (fgets(buffer, BUFF_SIZE, inp) != NULL) {
    char *end;
    int n;
    int prev = -1;
    int inc = -1;
    int valid = 1;
    char *i = buffer;
    while (*i != '\n') {
      n = strtol(i, &end, 10);
      i = end;
      if (n == prev) {
        valid = 0;
        break;
      }
      if (prev == -1) {
        prev = n;
      } else {
        int diff = n - prev;
        if (inc == -1) {
          if (diff < 0) {
            inc = 0;
          } else {
            inc = 1;
          }
        } else {
          if ((inc && diff < 0) || (!inc && diff > 0)) {
            valid = 0;
            break;
          }
        }
        if (abs(diff) < 1 || abs(diff) > 3) {
          valid = 0;
          break;
        }

        prev = n;
      }
    }
    printf("%s > %d\n", buffer, valid);
    if (valid) {
      res++;
    }
  }
  return res;
}

int main() {
  printf("%d\n", q1());
  return 0;
}
