/* Serialization is the process of converting a data structure or object into a
sequence of bits so that it can be stored in a file or memory buffer, or transmitted
across a network connection link to be reconstructed later in the same or another
computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no
restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that a binary tree can be serialized to a string and
this string can be deserialized to the original tree structure.

Example:

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary
tree. You do not necessarily need to follow this format, so please be creative
and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your
serialize and deserialize algorithms should be stateless.
*/


#include <vector>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;
/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		_ser(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return _deser(in);
	}

	void _ser(TreeNode* root, ostringstream & out) {
		if (root) {
			out << root->val << " ";
			_ser(root->left, out);
			_ser(root->right, out);
		}
		else
			out << "# ";
		return;
	}

	TreeNode* _deser(istringstream & in) {

		string tmp;
		in >> tmp;
		if (tmp == "#")
			return nullptr;
		TreeNode * ret = new TreeNode(stoi(tmp));
		ret->left = _deser(in);
		ret->right = _deser(in);
		return ret;
	}
};

int main() {
	vector<TreeNode> vec = { 1,2,3,4 };
	vec[0].left = &vec[1];
	vec[1].left = &vec[2];
	vec[2].right = &vec[3];
	Codec cdc;
	TreeNode* ret = cdc.deserialize(cdc.serialize(&vec[0]));
	assert(ret->val == 1);
	assert(ret->left->val == 2);
	assert(ret->left->left->val == 3);
	assert(ret->left->left->right->val == 4);
	return 0;
}
