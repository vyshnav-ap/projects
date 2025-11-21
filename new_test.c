#include <stdio.h>
#include <stdlib.h>  // for atoi()

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("No numbers provided.\n");
        return 0;
    }

    int i;
    float sum = 0.0;

    // Start from i = 1 to skip program name
    for (i = 1; i < argc; i++)
    {
        sum += atoi(argv[i]);  // convert string to integer
    }

    float average = sum / (argc - 1);
    printf("Average: %.2f\n", average);

    return 0;
}
