#pragma once
#include <string>
#include <vector>
#include <algorithm>
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

    // Order helpers
    void inorderHelper(Node* node, vector<string>& result);
    void preorderHelper(Node* node, vector<string>& result);
    void postorderHelper(Node* node, vector<string>& result);

    void inorderUfidHelper(Node* node, vector<string>& result);

    // Search helper
    Node* searchHelper(Node* node, string targetUfid);
    void searchNameHelper(Node *node, string targetName, bool &found);

    // AVL mechanics and balance tracking
    int getHeight(Node *node);
    int getBalanceFactor(Node *node);

    // Four standard AVL rotations
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);

    // Inorder successor helper
    Node* getInorderSuccessor(Node* node);

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
    void printInorder();
    void printPreorder();
    void printPostorder();

    // Utility
    int printLevelCount();
};