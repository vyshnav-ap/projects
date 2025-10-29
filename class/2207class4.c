#include<stdio.h>

int main() {
    int choice;
    float balance = 10000.0, amount;

    printf("Welcome to Simple Bank\n");

    printf("1. View Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Your current balance is: ₹%.2f\n", balance);
            break;
        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            balance += amount;
            printf("New balance: ₹%.2f\n", balance);
            break;
        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= balance) {
                balance -= amount;
                printf("New balance: ₹%.2f\n", balance);
            } else {
                printf("Insufficient balance!\n");
            }
            break;
        case 4:
            printf("Exiting... Thank you!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
