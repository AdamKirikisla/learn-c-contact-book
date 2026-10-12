# 📒 learn-c-contact-book

A small command-line contact book written in C. It's a practice project for learning **pointers**, **dynamic memory** (`malloc`, `realloc`, `free`) and **splitting code across files**.

## ✨ Features

| Option | Action |
|---|---|
| 1 | Add a new contact (name and phone) |
| 2 | Remove a contact by name |
| 3 | View one contact by name |
| 4 | View all contacts |
| 5 | Quit |

```
==============================
         CONTACT BOOK
==============================
  1) Add new contact
  2) Remove a contact
  3) View one contact
  4) View all contacts
  5) Quit
------------------------------
Enter a command:
```

## 🚀 Build and run

You need `gcc` and `make`.

```bash
cd src
make
./main
```

Clean up the build files with `make clean`.

## 📁 Project structure

```
src/
├── main.c      # menu loop and user input
├── contact.c   # contact functions (add, remove, view)
├── contact.h   # Contact struct and function prototypes
└── Makefile
```

## 🧠 What I'm practicing

- **`malloc`**: creates the starting array of contacts (`create_contacts`).
- **`realloc`**: grows the array by one slot for each new contact (`add_contact`).
- **`free`**: releases the array when the program quits.
- **Pointers**: `Contact *` for reading the array, and `Contact **` when a function must change the caller's pointer (because `realloc` can move the array).
- **Shifting an array**: removing a contact by copying the later ones down a slot (`remove_contact`).
- **Safe input**: `scanf` with width limits (`%49[^\n]`) so strings can't overflow their buffers, and clearing bad input with `getchar()`.
- **Header files**: keeping the struct and prototypes in `contact.h` and the code in `contact.c`.

## 📝 Notes

- A function that only reads or edits the contacts takes `Contact *`. A function that changes where the pointer points (`realloc`) takes `Contact **`.
- Unused slots left behind by a removal are cleaned up by the next `add_contact`, because its `realloc` resizes to exactly `count + 1` slots.

## 🔭 Ideas for later

- Save and load contacts from a file.
- Edit an existing contact.
- Handle duplicate names.
- Sort contacts alphabetically.
