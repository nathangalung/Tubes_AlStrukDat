#include "stack.h"
#include <stdio.h>

int main() {
    Stack myStack;
    Word word1, word2;
    
    CreateEmptyStack(&myStack);
    printf("Is myStack empty? %s\n", IsEmptyStack(myStack) ? "Yes" : "No");

    word1.Length = 5;
    word1.TabWord[0] = 't';
    word1.TabWord[1] = 'e';
    word1.TabWord[2] = 's';
    Push(&myStack, word1);

    printf("Is myStack empty? %s\n", IsEmptyStack(myStack) ? "Yes" : "No");

    printf("Is myStack full? %s\n", IsFullStack(myStack) ? "Yes" : "No");

    printf("myStack length: %d\n", LengthStack(myStack));

    Pop(&myStack, &word2);
    printf("Popped word: %c%c%c\n", word2.TabWord[0], word2.TabWord[1], word2.TabWord[2]);

    return 0;
}
