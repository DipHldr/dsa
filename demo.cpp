#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
       string s1,s2;
       cin>>s1>>s2;
       int l1=s1.length(),l2=s2.length();
       int l=(l1>l2)?l2:l1;
       int ind=0;
       for(int i=0;i<l;i++){
        if(s1[i]!=s2[i]){
            ind=i;
            break;
        }
       }

    //    cout<<l1<<" "<<l2<<endl;
    //    cout<<ind<<endl;
    //    cout<<l1-(ind+1)<<" "<<l2-(ind+1)<<endl;


       int len=abs((l1-(ind+1))+(l2-(ind+1)))+ind;
       cout<<len<<endl;

	}

}
