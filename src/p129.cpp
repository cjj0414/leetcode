#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v,TreeNode* l,TreeNode* r):left(l),right(r),val(v){};
};
int sumNumbers(TreeNode *root)
{
    stack<TreeNode *> s;
    auto curr = root;
    int res = 0;
    int temp = 0;
    int base = 0;
    while (curr)
    {
        //visit current node
        temp = temp * 10 + curr->val;
        //visit left subtree
        if (curr->left)
        {
            s.push(curr);
            base = base * 10 + curr->val;
            curr = curr->left;
            continue;
        }
        //visit right subtree
        if (curr->right)
        {
            base = base / 10;
            curr = curr->right;
            continue;
        }
        //leaf node, retrieve
        res += temp;
        while (curr->right == nullptr && (!s.empty()))
        {
            base = base / 10;
            curr = s.top();
            temp = base;
            s.pop();
        }
        curr = curr->right;
        cout << base << endl;
        if (curr == nullptr)
            continue;
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(4, new TreeNode(9, new TreeNode(5, nullptr, nullptr), new TreeNode(1, nullptr, nullptr)), new TreeNode(0, nullptr, nullptr));
    sumNumbers(root);
}