#include <stdio.h>
#include <stdlib.h>

typedef struct NTreeNode {
        int data;
        struct NTreeNode* firstChild;
        struct NTreeNode* nextSibling;
}NTreeNode;

NTreeNode* createNode(int data){
        NTreeNode* out = (NTreeNode*)malloc(sizeof(NTreeNode));
        out->data = data;
        out->firstChild = NULL;
        out->nextSibling = NULL;
        return out;
}

int main(void){
        NTreeNode* newnode = NULL;
        newnode = createNode(15);
        printf("%d \n", newnode->data);
        return 0;
}

