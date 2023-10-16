//
// Created by tahak on 8/29/2023.
//

#include "BST_Search.h"
BST_Search::BST_Search(std::vector<int> &vec) :
        primeVec(vec){
}
BstNode *BST_Search::newNode(int data) {
    struct BstNode* tmp = (struct BstNode*)malloc(sizeof(struct BstNode));
    tmp->key = data;
    tmp->left = tmp->right = nullptr;
    return tmp;
}

BstNode *BST_Search::assignBST(int start, int end) {

    // Initial case
    if(start > end) {
        return nullptr;
    }

    int mid = (start + end + 1) / 2;
    struct BstNode* root = newNode(primeVec[mid]);

    root->left = assignBST(start, mid - 1);

    root->right = assignBST(mid + 1, end);

    return root;
}

void BST_Search::printTree(struct BstNode *root) {
    if(root != nullptr) {
        printTree(root->left);
        std::cout <<  root->key << "\n";
        printTree(root->right);
    }
}


bool BST_Search::bstSearch(struct BstNode *root, int find) {
    while(root != nullptr) {
        if(root->key == find) {
            return true;
        }
        else if(find < root->key) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return false;
}

void BST_Search::deleteTree(struct BstNode *root) {
    if(root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}