/*
// Name: Ryan Xi
// UFID: 83786754

#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/AVL.h"
using namespace std;

// 1. Test at least five incorrect commands
TEST_CASE("Five incorrect commands", "[incorrect]") {
		AVLTree tree;

		// 1. Invalid Name (contains numbers)
		REQUIRE(tree.insert("A11y", "45679999") == false);

		// 2. Invalid UFID (too short)
		REQUIRE(tree.insert("Jeff", "1234") == false);

		// 3. Invalid UFID (contains letters)
		REQUIRE(tree.insert("Jeff", "1234abcd") == false);

		// 4. Duplicate UFID
		tree.insert("David", "11111111");
		REQUIRE(tree.insert("David", "11111111") == false);

		// 5. Search for a non-existent UFID
		REQUIRE(tree.searchID("99999999") == false);
}

// 2. Test at least three edge cases
TEST_CASE("Three edge cases", "[edge]") {
		AVLTree tree;

		// Edge Case 1: Removing a node that doesn't exist
		tree.insert("A", "10000000");
		REQUIRE(tree.remove("99999999") == false);

		// Edge Case 2: Removing from an out-of-bounds index using removeInorder
		REQUIRE(tree.removeInorder(5) == false); // Only 1 node exists, index 5 is invalid

		// Edge Case 3: Searching in an empty tree
		AVLTree emptyTree;
		REQUIRE(emptyTree.searchID("12345678") == false);
}

// 3. Test all four rotation cases
TEST_CASE("Four rotation cases", "[rotations]") {
		AVLTree tree;

		// Left-Left Rotation (Insert descending)
		tree.insert("C", "30000000");
		tree.insert("B", "20000000");
		tree.insert("A", "10000000"); // Triggers LL

		// Right-Right Rotation (Insert ascending)
		tree.insert("D", "40000000");
		tree.insert("E", "50000000");
		tree.insert("F", "60000000"); // Triggers RR

		// Right-Left Rotation
		tree.insert("I", "90000000");
		tree.insert("G", "70000000");
		tree.insert("H", "80000000"); // Triggers RL

		// Left-Right Rotation
		tree.insert("K", "05000000");
		tree.insert("L", "07000000");
		tree.insert("M", "06000000"); // Triggers LR

		// Verify tree is balanced by checking height (Level Count)
		// 12 nodes in an AVL tree should have a level count of exactly 4
		REQUIRE(tree.printLevelCount() == 4);
}

// 4. Test all three deletion cases
TEST_CASE("Three deletion cases", "[deletion]") {
		AVLTree tree;
		tree.insert("Root", "50000000");
		tree.insert("LeftChild", "25000000");
		tree.insert("RightChild", "75000000");
		tree.insert("RightLeftLeaf", "60000000");

		// Case 1: Deletion with no children (Leaf Node)
		REQUIRE(tree.remove("60000000") == true);
		REQUIRE(tree.searchID("60000000") == false);

		// Re-insert to setup Case 2
		tree.insert("RightLeftLeaf", "60000000");

		// Case 2: Deletion with one child (RightChild has only a left child now)
		REQUIRE(tree.remove("75000000") == true);
		REQUIRE(tree.searchID("75000000") == false);

		// Case 3: Deletion with two children (Root has a left and right branch)
		REQUIRE(tree.remove("50000000") == true);
		REQUIRE(tree.searchID("50000000") == false);
}

// 5. Insert 100 nodes, remove 10, check inorder
TEST_CASE("Insert 100, remove 10, verify order", "[stress]") {
		AVLTree tree;

		// Insert 100 nodes
		for (int i = 10000000; i < 10000100; i++) {
				string ufid = to_string(i);
				tree.insert("Student", ufid);
		}

		// Verify 100 insertions
		vector<string> inorderList = tree.getInorder();
		REQUIRE(inorderList.size() == 100);

		// Remove 10 random nodes (using the first 10 for simplicity)
		for (int i = 10000000; i < 10000010; i++) {
				string ufid = to_string(i);
				tree.remove(ufid);
		}

		// Verify 90 nodes remain
		inorderList = tree.getInorder();
		REQUIRE(inorderList.size() == 90);

		// Check that the remaining vector is strictly sorted inorder
		bool isSorted = true;
		for (size_t i = 1; i < inorderList.size(); i++) {
				if (inorderList[i - 1] >= inorderList[i]) {
						isSorted = false;
						break;
				}
		}
		REQUIRE(isSorted == true);
}
*/