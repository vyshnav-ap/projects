#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr =fopen("contact.csv","w");
    if(fptr == NULL){
        printf("File open error\n");
        return ;
    }

    // Option 1: Save contact count as first line (if you used it while loading)
    fprintf(fptr, "%d\n", (addressBook->contactCount));

    // Option 2: If you don’t use count in file, remove the above line

    // Write each contact in CSV format: name,phone,email
    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fptr);
    printf("Contacts saved successfully! \n");
    return;

  
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fptr =fopen("contact.csv","r");
    if(fptr == NULL){
        printf("File open error\n");
        return ;
    }
    fscanf(fptr,"%d\n",&addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++){
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook ->contacts[i].name,addressBook ->contacts[i].phone,addressBook ->contacts[i].email);
    } 
    fclose(fptr);
    printf("Contact load successfully!(%d contacts)\n",addressBook->contactCount);   
    //printf("Name:%s\n",name);
    //printf("ID:%d\n",ID);
}
