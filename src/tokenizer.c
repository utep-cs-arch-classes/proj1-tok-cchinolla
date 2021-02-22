#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//true if c is a tab or space, and not zero
int space_char(char c){
  if ((c != 0 ) && c == " " | c == "\t"){
    return true;
  }else{
    return false;
}


//true if c not a tab or space, and not zero
int non_space_char(char c){
  if ((c != 0) && c != " " | c != "\t"){
    return true;
  }else{
    return false;
}

//* to first non-space char in first word
char *word_start(char *str){
  int i = 0;
  while(non_space_char(word[i])){
    i++;
  }
}

//* to for space char after end of word
char *word_end(chaar *str){
  int i = 0;
  while(non_space_char(str[i])){
    i++;
  }
  return &str[i];
}

//the number of words in s
int count_words(char *str){
  int count = 0;
  int count2 = 0;
  while(*str){
    if(*str == '/t' || *str == ' ' || *str == '\n'){
      count 2 = 0;
    }else if(count2 == 0){
      count2 = 1;
      count++;
    }
    str++;
  }
  return count;
}
