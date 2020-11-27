#include "util.cpp"
#include <cmath>
int main()
{
        int x=27;
        int ret=0;
        // if(n==1)return 0;
        while(x>1){
            int last=1;
            for(int i=2;i<x+1;i++){
                if(!(x%i)){
                    ret=ret+i;
                    x=x/i;
                    break;
                }
            }
        }
return ret;
}
