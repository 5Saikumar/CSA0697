#include <stdio.h>
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void generatePrimes(int limit) {
    printf("Prime numbers up to %d are: ", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);
    generatePrimes(limit);
    return 0;
}

