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
/*TEST(duplicates){
    BinarySearchTree<int> t3;
    t3.insert(5);
    t3.insert(4);
    t3.insert(6);
    t3.insert(4);
    ASSERT_EQUAL(t3.size(),3);
    ASSERT_EQUAL(t3.height(),2);
    
}*/
TEST(test_find){
    BinarySearchTree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    cout << " inserted" << endl;
    ASSERT_EQUAL(*t.find(5), 5);
    cout << " inserted 5" << endl;
    ASSERT_EQUAL(*t.find(3), 3);
    cout << " inserted 3" << endl;

    ASSERT_EQUAL(*t.find(7), 7);
    cout << " found 7" << endl;
    
}
TEST(mingreaterIMPL){
    
    BinarySearchTree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    ASSERT_EQUAL(*t.min_greater_than(4), 5);
    cout << "1" << endl;
    ASSERT_EQUAL(*t.min_greater_than(6), 7);
    cout << "2" << endl;
    
}
TEST_MAIN()
