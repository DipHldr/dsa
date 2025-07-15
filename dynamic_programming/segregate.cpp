#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int ans[n][m];
	    int flag=1;
	    
	    for(int i=0;i<n;i++){
	        if(flag){
	        ans[0][i]=2;
	        flag=0;
	        }
	        else{
	        ans[0][i]=3;
	        flag=1;
	        }
	    }
	    
	    for(int row=1;row<n;row++){
	        for(int col=0;col<m;col++){
	            if(ans[row-1][col]==2)ans[row][col]=3;
	            else if(ans[row-1][col]==3) ans[row][col]=2;
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout<<ans[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}

}
