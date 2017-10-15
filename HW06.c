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

struct node * insert_front (struct node *list, int data) {
  struct node *insert = (struct node *) malloc(sizeof(struct node));
  (*insert).num = data;
  (*insert).next = list;
  return insert;
}

struct node * free_list (struct node *list) {
  struct node *front = list;
  while (list) {
    struct node *remove = list;
    list = (*list).next;
    free(remove);
  }
  return front;
}

int main () {

  struct node *list = 0;
  int count = 5;
  while (count > -1) {
    list = insert_front(list, count * 10);
    count--;
  }

  printf("Printing the list\n");
  print_list(list);
  printf("Now freeing the list\n");
  free_list(list);
  printf("Printing again should cause problems\n");
  print_list(list);

  return 0;
}
