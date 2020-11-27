#include "util.cpp"
#include <set>
int main(){
    vector<string> words;
    if (words.empty()) return 0;// vector<string>();
    set<string> hm;
    for(auto w:words) hm.insert(w);
    vector<string> ret;
    for(auto& s:words){
        if(s.size()==0) continue;
        vector<int> flags(s.size(),0);
        for(uint i=0;i<s.size();i++){
            for(uint j=i-1;j!=uint(-1);j--){
                if (!flags[j]) continue;
                auto it=hm.find(s.substr(j+1,i-j));
                if(it==hm.end()) continue;
                flags[i]=flags[j]+1; break;
            }
            if (hm.find(s.substr(0,i+1))!=hm.end()) flags[i]=max(flags[i],1);
        }
        if(flags[s.size()-1]>1) ret.push_back(s);
    }
    // return ret;    
    return 0;    
}