# AddressBook

A simple console-based contact management system written in **C**. It allows users to create, search, edit, delete, and list contacts, with data persisted to a CSV file.

## Features

* **Create Contact** — Add a new contact with name, phone, and email
* **Search Contact** — Find contacts by name, phone, or email
* **Edit Contact** — Update an existing contact's details
* **Delete Contact** — Remove a contact from the address book
* **List All Contacts** — View all saved contacts
* **Save and Exit** — Save contacts to `contacts.csv` before quitting

## Project Structure

```text
AddressBook/
├── main.c              # Program entry point and menu loop
├── contact.c           # Contact management operations
├── contact.h           # Contact structures and function declarations
├── file.c              # File handling for loading and saving contacts
├── file.h              # File handling function declarations
└── contacts.csv        # Persistent contact data
```

## Requirements

* GCC or another C compiler
* Linux, macOS, or Windows with a C development environment
* Terminal or Command Prompt

## File Description

| File           | Description                                                             |
| -------------- | ----------------------------------------------------------------------- |
| `main.c`       | Program entry point and menu handling                                   |
| `contact.c`    | Contact creation, searching, editing, deletion, validation, and listing |
| `contact.h`    | Contact structures and function declarations                            |
| `file.c`       | Loading and saving contact data                                         |
| `file.h`       | File handling function declarations                                     |
| `contacts.csv` | Stores contact information for persistent data storage                  |

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
  +--> List All Contacts
  |
  +--> Save and Exit
  |
  v
End
```

## Compilation

Compile the source files using GCC:

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
```

Enter the number corresponding to the operation you want to perform.

## Data Storage

Contact information is stored in `contacts.csv`.

Example:

```text
#3
Dileep,9087654321,dileep@gmail.com
Swapnika,7789654321,jenny@gmail.com
Mary,8907654321,mary@gmail.com
```

The first line stores the number of contacts, followed by the contact records.

When AddressBook starts, existing contacts are loaded from the CSV file. Selecting **Save and Exit** writes the current contacts back to the file.

## Author

**Manubolu Dileepchowdary**
