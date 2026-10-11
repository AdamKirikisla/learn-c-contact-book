#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int main()
{
    Contact *contacts = create_contacts();
    if (contacts == NULL)
        return 1;

    for (int i = 0; i < 2; i++)
        printf("\%s, %s\n", contacts[i].name, contacts[i].phone);

    free(contacts);
    contacts = NULL;
    return 0;
}
