#include <iostream>
#define SIZE 1001
using namespace std;
 
typedef struct tree * TreePtr;
typedef struct tree
{
    char data;
    TreePtr left;
    TreePtr right;
}Tree;
 
TreePtr LevelSearch(TreePtr mPtr, char mData)
{
    TreePtr Queue[SIZE];
    int REAR = 0, FRONT = 0;
    
    Queue[REAR] = mPtr;
    REAR = (REAR + 1) % SIZE;
 
    while (REAR != FRONT)
    {
        mPtr = Queue[FRONT];
        FRONT = (FRONT + 1) % SIZE;
        if (mPtr->data == mData) { return mPtr; }
 
        if (mPtr->left) { Queue[REAR] = mPtr->left; REAR = (REAR + 1) % SIZE; }
        if (mPtr->right) { Queue[REAR] = mPtr->right; REAR = (REAR + 1) % SIZE; }
    }
 
    return NULL;
}
 
void Inorder(TreePtr mPtr)
{
    if (mPtr)
    {
        Inorder(mPtr->left);
        cout << mPtr->data;
        Inorder(mPtr->right);
    }
}
 
void Postorder(TreePtr mPtr)
{
    if (mPtr)
    {
        Postorder(mPtr->left);
        Postorder(mPtr->right);
        cout << mPtr->data;
    }
}
 
void Preorder(TreePtr mPtr)
{
    if (mPtr)
    {
        cout << mPtr->data;
        Preorder(mPtr->left);
        Preorder(mPtr->right);
    }
}
 
int main(void)
{
    int mNum = 0;
    cin >> mNum;
 
    TreePtr Node = new Tree{'A', NULL, NULL};
    TreePtr Root = Node;
 
    char mChar[] = {NULL, NULL, NULL};
    for (int count = 0; count < mNum; count++)
    {
        cin >> mChar[0] >> mChar[1] >> mChar[2];
 
        TreePtr mTemp = LevelSearch(Root, mChar[0]);
        if (mTemp)
        {
            Node = mTemp;
            if (mChar[1] != '.') { Node->left = new Tree{ mChar[1], NULL, NULL }; }
            if (mChar[2] != '.') { Node->right = new Tree{ mChar[2], NULL, NULL }; }
        }
    }
 
    Preorder(Root); cout << endl;
    Inorder(Root); cout << endl;
    Postorder(Root); cout << endl;
 
    return 0;
}
