//
// Created by tahak on 8/29/2023.
//
#ifndef LABB3_BST_SEARCH_H
#define LABB3_BST_SEARCH_H

#include "searching.h"

struct BstNode {
    int key;
    BstNode* left;
    BstNode* right;
};

class BST_Search {
private:
    std::vector<int> &primeVec;

public:
    explicit BST_Search(std::vector<int>& vec);
    BstNode *newNode(int data);
    BstNode *assignBST(int start, int end);
    void printTree(struct BstNode* root);
    bool bstSearch(struct BstNode* root, int find);
    void deleteTree(struct BstNode* root);
};


#endif //LABB3_BST_SEARCH_H
