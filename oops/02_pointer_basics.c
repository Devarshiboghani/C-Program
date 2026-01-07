#include <stdio.h>

int main()
{
    int a = 10; // Regular variable
    int *p;     // Pointer variable

    p = &a; // p points to a (stores address of a)

    printf("Before change:\n");
    printf("a = %d\n", a);
    printf("*p = %d\n", *p);

    *p = 20; // Change value through pointer

    printf("\nAfter change through pointer:\n");
    printf("a = %d\n", a); // a changed because p points to a
    printf("*p = %d\n", *p);

    return 0;
}