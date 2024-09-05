#include <stdio.h>
int main() {
    int num, n, rem, rev = 0;
    printf("Enter a three-digit integer: ");
    scanf("%d", &num);
    n = num;
    while (n != 0) {
        rem = n % 10;
       rev += rem * rem * rem;
       n /= 10;
    }
    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);
    return 0;
}
