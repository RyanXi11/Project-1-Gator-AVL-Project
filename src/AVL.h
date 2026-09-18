#pragma once
#include <string>
#include <vector>
using namespace std;

struct Node{
  string name;
  string ufid;

  int height;
  Node* left;
  Node* right;

  Node(string name, string ufid) : name(name), ufid(ufid), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree{
  private:
    Node* root;

    Node* insertHelper(Node* node, string name, string ufid, bool& sucessful);
    Node* removeHelper(Node* node, string ufid, bool& sucessful);

  public: 
    AVLTree() : root(nullptr) {}

    bool insert(string name, string ufid);
    bool remove(string ufid);
    bool search(string ufid);

    vector<string> getInorder();
};