#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
// make BinarySearchTree_tests.exe
// ./BinarySearchTree_tests.exe
using namespace std;
#include <iostream>
#include <sstream>
TEST(test_empty) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());
}
TEST(test_inserts){
    BinarySearchTree<int> t;
    t.insert(22);
    ASSERT_EQUAL(t.size(), 1);
    ASSERT_TRUE(t.height() == 1);
    ASSERT_EQUAL(*t.min_element(),22);
    t.insert(11);
    t.insert(33);
    ASSERT_EQUAL(t.size(), 3);
    ASSERT_EQUAL(t.height(), 2);
    ASSERT_EQUAL(*t.min_element(), 11);
    ASSERT_TRUE(t.check_sorting_invariant());
}
TEST(printTree){
    BinarySearchTree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    t.traverse_inorder(std::cout);
    cout << endl;
    t.traverse_preorder(std::cout);
    cout << endl;
    BinarySearchTree<int> t2;
    t2.insert(8);
    t2.insert(4);
    t2.insert(5);
    t2.insert(3);
    t2.insert(7);
    t2.insert(9);
    t2.insert(6);
    t2.traverse_inorder(std::cout);
    cout << endl;
    t2.traverse_preorder(std::cout);
  

    
    
}

TEST_MAIN()
