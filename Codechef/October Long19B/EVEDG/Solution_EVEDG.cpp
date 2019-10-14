/*Logic:-
       If M is even , K Is 1 , as you can cover the whole graph as it's own subgraph.
       If number of odd degree vertices is 0 , just remove any two adjacent vertices as two other sets.
       if otherwise remove any odd degree vertice as the second set.
*/   

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
  int t;cin>>t;
	while(t--){
		int n , m , k;
		cin>>n>>m;
		int deg[n+1] = {} , temp;
		int a,b;cin>>a>>b;
		deg[a]++;deg[b]++;
		for(long int i = 2 ; i < 2*m ; i++){
			cin>>temp;
			deg[temp]++;
		}
		int modd = 1;
		if(m%2 == 0){
			cout<<1<<'\n';
			for(int i = 0 ; i < n ; i++) cout<<"1 ";
			cout<<'\n';
			modd = 0;
		}
		if(modd){
			int numOdd = 0;
			for(int i = 1 ; i < n + 1 ; i++)
			    if(deg[i]%2 == 1) numOdd++;
			if(!numOdd){
				cout<<3<<'\n';
				for(int i = 1 ; i <= n ; i++){
					if( i == a ) cout<<"2 ";
					else if(i == b) cout<<"3 ";
					else cout<<"1 ";
				}
				cout<<'\n';
			}else{
				cout<<2<<'\n';
				int odd;
				for(int i = 1 ; i < n + 1 ; i++){
					if(deg[i]%2 == 1){
						odd = i;
						break;
					}
				}
				for(int i =  1 ; i < n + 1 ;i++){
					if(i == odd) cout<<"2 ";
					else cout<<"1 ";
				}
				cout<<'\n';
		    }
	    }
    }
}
