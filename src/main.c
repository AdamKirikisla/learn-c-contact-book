#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int main()
{
    char person[50];
    int controller = 0;

    int count = 2;

    Contact *contacts = create_contacts();
    if (contacts == NULL)
        return 1;

    do
    {
        printf("\nContacts\n");
        printf("\n1) Add new contact\n");
        printf("\n2) Remove a contact\n");
        printf("\n4) View all contacts\n");
        printf("\n5) Quit\n");
        printf("\nEnter a command: ");
        scanf("%d", &controller);

        switch (controller)
        {
        case 1:
            add_contact(&contacts, &count, "Sam", "514-000-0000");
            break;

        case 2:
            printf("Who would you like to remove from your contacts: ");
            scanf("%49s", person); // manual limit
            remove_contact(&contacts, &count, person);
            break;

        case 4:
            view_contacts(contacts, count);
            break;

        case 5:
            break;

        default:
            printf("Wrong input\n");
            break;
        }
    } while (controller != 5);

    printf("Goodbye!\n");

    free(contacts);
    contacts = NULL;

    return 0;
}
