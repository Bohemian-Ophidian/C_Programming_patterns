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

void addChild(NTreeNode* parent, int data){
        NTreeNode* Node = createNode(data);
        if(parent->firstChild == NULL){
                parent->firstChild = Node;
                return;
        }
        parent = parent->firstChild;
        while(parent->nextSibling !=NULL){
                parent = parent->nextSibling;
        }
        parent->nextSibling = Node;
        return;
}

int main(void){
        NTreeNode* newnode = NULL;
        newnode = createNode(15);
        addChild(newnode, 17);
        addChild(newnode, 18);
        printf("%d \n", newnode->data);
        printf("%d \n", newnode->firstChild->data);
        printf("%d \n", newnode->firstChild->nextSibling->data);
        return 0;
}

