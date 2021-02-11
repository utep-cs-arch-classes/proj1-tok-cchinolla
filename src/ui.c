#include <stdio.h>
#define LIMIT 100
char str[LIMIT];


int main(){
  // char str[100];
  printf("Enter a String or press ZERO to exit\n");
  int x = 1;
  int i = 0;
  while(x){
    char input;
    putchar('$');
    for(input; (input = getchar()) != '\n' && i < LIMIT; i++){
      if(input == '0'){
	x = 0;
	break;
      }
      str[i] = input;
      putchar(input);     
    }
      putchar('\n');
  }
}
