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

    // Core recursive helpers
    Node* insertHelper(Node* node, string name, string ufid, bool& sucessful);
    Node* removeHelper(Node* node, string ufid, bool& sucessful);

    // AVL mechanics and balance tracking
    int getHeight(Node *node);
    int getBalanceFactor(Node *node);

    // Four standard AVL rotations
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);

  public: 
    AVLTree() : root(nullptr) {}

    //Core commands
    bool insert(string name, string ufid);
    bool remove(string ufid);
    bool removeInorder(int N);

    // Search commands
    bool searchID(string ufid);
    bool searchName(string name);

    //Traversal commands
    vector<string> getInorder();
    vector<string> getPreorder();
    vector<string> getPostorder();

    // Utility
    int getLevelCount();
};