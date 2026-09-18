#include <stdio.h>
#include "contact.h"


int main() 
{
    int choice;
    AddressBook addressBook;
    char line[32];

    // addressBook.contactCount = 0;
    initialize(&addressBook); // Initialize the address book

    do 
    {
        printf("\n\n*******************************************\n");
        printf("|            ADDRESS BOOK MENU            |\n");
        printf("-------------------------------------------\n");
        printf("|   1   |   %-25s     |\n","CREATE CONTACT");
        printf("|   2   |   %-25s     |\n","SEARCH CONTACT");
        printf("|   3   |   %-25s     |\n","EDIT CONTACT");
        printf("|   4   |   %-25s     |\n","DELETE CONTACT");
        printf("|   5   |   %-25s     |\n","LIST ALL CONTACT");
    	printf("|   6   |   %-25s     |\n","SAVE AND EXIT");		
        printf("|   7   |   %-25s     |\n","EXIT");
        printf("-------------------------------------------\n");

        printf("Enter your choice: ");
        if(fgets(line,sizeof(line),stdin) == NULL){
            break; //handle EOF gracefully
        }
        if(sscanf(line, "%d", &choice) !=1 ){
            printf("Invalid input.please enter a number.\n");
            continue;
        }
        
        switch (choice) 
        {
            case 1:
                //Create the new contact and add it to the addressbook. 
                createContact(&addressBook);
                break;
            case 2:
                //Search the contacts by name,phone_no,email.
                searchContact(&addressBook,1);
                break;
            case 3:
                //Edit the contact which is existed.
                editContact(&addressBook);
                break;
            case 4:
                //Delete the contact from the addressbook.
                deleteContact(&addressBook);
                break;
            case 5:          
                //Display all the contacts which is saved in addressbook.
                listContacts(&addressBook);
                break;
            case 6:
                //Save the contacts to the file and exit from the program.
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                return 0;
            case 7:
                //Exit without saving any changes.
                printf("Excited Successfully....\n");
            default:
                //To handle inavalid option which is not available in the menu.
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
