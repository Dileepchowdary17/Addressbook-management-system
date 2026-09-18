# AddressBook

A simple console-based contact management system written in **C**. It allows you to create, search, edit, delete, and list contacts, with data persisted to a CSV file.

## Features

* **Create Contact** — Add a new contact with name, phone, and email
* **Search Contact** — Find contacts by name, phone, or email
* **Edit Contact** — Update an existing contact's details
* **Delete Contact** — Remove a contact from the address book
* **List All Contacts** — View all saved contacts
* **Save and Exit** — Save all contacts to `contacts.csv` before quitting
* **Input Validation** — Validate name, phone number, and email
* **Duplicate Checking** — Prevent duplicate phone numbers and email addresses
* **Alphabetical Sorting** — Sort contacts by name

## Project Structure

```text
AddressBook/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.csv
└── README.md
```

## Requirements

* GCC or another C compiler
* Linux, macOS, or Windows
* Terminal or Command Prompt

## File Description

| File           | Description                                                             |
| -------------- | ----------------------------------------------------------------------- |
| `main.c`       | Program entry point and menu handling                                   |
| `contact.c`    | Contact creation, searching, editing, deletion, validation, and listing |
| `contact.h`    | Contact and AddressBook structures and function declarations            |
| `file.c`       | Loading and saving contact data                                         |
| `file.h`       | File handling function declarations                                     |
| `contacts.csv` | Persistent contact data                                                 |
| `README.md`    | Project documentation                                                   |

## Application Flow

```text
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
```

## Compilation

Compile all source files using GCC:

```bash
gcc main.c contact.c file.c -o addressbook
```

## Execution

### Linux / macOS

```bash
./addressbook
```

### Windows

```bash
addressbook.exe
```

## Usage

When the program starts, the following menu is displayed:

```text
*******************************************
|            ADDRESS BOOK MENU            |
-------------------------------------------
|   1   |   CREATE CONTACT               |
|   2   |   SEARCH CONTACT               |
|   3   |   EDIT CONTACT                 |
|   4   |   DELETE CONTACT               |
|   5   |   LIST ALL CONTACTS            |
|   6   |   SAVE AND EXIT                |
|   7   |   EXIT                         |
-------------------------------------------
Enter your choice:
```

Enter the number corresponding to the operation you want to perform.

## Data Storage

Contact information is stored in `contacts.csv` using a simple CSV format.

Example:

```text
#3
Dileep,9087654321,dileep@gmail.com
Swapnika,7787654321,jenny@gmail.com
Mary,8907654321,mary@gmail.com
```

The first line stores the number of contacts, followed by the contact records.

When AddressBook starts, the saved contacts are loaded from `contacts.csv` into memory. When **Save and Exit** is selected, the current contact data is written back to the CSV file.

## Author

**Manubolu Dileepchowdary**
