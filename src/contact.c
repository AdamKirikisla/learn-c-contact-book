#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

Contact *create_contacts(void)
{
    Contact *contacts = malloc(2 * sizeof(Contact));
    if (contacts == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Default Values
    strcpy(contacts[0].name, "Alex");
    strcpy(contacts[0].phone, "514-732-1834");
    strcpy(contacts[1].name, "John");
    strcpy(contacts[1].phone, "438-851-2345");

    return contacts;
}
