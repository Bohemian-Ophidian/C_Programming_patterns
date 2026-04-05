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

void printInorder(TreeNode* root){
        //recursive 
        if(root == NULL)
                return;
        printInorder(root->left);
        printf("%d\t", root->data);
        printInorder(root->right);
        return;
}

void printPostorder(TreeNode* root){
        if(root == NULL)
                return;
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d\t", root->data);
        return;
}

void printPreorder(TreeNode* root){
        if(root == NULL)
                return;
        printf("%d\t", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
        return;
}

TreeNode* findSuccessor(TreeNode** root){
        if((*root)->left == NULL){
                TreeNode* temp = *root;
                *root = (*root)->right;
                return temp;
        }
        return findSuccessor(&(*root)->left);
}



void deleteNode(TreeNode** root, int data){
        if(*root == NULL)
                return;
        if((*root)->data >data)
                deleteNode(&(*root)->left, data);
        else if ((*root)->data <data)
                deleteNode(&(*root)->right, data);
        else {
                if((*root)->left == NULL && (*root)->right == NULL){
                        free(*root);
                        *root = NULL;
                        return;
                }
                else if((*root)->right == NULL){
                        TreeNode* temp = *root;
                        *root = (*root)->left;
                        free(temp);
                }
                else if((*root)->left == NULL){
                        TreeNode* temp = *root;
                        *root = (*root)->right;
                        free(temp);
                }
                else {
                        TreeNode* temp = *root;
                        *root = findSuccessor(&(*root)->right);
                        (*root)->left = temp->left;
                        if(temp->right != *root){
                            (*root)->right = temp->right;
                        }
                        free(temp);
                }
                      

        }
}

int main(void){
        TreeNode* root = initTreeNode();
        insertTreeNode(&root, 16);
        insertTreeNode(&root, 17);
        insertTreeNode(&root, 15);
        insertTreeNode(&root, 20);
        insertTreeNode(&root, 21);
        insertTreeNode(&root, 13);
        insertTreeNode(&root, 14);
        insertTreeNode(&root, 77);
        insertTreeNode(&root, 78);
        insertTreeNode(&root, 55);
        insertTreeNode(&root, 8);
        insertTreeNode(&root, 1);
        insertTreeNode(&root, 2);
        printf("%d\n",root->data);
        printf("%d\n",root->left->data);
        printf("%d\n",root->right->data);
        TreeNode* ptr = findMax(root);
        printf("%d\n", ptr->data);
        printInorder(root);
        printf("\n");
        deleteNode(&root, 16);
        deleteNode(&root,21);
        deleteNode(&root, 2);
        printInorder(root);
        printf("\n");
        printPreorder(root);
        printf("\n");
        printInorder(root);

        destroyTreeNode(root);
        root = NULL;//good practice to avoid pointer pointing in unwanted spaces
        return 0;
}
