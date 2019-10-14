/* If a divides b and b divides c , then a also divides c.
So , if some A[j] is divisible by A[i] , then , We no longer need to compute
the star power of A[j] ,  as , StarPower(A[i]) > StarPower(A[j]) */

#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
  int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n] , s[n] = {}; //Implementation Inspired from Prime Sieve of Eratosthenes.
		for(int i = 0 ; i < n ; i++) cin>>a[i];
		if(a[n-1] == 1) cout<<n-1<<'\n';
		else{
			int count = 0;
		    for(int i = n - 2 ; i >= 0 ; i--){
			    if(a[i]%a[n-1] == 0){
				    count++;
				    s[i] = 1;
		        }
		    }
		    int max = count;
		    for(int i = n-2 ; i > 0; i--){
			    if(!(s[i])){
				    count = 0;
				    for(int j = i - 1 ; j >= 0 ; j--){
					    if(a[j]%a[i] == 0){
						    count++;
						    s[j] = 1;
					    }
				    }
			        if(count > max){max = count;}
			    }
		    }
            cout<<max<<'\n';
		}
    }
}
