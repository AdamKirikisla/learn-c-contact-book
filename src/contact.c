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
// ** because contacts already has one * in main (Contact *), and we need
// its address to change where it points after realloc
void add_contact(Contact **contacts, int *count, const char *name, const char *phone)
{
    Contact *temp = realloc(*contacts, (*count + 1) * sizeof(Contact));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    *contacts = temp;
    temp = NULL;

    strcpy((*contacts)[*count].name, name);
    strcpy((*contacts)[*count].phone, phone);
    (*count)++;
}
