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
TEST(min_element){
    BinarySearchTree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    ASSERT_EQUAL(*t.min_element(), 3);
    BinarySearchTree<int> t2;
    ASSERT_EQUAL(t2.min_element(), t2.end());
    t2.insert(1);
    t2.insert(2);
    t2.insert(3);
    ASSERT_EQUAL(*t2.min_element(), 1);
    //one element
    BinarySearchTree<int> t3;
    t3.insert(1);
    ASSERT_EQUAL(*t3.min_element(), 1);


    
}
TEST(max_element){
    BinarySearchTree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    ASSERT_EQUAL(*t.max_element(), 7);
    BinarySearchTree<int> t2;
    ASSERT_EQUAL(t2.max_element(), t2.end());
    t2.insert(10);
    t2.insert(9);
    t2.insert(8);
    ASSERT_EQUAL(*t2.max_element(), 10);
    //one element
    BinarySearchTree<int> t3;
    t3.insert(1);
    ASSERT_EQUAL(*t3.max_element(), 1);
    BinarySearchTree<int> t4;
    t4.insert(10);
    t4.insert(20);
    t4.insert(30);
    ASSERT_EQUAL(*t4.max_element(), 30);
    
}
TEST(plusplusoperator){
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(3);
    t.insert(7);
    auto it = t.begin();
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_EQUAL(*it, 6);
    ++it;
    ASSERT_EQUAL(*it, 7);
}
TEST(equalsoperator){
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(3);
    t.insert(7);
    auto it = t.begin();
    auto it2 = t.begin();
    ASSERT_TRUE(it == it2);
    ++it;
    ASSERT_TRUE(it != it2);
}
TEST(copyCtor){
    //tree w elements
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(3);
    t.insert(7);
    BinarySearchTree<int> t2(t);
    ASSERT_EQUAL(t2.size(), 3);
    ASSERT_EQUAL(t2.height(), 2);
    ASSERT_EQUAL(*t2.min_element(), 3);
    ASSERT_TRUE(t2.check_sorting_invariant());
    //empty
    BinarySearchTree<int> t3;
    BinarySearchTree<int> t4(t3);
    ASSERT_EQUAL(t4.size(), 0);
    ASSERT_EQUAL(t4.height(), 0);
    ASSERT_TRUE(t4.empty());
    //now change copied and other
    t3.insert(69);
    t3.insert(1);
    ASSERT_EQUAL(t4.size(), 0);
    t4.insert(1);
    ASSERT_EQUAL(t3.size(), 2);
    ASSERT_EQUAL(*t3.min_element(), 1);
    //diff structures
    BinarySearchTree<int> t5;
    t5.insert(1);
    t5.insert(2);
    t5.insert(3);
    t5.insert(4);
    BinarySearchTree<int> t6(t5);
    ASSERT_EQUAL(t6.size(), 4);
    ASSERT_EQUAL(t6.height(), 4);

}
TEST(assignment){
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(3);
    t.insert(7);
    BinarySearchTree<int> t2;
    t2 = t;
    ASSERT_EQUAL(t2.size(), 3);
    ASSERT_EQUAL(t2.height(), 2);
    ASSERT_EQUAL(*t2.min_element(), 3);
   
    BinarySearchTree<int> t3;
    t3.insert(1);
    t3.insert(69);
    t3 = t;
    ASSERT_EQUAL(t3.size(), 3);
    ASSERT_EQUAL(t3.height(), 2);
    ASSERT_EQUAL(*t3.min_element(), 3);
    ASSERT_TRUE(t3.check_sorting_invariant());
}
TEST(empty){
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(3);
    t.insert(7);
    ASSERT_FALSE(t.empty());
    BinarySearchTree<int> t2;
    ASSERT_TRUE(t2.empty());
    
}
TEST(begin_and_end){
    //empty tree
    BinarySearchTree<int> t;
    auto it = t.begin();
    auto itEr = t.end();
    ASSERT_EQUAL(it,itEr);
    t.insert(67);
    it = t.begin();
    itEr = t.end();
    ASSERT_EQUAL(*it,67);
    
    ASSERT_FALSE(it == itEr);
    t.insert(56);
    t.insert(45);
    t.insert(34);
    t.insert(23);
    t.begin();
    ASSERT_EQUAL(*it,67);
    ASSERT_TRUE(it != itEr);
    
    BinarySearchTree<int> kk;
    kk.insert(20);
    kk.insert(21);
    kk.insert(22);
    kk.insert(23);
    kk.insert(24);
    int expected = 20;
    for (auto it4 = kk.begin(); it4 != kk.end(); ++it4) {
        ASSERT_TRUE(*it4 == expected);
        expected += 1;
    }
    ASSERT_TRUE(kk.check_sorting_invariant());
}
TEST(find){
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(69);
    t.insert(67);
    auto it = t.find(6);
    ASSERT_EQUAL(*it, 6);
    auto it2 = t.find(69);
    ASSERT_EQUAL(*it2, 69);
    auto it3 = t.find(67);
    ASSERT_EQUAL(*it3, 67);
    BinarySearchTree<int> t2;
    auto it4 = t2.find(6);
    ASSERT_EQUAL(it4, t2.end());
    ASSERT_TRUE(t.check_sorting_invariant())
}
TEST(checksortinvariant){
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(69);
    t.insert(67);
    ASSERT_TRUE(t.check_sorting_invariant());
    BinarySearchTree<int> t2;
    ASSERT_TRUE(t2.check_sorting_invariant());
    t2.insert(1);
    ASSERT_TRUE(t2.check_sorting_invariant());
    auto it = t.begin();
    *it = 100;
    ASSERT_FALSE(t.check_sorting_invariant());
    BinarySearchTree<int> t3;
    t3.insert(18);
    t3.insert(13);
    t3.insert(23);
    t3.insert(21);
    t3.insert(28);
    ASSERT_TRUE(t3.check_sorting_invariant());
    auto it4 = t3.find(28);
    ASSERT_FALSE(t3.end() == it4);
    *it4 = 15;
    ASSERT_FALSE(t3.check_sorting_invariant());
    BinarySearchTree<int> t4;
    t4.insert(63);
    t4.insert(45);
    t4.insert(90);
    auto it1 = t4.find(45);
    *it1 = 72;
    ASSERT_FALSE(t4.check_sorting_invariant());
    BinarySearchTree<int> t5;
    t5.insert(27);
    t5.insert(18);
    t5.insert(36);
    auto it2 = t5.find(36);
    *it2 = 20;
    ASSERT_FALSE(t5.check_sorting_invariant());
}
//this is to figure out which test has a false positive

TEST(one_node_greater_replacement_check_sorts){
    BinarySearchTree<int> mc;
    mc.insert(22);
    mc.insert(21);
    auto it5 = mc.find(21);
    *it5 = 23;
    ASSERT_FALSE(mc.check_sorting_invariant());
}
TEST(insert_greater_val_in_left_check_sorts){
    BinarySearchTree<int> am;
    am.insert(108);
    am.insert(54);
    am.insert(27);
    am.insert(72);
    auto it6 = am.find(27);
    *it6 = 117;  
    ASSERT_FALSE(am.check_sorting_invariant());
}
TEST(swap_in_lesser_value_in_right_branch_check_sorts){
    BinarySearchTree<int> kr;
    kr.insert(7);
    kr.insert(9);
    kr.insert(8); 
    auto it7 = kr.find(8);
    *it7 = 4;  
    ASSERT_FALSE(kr.check_sorting_invariant());
}
TEST(swap_in_greater_value_in_left_branch_check_sorts){
    BinarySearchTree<int> t6;
    t6.insert(54);
    t6.insert(27);
    t6.insert(45);
    t6.insert(36);
    ASSERT_TRUE(t6.check_sorting_invariant());
    auto it3 = t6.find(45);
    *it3 = 55;
    ASSERT_FALSE(t6.check_sorting_invariant());
}



TEST_MAIN()
