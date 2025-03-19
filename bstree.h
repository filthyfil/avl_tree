#pragma once

#include <vector>
#include <iostream> // for std::max

// A Binary Search Tree implementation.
template <typename T>
class BSTree {
private:

	// A node in the tree. Each node has pointers to its left and right nodes
	// as well as its parent. When a node is created, the parent and data item
	// must be provided.
	class node {
	public:
		T data;
		node* left;
		node* right;
		node* parent;
		node (const T& d, node* p) {
			parent = p;
			data = d;
			left = right = nullptr;
		}
	};

	// Pointer to the root node. Initially this is null for an empty tree.
	node* root;

	// Copy the subtree of another BSTree object into this object. Used by
	// the copy constructor and assignment operator.
	void copy (node* p) {
		if (p) { // If p points to a node...
			insert(p->data); // Insert data item
			copy(p->left); // Copy the left subtree
			copy(p->right); // Copy the right subtree
		}
	}

	// Destroy a node and all nodes in both subtrees. Called by the
	// destructor.
	void destroy (node* p) {
		if (p) { // If p is not null...
			destroy(p->left); // Destroy the left subtree
			destroy(p->right); // Destroy the right subtree
			delete p; // Destroy the node
		}
	}

	// Helper function to determine if a data value is contained in the tree.
	// Takes the data value being searched and a pointer to the node in the
	// tree. Returns pointer to node in which data item is found, a null
	// pointer otherwise.
	node* find (const T& d, node* p) const {
		// Given: p is a pointer to an existing node
		if (d == p->data) // Is this the value we're looking for?
			return p;
		if (d < p->data) // Check left side, if null then not found
			return p->left ? find(d, p->left) : nullptr;
		return p->right ? find(d, p->right) : nullptr; // Check right side...
	}

	// Helper function to insert a data item into the tree. Takes the data
	// and a pointer to a node in the tree. Recursively decends down the tree
	// until position were insertion should take place is found.
	void insert (const T& d, node* p) {
		// Given: p is a pointer to an existing node (root of a subtree)
		if (d < p->data) { // Insert into left subtree?
			if (p->left) // Left subtree exists?
				insert(d, p->left); // Insert into left subtree...
			else // No left subtree, insert the new node
				p->left = new node(d, p);
		}
		else if (d > p->data) { // Insert into right subtree?
			if (p->right) // Right subtree exists?
				insert(d, p->right); // Insert into right subtree...
			else // No right subtree, insert the new node
				p->right = new node(d, p);
		}
		// else: node p has data value being inserted, ignore (no dups allowed)
	}

	// An inorder traversal for a subtree rooted at node p. Performs an
	// inorder traversal on the left subtree, then calls f for the data item
	// at p, then performs an inorder traversal on the right subtree.
	template <typename U>
	void inorder (node* p, U f) const {
		if (p) {
			inorder(p->left, f);
			f(p->data);
			inorder(p->right, f);
		}
	}

	// A preorder traversal for a subtree rooted at node p. Calls f for the
	// data item at p with the given depth, then performs a preorder
	// traversal on the left and right subtrees passing the depth plus 1.
	template <typename U>
	void preorder (node* p, U f, int depth) const {
		if (p) {
			f(p->data, depth);
			preorder(p->left, f, depth + 1);
			preorder(p->right, f, depth + 1);
		}
	}

	// Helper function to find the depth of the tree.
	int find_depth (node* p /* assumes p != nullptr */) const {
		int left_depth = p->left ? find_depth(p->left) : 0; // Find left depth
		int right_depth = p->right ? find_depth(p->right) : 0; // Find right depth
		return 1 + (left_depth > right_depth ? left_depth : right_depth);
	}

public:

	// Constructor, initializes an empty tree by setting the root pointer to
	// null.
	BSTree() { root = nullptr; }

	// Copy constructor
	BSTree(const BSTree& t) { root = nullptr; copy(t.root); }

	// Assignment overload
	BSTree& operator= (const BSTree& t) {
		destroy(root); // Destroy the current tree
		root = nullptr; // Initialize root pointer
		copy(t.root); // Copy the tree
		return *this;
	}

	// Destructor, destroys all nodes
	~BSTree() { destroy(root); }

	// Find a data item in the tree. Return true if data value exists,
	// otherwise return false. Calls recursive find helper function.
	bool find (const T& d) const {
		return root && find(d, root);
	}

	// Insert a new data item into the tree. If the data item already exists,
	// it is ignored (no duplicates are added). Calls recursive insert helper
	// function.
	void insert (const T& d) {
		if (!root) // Is tree empty?
			root = new node(d, nullptr); // Create root node
		else if (d < root->data) { // Add new value to left side?
			if (root->left) // Is there is a left subtree?
				insert(d, root->left); // Insert into left subtree...
			else // No left subtree, create node on left side
				root->left = new node(d, root);
		}
		else if (d > root->data) { // Add new value to right side?
			if (root->right) // Is there a right subtree?
				insert(d, root->right); // Insert into right subtree...
			else // No right subtree, create node on right side
				root->right = new node(d, root);
		}
	}

	// Perform an inorder traversal using function f. Calls the recursive
	// helper function.
	template <typename U>
	void inorder (U f) const { inorder(root, f); }

	// Perform a preorder traversal using function f. Calls the recursive
	// helper function. Note that function f requires a second parameter
	// which is the depth.
	template <typename U>
	void preorder (U f) const { preorder(root, f, 0); }

	// Returns the depth of the tree. Calls the recursive helper function.
	int depth () const { return root ? find_depth(root) - 1 : 0; }

	// **************************************************************
	// TODO: Implement your constructor here
	BSTree(std::vector<T> v) {
		root = nullptr;
		for (auto& i : v) {
			// the goal is to make a bbst
			// i dont want to sort the vector because that is too easy
			// i will implement an AVL tree since it has self-balancing properties
			/* AVL SORT:
				1. simple bst insert
				2. then fix the AVL property via rotations and double rotations
			   AVL PROPERTY:
			 	heights of left and right children of every node to differ
				by +1 or -1
			*/
			// this should yield a balanced BST

			insert(i); // so (1) is complete i.e. simple bst insert
			node* new_node = find(i, root); // try to find the new node

			// now maintain AVL property:
			// we inserted the new node, but what's the balance factor?
		
			while (new_node != nullptr) {
				int balance_factor = balance(new_node);

				// there are 4 cases to check for to maintain AVL
				// case 1 & 2: left heavy
				if (balance_factor > 1) {
					if (balance(new_node->left) >= 0) // case 1: LL
						new_node = rotateRight(new_node);
					else { // case 2: LR
						new_node->left = rotateLeft(new_node->left);
						new_node = rotateRight(new_node);
					}
					/*
					case 1 looks like: 
					    O
					   /
					  O    ->    O
					 /	        / \
					O          O   O
					
					case 2 looks like: 
					    O          O
					   /          /
					  O    ->    O     ->    O
					   \        /           / \
					    O      O           O   O
					*/
				}

				// case 3 & 4: right heavy
				else if (balance_factor < -1) {
					if (balance(new_node->right) <= 0) // case 3: RR
						new_node = rotateLeft(new_node);
					else { // case 4: RL
						new_node->right = rotateRight(new_node->right);
						new_node = rotateLeft(new_node);
					}
					/*
					case 3 looks like: 
					O
					 \
					  O    ->    O
					   \        / \ 
					    O      O   O
					
					case 4 looks like: 
					O          O
					 \          \
					  O   ->     O     ->     O
					 /            \          / \ 
					O              O        O   O
					*/
				}

				// when new_node becomes the root, update the root pointer
				if (new_node && new_node->parent == nullptr)
                root = new_node;
            
            	new_node = new_node ? new_node->parent : nullptr;
			}
		}
	}

private:
	// **************************************************************
	// TODO: Implement any helper functions you may need here
	
	// need getter for height and a check for balance. common practice for leaves null children to have -1 height
	// need rotate functions. 

	int getHeight(node* n) {
		// the height of any node is the max of the depth of any subtree in n
		if (n == nullptr) // is null child?
       		return -1; // by AVL convention, and to make the recursive calculation work
		// recursive call to left and right subtrees
		return 1 + std::max(getHeight(n->left), getHeight(n->right));
	}

	int balance(node* n) {
		if (n == nullptr) // is null child?
			return 0; // balanced since there are only null children
		// recursive call to left and right subtrees height
		return getHeight(n->left) - getHeight(n->right);
		// if positive, it is left heavy, 
		// if negative, it is right heavy
		// stop when this is 0 (if there are odd elements in vector), -1, or 1
	}
	
	node* rotateRight(node* n) {
		if (!n || !n->left) return n; // null dereference prevention
		// "lift up" left child, parent n "falls/rotates" to the right
		node* left_child = n->left;
		node* T2 = left_child->right; // "tree 2"

		// rotation
		left_child->right = n; 
		n->left = T2;

		// update parents
		left_child->parent = n->parent;
		n->parent = left_child;
		if (T2)
			T2->parent = n;

		// attach rotated subtree to grandparent
		if (left_child->parent) {
			(left_child->parent->left == n ? left_child->parent->left : left_child->parent->right) = left_child;
		}

		return left_child;
	}
	node* rotateLeft(node* n) {
		if (!n || !n->right) return n; // null dereference prevention
		// "lift up" right child, parent n "falls/rotates" to the left
		node* right_child = n->right;
		node* T2 = right_child->left; // "tree 2"

		// rotation
		right_child->left = n;
		n->right = T2;

		// update parents
		right_child->parent = n->parent;
		n->parent = right_child;
		if (T2)
			T2->parent = n;

		// attach rotated subtree to grandparent
		if (right_child->parent) {
			(right_child->parent->left == n ? right_child->parent->left : right_child->parent->right) = right_child;
		}

		return right_child;
	}

	// returns the height of the subtree if balanced, or -2 if not AVL balanced
	int checkAVL(node* n) const {
		if (!n)
			return -1;  // by AVL convention, empty subtree height is -1
		int leftHeight = checkAVL(n->left);
		if (leftHeight == -2) return -2;  // left subtree is not AVL (-2 is arbitrary) > 1 
		int rightHeight = checkAVL(n->right);
		if (rightHeight == -2) return -2; // right subtree is not AVL (-2 is arbitrary) > 1
		if (std::abs(leftHeight - rightHeight) > 1)
			return -2;  // this node violates the AVL condition (-2 is arbitrary) > 1
		return 1 + std::max(leftHeight, rightHeight);
	}
public:
	// returns true if the tree satisfies the AVL property
	bool isAVL() const {
		return checkAVL(root) != -2;
	}
};
