#include <assert.h>
#include <stdio.h>

#include "linkedList.h"

int main(void)
{
    ListNode node = {'a', NULL};

    assert(isEmpty(NULL));
    assert(!isEmpty(&node));

    puts("All linked-list tests passed.");
    return 0;
}
