#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortchoice) 
{
    
    // Sort contacts based on the chosen criteria
    printf("sort according to \n1.name\n2.phone\n3.email\n");
    scanf("%d",&sortchoice);
     for(int i=0;i<addressBook->contactCount-1;i++)
    {
        for(int j=0;j<addressBook->contactCount-i-1;j++)
        {
            int cmp=0;
            if(sortchoice==1)
            cmp=strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
            else if(sortchoice==2)
            cmp=strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
            else if(sortchoice==3)
            cmp=strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
            if(cmp>0)  
            {
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }

        }
    }
    printf("Name\t\t    Phone\t  \t   Email\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        
        printf("%-2d. %-16s %-16s %-16s\n",i+1,addressBook->contacts[i].name,
        addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    return ;
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook); 
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

int validate_name(char *str){
    // isalnum()
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z')||(str[i]==' '))) {
                printf("only alphabets are allowed");
            return 0; 
        }
    }
    return 1; 
}
int validate_phone(char *str,AddressBook *addressBook){
    int flag =0;
    if (strlen(str) != 10){
        printf("Enter a valid phone number!");
        return 0;
    }
    for(int i=0;i<10;i++){
    if(str[i] >= '0' && str[i] <= '9'){
        flag = 1;
        
    }
    for(int i=0;i<addressBook -> contactCount;i++){
        if(strcmp(str,addressBook->contacts[i].phone)==0){
            flag = 0;
        }
    }
}
if(flag){
    return 1;
}
else
{
    printf("duplicate phone number is found!!");
    return 0;
}
    
}
int validate_email(char *str,AddressBook *addressBook){
    
    for(int i=0;str[i] != '\0';i++){
    if(str[i]>='A'&& str[i]<='Z'){
        printf("Email input must be in lowercase characters.");
        return 0;    
    }
    
}

    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(str, addressBook->contacts[i].email) == 0) {
            printf("Enter a valid email ");
            return 0; 
        }
    }

    
    char *p1 = strchr(str,'@');
    char *p2 = strchr(str,'.');
 if (p1 && p2 && p2 > p1+1) {
        if (p1 != str && *(p1+1) != '.' && *(p2+1) != '\0') {
            return 1; // valid
        }
    }
    printf("Invalid email format.\n");
    return 0;
}



void createContact(AddressBook *addressBook)
{   
    char name[100],phone[100],mail[100];
    while(1){
    printf("Enter the name : ");
    getchar();
    scanf("%[^\n]",name);
    if(validate_name(name))
        break;
    printf("\n***please try again***\n");
    }
    int ret=validate_name(name);
    if(ret){
    while(1){
    printf("Enter the phone no. : ");
    scanf(" %s",phone);
        if (validate_phone(phone, addressBook))
            break;
        printf("\n***please try again***\n");
    }
     int ret=validate_phone(phone,addressBook);
    if(ret){
    while(1){
    printf("Enter the email : ");
    scanf("%s",mail);
        if (validate_email(mail, addressBook))
            break;
        printf("\n***please try again***\n");
    }
     int ret=validate_email(mail,addressBook);
    if(ret){

    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,mail);

     addressBook->contactCount++;
    
     printf("Contact added successfully!\n");
    }
    }
    }
	/* Define the logic to create a Contacts */
    
}

int searchContact(AddressBook *addressBook) 
{
    char name[50];
    char phone[50];
    char email[50];
    int choice;
    printf("enter the choice :\n 1.search by name \n 2.search by phone \n3.search by email \n");
    scanf("%d",&choice);
    if (choice < 1 || choice > 3) {
    printf("Invalid choice!\n");
    return 0;
    }
    switch(choice)
    {
        case 1:
        printf("Enter the name : ");
        getchar();
        scanf("%[^\n]",name);
        if(validate_name(name)){
        if (strlen(name) == 0) {
        printf("Name cannot be empty!\n");
        return 0;
        }
        int flag = 0;
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].name,name)==0){
                flag=1;
                printf("%d %-30s %-19s %-30s",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                break;
            }

        }
        if(flag ==1){
                
              return 1;

        }
        else{
            printf("contact not found");
            return 0;
            
        }
    }
        
        break;
    
    case 2:
        printf("Enter the phone number : ");
        // getchar();
        scanf("%s",phone);
        if(validate_phone(phone,addressBook)){
        if(strlen(phone) !=10){
            printf("Invalid phone number! Must be 10 digits.\n");
            return 0;
        }
        int flag2 = 0;
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].phone,phone)==0){
                flag2=1;
                printf("%d %-30s %-19s %-30s",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                break;
            }

        }
        if(flag2 ==0){
            //printf("contact not found");
              return 0;

        }
        else{
            return 1;
            
        }
    }
        
        break;
    
    case 3:
        printf("Enter the Email id : ");
        // getchar();
        scanf("%s",email);
        if(validate_email(email,addressBook)){
        int flag3 = 0;
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].email,email)==0){
                flag3=1;
                printf("%d %-30s %-19s %-30s",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                break;
            }

        }
        if(flag3 ==0){
            printf("contact not found");
            return 0;

        }
        else{
            return 1;

        }
    }
        break;
    
        default:
        printf("\ncontact not found\n");
    }

    
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
    char name[100],phone[100],email[100];
    int ret = searchContact(addressBook);
    if (ret == 0){
        printf("contact not available can't edit the contact");
        return ;
    }
    printf("\nEnter the index :");
    int i=0,n;
    scanf("%d",&i);
    printf("\n1.Edit name \n2.Edit Phone \n3.edit Email\n");
    scanf("%d",&n);
    if(n == 1){
        while(1){
        printf("Enter the name to edit: ");
        scanf(" %[^\n]",name);
        if(validate_name(name)){
            strcpy(addressBook -> contacts[i].name,name);
            printf("Contact edited successfully!\n");
            break;
        }
        printf("\n***Please try again.***\n");
        }
    }
    else if(n == 2){
        while(1){
        printf("Enter the phone no. to edit: ");
        scanf("%s",phone);
        if(validate_phone(phone,addressBook)){
        strcpy(addressBook -> contacts[i].phone,phone);
        printf("Contact edited successfully!\n");
            break;
        }
        printf("\n***Please try again.***\n");
        }
    }
    
    else if(n == 3){
        printf("Entre the email to edit: ");
        scanf("%s",email);
        if(validate_email(email,addressBook)){
        strcpy(addressBook -> contacts[i].email,email);
        printf("email is successfully updated");
        }
    }
    else{
        printf("Invalid choice");
    }



	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   //char name[100],phone[100],email[100];
    int ret = searchContact(addressBook);
    if (ret == 0){
        printf("contact not available can't edit the contact");
        return;
    }
    printf("\nEnter the index to delete:");
    int i=0;
    scanf("%d",&i);
    if (i < 0 || i >= addressBook->contactCount) {
        printf("Invalid index!\n");
        return;
    }
    for(;i<addressBook->contactCount;i++) // shift the strcut
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    addressBook->contactCount--;
     printf("✅ Contact deleted successfully!\n");
} 
