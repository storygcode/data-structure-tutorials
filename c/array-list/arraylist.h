#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
    int data;
} ArrayListNode;

typedef struct ArrayListType
{
    int size;
    int count;
    ArrayListNode* pElement;
} ArrayList;

ArrayList* createArrayList(int size);
void deleteArrayList(ArrayList *pList);
int isArrayListFull(ArrayList *pList);
int addArrayListElement(ArrayList *pList, int position, ArrayListNode element);
int removeArrayListElement(ArrayList *pList, int position);
ArrayListNode *getArrayListElement(ArrayList *pList, int position);
int getElementCount(ArrayList *pList);
void displayArrayList(ArrayList *pList);
void clearArrayList(ArrayList *pList);


#endif

#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__

#define TRUE 1
#define FALSE 0

#endif

