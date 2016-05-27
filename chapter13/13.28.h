#include <string>

using namespace std;

class TreeNode {
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(): value(""), count(1), left(nullptr), right(nullptr) {}
    TreeNode(const string &s = string(), TreeNode *lchild = nullptr,
            TreeNode *rchild = nullptr): value(s), count(1),
            left(lchild), right(rchild) {}
    TreeNode(const TreeNode &tn);

    ~TreeNode();

    void CopyTree();
    int ReleaseTree();
};

TreeNode::TreeNode(const TreeNode &tn):
    value(tn.value), count(1), left(tn.left), right(tn.right) {
        if (left) left->CopyTree();
        if (right) right->CopyTree();
    }

TreeNode::~TreeNode() {
    if (count)
        ReleaseTree();
}

void TreeNode::CopyTree() {
    if (left) left->CopyTree();
    if (right) right->CopyTree();
    count++;
}
int TreeNode::ReleaseTree() {
    if (left)
        delete left;
    if (right)
        delete right;
    return --count;
}

class BinStrTree {
private:
    TreeNode *root;
public:
    BinStrTree(): root(nullptr) {}
    BinStrTree(TreeNode *t = nullptr): root(t) {}
    BinStrTree(const BinStrTree &bst);
    ~BinStrTree();
};

BinStrTree::BinStrTree(const BinStrTree &bst): root(bst.root) {
    root->CopyTree();
}
BinStrTree::~BinStrTree() {
    if (!root->ReleaseTree())
        delete root;
}
