#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        vector<string>v1;
        vector<int>v2;
        string t="";
        int x=0;
        int d=0;
        for(int i=0;i<n;++i){
            if(isalpha(s[i])){
                    if(d==1){
                        v2.push_back(x);
                        d=0;
                        x=0;
                    }
                t+=s[i];
            }
            else{
                if(d==0){
                    v1.push_back(t);
                    d=1;
                    t="";
                }
                x=x*10+(s[i]-'0');
            }
        }
        v2.push_back(x);
        string res="";
        for(int i=0;i<v1.size();++i){
            string c=v1[i];
            for(int j=0;j<v2[i];++j){
                res+=c;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
