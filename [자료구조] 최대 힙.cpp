#include <iostream> /* YCY */
#define CompPriority(X, Y) X - Y /* 우선순위 비교 매크로 */
#define GetParentIDX(X) X/2 /* 부모 노드의 인덱스 값 반환 매크로 - (자식 노드의 인덱스 값 / 2) */
#define GetLChildIDX(X) X*2 /* 왼쪽 자식 노드의 인덱스 값 반환 매크로 - (부모 노드의 인덱스 값 * 2) */
#define GetRChildIDX(X) X*2+1 /* 오른쪽 자식 노드의 인덱스 값 반환 매크로 - (부모 노드의 인덱스 값 * 2 + 1) */
using namespace std;
 
/* Struct */
typedef struct min_heap * PtrHeap;
typedef struct min_heap
{
    int numOfData; /* Heap Length */
    int heapArray[100010]; /* Heap Data Array */
} MIN_HEAP;
MIN_HEAP mHeap = { 0, {0, } };
 
/* 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환 함수 */
int GetHiPriChildIDX(PtrHeap mHeap, int idx)
{
    /* 자식 노드가 존재하지 않는 경우 */
    if (GetLChildIDX(idx) > mHeap->numOfData) { return 0; }
    /* 자식 노드가 왼쪽 자식 노드 하나만 존재하는 경우 */
    else if (GetLChildIDX(idx) == mHeap->numOfData) { return GetLChildIDX(idx); } 
    /* 자식 노드가 둘 다 존재하는 경우 */
    else { return CompPriority(mHeap->heapArray[GetLChildIDX(idx)], mHeap->heapArray[GetRChildIDX(idx)]) < 0 ? GetRChildIDX(idx) : GetLChildIDX(idx); }
    /* 
        1. return GetRChildIDX() = 오른쪽 자식 노드의 우선순위가 높은 경우
        2. return GetLChildIDX() = 왼쪽 자식 노드의 우선순위가 높은 경우
    */
}
 
/* Heap Insert Method */
void HeapInsert(PtrHeap mHeap, int num)
{
    /* Integer */
    int idx = mHeap->numOfData + 1; /* 새 노드가 저장 될 인덱스 값 저장 */
 
    while (idx != 1)
    {
        /* 새 노드의 우선순위가 높은 경우 */
        if (CompPriority(num, mHeap->heapArray[GetParentIDX(idx)]) > 0)
        {
            mHeap->heapArray[idx] = mHeap->heapArray[GetParentIDX(idx)]; /* 부모 노드를 한 레벨 내린다. */
            idx = GetParentIDX(idx); /* 새 노드를 한 레벨 올린다. */
        } else { break; } /* 새 노드의 우선순위가 낮은 경우 */
    }
 
    mHeap->heapArray[idx] = num; /* 새 노드를 배열에 저장 */
    mHeap->numOfData++; /* 힙의 수 증가 */
}
 
/* Heap Delete Method */
int HeapDelete(PtrHeap mHeap)
{
    /* Integer */
    const int retData = mHeap->heapArray[1]; /* 반환을 위해 힙에서 삭제 할 데이터 */
    int lastElem = mHeap->heapArray[mHeap->numOfData]; /* 힙의 마지막 노드 값 저장 */
    int parentIDX = 1; /* 루트 노드가 위치해야 할 인덱스 값 저장 */
    int childIDX = 0;
 
    /* 루트 노드의 우선순위가 높은 자식 노드를 시작하는 반복문 */
    while (childIDX = GetHiPriChildIDX(mHeap, parentIDX))
    {
        /* 마지막 노드의 우선순위과 높은 경우 */
        if (CompPriority(lastElem, mHeap->heapArray[childIDX]) >= 0) { break; }
        /* 마지막 노드의 우선순위가 낮은 경우 */
 
        /* 비교대상 노드의 위치를 한 레벨 올린다. */
        mHeap->heapArray[parentIDX] = mHeap->heapArray[childIDX];
        /* 마지막 노드가 저장 될 위치정보를 한 레벨 내린다. */
        parentIDX = childIDX;
    } /* 반복문을 탈출하면 ParentIDX 에는 마지막 노드의 위치 정보가 저장된다. */
 
    mHeap->heapArray[parentIDX] = lastElem; /* 마지막 노드의 최종 저장 */
    mHeap->numOfData--; /* 힙의 수 감소 */
 
    /* 힙에서 삭제 된 값 반환 */
    return retData;
}
 
int main(void)
{
    /* Integer */
    int num = 0, mTemp;
    cin >> num;
 
    for (int count = 0; count < num; count++)
    {
        /* input */
        cin >> mTemp;
 
        /* output */
        mTemp != 0 ? HeapInsert(&mHeap, mTemp) : printf("%d\n", (mHeap.numOfData == 0 ? 0 : HeapDelete(&mHeap)));
    }
 
    return 0;
}
