#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int nmb;
    struct node* left;
    struct node* right;
};

struct node* creatnode(int nmb) {
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    if (NewNode == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    NewNode->nmb = nmb;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}
int test_one(struct node* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }
    if (root->nmb < min || root->nmb > max) {
        return 0;
    }
    return test_one(root->left, min, root->nmb) && test_one(root->right, root->nmb, max);
}

int test_two(struct node* root) {
    if (root == NULL) {
        return 1;
    }
    return test_one(root->left, INT_MIN, root->nmb) && test_one(root->right, root->nmb, INT_MAX);
}

int main() {
    struct node* root = creatnode(50);
    root->left = creatnode(30);
    root->right = creatnode(70);
    root->left->left = creatnode(20);
    root->left->right = creatnode(30);
    root->right->left = creatnode(60);
    root->right->right = creatnode(80);

    if (test_two(root) == 1) {
        printf("The tree is a Binary Search Tree.\n");
    }
    else {
        printf("The tree is not a Binary Search Tree.\n");
    }

    return 0;
}
