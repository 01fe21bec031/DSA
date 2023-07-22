#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int min, max, count, i;
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &count);

    srand(time(NULL));

    FILE *fp;
    fp = fopen("random_numbers.txt", "w");

    for (i = 0; i < count; i++) {
        int num = (rand() % (max - min + 1)) + min;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);

    printf("%d random numbers generated and saved to file 'random_numbers.txt'.\n", count);

    return 0;
}

