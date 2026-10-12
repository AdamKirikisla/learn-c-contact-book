#ifndef CONTACT_H
#define CONTACT_H

typedef struct
{
    char name[50];
    char phone[15];
} Contact;

Contact *create_contacts(void);
void add_contact(Contact **contacts, int *count, const char *name, const char *phone);
void remove_contact(Contact **contacts, int *count, char *person);
void view_contacts(Contact *contacts, int count, char *person);
void view_all_contacts(Contact *contacts, int count);

#endif
