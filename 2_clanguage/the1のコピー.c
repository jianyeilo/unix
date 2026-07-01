#include <stdio.h>
#define yy  222

int c = 10; /*全てのところに使える変数*/

int main(void) /*void 引数なし.  返り値の型  関数名  (引数の型)*/
{
    const double pi =3.14; /*定数*/
    printf("Hello orld\n"); 
    /*
    cc(clang) hello.c -o hello

    c言語のソースファイルhello.c を　コンパイルし　helloとして　出力(-o(out))
    
    */

    int age = 20; /*main の中*/

    {
        int t = 2; /*{}の中*/
    }

    printf("%dk\n",age);
    /* %d: int を入力
    */

    return 0;
}
