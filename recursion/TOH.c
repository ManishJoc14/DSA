#include <stdio.h>
#include <stdlib.h>

void TOH(int n, char L, char C, char R)
{

    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", L, R);
        return;
    }

    TOH(n - 1, L, R, C);

    printf("move disk %d from %c to %c\n", n, L, R);

    TOH(n - 1, R, C, L);
}

int main()
{

    int n = 3;
    TOH(n, 'L', 'C', 'R');

    return 0;
}