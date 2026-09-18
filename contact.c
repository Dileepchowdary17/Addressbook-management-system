/*
NAME: MANUBOLU DILEEP CHOWDARY
PROJECT NAME: ADDRESSBOOK MANAGEMENT SYSTEM
DURATION: START DATE: 01/08/2026  END DATE: 07/08/2026
DESCRIPTION:
- Addressbook is a menu-driven application built using c programming which stores and manages the contact information.
- Each contact contains:
  Name:
  Phone number:
  Email ID:
- The user can do following operations:
  ->Add new contacts
  ->Search contacts
  ->Edit contacts
  ->Delete contacts
  ->View all contacts
  ->Save contacts permanently into a file
  ->Load contacts automatically when the program starts
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"


void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void display_contact(AddressBook *addressBook, int index);


char validate_name(char *name);
char validate_phone(char *phone, AddressBook *addressBook);
char validate_email(char *email, AddressBook *addressBook);

int search_by_name(AddressBook *addressBook,int flag);
int search_by_phone(AddressBook *addressBook);
int search_by_email(AddressBook *addressBook);


void edit_name(AddressBook *addressBook, int index);
void edit_phone(AddressBook *addressBook, int index);
void edit_email(AddressBook *addressBook, int index);


void createContact(AddressBook *addressBook)
{

    char name[30], phone[11], email[30];
    int res;
    do {
        printf("Enter the name : ");
        scanf(" %[^\n]", name);

        res = validate_name(name);

    } while(res == 0);
    
    do {
        printf("Enter the phone : ");
        scanf(" %[^\n]", phone);

        res = validate_phone(phone,addressBook);

    }while(res == 0);

    do{
        printf("Enter the email : ");
        scanf(" %[^\n]", email);

        res = validate_email(email,addressBook);
    }while(res == 0);


    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);

    addressBook->contactCount++;
}

int searchContact(AddressBook *addressBook, char flag) 
{
    int choice;
    while (1)
    {
        printf("******************************************\n");
        printf("|          SEARCH CONTACT BY             |\n");
        printf("------------------------------------------\n");
        printf("|    1    |   %-25s  |\n","SEARCH BY NAME ");
        printf("|    2    |   %-25s  |\n","SEARCH BY PHONE");
        printf("|    3    |   %-25s  |\n","SEARCH BY EMAIL");       
        printf("------------------------------------------\n");
        printf("Enter your choice: ");

        if(scanf("%d",&choice) != 1)
        {   
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if(choice>=1 && choice<=3){
            break;
        }
        printf("Invalid input. Please enter 1-3.\n");
    }
    
    int index;
    switch(choice)
    {
        case 1:
            index = search_by_name(addressBook, flag);
            break;

        case 2:
            index = search_by_phone(addressBook);
            break;

        case 3:
            index = search_by_email(addressBook);
            break;

        default:
            printf("Invalid input\n");
    }
    return index;
}

//Allow the user to choose a option to update the selected contact.
void editContact(AddressBook *addressBook)
{
    int choice;
    int index = searchContact(addressBook,1);
    if(index < 0)
    return;

    while(1)
    {
        printf("Edit Options: \n");
        printf("1. Edit name\n");
        printf("2. Edit phone_no\n");
        printf("3. Edit email\n");

        printf("***************************************\n");
        printf("|            Edit Options             |\n");
        printf("---------------------------------------\n");
        printf("|   1   |   %-25s |\n","EDIT NAME ");
        printf("|   2   |   %-25s |\n","EDIT PHONE N.O ");
        printf("|   3   |   %-25s |\n","Edit Email ID ");
        printf("---------------------------------------\n");
        printf("Enter your choice: ");

        if(scanf("%d",&choice) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Invalid input.\n");
            continue;
        }

        if(choice >= 1 && choice <= 3)
        {
            break;
        }
        printf("Invalid choice. Enter 1-3\n");
    }

    switch (choice)
    {
        case 1:
            edit_name(addressBook, index);
            break;

        case 2:
            edit_phone(addressBook, index);
            break;

        case 3:
            edit_email(addressBook, index);
            break;

        default :
            printf("Invalid Input..\n");
        }
        
        printf("Contact edited successfully\n");
        display_contact(addressBook, index);
}
    
    //Remove the selected contact by shifting the last ones to left
void deleteContact(AddressBook *addressBook)
{
        int index = searchContact(addressBook, 1);
        if(index<0){
            return ;
        }
        
        for(int i = index; i < (addressBook->contactCount) - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i+1];
        }
        
        addressBook->contactCount--;
        printf("Contact deleted successfully\n");
        return ;
}

// Sort contacts based on the chosen criteria
void listContacts(AddressBook *addressBook) 
{
    if(addressBook->contactCount == 0){
        printf("AddressBook is Empty\n");
        return ;
    }

    for(int i = 0; i < addressBook->contactCount-1; i++){
        for(int j = 0; j < addressBook->contactCount-i-1; j++){
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0){
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }

    printf("--------------------------------------------------------------------------------------\n");
    printf("|                                    ADDRESS BOOK                                    |\n");
    printf("**************************************************************************************\n");
    printf("| %-3s| %-25s | %-15s | %-30s |\n","S.No", "Name", "Phone", "Email");
    printf("+-----+---------------------------+-----------------+--------------------------------+\n");
    
    for( int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-3d | %-25s | %-15s | %-30s |\n",
            i+1,
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
        }    
    printf("+-----+---------------------------+-----------------+--------------------------------+\n");
    
    return;
}
void saveAndExit(AddressBook *addressBook) 
{   
    saveContactsToFile(addressBook); 
    printf("Saving and exiting....");
    exit(0); 
}

// Print the selected contact's details in a structured block.
void display_contact(AddressBook *addressBook, int index){
    
    printf("***************************************\n");    
    printf("|            CONTACT DETAILS          |\n");
    printf("---------------------------------------\n");
    printf("| NAME    | %-25s |\n",addressBook->contacts[index].name);
    printf("| PHONE   | %-25s |\n",addressBook->contacts[index].phone);
    printf("| EMAIL   | %-25s |\n",addressBook->contacts[index].email);
    printf("---------------------------------------\n\n");

    return ;
}

//validate the name that matches the requirements(letters,spaces).
char validate_name(char *name){
    for(int i = 0; name[i]; i++){
        if(!(((name[i]>='A') && (name[i]<='Z')) || ((name[i]>='a') && (name[i]<='z')) || (name[i]==' ' || name[i]=='.'))){
            printf("Invalid name\n");
            return 0;
        }
    }
    return 1;
}

//validate the phone number that matches the requirements(length,format,without duplicates).
char validate_phone(char *phone,AddressBook *addressBook){
    //check the phone number length.
    if(strlen(phone)!=10){
        printf("You entered contact length is invalid.\n");
        return 0;
    }

    //check phone number wheather valid or not.
    for(int i = 0; phone[i]; i++){
        if(!(phone[i]>='0' && phone[i]<='9')){
            printf("Inavlid number.\n");
            return 0;
        }
    }

    //check phone number if it is duplicate or not.
    for(int i = 0; i < addressBook ->contactCount; i++){
        if(strcmp(phone,addressBook->contacts[i].phone)==0){
            printf("You entered phone number is already existed.\n");
            return 0;
        }
    }
    return 1;
}

char validate_email(char *email,AddressBook *addressbook){
    int c = 0,d = 0;
    int length = strlen(email);

    if(length<11){      //Length should be atleast 11 characters(Eg:a@gmail.com)
        return 0;
    }
    if(email[0]>='0' && email[0]<='9'){
        printf("email shouln't start with digits.\n");
        return 0;
    }
    for(int i = 0; email[i] ; i++){
        if(!(((email[i]>='A') && (email[i]<='Z')) || ((email[i]>='a') && (email[i]<='z')) || (email[i] == '@' || email[i] == '.' || email[i] == '-' || email[i] == '_'))){
            printf("invalid email.\n");
            return 0;
        }

        if(email[i] == '@') c = 1;
        if(email[i] == '.') d = 1;
    }
    if(c == 0 || d == 0)
    {
        printf("Invalid email it should contain '@' and '.'\n");
        return 0;
    }
    
    for(int i = 0; i < addressbook ->contactCount; i++)
    {
        if(strcmp(email,addressbook->contacts[i].email) == 0)
        {
            printf("You entered email is already existed.\n");
            return 0;
        }
    }
    return 1;
}

int search_by_name(AddressBook *addressBook,int flag)
{
    char name[30];

    while(1){

        printf("\nEnter the name to search: \n");
        scanf(" %[^\n]",name);

        int count = 0;
        int index = -1;

        int *dup = malloc(sizeof(int)* addressBook->contactCount);
        
        if(dup == NULL)
        {
            printf("Memory allocation failed\n");
            return -1;
        }
        for(int i = 0; i < addressBook ->contactCount; i++)
        {
            if(strcmp(name,addressBook->contacts[i].name) == 0)
            {
                index = i;
                dup[count++] = i;
                // dup[count] = index;
                // printf("%s\n",name);
            }
        }

        if(count == 0){
            printf("Contact is not found\n");
            free(dup);
            continue;
            // return -1;
        }
        
        if(count == 1)
        {
            printf("Contact found at S.No: %d\n",index + 1);
            display_contact(addressBook, index);

            free(dup);
            return index;
        }
        
        printf("Multiple names found.\n");

        for(int i = 0; i < count; i++)
        {
            printf("\nContact %d:\n",i+1);
            display_contact(addressBook, dup[i]);
        }

        while(1)
        {
            int choice;

            printf("\nSelect the contact(1-%d): \n", count);
            
            if(scanf("%d", &choice) != 1){
                printf("Invalid input. Enter a number.\n");
                while(getchar() != '\n');
                continue;
            }
            if(choice>=1 && choice<=count)
            {
                int selected_index = dup[choice-1];
                printf("\nSelected Contact is:\n");
                display_contact(addressBook, selected_index);
                free(dup);
                return selected_index;
            }
            printf("Invalid choice! Please select 1-%d.\n", count);
        }
    }
}

int search_by_phone(AddressBook *addressBook)
{
    char phone[20];

    while(1)
    {

        printf("\nEnter the phone_no to search: ");
        scanf("%19s",phone);
        
        int found = 0;
        
        for(int ind = 0; ind < addressBook->contactCount; ind++)
        {
            if(strcmp(phone,addressBook->contacts[ind].phone) == 0)
            {
                printf("Search Found at S.No: %d!\n", ind + 1);
                display_contact(addressBook,ind);
                found = 1;
                return ind;
            }
        }
        if(found == 0)
        {
            printf("Contact is not found!\n");
            printf("Enter thephone number again.\n");
        }
    }
}
    
int search_by_email(AddressBook *addressBook)
{
    char email[30];

    while(1)
    {

        printf("\nEnter the Email to search: ");
        scanf("%29s",email);
        int found = 0;
        
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(email,addressBook->contacts[i].email) == 0)
            {
                printf("\nContact found at S.No: %d\n",i + 1);
                display_contact(addressBook,i);

                found = 1;
                return i;
            }
        }
        
        if(found == 0)
        {
            printf("Contact is not found\n");
            printf("Please enter the email again.\n");
        }
    }
}


void edit_name(AddressBook *addressBook, int index)
{
    char name[20];
    while(1)
    {
        printf("Enter the Name:\n");
        scanf(" %19[^\n]",name);

        if(validate_name(name))
        {
            strcpy(addressBook->contacts[index].name,name);
            break;
        } 
    }
}


void edit_phone(AddressBook *addressBook, int index)
{
    char phone[20];
    while(1)
    {
        printf("Enter the Phone_no:\n");
        scanf(" %19[^\n]",phone);

        if(strlen(phone) != 10){
            printf("Phone number should be exactly 10 digits.\n");
            continue;
        }
        int valid = 1;

        for(int i = 0; phone[i]; i++){
            if(phone[i] < '0' || phone[i] > '9'){
                valid = 0;
                break;
            }
        }

        if(valid == 0){
            printf("Invalid phone number.\n");
            continue;
        }
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(i != index &&
            strcmp(phone,addressBook->contacts[i].phone) == 0){
                printf("Phone number already exists.\n");
                valid = 0;
                break;
            }
        }

        if(valid){
            strcpy(addressBook->contacts[index].phone, phone);
            break;
        }
    }
}

void edit_email(AddressBook *addressBook, int index){
    char email[30];
    while(1)
    {
        printf("Enter the email\n");
        scanf(" %29[^\n]",email);
        char res = validate_email(email, addressBook);

        if(res == 0){
            printf("Invalid email\n");
        }
        else if(res == 1){
            strcpy(addressBook->contacts[index].email, email);
            break;
        }
        else if(res == 2){
            printf("Email already exists\n");
        }
    }
}

