#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

    TreeNode<T>* LCA(TreeNode<T> *root, T node1, T node2){
        if (root == nullptr) return nullptr;
        if (root->val == node1 || root->val == node2) return root;

        TreeNode<T>* left = LCA(root->left, node1, node2);
        TreeNode<T>* right = LCA(root->right, node1, node2);

        if (left == nullptr && right == nullptr) return nullptr;
        if (left != nullptr && right != nullptr) return root;

        return left == nullptr ? right : left;

    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    void traverseInOrder(std::vector<T>* order) override {
        // homework, to be done iteratively
        LinkedStack<TreeNode<T>*> stack;
        TreeNode<T>* current = root;
        while (current != nullptr || !stack.isEmpty()){
            while (current != nullptr){
                stack.push(current);
                current = current->getLeft();
            }
            current = stack.peek();
            stack.pop();
            order->push_back(current->val);
            //std::cout << current->val << std::endl;
            current = current->getRight();
        }
    }

    void traversePreOrder() override {
        // don't bother
    }
    void traversePostOrder(std::vector<T>* order) override {
        // homework, to be done iteratively
        LinkedStack<TreeNode<T>*> stack;
        TreeNode<T> *current = root;
        while (true){
            while (current != nullptr) {
                stack.push(current);
                stack.push(current);
                current = current->getLeft();
            }
            if (stack.isEmpty()) return;
            current = stack.peek();
            stack.pop();
            if (!stack.isEmpty() && stack.peek() == current) current = current->getRight();
            else{
                order->push_back(current->val);
                //std::cout << current->val << std::endl;
                current = nullptr;
            }
        }
    }

    virtual ~BinaryTree() {
        clear(root);
        root = nullptr;
    }

    T LCA(T node1, T node2) {
        TreeNode<T>* node = LCA(root, node1, node2);
        return node == nullptr ? -1 : node->val;
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

    void clear(TreeNode<T> *root){
        delete root;
        if (root->left != nullptr){
            clear(root->left);
        }
        if (root->right != nullptr){
            clear(root->right);
        }
    }

};
