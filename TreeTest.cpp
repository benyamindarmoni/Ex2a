/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
   .CHECK_OK    (emptytree.insert(50)) 
   .CHECK_OK    (emptytree.insert(5)) 
   .CHECK_OK    (emptytree.insert(60)) 
   .CHECK_OK    (emptytree.remove(50))
   .CHECK_EQUAL (emptytree.size() ,2)
    .CHECK_EQUAL (emptytree.root() ,5)
    .CHECK_EQUAL (emptytree.right(5) ,60)
   .CHECK_OK    (emptytree.insert(61)) 
    .CHECK_OK    (emptytree.insert(62)) 
       
        
         .CHECK_OK    (emptytree.remove(5))
         .CHECK_THROWS(emptytree.remove(5))
          .CHECK_EQUAL(emptytree.root(),60)
           .CHECK_THROWS(emptytree.left(60))
            .CHECK_THROWS(emptytree.right(62))
           .CHECK_THROWS(emptytree.parent(60))
            .CHECK_OK    (emptytree.insert(2)) 
              .CHECK_EQUAL (emptytree.size() ,4)
               .CHECK_OK    (emptytree.remove(60))
                .CHECK_EQUAL (emptytree.root() ,2)
                .CHECK_EQUAL (emptytree.right(2) ,61)
                  .CHECK_EQUAL (emptytree.size() ,3)
                  .CHECK_THROWS(emptytree.insert(62))
                  .CHECK_THROWS(emptytree.remove(1))
                  .CHECK_EQUAL (emptytree.contains(2),1)
                  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
