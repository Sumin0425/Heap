#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>
#include"Heap.h"
#include<string.h>
#pragma warning(disable : 4996)


const int MAXheap = 20;
typedef struct {
	int score_p;
	char* name_p;
}person;


int compare(const person *argu1, const person *argu2)
{
	if (argu1->score_p > argu2->score_p)
	{
		return 1;
	}
	
	else if (argu1->score_p < argu2->score_p)
	{
		return -1; 
	}

	else
	{
		return 0; 
	}
}
void InitHeap(person * p)

{

	p->score_p = 0;
	p->name_p = NULL;

}

void main() {
	person* outp;
	outp = (person *)malloc(sizeof(person));
	InitHeap(outp);
	person* p;
	p = (person *)malloc(sizeof(person));
	InitHeap(p);


	int i = 0, k = 0;
	int score = 0;
	char name[20];
	HEAP* heap0;
	int rank;
	heap0 = buildHeap(MAXheap, compare);
	while (1)
	{
		printf("������ �Է� : 1, ��� ��� : 2 ����:3\n ");
		scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		printf("�̸�:");
		scanf("%s", &name);
		printf("����:");
		scanf_s("%d", &score);
		p->name_p = name;
		p->score_p = score;
		heapInsert(heap0, p);
		break;

	case 2:
		printf("����ϰ� ���� ���:");
		scanf_s("%d", &rank);
		if (rank == 1)
		{
			outp = heap0->heapAry[0];
			printf("%d���� %s�Դϴ�\n ������ �ּ���.", rank, outp->name_p);
			break;
		}
		else {
			for (k = 1; k <= rank; k++) {
				heapDelete(heap0, (void**)p);
			}
			outp = heap0->heapAry[0];
			printf("%d���� %s�Դϴ�\n ������ �ּ���.", rank, outp->name_p);
			break;
		}

	case 3:
		exit(1);
	}
}




}


