#include <stdio.h>
#include <stdlib.h>
#include "file.h"

// Write all the contacts to contact.csv in a basic comma-separated format(CSV).
void saveContactsToFile(AddressBook *addressBook) {
    FILE *fcontact = fopen("contacts.csv","w");

    if(fcontact == NULL){
        perror("Error opeing contact.csv");
        return;
    }

    // This line stores the contact count as #<count>. Example: #1
    fprintf(fcontact,"#%d\n",addressBook->contactCount);

    for(int i = 0; i < addressBook->contactCount; i++){
        fprintf(fcontact,"%-5s,%-10s,%-30s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }

    fclose(fcontact);
  
}

// Read all the contacts from contact.csv if the file exists.
// Expects first line to be #<count> followed by name,phone,email lines.

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fcontact = fopen("contacts.csv","r");
    
    if(fcontact == NULL){
        fprintf(stderr,"can't access file contact.csv");
        return;
    }
    if(ferror(fcontact)){
        printf("1st time error\n");
    }

    // read the contact count from the first line onwards and increment the contactCount in the address book.
    fscanf(fcontact,"#%d\n",&addressBook->contactCount);

    for(int i = 0; i < addressBook->contactCount; i++){
        fscanf(fcontact,"%[^,],%[^,],%[^\n]\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }

    if(ferror(fcontact)){
        printf("2nd time error\n");
    }
    fclose(fcontact);

    printf("%d contacts loaded successfully.\n",addressBook->contactCount);

}
