
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  int c;
/*getchar: inputがosーstream-getcharによってintに 、１文字ずつwhileを*/
  while ((c = getchar()) != EOF){
    if (isupper(c)){
      putchar(tolower(c));
    } else {
      putchar(toupper(c));
    }
  }
  exit(0);
}
