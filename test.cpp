#include <stdio.h>
void changePointer(int *ptr)
{
    ptr = new int(10);
    // *ptr = 5;
}
int main()
{
    printf("%d", 5 / 2);

    return 0;
}