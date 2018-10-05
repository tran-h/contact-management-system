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
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
#include "contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *contactName) {
    int yesOrNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]s", contactName->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesOrNo = yes();

    switch (yesOrNo) {
    case 0:
        break;
    default:
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6s", contactName->middleInitial);
        break;
    }

    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]s", contactName->lastName);
}


// getAddress:
void getAddress(struct Address *contactAddress) {
    int yesOrNo;

    printf("Please enter the contact's street number: ");
    contactAddress->streetNumber = getInt();
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]s", contactAddress->street);
    printf("Do you want to enter an apartment number? (y or n): ");
    yesOrNo = yes();

    switch (yesOrNo)
    {
    case 0:
        contactAddress->apartmentNumber = 0;
        break;
    default:
        printf("Please enter the contact's apartment number: ");
        contactAddress->apartmentNumber = getInt();
        break;
    }

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]s", contactAddress->postalCode);
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]s", contactAddress->city);
}



// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers *contactNumbers) {
    int yesOrNo;

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(contactNumbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    yesOrNo = yes();

    switch (yesOrNo)
    {
    case 0:
        strcpy(contactNumbers->home, "");
        break;
    default:
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(contactNumbers->home);
        break;
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesOrNo = yes();

    switch (yesOrNo)
    {
    case 0:
        strcpy(contactNumbers->business, "");
        break;
    default:
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(contactNumbers->business);
        break;
    }
}



// getContact
void getContact(struct Contact *contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
