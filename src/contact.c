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

void remove_contact(Contact **contacts, int *count, char *person)
{
    int index = -1;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(person, (*contacts)[i].name) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Contact not found.\n");
        return;
    }

    // Shift down
    for (int i = index; i < *count - 1; i++)
        (*contacts)[i] = (*contacts)[i + 1]; // put what's in slot 2 into slot 1

    (*count)--;
    printf("%s removed from contacts\n", person);

    // still have unused slots
    // No need for a realloc since add_contact calls realloc with count + 1 slots, which shrinks the array to fit and frees all the unused slots.
}

void view_contacts(Contact *contacts, int count, char *person)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(person, contacts[i].name) == 0)
        {
            printf("%s, %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void view_all_contacts(Contact *contacts, int count)
{
    for (int i = 0; i < count; i++)
        printf("%s, %s\n", contacts[i].name, contacts[i].phone);
}
