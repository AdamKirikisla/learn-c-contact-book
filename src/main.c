#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int main()
{
    char person[50];
    char number[15];
    int controller = 0;

    int count = 2;

    Contact *contacts = create_contacts();
    if (contacts == NULL)
        return 1;

    do
    {
        printf("\n==============================\n");
        printf("         CONTACT BOOK\n");
        printf("==============================\n");
        printf("  1) Add new contact\n");
        printf("  2) Remove a contact\n");
        printf("  3) View one contact\n");
        printf("  4) View all contacts\n");
        printf("  5) Quit\n");
        printf("------------------------------\n");
        printf("Enter a command: ");

        // scanf returns how many values it read: 1 = got a number, 0 = not a number.
        // So != 1 means the user typed something that isn't a number (like "abc").
        if (scanf("%d", &controller) != 1)
        {
            // controller was never set, so reset it to 0 (not a menu option)
            // -> the switch goes to default and prints "Wrong input"
            controller = 0;

            // The bad text ("abc") is still waiting in the input. If we leave it,
            // the next scanf fails on it again, forever.
            // ch holds one character at a time. It is an int because getchar()
            // can also return EOF (end of input, usually -1), which doesn't fit in a char.
            int ch;

            // Each pass: getchar() takes one character, stores it in ch, and we check it.
            // - not Enter ('\n') and not EOF -> condition true, go again
            // - Enter or EOF -> condition false, stop
            // The body is empty (;) because the reading happens in the condition.
            // Example: input "ab" + Enter -> takes a, b, then Enter, and the input is empty.
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }

        switch (controller)
        {
        case 1:
            printf("Enter the contact's name: ");
            scanf(" %49[^\n]", person); // 49 manual limit and you can add spacing
            printf("Enter the contact's number: ");
            scanf(" %14[^\n]", number);
            add_contact(&contacts, &count, person, number);
            break;

        case 2:
            printf("Who would you like to remove from your contacts: ");
            scanf(" %49[^\n]", person);
            remove_contact(&contacts, &count, person);
            break;

        case 3:
            printf("Enter the contact's name: ");
            scanf(" %49[^\n]", person);
            view_contact(contacts, count, person);
            break;

        case 4:
            view_all_contacts(contacts, count);
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
