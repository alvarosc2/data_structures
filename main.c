#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// Prototypes
void instructions(void);

// Functions
void instructions(void)
{
    puts("Enter your choice:\n"
         "    1 to insert an element into the list.\n"
         "    2 to delete an element from the list.\n"
         "    3 to quit.");
}

int main(void)
{
    ListNodePtr startPtr = NULL;
    char item;

    instructions();
    printf("%s", "? ");
    unsigned int choice;
    scanf("%u", &choice);

    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            /* Insert an element in the linked list */
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item);
            printList(startPtr);

            break;

        case 2:
            /* Delete an element */
            if (!isEmpty(startPtr))
            {
                printf("%s", "Enter character to be deleted: ");
                scanf("\n%c", &item);

                if (delete(&startPtr, item))
                {
                    printf("%c deleted.\n", item);
                    printList(startPtr);
                }
                else
                {
                    printf("%c not found.\n\n", item);
                }
            }
            else
            {
                puts("List is empty.\n");
            }
            break;

        default:
            puts("Invalid choice.\n");
            instructions();
            break;
        }

        printf("%s", "? ");
        scanf("%u", &choice);
    }

    puts("End of the program.");

    return 0;
}