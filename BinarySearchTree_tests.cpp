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

    //insert a crap ton of inserts 
    BinarySearchTree<int> fatTree;
    vector<int> adds = {9,18,27,36,45,54,63,72,81,90,99};
    for(int i  = 0; i < adds; i++){
        int branch = adds[i];
        fatTree.insert(branch);
    }
    ASSERT_FALSE(fatTree.empty());
    ASSERT_EQUAL(fatTree.height(), 11); //checks height for right skewed tree
    ASSERT_EQUAL(fatTree.size(),11);
    ASSERT_EQUAL(*fatTree.min_element(), 9);
    ASSERT_EQUAL(*fatTree.max_element(),99);
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
    
}
TEST(max_element){
    BinarySearchTree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    ASSERT_EQUAL(*t.max_element(), 7);
    
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
    BinarySearchTree<int> t;
    t.insert(6);
    t.insert(3); 
    t.insert(7);
    ASSERT_TRUE(t.check_sorting_invariant());
    BinarySearchTree<int> t2(t);
    ASSERT_EQUAL(t, t2); //checks that copy is equal
    //checks if copy has the same elements
    ASSERT_EQUAL(t2.find(6),true);
    ASSERT_EQUAL(t2.find(3),true);
    ASSERT_EQUAL(t2.find(7),true); 
    ASSERT_EQUAL(t2.size(), 3);
    ASSERT_EQUAL(t2.height(), 2);
    ASSERT_EQUAL(*t2.min_element(), 3);
    ASSERT_TRUE(t2.check_sorting_invariant());
    //modify original and make sure copy isn't changed as well
    t.insert(2);
    ASSERT_EQUAL(t2.find(2),false);
    ASSERT_TRUE(t != t2);

    //tests copy of empty tree
    BinarySearchTree<int> nerds;
    BinarySearchTree<int> gummy(nerds);
    ASSERT_EQUAL(nerds,gummy);
    ASSERT_TRUE(nerds.empty());
    ASSERT_TRUE(gummy.empty());

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
}
TEST(check_sorting_invariant){
    //no duplicates
    BinarySearchTree<int> pi;
    ASSERT_EQUAL(pi.check_sorting_invariant(), true);
    ASSERT_EQUAL(pi.insert(69),true);
    ASSERT_EQUAL(pi.insert(45),true);
    ASSERT_EQUAL(pi.insert(98),true);
    ASSERT_EQUAL(pi.insert(45),false);
    ASSERT_EQUAL(pi.size(), 3);

    //check inserts done in reverse order still satisfies invariant
    BinarySearchTree<int> frog;
    frog.insert(96);
    frog.insert(84);
    frog.insert(72);
    frog.insert(60);
    frog.insert(48);
    ASSERT_TRUE(frog.check_sorting_invariant());
}
TEST(height){
    BinarySearchTree<int> mj;
    mj.insert(54);
    mj.insert(63);
    mj.insert(45);
    mj.insert(72);
    mj.insert(36);
    mj.insert(81);
    mj.insert(27);
    mj.insert(90);
    mj.insert(18);
    ASSERT_EQUAL(mj.height(), 5); //checks height when both sides r balanced
    mj.insert(99); 
    ASSERT_EQUAL(mj.height(),6); //checks height when one side is longer.

}
TEST(==_operator){
    //empty trees = 
    BinarySearchTree<int> fp;
    BinarySearchTree<int> dp;
    ASSERT_TRUE(fp == dp);
    //empty tree != non empty tree
    fp.insert(34);
    fp.insert(45);
    fp.insert(22);
    ASSERT_FALSE(fp == dp);
    //trees with same elements but diff structures !=
    dp.insert(22);
    dp.insert(34);
    dp.insert(45);
    ASSERT_FALSE(fp == dp);

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
}



TEST_MAIN()
