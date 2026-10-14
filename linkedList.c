#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void insert(ListNodePtr *sPtr, char value)
{
    // Create node
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        while (currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%c not inserted. No memory available.\n", value);
    }
}

char delete(ListNodePtr *sPtr, char value)
{
    // delete first node if a match is found
    if (value == (*sPtr)->data)
    {
        ListNodePtr tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);

        return value;
    }
    else
    {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // delete node at currentPtr
        if (currentPtr != NULL)
        {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);

            return value;
        }
    }

    return '\0';
}

// Return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

void printList(ListNodePtr currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        puts("The list is: ");

        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}