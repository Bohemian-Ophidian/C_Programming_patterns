#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void Traverse(NTreeNode* root){
        if(root == NULL)
                return;
        printf("%d \t", root->data);
        Traverse(root->firstChild);
        Traverse(root->nextSibling);
        return;
}

void levelOrderTraversal(NTreeNode* root){
        //pass for now
}

int getDegree(NTreeNode* parent){
        int deg = 0;
        NTreeNode* child = parent->firstChild;
        while(child != NULL){
                deg++;
                child = child->nextSibling;
        }
        return deg;
}

bool isLeaf(NTreeNode* node){
        if(node->firstChild== NULL)
                return true;
        else
                return false;
}

NTreeNode* findNode(NTreeNode* parent, int data){
        if(parent == NULL)
                return NULL;
        else if(parent->data == data)
                return parent;
        else{
                NTreeNode* resDepth = findNode(parent->firstChild, data);
                if(resDepth !=NULL)
                        return resDepth;
                else
                        return findNode(parent->nextSibling, data);
        }
        return NULL;
}


int main(void){
        NTreeNode* newnode = NULL;
        newnode = createNode(15);
        addChild(newnode, 17);
        addChild(newnode, 18);
        addChild(newnode, 26);
        addChild(newnode->firstChild, 21);
        addChild(newnode->firstChild->nextSibling, 22);
        Traverse(newnode);
        printf("\n");
        printf("The degree of the parent is %d", getDegree(newnode));
        printf("\n");
        printf("The check for being the leaf node : %d", isLeaf(newnode));
        printf("\n");
        printf("The Check for being the leaf node : %d", isLeaf(newnode->firstChild));
        printf("\n");
        NTreeNode* check = findNode(newnode, 21);
        printf("%d", check->data);

        return 0;
}

