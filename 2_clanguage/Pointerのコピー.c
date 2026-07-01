#include <stdio.h>
int Pointer(void);
int sum(int *p, int n);

int main(void)
{
  int a=0, b=0;
  int *p;  /*　pはpiontertype　　pが指すpointerの値*/
  p = &a; /* pにaのpointer格納 type is pointer */ 

  printf("%d,%d,%d\n",*p,a,b);
  Pointer();
  return 0;

}

int sum(int *p, int n)
{
    int s = 0;
    int i;

    for (i = 0; i < n; i++) {
        s += *(p + i);
    }

    return s;
}

int Pointer(void)
{
    int a[5] = {10, 20, 30, 40, 50};

    printf("a[0] = %d\n", a[0]);
    printf("*a = %d\n", *a);

    printf("a[2] = %d\n", a[2]);
    printf("*(a+2) = %d\n", *(a + 2));

    printf("sum = %d\n", sum(a, 5));

    return 0;
}

/*構造体
*/

struct Student
{
    char name[20];
    int age;
    double height;
};