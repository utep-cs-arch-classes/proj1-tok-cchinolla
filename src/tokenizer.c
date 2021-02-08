#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define true 1
#define false 0


/*Return true (non-zero)  if c is a whitespace character ('\t' or ' ').
  Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t'|| c == '\n'){//if theres a space, tab, or new line
    return true;
  }
  else{//if its a character
       return false;
       }
}  
 

/* Return true (non-zero) if c is a non-whitespace character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c == '\t' || c == ' ' || c == '\n'){//if theres a space, tab, or new line
    return false;
  }
  else{//if its a character
    return true;
  }
}
/*Returns a pointer to the first character of the next space-separated word in
  zero-terminated str. Return a sero pointer if str does not contain any words. */
  char  *word_start(char *str){
    //while its a space keep going
    int i = 0;
    while(space_char(str[i])){
      i++;//increment i
      }
      //if not then return its index as a pointer
      return &str[i];
  }


/*Returns a pointer terminator char following *word*/
    char *word_terminator(char *word){
      int i = 0;
      while(non_space_char(word[i])){//while theres a non space charkeep going
	i++;
      }
      //once space is found then return its index
	return &word[i];
      }

/*Counts the number of words in the string argument. */
      int count_words(char *str){
   
	int count = 0;
	int count2 = 0;
	while(*str){
	  if(*str == '\t' || *str == ' ' || *str == '\n'){
	    count2 = 0;
	  }else if(count2 == 0){
	    count2 = 1;
	    count++;
	  }
	  str++;
	}
	return count;
      }

/*Returns a freshly allocated new zero-terminated string
  containing <len> chars from <inStr> */
      char *copy_str(char *inStr, short len){
	char *outStr = malloc((len + 1) * sizeof(char));
	int i = 0;
       
       	while(i<=len){
	  *(outStr+i) = *(inStr+i);
	  // outStr[i] = inStr[i];
         i++;
       	}
	return outStr;
      }

char **tokenize(char *str){
        int totalNumWords = count_words(str);
	char **tokens = malloc((totalNumWords+1) * sizeof(char *));
	char *startWord = word_start(str);
	char *wordTerm = word_terminator(str);
	int i;
	for(i =0; i<totalNumWords; i++){
	  tokens[i] = copy_str(startWord, wordTerm-startWord);
	  startWord = word_start(wordTerm);
	  wordTerm = word_terminator(startWord);
	}
	tokens[i] = NULL;
	return tokens;
      }
    


/*Prints all tokens. */
 void print_tokens(char **tokens){
   int i =0;
   while(tokens[i] != NULL){
     printf("%s\n", tokens[i]);
     i++;
   }
 }


/* Frees all tokens and the vector coontaining themxxx. */
 void free_tokens(char **tokens){
   int i = 0;
   for(i =0; tokens[i] != 0; i++){
     free(tokens[i]);
   }
   free(tokens);
 }


