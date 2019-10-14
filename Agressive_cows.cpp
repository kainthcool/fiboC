#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans;
int c,n;
int checkans(int a[],int m){
	int t=1;
	int pos=a[0];
	for(int i=0;i<n;i++){
		if(a[i]-pos>=m){
			t++;
			pos=a[i];
		}
	}
	return t;

}

void bs(int a[],int l,int h){
	if(l<=h){
		int m=(l+h)/2;
		if(checkans(a,m)>=c){
			ans=m;
			return bs(a,m+1,h);
		}
		else{
			return bs(a,l,m-1);
		}
	}
}


int32_t main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;cin>>t;
    while(t--){
    	n=0;
    	c=0;
    	ans=0;
	   	cin>>n;
	    cin>>c;
	    int a[n];
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    	}
    	sort(a,a+n);
    	bs(a,0,a[n-1]);
    	cout<<ans<<endl;
	}
}