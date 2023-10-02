// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node creation
class Node
{
	public:
		int val;
		
		// Since n children are possible for a root.
		// A list created to store all the children.
		vector<Node *> child;
		
		// Constructor
		Node(int data) : val(data) {}
};

// Function to insert
void insert(Node *root, int parent, Node *node)
{
	
	// Root is empty then the node will
	// become the root
	if (!root)
	{
		root = node;
	}
	else
	{
		if (root->val == parent)
		{
		root->child.push_back(node);
		}
		else
		{
			// Recursive approach to
			// insert the child
			int l = root->child.size();
			
			for(int i = 0; i < l; i++)
			{
				if (root->child[i]->val == parent)
					insert(root->child[i], parent, node);
				else
					insert(root->child[i], parent, node);
			}
		}
	}
}

// Function to perform level order traversal
void levelorder(vector<Node *> &prev_level)
{
	vector<Node *> cur_level;
	vector<int> print_data;
	int l = prev_level.size();
	
	if (l == 0)
	{
		exit(0);
	}
	
	for(int i = 0; i < l; i++)
	{
		int prev_level_len = prev_level[i]->child.size();
		
		for(int j = 0; j < prev_level_len; j++)
		{
			
			// enqueue all the children
			// into cur_level list
			cur_level.push_back(prev_level[i]->child[j]);
			
			// Copies the entire cur_level
			// list into prev_level
			print_data.push_back(prev_level[i]->child[j]->val);
		}
	}
	
	prev_level = cur_level;
	for(auto i : print_data)
	{
		cout << i << " ";
	}
	levelorder(prev_level);
}

// Function that calls levelorder method to
// perform level order traversal
void levelorder_root(Node *root)
{
	if (root)
	{
		vector<Node *> level;
		level.push_back(root);
		printf("%d\n", root->val);
		levelorder(level);
	}
}

// Driver code
int main(int argc, char const *argv[])
{
	
	// -1 is the root element
	int arr[] = {-1, -1, -1, -1, -1};
	Node *root = new Node(-1);
	int l = sizeof(arr) / sizeof(int);
	vector<int> que;
	
	// Inserting root element to the queue
	que.push_back(-1);
	
	while (true)
	{
		vector<int> temp;
		for(int i = 0; i < l; i++)
		{
			if (find(que.begin(),
					que.end(), arr[i]) != que.end())
			{
				// Insert elements into the tree
				insert(root, arr[i], new Node(i));
				temp.push_back(i);
			}
		}
	
		// Append child nodes into the queue
		// and insert the child
		que = temp;
		
		if (que.size() == 0)
		{
			break;
		}
	}
	levelorder_root(root);
}


