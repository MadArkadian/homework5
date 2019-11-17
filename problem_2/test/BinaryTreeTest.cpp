#include "BinaryTree.h"
#include "gtest/gtest.h"

BinaryTree<int>* generateTree() {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(8));
    BinaryTree<int> *tree = new BinaryTree<int>(root);

    return tree;
}

TEST(tree, demo) {
    BinaryTree<int>* tree = generateTree();
    ASSERT_EQ(tree->height(),3);
    delete tree;
}

TEST(tree, inorder_iterative) {
    BinaryTree<int>* tree = generateTree();
    std::vector<int> answer{2, 1, 7, 3, 8, 5};
    std::vector<int> inOrderResult;
    tree->traverseInOrder(&inOrderResult);
    ASSERT_EQ(inOrderResult,answer);
    delete tree;
}

TEST(tree, postorder) {
    BinaryTree<int>* tree = generateTree();
    std::vector<int> answer{2, 7, 1, 8, 5, 3};
    std::vector<int> postOrderResult;
    tree->traversePostOrder(&postOrderResult);
    ASSERT_EQ(postOrderResult, answer);
    delete tree;
}

TEST(tree, LCA) {
    BinaryTree<int>* tree = generateTree();
    ASSERT_EQ(tree->LCA(1, 2), 1);
    ASSERT_EQ(tree->LCA(2, 1), 1);
    ASSERT_EQ(tree->LCA(5, 1), 3);
    ASSERT_EQ(tree->LCA(1, 5), 3);
    ASSERT_EQ(tree->LCA(2, 8), 3);
    ASSERT_EQ(tree->LCA(2, 3), 3);
    ASSERT_EQ(tree->LCA(3, 2), 3);
    ASSERT_EQ(tree->LCA(5, 5), 5);
    delete tree;
}

