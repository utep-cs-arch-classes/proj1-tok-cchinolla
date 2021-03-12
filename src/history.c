#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  Item *item = malloc(sizeof(Item));
  Item *temp = list->root;

  item->str = str;
  item->next = NULL;
  int count = 0;

  if(list->root == NULL){
    item->id = count;
    list->root = item;
  }else{
    count = 1;
    while (temp->next != NULL){
      count++;
      temp = temp->next;
    }
    temp->next = item;
    item->id = count;
  }
}

char *get_history(List *list, int id){
  if(list->root == NULL){
    printf("list in empty");
  }else{
    Item *current = list-.root;
    while(current->next != NULL){
      if(current->id == id){
	return current->str;
      }
      current = current->next;
    }
  }
}

