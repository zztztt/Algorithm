// Copyright 2014 zhitong zhang
#include "AVLTree.h"

#include <iostream>

using std::count;
namespace newbee {

Node* AVLTree::Find(int data) {
  return Find(root_, data);
}

Node* AVLTree::Find(Node *node, int data) {
  if (node == NULL) {
    return NULL;
  }
  if (node->data_ > data) {
    return Find(node->left_, data);
  } else if (node->data_ < data) {
    return Find(node->right_, data);
  } else {
    return node;
  }
}

void AVLTree::Insert(int data) {
  Insert(root_, data);
}

void AVLTree::Insert(Node* &node, int data) {
  if (node == NULL) {
    node = new Node();
    node->data_ = data;
    cout << "Insert element : " << node->data_ <<  endl;
    return;
  }
  if (node->data_ > data) {
    Insert(node->left_, data);
    GetBalance(node);
  } else if (node->data_ < data) {
    Insert(node->right_, data);
    GetBalance(node);
  } else {
    ++(node->count_);
  }
}

void AVLTree::Delete(int data) {
  Delete(root_, data);
}

void AVLTree::Delete(Node* &node, int data) {
  if (node == NULL) {
    return;
  }
  if (node->data_ > data) {
    Delete(node->left_, data);
    GetBalance(node);
  } else if (node->data_ < data) {
    Delete(node->right_, data);
    GetBalance(node);
  } else {
    cout << "Delete element " << data << endl;
    Node *temp;
    if (node->left_ && node->right_) {
      temp = node->right_;
      while (temp->left_) temp = temp->left_;
      node->data_ = temp->data_;
      node->count_ = temp->count_;
      Delete(node->right_, node->data_);
      GetBalance(node);
    } else {
      temp = node;
      node = (node->left_) ? node->left_ : node->right_;
      delete temp;
      temp = NULL;
    }
  }
}

void AVLTree::Inorder() {
  Inorder(root_);
  cout << endl;
}

void AVLTree::Inorder(Node *node) {
  if (node == NULL) {
    return;
  }
  Inorder(node->left_);
  cout << node->data_ << " ";
  Inorder(node->right_);
}

void AVLTree::Preorder() {
  Preorder(root_);
  cout << endl;
}

void AVLTree::Preorder(Node *node) {
  if (node == NULL) {
    return;
  }
  cout << "(" << node->data_ << ", " << node->height_ << ") ";
  Preorder(node->left_);
  Preorder(node->right_);
}

void AVLTree::Postorder() {
  cout << "Postorder" << endl;
}

void AVLTree::Postorder(Node *node) {
  cout << "Postorder" << endl;
}

void AVLTree::GetBalance(Node* &node) {
  if (Height(node->right_) - Height(node->left_) > 1) {
    if (Height(node->right_->left_) > Height(node->right_->right_)) {
      RLRotate(node);
    } else {
      RRRotate(node);
    }
  } else if (Height(node->left_) - Height(node->right_) > 1) {
    if (Height(node->left_->right_) > Height(node->left_->left_)) {
      LRRotate(node);
    } else {
      LLRotate(node);
    }
  } else {
    node->height_ = MAX(Height(node->left_), Height(node->right_)) + 1;
  }
}
void AVLTree::LLRotate(Node* &node) {
  cout << "LLRotate" << endl;
  Node *rotate_node = node->left_;
  node->left_ = rotate_node->right_;
  rotate_node->right_ = node;

  node->height_ = MAX(Height(node->left_), Height(node->right_)) + 1;
  rotate_node->height_ = MAX(Height(rotate_node->left_), node->height_) + 1;
  node = rotate_node;
}

void AVLTree::LRRotate(Node* &node) {
  cout << "LRRotate" << endl;
  RRRotate(node->left_);
  LLRotate(node);
}

void AVLTree::RLRotate(Node* &node) {
  cout << "RLRotate" << endl;
  LLRotate(node->right_);
  RRRotate(node);
}

void AVLTree::RRRotate(Node* &node) {
  cout << "RRRotate" << endl;
  Node *rotate_node = node->right_;
  node->right_ = rotate_node->left_;
  rotate_node->left_ = node;

  node->height_ = MAX(Height(node->left_), Height(node->right_)) + 1;
  cout << node->data_ << "/"<< Height(node->left_) << "/" << Height(node->right_) << endl;
  rotate_node->height_ = MAX(node->height_, Height(rotate_node->right_)) + 1;
  cout << rotate_node->data_ << "/" <<  Height(rotate_node->left_) << "/" << Height(rotate_node->right_) << endl;
  node = rotate_node;
}

}  // namespace newbee

