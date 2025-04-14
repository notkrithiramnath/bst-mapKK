#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
// make BinarySearchTree_tests.exe
// ./BinarySearchTree_tests.exe

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
}
TEST(duplicates){
    
}

TEST_MAIN()
