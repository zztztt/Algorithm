// Copyright [2014] <zhitong zhang>
#ifndef AVLTREE_H_
#define AVLTREE_H_

#define MAX(a, b) (a > b ? a : b)
namespace newbee {

class Node {
 public:
  Node() : left_(NULL), right_(NULL), height_(0), count_(0) {}
  int data_;
  Node *left_;
  Node *right_;
  int height_;
  int count_;
};


class AVLTree {
 public:
  AVLTree() : root_(NULL) {}
  Node* Find(int data);
  void Insert(int data);
  void Delete(int data);
  void Inorder();
  void Preorder();
  void Postorder();

 private:
  Node *root_;
  Node* Find(Node *node, int data);
  void Insert(Node* &node, int data);
  void Delete(Node* &node, int data);
  void Inorder(Node *node);
  void Preorder(Node *node);
  void Postorder(Node *node);
  void GetBalance(Node* &node);
  void LLRotate(Node* &node);
  void LRRotate(Node* &node);
  void RLRotate(Node* &node);
  void RRRotate(Node* &node);
  int Height(Node *node) {
    return node ? node->height_ : -1;
  }
};

}  // namespace newbee

#endif  // AVLTREE_H_
