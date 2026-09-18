AddressBook

A menu-driven contact management application developed in C. AddressBook allows users to create, search, edit, delete, and list contacts, with persistent storage using a CSV file.

Features

* Create new contacts
* Search contacts by name, phone, or email
* Edit existing contacts
* Delete contacts
* List contacts alphabetically by name
* Validate contact information
* Prevent duplicate phone numbers and email addresses
* Save contacts to a CSV file
* Load saved contacts when the application starts

Project Structure

AddressBook/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.csv
└── README.md


Requirements

* C compiler (GCC recommended)
* Linux, macOS, or Windows
* Terminal

File Description

| File           | Description                                                                        |
| -------------- | ---------------------------------------------------------------------------------- |
|  main.c        | Handles program execution and menu operations                                      |
|  contact.c     | Implements contact creation, searching, editing, deletion, validation, and listing |
|  contact.h     | Defines contact structures and declares contact-related functions                  |
|  file.c        | Implements saving and loading contacts                                             |
|  file.h        | Declares file handling functions                                                   |
|  contacts.csv  | Stores contact data for persistent storage                                         |
|  README.md     | Project documentation                                                              |

Application Flow

Start
  |
  v
Initialize AddressBook
  |
  v
Load contacts.csv
  |
  v
Display Menu
  |
  +--> Create Contact
  |
  +--> Search Contact
  |
  +--> Edit Contact
  |
  +--> Delete Contact
  |
  +--> List Contacts
  |
  +--> Save and Exit
  |
  v
End


Compilation

Compile all source files using GCC:

gcc main.c contact.c file.c -o addressbook


Execution

Linux / macOS

./addressbook


Windows

addressbook.exe

Usage

After starting the application, select an option from the menu:

***************************************
|           ADDRESS BOOK MENU         |
---------------------------------------
|   1   |   CREATE CONTACT            |
|   2   |   SEARCH CONTACT            |
|   3   |   EDIT CONTACT              |
|   4   |   DELETE CONTACT            |
|   5   |   LIST ALL CONTACTS         |
|   6   |   SAVE AND EXIT             |
|   7   |   EXIT                      |
---------------------------------------
Choose your Option:

Enter the number wants to perform the selected operation.

Data Storage

AddressBook uses contacts.csv to store contact information.

The file follows a simple comma-separated format:

#3
Dileep,9087654321,dileep@gmail.com
Swapnika,7789654321,jenny@gmail.com
Mary,8907654321,mary@gmail.com

The first line stores the number of contacts, followed by the contact records.

When AddressBook starts, the saved contacts are loaded from the CSV file into memory. When the user selects **Save and Exit**, the current contacts are written back to the file.

Author

Manubolu Dileepchowdary
