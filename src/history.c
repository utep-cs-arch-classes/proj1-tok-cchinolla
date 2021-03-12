#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

