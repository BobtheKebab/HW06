#include <stdio.h>
#include <stdlib.h>

struct node {
  int num;
  struct node *next;
};

void print_list (struct node *list) {
  int count = 0;
  while (list) {
    printf("%d : %d\n", count++, (*list).num);
    list = (*list).next;
  }
}

int main () {

  printf("boi\n");

  return 0;
}
