#include <iostream>

#include "AVLTree.h"

using namespace std;

int main(int argc, const char * argv[]) {
  cout << "AVL Tree" << endl;
  newbee::AVLTree tree;
  tree.Insert(4);
  tree.Insert(5);
  tree.Insert(6);
  tree.Insert(7);
  tree.Inorder();
  tree.Preorder();
  tree.Insert(8);
  tree.Inorder();
  tree.Preorder();
  tree.Insert(9);
  tree.Inorder();
  tree.Preorder();
  tree.Insert(1);
  tree.Inorder();
  tree.Preorder();
  tree.Insert(2);
  tree.Inorder();
  tree.Preorder();
  tree.Delete(2);
  tree.Inorder();
  tree.Preorder();
  tree.Delete(1);
  tree.Inorder();
  tree.Preorder();
  tree.Delete(9);
  tree.Inorder();
  tree.Preorder();
  tree.Delete(8);
  tree.Inorder();
  tree.Preorder();
  tree.Delete(7);
  tree.Inorder();
  tree.Preorder();
  if (tree.Find(3)) {
    cout << "get it" << endl;
  }
  return 0;
}
