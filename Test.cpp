

#include "sources/BinaryTree.hpp"
#include "doctest.h"
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE ("letters big") {
    BinaryTree<char>  tree_of_letters;
    tree_of_letters.add_root('A')
            .add_left('A', 'B')      
            .add_left('B', 'D')      
            .add_right('B', 'E')     
            .add_right('A', 'C')     
            .add_left('C', 'F');     


    auto it =  tree_of_letters.begin_preorder();
            CHECK(*it == 'A');
    it++;
            CHECK(*it == 'B');

    stringstream output;
    for (auto it= tree_of_letters.begin_preorder(); it!= tree_of_letters.end_preorder(); ++it) {
        output << (*it) << " " ;
    }
            CHECK(output.str() == "A B D E C F ");

    stringstream output1;
    for (auto it= tree_of_letters.begin_inorder(); it!= tree_of_letters.end_inorder(); ++it) {
        output1 << (*it) << " " ;
    }
            CHECK(output1.str() == "D B E A F C ");

    stringstream output2;
    for (auto it= tree_of_letters.begin_postorder(); it!= tree_of_letters.end_postorder(); ++it) {
        output2 << (*it) << " " ;
    }
            CHECK(output2.str() == "D E B F C A ");

            CHECK_THROWS_AS( tree_of_letters.add_left(100, 2), std::invalid_argument);

}

TEST_CASE ("letters small") {
    BinaryTree<char> tree_of_letters;
    tree_of_letters.add_root('a')
            .add_left('a', 'b')      
            .add_left('b', 'd')      
            .add_right('b', 'e')     
            .add_right('a', 'c')     
            .add_left('c', 'f');     


    auto it =  tree_of_letters.begin_preorder();
            CHECK(*it == 'a');
    it++;
            CHECK(*it == 'b');

    stringstream output;
    for (auto it= tree_of_letters.begin_preorder(); it!= tree_of_letters.end_preorder(); ++it) {
        output << (*it) << " " ;
    }
            CHECK(output.str() == "a b d e c f ");

    stringstream output1;
    for (auto it= tree_of_letters.begin_inorder(); it!= tree_of_letters.end_inorder(); ++it) {
        output1 << (*it) << " " ;
    }
            CHECK(output1.str() == "d b e a f c ");

    stringstream output2;
    for (auto it= tree_of_letters.begin_postorder(); it!= tree_of_letters.end_postorder(); ++it) {
        output2 << (*it) << " " ;
    }
            CHECK(output2.str() == "d e b f c a ");

            CHECK_THROWS_AS( tree_of_letters.add_left('1', '2'), std::invalid_argument);

}


TEST_CASE ("int") {
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(2)
            .add_left(2, 0)      
            .add_right(2, 3)      
            .add_right(3, 7)     
            .add_left(7, 4)     
            .add_right(7, 8)     
            .add_right(4, 5);     

    auto it = tree_of_ints.begin_preorder();
            CHECK(*it == 2);
    it++;
            CHECK(*it == 0);

    stringstream output;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        output << (*it) << " " ;
    }
            CHECK(output.str() == "2 0 3 7 4 5 8 ");

    stringstream output1;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        output1 << (*it) << " " ;
    }
            CHECK(output1.str() == "0 2 3 4 5 7 8 ");

    stringstream output2;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        output2 << (*it) << " " ;
    }
            CHECK(output2.str() == "0 5 4 8 7 3 2 ");

    it = tree_of_ints.begin_preorder();
    it++;
    *it = 10;
    stringstream output3;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        output3 << (*it) << " " ;
    }
            CHECK(output3.str() == "2 10 3 7 4 5 8 ");

            CHECK_THROWS_AS(tree_of_ints.add_left(100, 2), std::invalid_argument);
}


TEST_CASE ("yored left") {
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(7)
            .add_left(7, 6)      
            .add_left(6, 5)      
            .add_left(5, 4)     
            .add_left(4, 3)     
            .add_left(3, 2)     
            .add_left(2, 1);     

    auto it = tree_of_ints.begin_preorder();
            CHECK(*it == 7);
    it++;
            CHECK(*it == 6);

    stringstream output;
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it) {
        output << (*it) << " ";
    }
            CHECK(output.str() == "7 6 5 4 3 2 1 ");


    stringstream output1;
    for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it) {
        output1 << (*it) << " ";
    }
            CHECK(output1.str() == "1 2 3 4 5 6 7 ");

    stringstream output2;
    for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it) {
        output2 << (*it) << " ";
    }
            CHECK(output2.str() == "1 2 3 4 5 6 7 ");
    it = tree_of_ints.begin_preorder();
    it++;
    *it = 108;
    stringstream output3;
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it) {
        output3 << (*it) << " ";
    }
            CHECK(output3.str() == "7 108 5 4 3 2 1 ");
}


TEST_CASE ("yored right") {
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
            .add_right(1, 2)      
            .add_right(2, 3)      
            .add_right(3, 4)     
            .add_right(4, 5)     
            .add_right(5, 6)     
            .add_right(6, 7);     

    auto it = tree_of_ints.begin_preorder();
            CHECK(*it == 1);
    it++;
            CHECK(*it == 2);

    stringstream output;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        output << (*it) << " " ;
    }
            CHECK(output.str() == "1 2 3 4 5 6 7 ");


    stringstream output1;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        output1 << (*it) << " " ;
    }
            CHECK(output1.str() == "1 2 3 4 5 6 7 ");

    stringstream output2;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        output2 << (*it) << " " ;
    }
            CHECK(output2.str() == "7 6 5 4 3 2 1 ");

    it = tree_of_ints.begin_postorder();
    it++;
    *it = 77;
    stringstream output3;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        output3 << (*it) << " " ;
    }
            CHECK(output3.str() == "7 77 5 4 3 2 1 ");

            CHECK_THROWS_AS(tree_of_ints.add_left(10000, 2), std::invalid_argument);
}



TEST_CASE ("Incomplete numbers and int") {
    BinaryTree<double> tree_of_ints_double;
    tree_of_ints_double.add_root(5)
            .add_left(5, 8)      
            .add_right(5, 9.5)      
            .add_left(8, 7.5)     
            .add_right(8, 1)     
            .add_right(9.5,
                       101)     
            .add_left(9.5, 100);     

    auto it = tree_of_ints_double.begin_preorder();
            CHECK(*it == 5);
    it++;
            CHECK(*it == 8);

    stringstream output;
    for (auto it = tree_of_ints_double.begin_preorder(); it != tree_of_ints_double.end_preorder(); ++it) {
        output << (*it) << " ";
    }
            CHECK(output.str() == "5 8 7.5 1 9.5 100 101 ");


    stringstream output1;
    for (auto it = tree_of_ints_double.begin_inorder(); it != tree_of_ints_double.end_inorder(); ++it) {
        output1 << (*it) << " ";
    }
            CHECK(output1.str() == "7.5 8 1 5 100 9.5 101 ");

    stringstream output2;
    for (auto it = tree_of_ints_double.begin_postorder(); it != tree_of_ints_double.end_postorder(); ++it) {
        output2 << (*it) << " ";
    }
            CHECK(output2.str() == "7.5 1 8 100 101 9.5 5 ");
    it = tree_of_ints_double.begin_postorder();
    it++;
    *it = 9;
    stringstream output3;
    for (auto it = tree_of_ints_double.begin_preorder(); it != tree_of_ints_double.end_preorder(); ++it) {
        output3 << (*it) << " ";
    }
            CHECK(output3.str() == "5 8 7.5 9 9.5 100 101 ");

            CHECK_THROWS_AS(tree_of_ints_double.add_left(10000, 2), std::invalid_argument);
}



TEST_CASE ("Incomplete numbers") {
    BinaryTree<double> tree_Incomplete_numbers;
    tree_Incomplete_numbers.add_root(1.5)
            .add_left(1.5, 2.5)      
            .add_right(1.5, 3.5)      
            .add_left(2.5, 4.5)     
            .add_right(2.5, 5.5);     

    auto it = tree_Incomplete_numbers.begin_preorder();
            CHECK(*it == 1.5);
    it++;
            CHECK(*it == 2.5);

    stringstream output;
    for (auto it = tree_Incomplete_numbers.begin_preorder(); it != tree_Incomplete_numbers.end_preorder(); ++it) {
        output << (*it) << " ";
    }
            CHECK(output.str() == "1.5 2.5 4.5 5.5 3.5 ");


    stringstream output1;
    for (auto it = tree_Incomplete_numbers.begin_inorder(); it != tree_Incomplete_numbers.end_inorder(); ++it) {
        output1 << (*it) << " ";
    }
            CHECK(output1.str() == "4.5 2.5 5.5 1.5 3.5 ");

    stringstream output2;
    for (auto it = tree_Incomplete_numbers.begin_postorder(); it != tree_Incomplete_numbers.end_postorder(); ++it) {
        output2 << (*it) << " ";
    }
            CHECK(output2.str() == "4.5 5.5 2.5 3.5 1.5 ");
    it = tree_Incomplete_numbers.begin_preorder();
    it++;
    *it = 9.9;
    stringstream output3;
    for (auto it = tree_Incomplete_numbers.begin_preorder(); it != tree_Incomplete_numbers.end_preorder(); ++it) {
        output3 << (*it) << " ";
    }
            CHECK(output3.str() == "1.5 9.9 4.5 5.5 3.5 ");

            CHECK_THROWS_AS(tree_Incomplete_numbers.add_left(10000, 2), std::invalid_argument);
}



TEST_CASE ("mixed") {
    BinaryTree<string> mixed;
    mixed.add_root("2")
            .add_left("2", "a")      
            .add_right("2", "nofar")      
            .add_left("a", "1000")     
            .add_left("nofar", "2.5")     

            .add_right("nofar", "3.5");     

    auto it = mixed.begin_preorder();
            CHECK(*it =="2");
    it++;
            CHECK(*it == "a");

    stringstream output;
    for (auto it = mixed.begin_preorder(); it != mixed.end_preorder(); ++it) {
        output << (*it) << " ";
    }
            CHECK(output.str() == "2 a 1000 nofar 2.5 3.5 ");


    stringstream output1;
    for (auto it = mixed.begin_inorder(); it != mixed.end_inorder(); ++it) {
        output1 << (*it) << " ";
    }
            CHECK(output1.str() == "1000 a 2 2.5 nofar 3.5 ");

    stringstream output2;
    for (auto it = mixed.begin_postorder(); it != mixed.end_postorder(); ++it) {
        output2 << (*it) << " ";
    }
            CHECK(output2.str() == "1000 a 2.5 3.5 nofar 2 ");
    it = mixed.begin_preorder();
    it++;
    *it = "b";
    stringstream output3;
    for (auto it =mixed.begin_preorder(); it != mixed.end_preorder(); ++it) {
        output3 << (*it) << " ";
    }
            CHECK(output3.str() == "2 b 1000 nofar 2.5 3.5 ");

            CHECK_THROWS_AS(mixed.add_left("10000", "2"), std::invalid_argument);
}



TEST_CASE ("Overrun and replacement") {
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(100)
            .add_left(100, 50)      
            .add_right(100, 150)      
            .add_left(50, 0)     
            .add_right(50, 60)     
            .add_left(150, 140)     
            .add_right(150, 200);     

    auto it = tree_of_ints.begin_preorder();
            CHECK(*it == 100);
    it++;
            CHECK(*it == 50);

    stringstream output;
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it) {
        output << (*it) << " ";
    }
            CHECK(output.str() == "100 50 0 60 150 140 200 ");


    stringstream output1;
    for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it) {
        output1 << (*it) << " ";
    }
            CHECK(output1.str() == "0 50 60 100 140 150 200 ");

    stringstream output2;
    for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it) {
        output2 << (*it) << " ";
    }
            CHECK(output2.str() == "0 60 50 140 200 150 100 ");

    tree_of_ints.add_left(100, 40)
            .add_left(40,1)
            .add_left(140, 130);


    stringstream output4;
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it) {
        output4 << (*it) << " ";
    }
            CHECK(output4.str() == "100 40 1 60 150 140 130 200 ");


    stringstream output5;
    for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it) {
        output5 << (*it) << " ";
    }
            CHECK(output5.str() == "1 40 60 100 130 140 150 200 ");

    stringstream output6;
    for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it) {
        output6 << (*it) << " ";
    }
            CHECK(output6.str() == "1 60 40 130 140 200 150 100 ");

}
