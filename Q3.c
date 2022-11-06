#pragma warning(disable:4996) 
#include <stdio.h> 
#include <stdlib.h> 

// struct to collect counting info about english letters found in a text file. 

typedef struct letter {

    char small;
    char big;
    int counter;
    
    struct letter* next; //added next and prev
    struct letter* prev;
}letter;

//Function to free linked list 

void freeList(letter* head) {
    letter* releaseItem;
    letter* runItem = head;
    while (runItem != NULL) {

        releaseItem = runItem;

        runItem = runItem->next;

        free(releaseItem);

    }

}
int main()

{

    //Next two string represents all the english alphabets (small and capital) 
    char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";

    char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //CHANGE number FROM 20 TO 26
    int lettersCountArr[26] = { 0 };

    char readChar, ch;

    FILE* f;

    //Creating the text file
    f = fopen("myFile.txt", "w");
    fputs("Who dares Wins.", f);
    fclose(f);

    f = fopen("myFile.txt", "r");

    // Display the content of myFile.txt and count letters 
    printf("the content of myFile.txt :\n");

    //changed in the while from !=0 to != EOF
    while ((readChar = fgetc(f)) != EOF) {

        printf("%c", readChar);

        for (int i = 0; i < strlen(smallAlpha); ++i) {

            if (readChar == smallAlpha[i] || readChar == bigAlpha[i])

                lettersCountArr[i]++;
        }
    }

    fclose(f);

    // Build Linked list from file content 
    // Every node represent English letter (small and big). 

    letter* HEAD = NULL;
    letter* TAIL = NULL;

    for (int j = 0; j < strlen(smallAlpha); ++j) {

        letter* letterItem = (letter*)malloc(sizeof(letter));

        if (!letterItem) {

            puts("Error Allocating Memory!");
            exit(1);

        }
        letterItem->small = 'a' + j;
        letterItem->big = 'A' + j;
        letterItem->counter = lettersCountArr[j];

        // Creating the linked list 
        if (HEAD == NULL) //editing of the definitions
        {
            HEAD = TAIL = letterItem;
            letterItem->next = NULL;
            letterItem->prev = NULL;
        }
        else
        {
            TAIL->next = letterItem;
            letterItem->prev = TAIL;
            letterItem->next = NULL;
            TAIL = letterItem;
        }
    }

    return 0;
}