#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>


#define MAX 200 

typedef struct {
	void** heapAry;
	int last;
	int size;
	int(*compare)(void* argu1, void* argu2);
	int maxSize;
} HEAP;



void reheapUP(HEAP* heap, int childLoc)
{
	int parent;
	void** heapAry;
	void* hold;

	if (childLoc)
	{
		heapAry = heap->heapAry;
		parent = (childLoc - 1) / 2;
		if (heap->compare(heapAry[childLoc],heapAry[parent])>0)
		{
			hold = heapAry[parent];
			heapAry[childLoc] = heapAry[childLoc];
			heapAry[childLoc] = hold;
			reheapUP(heap, parent);
		}
	}
	return;
}

bool heapInsert(HEAP* heap, void* dataPtr)
{
	if (heap->size == 0)
	{
		heap->size = 1;
		heap->last=0;
		heap->heapAry[heap->last] = dataPtr;
		return true;
	}
	if (heap->last == heap->maxSize - 1)
		return false;
	++(heap->last);
	++(heap->size);
	heap->heapAry[heap->last] = dataPtr;
	reheapUP(heap, heap->last);
	return true;
}

void reheapDOWN(HEAP* heap, int root)
{
	void* hold;
	void* leftData;
	void* rightData;
	int largeLoc;
	int last;

	last = heap->last;
	if ((root * 2 + 1) <= last)
	{
		leftData = heap->heapAry[root * 2 + 1];
		if ((root * 2 + 2) <= last)
			rightData = heap->heapAry[root * 2 + 2];
		else
			rightData = NULL;

		if ((!rightData) || heap->compare(leftData, rightData) > 0)
		{
			largeLoc = root * 2 + 1;
		}
		else
		{
			largeLoc = root * 2 + 2;
		}
		if (heap->compare(heap->heapAry[root], heap->heapAry[largeLoc]) < 0)
		{
			hold = heap->heapAry[root];
			heap->heapAry[root] = heap->heapAry[largeLoc];
			heap->heapAry[largeLoc] = hold;
			reheapDOWN(heap, largeLoc);
		}
		
	}return;
}

void* heapDelete(HEAP* heap, void** dataOutPtr)
{
	if (heap->size == 0)
		return false;
	(*dataOutPtr) = heap->heapAry[0];
	heap->heapAry[0] = heap->heapAry[heap->last];
	(heap->last)--;
	(heap->size)--;
	reheapDOWN(heap, 0);
	return (*dataOutPtr);
}

HEAP* buildHeap(int maxSize, int(*compare)(void* argu1, void* argu2))
{
	HEAP* heap;
	heap = (HEAP*)malloc(sizeof(HEAP));
	if (!heap)
		return NULL;

	heap->last = -1;
	heap->compare = compare;

	heap->maxSize = (int)pow(2, ceil(log2(maxSize))) - 1;
	heap->heapAry = (void*)calloc(heap->maxSize, sizeof(void*));
	return heap;
}