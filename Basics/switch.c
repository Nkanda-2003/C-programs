#include <stdio.h>

int main()
{
    int day;

    // Ask user to enter day number
    printf("Enter day number (1-3): ");
    scanf("%d", &day);

    // Select output based on day number
    switch(day)
    {
        case 1:
            printf("Monday\n");
            break;  // Exit switch

        case 2:
            printf("Tuesday\n");
            break;

        case 3:
            printf("Wednesday\n");
            break;

        default:
            printf("Invalid Day\n");
    }

    return 0;
}
