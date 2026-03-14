#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
}TreeNode;

TreeNode* initTreeNode(){
        return NULL;
}

void destroyTreeNode(TreeNode* root){
        if(root == NULL){
                return;
        }

        destroyTreeNode(root->left);
        destroyTreeNode(root->right);
        free(root);
        return;
}

void destroyTree(TreeNode** root){
        if(*root == NULL){
                return;
        }

        destroyTree(&(*root)->left);
        destroyTree(&(*root)->right);
        free(*root);
        root = NULL;
        return;
}// although the above function may seem redundant; it shows alternative ways of programming the same function


TreeNode* createTreeNode(int data){
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        if(newNode == NULL){// add memory cleanup code
                fprintf(stderr, "Error: Memory allocation failed. Shutting down. \n");
                exit(EXIT_FAILURE);
        }
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = data;
        return newNode;
}

void insertTreeNode(TreeNode** root, int data){
        if(*root == NULL){
                *root = createTreeNode(data);
                return;
        }
        if((*root)->data >= data){
                return insertTreeNode(&(*root)->left, data);
        }
        if((*root)->data < data){
                return insertTreeNode(&(*root)->right, data);
        }

}
TreeNode* searchTreeNode(TreeNode* root, int data){
        while(root!=NULL){
                if(root->data == data)
                        return root;
                else if(root->data > data)
                        root = root->left;
                else if(root->data < data)
                        root = root->right;
        }
        return NULL;
}
TreeNode* findMin(TreeNode* root){
        if(root == NULL)
                return NULL;
        while(root->left!= NULL){
                root = root->left;
        }

        return root;
}
TreeNode* findMax(TreeNode* root){
        if(root == NULL)
                return NULL;
        while(root->right != NULL){
                root = root->right;
        }
        return root;
}
int main(void){
        TreeNode* root = initTreeNode();
        insertTreeNode(&root, 16);
        insertTreeNode(&root, 17);
        insertTreeNode(&root, 15);
        printf("%d\n",root->data);
        printf("%d\n",root->left->data);
        printf("%d\n",root->right->data);
        TreeNode* ptr = searchTreeNode(root, 16);
        printf("%d\n", ptr->data);
        destroyTreeNode(root);
        root = NULL;//good practice to avoid pointer pointing in unwanted spaces
        return 0;
}
