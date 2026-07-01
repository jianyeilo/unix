#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 1024

int get_line(char *s, int size)/*標準入力から1行読み込み、最後の改行 \n を削除して、文字列の長さを返す関数*/
{
  int len;

  if (fgets(s, size, stdin) == NULL) { /* stdinを一行読み込みlistにしsizeの大きさを返す　*/
    fprintf(stderr, "unexpected EOF.\n");
    exit(1);
  }
  len = strlen(s);
  if (len > 0 && s[len-1] == '\n'){
    s[--len] = '\0';
  }
  return len;
}

int main()
{
  char s1[STRSIZE], s2[STRSIZE], buf[2*STRSIZE+12];
  int len1, len2;

  len1 = get_line(s1, STRSIZE);
  len2 = get_line(s2, STRSIZE);
  printf("s1             = %s\n", s1);
  printf("s2             = %s\n", s2);
  printf("strlen(s1)     = %d\n", len1);
  printf("strlen(s2)     = %d\n", len2);
  printf("strcmp(s1, s2) = %d\n", strcmp(s1, s2));
  puts("*** strcpy(buf, s1) ***");
  strcpy(buf, s1);
  puts("*** strcat(buf, s2) ***");
  strcat(buf, s2);              /* `strcpy(buf+len1, s2);' is faster. */
  printf("buf            = %s\n", buf);
  puts("*** sprintf(buf, \"s1 = %s, s2 = %s\\n\", s1, s2) ***");
  sprintf(buf, "s1 = %s, s2 = %s\n", s1, s2);
  puts("*** fputs(buf, stdout) ***");
  fputs(buf, stdout);
  printf("atoi(s1)       = %d\n", atoi(s1));
  printf("atof(s2)       = %f\n", atof(s2));
  return 0;
}
