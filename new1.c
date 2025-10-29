#include<stdio.h>

int main() {
    int n, s, d;

    // Input: nth day
    scanf("%d", &n);

    if(n > 0 && n <= 365) {
        // Input: first day of the year (1=Sunday ... 7=Saturday)
        scanf("%d", &s);

        if(s >= 1 && s <= 7) {
            d = (n + s - 1) % 7;

            // Output the day
            switch(d) {
                case 1:
                    printf("The day is Sunday\n");
                    break;
                case 2:
                    printf("The day is Monday\n");
                    break;
                case 3:
                    printf("The day is Tuesday\n");
                    break;
                case 4:
                    printf("The day is Wednesday\n");
                    break;
                case 5:
                    printf("The day is Thursday\n");
                    break;
                case 6:
                    printf("The day is Friday\n");
                    break;
                case 0:
                    printf("The day is Saturday\n");
                    break;
                default:
                    printf("Error: Invalid day index\n");
            }
        } else {
            printf("Invalid entry for first day\n");
        }
    } else {
        printf("Invalid entry for nth day\n");
    }

    return 0;
}
