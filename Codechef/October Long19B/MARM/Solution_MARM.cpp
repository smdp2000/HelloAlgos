#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
  ULL t;cin>>t;
	while(t--){
		ULL n,k;
		cin>>n>>k;
		ULL A[n];
		for(ULL i=0;i<n;i++) cin>>A[i];
		if(n != 1){
		    if(n%2==0){   //Sequence repeats every 3n times.
		    	k = k%(3*n);
		    	for(ULL i=0;i<k;i++) A[i%n] = A[i%n]^A[n-(i%n)-1];
		        for(ULL i=0;i<n;i++) cout<<A[i]<<" ";
		        cout<<'\n';
		    }else{
		    	if(k%(3*n) > n) k = k%(3*n);  //If n is odd , middle element becomes 0.
		    	else if(k > n) k = k%(3*n) + 3*n;  //B'cuz A^A = 0;
		    	for(ULL i=0;i<k;i++) A[i%n] = A[i%n]^A[n-(i%n)-1];
		        for(ULL i=0;i<n;i++) cout<<A[i]<<" ";
		        cout<<'\n';
		    }
		}else cout<<0<<'\n';
	}
}
