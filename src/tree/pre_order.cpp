#include "util.cpp"
vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> res;
    auto *curr = root;
    while (curr)
    {
        //visit current node
        res.push_back(curr->val);
        //visit left subtree
        if (curr->left)
        {
            s.push(curr);
            curr = curr->left;
            continue;
        }
        //visit right subtree
        if (curr->right)
        {
            curr = curr->right;
            continue;
        }
        //for leaf node
        while (curr->right == nullptr && (!s.empty()))
        {
            curr = s.top();
            s.pop();
        }
        curr = curr->right;
    }
    return res;
}
