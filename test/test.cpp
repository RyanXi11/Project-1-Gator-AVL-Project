// Name: Ryan Xi
// UFID: 83786754

#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/AVL.h"
using namespace std;

// 1. Five command executions that print "unsuccessful"
TEST_CASE("Five unsuccessful command executions", "[unsuccessful]")
{
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
	REQUIRE(tree.search("99999999") == false);
}

// 2. Test all four rotation cases
TEST_CASE("Test all four rotation cases", "[rotations]"){
	AVLTree tree;

	// Left-Left Rotation (Insert descending order)
	tree.insert("C", "33333333");
	tree.insert("B", "22222222");
	tree.insert("A", "11111111");

	// Right-Right Rotation (Insert ascending order)
	tree.insert("D", "44444444");
	tree.insert("E", "55555555");
	tree.insert("F", "66666666");

	// Right-Left Rotation
	tree.insert("I", "99999999");
	tree.insert("G", "77777777");
	tree.insert("H", "88888888");

	// Left-Right Rotation
	tree.insert("K", "50000000");
	tree.insert("M", "70000000");
	tree.insert("L", "60000000");

	REQUIRE(tree.getInorder().size() == 12);
}

// 3. Insert 100 nodes, remove 10 random nodes
TEST_CASE("Insert 100 nodes, remove 10, check inorder", "[stress]"){
	AVLTree tree;

	// Insert 100 nodes
	for(int i = 10000000; i < 10000100; i++){
		string ufid = to_string(i);
		tree.insert("Student", ufid);
	}

	// Remove 10 nodes
	for(int i = 10000000; i < 10000010; i++){
		string ufid = to_string(i);
		tree.remove(ufid);
	}

	vector<string> inorderList = tree.getInorder();
	REQUIRE(inorderList.size() == 90);
}
