#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    string FirstNonRepeating(string str){
        unordered_map<char ,int>count;
        queue<char>q;
        string ans="";
        for(int i=0;i<str.size();i++){
            char ch=str[i];

            count[ch]++;
            q.push(ch);
            while(!q.empty()){
                if(count[q.front()]>1){
                    q.pop();
                }
                else{
                    ans.push_back(q.front());
                    break;
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }

        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        solution obj;
        string ans=obj.FirstNonRepeating(str);
        cout<<ans<<endl;
    }
    return 0;
}