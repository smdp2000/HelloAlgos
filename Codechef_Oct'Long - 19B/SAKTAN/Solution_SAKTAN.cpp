#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULL;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
  ULL t;cin>>t;
	while(t--){
		ULL n,m,q;
		cin>>n>>m>>q;
		ULL r[n] = {} , c[m] = {}  , r1 , c1;
		for(ULL i = 0 ; i < q ; i++){
			cin>>r1>>c1;
			r[r1 - 1]++;c[c1 -1]++;
		}
		ULL numoddr = 0 , numoddc = 0;
		for(ULL i = 0 ; i < n ; i++){if(r[i] % 2 == 1) numoddr++;} //Checking Num of Odds in Rows.
		for(ULL i = 0 ; i < m ; i++){if(c[i] % 2 == 1) numoddc++;} //Checking Num of Odds in Coloumns.
		ULL odd = numoddr*(m - numoddc) + numoddc*(n - numoddr); //Total number of Odds possible in the matrix.
		cout<<odd<<'\n';
	}
}
