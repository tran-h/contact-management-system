/* -------------------------------------------
Name: Henry Tran
Student number: 
Email: 
Section: SNN
Date: March 27, 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void) {
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt function definition goes here:
int getInt(void) {
    char nl = 'x';
    int value;
    scanf("%d%c", &value, &nl);
    while (nl != '\n') {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &nl);
    }
    return value;
}


// getIntInRange function definition goes here:
int getIntInRange(int min, int max) {
    int value;
    value = getInt();
    while (value < min || value > max) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        value = getInt();
    }
    return value;
}


// yes function definition goes here:
int yes(void) {
    char ch;
    char nl;
    scanf(" %c%c", &ch, &nl);
    while (nl != '\n') {
        clearKeyboard();
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf(" %c%c", &ch, &nl);
    }
    switch (ch)
    {
    case 'Y':
    case 'y':
        return 1;
    default:
        return 0;
        break;
    }
}


// menu function definition goes here:
int menu(void) {
    int value;
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    value = getIntInRange(0, 6);
	printf("\n");
    return value;
}


// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void) {
    int menuValue;
    int yesOrNo;
    int done = 0;
    struct Contact contactsArray[MAXCONTACTS] = {
    {{"Rick",{'\0'}, "Grimes"},
    {11, "Trailer Park", 0, "A7A 2J2", "King City"},
    {"4161112222", "4162223333", "4163334444"}},
    {
        {"Maggie", "R.", "Greene" },
        {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
        {"9051112222","9052223333","9053334444"}},
        {
            {"Morgan","A.","Jones"},
            {77,"Cottage Lane", 0,"C7C 9Q9","Peterborough"},
            {"7051112222","7052223333","7053334444"}},
            {
                {"Sasha", {'\0'}, "Williams"},
                {55,"Hightop House",0,"A9A 3K3","Bolton"},
                {"9052223333","9052223333","9054445555"}},
    };
    menuValue = menu();
    while (!done) {
        switch (menuValue)
        {
        case 1:
            displayContacts(contactsArray, MAXCONTACTS);
            pause();
			printf("\n");
            menuValue = menu();
            break;
        case 2:
            addContact(contactsArray, MAXCONTACTS);
            pause();
			printf("\n");
            menuValue = menu();
            break;
        case 3:
            updateContact(contactsArray, MAXCONTACTS);
            pause();
			printf("\n");
            menuValue = menu();
            break;
        case 4:
            deleteContact(contactsArray, MAXCONTACTS);
            pause();
			printf("\n");
            menuValue = menu();
            break;
        case 5:
            searchContacts(contactsArray, MAXCONTACTS);
            pause();
			printf("\n");
            menuValue = menu();
            break;
        case 6:
            sortContacts(contactsArray, MAXCONTACTS);
            pause();
			printf("\n");
            menuValue = menu();
            break;
        case 0:
            printf("Exit the program? (Y)es/(N)o: ");
            yesOrNo = yes();
            if (yesOrNo == 1) {
                printf("\nContact Management System: terminated\n");
                done = 1;
            }
            else {
				printf("\n");
                menuValue = menu();
            }
            break;
        default:
            break;
        }
    }
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[]) {
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            return i;
        }
    }
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int noOfContacts) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", noOfContacts);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact) {
    if (strlen(contact->name.middleInitial) > 0) {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    else {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    if (contact->address.apartmentNumber > 0) {
        printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
    }
    else {
        printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
    }
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {
    int noOfContacts = 0;
    int i;
    displayContactHeader();
    for (i = 0; i < size; i++) {
        if (strlen(contacts[i].numbers.cell) > 0) {
            displayContact(&contacts[i]);
            noOfContacts++;
        }
    }
    displayContactFooter(noOfContacts);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {
    char cellNumber[11] = { 0 };
    int index;
    while (strlen(cellNumber) < 10) {
        printf("Enter the cell number for the contact: ");
        getTenDigitPhone(cellNumber);
    }
    index = findContactIndex(contacts, size, cellNumber);
    if (index > -1) {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
    int i;
    int noOfContacts = 0;
    for (i = 0; i < size; i++) {
        if (strlen(contacts[i].numbers.cell) == 0) {
            getContact(&contacts[i]);
            noOfContacts++;
            printf("--- New contact added! ---\n");
        }
        if (strlen(contacts[i].numbers.cell) == 10) {
            noOfContacts++;
        }
    }
    if (noOfContacts == size) {
        printf("*** ERROR: The contact list is full! ***\n");
    }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {
    char cellNumber[11] = { 0 };
    int index;
    while (strlen(cellNumber) < 10) {
        printf("Enter the cell number for the contact: ");
        getTenDigitPhone(cellNumber);
    }
    index = findContactIndex(contacts, size, cellNumber);
    if (index > -1) {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1) {
            getName(&contacts[index].name);
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1) {
            getAddress(&contacts[index].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1) {
            getNumbers(&contacts[index].numbers);
        }
        printf("--- Contact Updated! ---\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
    char cellNumber[11] = { 0 };
    int index;
    while (strlen(cellNumber) < 10) {
        printf("Enter the cell number for the contact: ");
        getTenDigitPhone(cellNumber);
    }
    index = findContactIndex(contacts, size, cellNumber);
    if (index > -1) {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1) {
            strcpy(contacts[index].numbers.cell, "");
            printf("--- Contact deleted! ---\n");
        }
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size) {
    printf("<<< Feature to sort is unavailabe >>>\n");
}