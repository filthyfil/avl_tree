// A test program for assignment "bstree-construct"
#include "bstree.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

// For random number generation (global)
default_random_engine re(chrono::system_clock::now().time_since_epoch().count());

int tree_depth (int vector_size);
bool testAVL(int vector_size);

int main () {
	cout << fixed << setprecision(6);
	cout << "Vector Size  Expected Depth  Actual Depth  Result" << endl;
	cout << "-----------  --------------  ------------  ------" << endl;

	// Run tests for binary search trees of depths 0 through 15
	for (int depth = 0; depth < 16; depth++) {
		// Calculate vector size for a tree of the given depth
		int vector_size = pow(2, depth + 1) - 1;
		// Create a tree from the vector and get the actual depth
		int actual_depth = tree_depth(vector_size);
		// Output the results
		cout << setw(8) << vector_size << setw(14) << depth << setw(15) << actual_depth
			<< setw(11) << (actual_depth == depth ? "Pass" : "FAIL") << setw(15) << (testAVL(vector_size) ? "Pass" : "FAIL") << endl;
	}
}

int tree_depth (int vector_size) {

	// Create a vector of integers from 1 to vector_size
	vector<int> v(vector_size);
	iota(v.begin(), v.end(), 1);

	// Randomize the vector
	//shuffle(v.begin(), v.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
	shuffle(v.begin(), v.end(), re);

	// Create a binary search tree and insert the elements of the vector
	BSTree<int> t(v);

	// Return the depth of the tree
	return t.depth();
}

bool testAVL (int vector_size) {

	// Create a vector of integers from 1 to vector_size
	vector<int> v(vector_size);
	iota(v.begin(), v.end(), 1);

	// Randomize the vector
	//shuffle(v.begin(), v.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
	shuffle(v.begin(), v.end(), re);

	// Create a binary search tree and insert the elements of the vector
	BSTree<int> t(v);

	return t.isAVL();
}