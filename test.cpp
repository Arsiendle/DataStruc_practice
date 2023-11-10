#include <stdio.h>
void changePointer(int *ptr)
{
    ptr = new int(10);
    // *ptr = 5;
}
int main()
{
    int *ptr = new int(1);
    printf("%d\n", *ptr);
    printf("%p\n", ptr);
    changePointer(ptr);
    printf("%d\n", *ptr);
    printf("%p\n", ptr);

    return 0;
}