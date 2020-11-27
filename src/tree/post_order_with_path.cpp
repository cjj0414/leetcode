#include "util.cpp"

vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> path;
    vector<int> res;
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            path.push(curr);
            curr = curr->left;
            continue;
        }
        if (curr->right)
        {
            path.push(curr);
            curr = curr->right;
            continue;
        }
        TreeNode *last = nullptr;
        while (1)
        {
            if (curr->right == last)
            {
                res.push_back(curr->val);
            }
            else if (curr->left == last)
            {
                if (curr->right)
                {
                    path.push(curr);
                    last=curr;
                    curr = curr->right;
                    break;
                }
                else
                {
                    res.push_back(curr->val);
                }
            }
            if(path.empty()) break;
            last = curr;
            curr = path.top();
            path.pop();
        }
        if(curr==root) break;
    }
    return res;
}
int main(){
    TreeNode *root = new TreeNode(4, new TreeNode(9, new TreeNode(5, nullptr, nullptr), new TreeNode(1, nullptr, nullptr)), new TreeNode(0, nullptr, nullptr));
    auto res=postorderTraversal(root);
    for(auto e:res) cout<<e<<", ";
}