#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//true if c is a tab or space, and not zero
int space_char(char c){
  if ((c != '\0' ) && c == ' ' | c == '\t'){
    return 1;
  }else{
    return 0;
}


//true if c not a tab or space, and not zero
int non_space_char(char c){
  if ((c != '\0') && c != " " | c != "\t"){
    return 1;
  }else{
    return 0;
}

//* to first non-space char in first word
char *word_start(char *str){
  int i = 0;
  while(space_char(str[i])){
    i++;
  }
  return &str[i];
}

//* to for space char after end of word
char *word_end(chaar *word){
  int i = 0;
  while(non_space_char(word[i])){
    i++;
  }
  return &word[i];
}

//the number of words in s
int count_words(char *s){
  int count = 0;
  int i = 0;
  while(s != word_end(s)){
    s = word_end(s);
    count++;
  }
  return count;
}

 char *copy_str(char *inStr, short len){
   char *outputString = malloc((len +1) * sizeof(char));
   int i = 0;
   while (i <= len){
     outputString[i] = inStr[i];
     i++;
   }
   return outputString;
 }

 char **tokenize(char *str){
   int index, len;
   int totalIndex = count_words(str);
   char **tokens = malloc((totalIndex + 1) *sizeof(char *));
   char *wordStart = word_start(str);
   char *wordEnd = word_end(str);

   for(i = 0; i < totalIndex; i++){
     tokens[i] = copy_str(wordStart, wordEnd-wordStart);
     wordStart = word_start(wordEnd);
     wordEnd = word_end(wordStart);
   }
   tokens[i] = 0;
   return tokens;
 }

 void print_tokens(char **tokens){
   int i = 0;
   while(tokens[i] != NULL){
     printf("%s\n", tokens[i]);
     index++;
   }
 }

 void free_tokens(char **tokens){
   int i = 0;
   while(tokens[i] != NULL){
     free(tokens[i]);
     i++;
   }
   free(tokens);
 }
