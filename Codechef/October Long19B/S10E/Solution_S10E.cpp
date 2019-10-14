#include<bits/stdc++.h> //Includes all the header files.
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);  //Speeds up
	cin.tie(NULL);cout.tie(NULL);  //Input && Output.
	int t;cin>>t;  //Number of Testcases.
	while(t--){
		int n; cin>>n;  //Number of Days.
		int prices[n];
		for(int i = 0 ; i < n ; i++) cin>>prices[i]; //Prices on Respective days.
	    int good = 0,ifbad; //Good days = 0 at start.
	    for(int i = 0 ; i < n ; i++){
	    	if(i < 5){ //Special condition for n < 5
	    		ifbad = 0;
	    		for(int j = 0 ; j < i ; j++){
	    			if(prices[j] <= prices[i]){
	    			ifbad = 1; //If price is greater or equal to previous days.
	    			break;
	    			}
	    		}
	    		if(ifbad == 0) good++; //Good day as price is strictly lower.
	    	}else{
	    		ifbad = 0;
	    		for(int j = i-1 ; j > i-6 ; j--){
	    			if(prices[j] <= prices[i]){
	    				ifbad = 1;
	    				break;
	    			}
	    		}
	    		if(ifbad == 0) good++;
	    	}
	    }
	    cout<<good<<'\n';
	}
}
