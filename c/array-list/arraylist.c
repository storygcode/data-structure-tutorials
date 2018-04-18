#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* createArrayList(int size)
{

    ArrayList *pRet = NULL;

    //array list size is greater than 0
    if (size < 0) 
    {
        printf("Error, Size is Greater than 0. in %s\n", __func__);
        return NULL;
    }

    pRet = (ArrayList *)malloc(sizeof(ArrayList));
    
    if (pRet == NULL)
    {
        printf("Error, malloc fail. in %s\n", __func__);
        return NULL;
    }

    int sizeOfNodes = sizeof(ArrayListNode) * size;

    pRet->pElement = (ArrayListNode *)malloc(sizeOfNodes);

    if (pRet->pElement == NULL)
    {
        printf("Error, malloc fail. in %s\n", __func__);
        return NULL;
    }

    pRet->size = size;
    pRet->count = 0;

    memset(pRet->pElement, 0, sizeOfNodes);

    return pRet;
}

void deleteArrayList(ArrayList* pList)
{
    if (pList != NULL)
    {
        free(pList->pElement);
        free(pList);
    }
}

int isArrayListFull(ArrayList* pList)
{

    if (pList != NULL && pList->count == pList->size)
    {
        return TRUE;
    }

    return FALSE;
}

int addArrayListElement(ArrayList* pList, int position, ArrayListNode element)
{

    if (position < 0)
    {
        printf("Error, Size is Greater than 0. in %s\n", __func__);
        return FALSE;
    }

    if (pList == NULL)
    {
        printf("Error, NULL given. in %s\n", __func__);
        return FALSE;
    }

    if (isArrayListFull(pList) == TRUE)
    {
        printf("Error,List is Full. in %s\n", __func__);
        return FALSE;
    }

    if (position <= pList->count)
    {

        for (int i = pList->count - 1; i >= position; i--)
        {
            pList->pElement[i+1] = pList->pElement[i];
        }

        pList->pElement[position] = element;

    }else {
        printf("Error, 'position' is not Proper. in %s\n", __func__);
        return FALSE;
    }

    pList->count++;

    return TRUE;
}

int removeArrayListElement(ArrayList* pList, int position)
{

    if (position < 0)
    {
        printf("Error, Size is Greater than 0. in %s\n", __func__);
        return FALSE;
    }

    if (pList == NULL)
    {
        printf("Error, NULL given. in %s\n", __func__);
        return FALSE;
    }

    if (position > pList->count)
    {
        printf("Error, 'position' is not Proper. in %s\n", __func__);
        return FALSE;
    }

    for (int i = position; i < pList->count - 1; i++)
    {
        pList->pElement[i] = pList->pElement[i + 1];
    }

    pList->count--;

    return TRUE;
}

ArrayListNode* getArrayListElement(ArrayList* pList, int position)
{
    if (position < 0)
    {
        printf("Error, Size is Greater than 0. in %s", __func__);
        return FALSE;
    }

    if (pList == NULL)
    {
        printf("Error, NULL given. in %s\n", __func__);
        return FALSE;
    }

    if (position >= getElementCount(pList))
    {
        printf("No Data in Position :%d",position);
        return NULL;
    }

    return &(pList->pElement[position]);
}

int getElementCount(ArrayList* pList)
{
    if (pList != NULL)
        return pList->count;
    return 0;
}

void displayArrayList(ArrayList* pList)
{
    if (pList == NULL)
    {
        printf("pList is Empty\n");
        return;
    }

    printf("list size     : %d\n", pList->size);
    printf("element count : %d\n", pList->count);

    for (int i = 0; i < pList->count; i++)
        printf("[%d],%d\n", i, getArrayListElement(pList, i)->data);
}