#include <iostream>
#include <stack>
using namespace std;

class TreeNode
{
public:
    TreeNode(int v, TreeNode *lp, TreeNode *rp) : value(v), left(lp), right(rp){};
    int value;
    TreeNode *left;
    TreeNode *right;
};
void PreOrder(TreeNode *root)
{
    TreeNode *curr = root;
    stack<TreeNode *> s;
    while (curr)
    {
        cout << curr->value << ",";

        //左子树为空
        if (curr->left)
        {
            s.push(curr);
            curr = curr->left;
        }
        else if (curr->right)
        {
            s.push(curr);
            curr = curr->right;
        }
        else
        {
            if (s.empty())
                break;
            curr = s.top()->right;
            s.pop();
        }
    }
}

void InOrder(TreeNode *root)
{
    TreeNode *curr = root;
    stack<TreeNode *> s;
    while (curr)
    {
        if (curr->left)
        {
            if(curr->right) s.push(curr);
            curr = curr->left;
        }
        else if (curr->right)
        {
            cout << curr->value << ",";
            curr = curr->right;
        }
        else
        {
            cout << curr->value << ",";
            curr = s.top();
            s.pop();
            cout << curr->value << ",";
            curr = curr->right;
        }
    };
}
enum Side{ L, R};
void PostOrder(TreeNode *root)
{
    TreeNode *curr = root;
    stack<pair<TreeNode *, Side>> s;
    while (curr)
    {
        if (curr->left)
        {
            s.push({curr, L});
            curr = curr->left;
        }
        else if (curr->right)
        {
            s.push({curr, R});
            curr = curr->right;
        }
        else
        {
            while (!s.empty() && s.top().second == R)
            {
                cout << curr->value << ",";
                curr = s.top().first;
                s.pop();
            }
            if (s.empty())
                return;
            cout<<curr->value<<",";
            curr = s.top().first->right;
            s.pop();
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, nullptr), new TreeNode(5, nullptr, nullptr)), new TreeNode(3, new TreeNode(6, nullptr, nullptr), new TreeNode(7, nullptr, nullptr)));
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    return 0;
}
