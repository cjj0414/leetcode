#include "util.cpp"
vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *curr = root;
    vector<int> res;
    while (curr)
    {
        if (curr->left)
        {
            s.push(curr);
            curr = curr->left;
            continue;
        };
        res.push_back(curr->val);
        if (curr->right)
        {
            curr = curr->right;
            continue;
        };
        while (curr->right == nullptr && (!s.empty()))
        {
            curr = s.top();
            res.push_back(curr->val);
            s.pop();
        }
        curr = curr->right;
    }
    return res;
}
