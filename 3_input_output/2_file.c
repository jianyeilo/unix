#include <stdio.h>

int main(void)
{
    FILE *fp; /*fpはPointer、type はファイル*/
    int c;

    fp = fopen("sampl.txt", "r"); /*streamによるデータのPointerをfpに渡す */

    if (fp == NULL) {
    printf("ファイルを開けません\n");
    return 1;
    }
    while ((c = getc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);

    return 0;
}