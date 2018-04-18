#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(int argc, char *argv[])
{
    ArrayList* pList1 = createArrayList(3);
    ArrayList* pList2 = createArrayList(5);
    
    ArrayListNode node;
    
    node.data = 1;
    addArrayListElement(pList1, 0, node);
    addArrayListElement(pList2, 0, node);
    displayArrayList(pList1);
    displayArrayList(pList2);

    node.data = 2;
    addArrayListElement(pList1, 1, node);
    addArrayListElement(pList2, 1, node);
    displayArrayList(pList1);
    displayArrayList(pList2);

    node.data = 3;
    addArrayListElement(pList1, 0, node);
    addArrayListElement(pList2, 0, node);
    displayArrayList(pList1);
    displayArrayList(pList2);

    node.data = 4;
    
    addArrayListElement(pList1, 3, node);
    addArrayListElement(pList2, 3, node);
    displayArrayList(pList1);
    displayArrayList(pList2);

    removeArrayListElement(pList1, 2);

    node.data = 5;
    addArrayListElement(pList1, 0, node);
    addArrayListElement(pList2, 0, node);
    displayArrayList(pList1);
    displayArrayList(pList2);
}