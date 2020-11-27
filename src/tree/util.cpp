#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v,TreeNode* l,TreeNode* r):left(l),right(r),val(v){};

}; 
ostream& operator<<(ostream& os,const vector<int> &v){
    for(auto val:v) os<<setw(5)<<left<<val;
    return os;
}
ostream& operator<<(ostream& os,const vector<vector<int>> &v){
    for(auto val:v) os<<val<<endl;
    return os;
}
inline int writeCSV(const vector<vector<int>> &v){
    ofstream ofs("sts.csv");
    // for(int i=v[0].size()-1;i>=0;i--){
    //     for(uint j=0;j<v.size();j++){
    //         ofs<<setw(5)<<left<<v[j][i];
    //     }
    //     ofs<<endl;
    // }
    for(auto& e:v) ofs<<e<<endl;
    ofs.close();
    return 0;
}

ostream& operator<<(ostream& os,const vector<uint> &v){
    for(auto val:v) os<<setw(5)<<left<<val;
    return os;
}
ostream& operator<<(ostream& os,const vector<vector<uint>> &v){
    for(auto val:v) os<<val<<endl;
    return os;
}
inline int writeCSV(const vector<vector<uint>> &v){
    ofstream ofs("sts.csv");
    ofs<<v;
    ofs.close();
    return 0;
}