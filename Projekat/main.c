/*

Milica Simeunovic RA93/2018

-------------------------------------------------------------------------------

Projekat predstavlja jednostruko spregnutu listu elemenata celobrojnog tipa.
Korisnik unosi zeljenu duzinu i elemente liste s tim da je unapred postavljena
maksimalna granica duzine. Uneti elementi se dodaju na kraj glavne liste.
Koristeci funkcije moveNode() i alternatingSplit() pocetna lista razdvaja se na
dve manje tako da svaki neparni element (prvi, treci, peti...) ide u jednu a
svaki parni u drugu listu, ali u obrnutom redosledu u odnosu na redosled unosa.

Ocekivani izlaz:

This is your main list: //all elements
This is odd indexes list: //odd indexes
This is even indexes list: //even indexes

-------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SingleLinkedList.h"

#define MAX_LENGTH 30

int main(void)
{
    struct node* mainList;
    struct node* oddList;
    struct node* evenList;
    static int_least32_t n;
    static int_least32_t cnt;
    static int_least32_t i;

    printf("Enter number of elements:\n ");
    scanf("%d", &cnt);
    assert(cnt > 0 && cnt < MAX_LENGTH);

    printf("\n\n\nAdd elements to the list.\n\n");
    for (i = 1; i <= cnt; i++)
    {
        printf("Enter an integer value: ");
        scanf("%d", &n);
        addLast(&mainList, n);
    }

    printf("\n\nThis is your main list: \n");
    printList(mainList);

    alternatingSplit(mainList, &oddList, &evenList);

    printf("\n\nThis is odd indexes list: \n");
    printList(oddList);

    printf("\n\nThis is even indexes list: \n");
    printList(evenList);

    deleteList(&mainList);

    return 0;
}
