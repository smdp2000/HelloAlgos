/*First check the Numbers with Known bases.If a common number is still possible,
  Search for it in all of unknown base numbers.
  If no known-base numbers exist , then answer is the smallest of intersection of all unknown-base numbers 
  from base 2-36
*/  

#include<bits/stdc++.h>
using namespace std;
typedef  long long int ULL;
ULL val(char c){
	if(c >= '0' && c <= '9') return (ULL)c - '0';
	else return (ULL)c - 'A' + 10;
}
ULL convdec(string s , int base){
    ULL l = s.length(),power = 1 , ans = 0;
    for(int i = l-1 ; i >= 0 ; i--){
        if(val(s[i]) >= base || power > 1000000000000) return -1;
        ans += val(s[i])*power;
        power *= base;
        if(ans > 1000000000000) return -1;
    }
    return ans;    
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ULL t;cin>>t;
	vector<pair<ULL,string> > known;
	vector<string> unknown;
	while(t--){
		ULL n;cin>>n;
		ULL t;string s;
		for(ULL i = 0 ; i < n ; i++){
		    cin>>t>>s;
		    if(t != -1)known.push_back(make_pair(t,s));
		    else unknown.push_back(s);
		}
		ULL check = -1,k,poss = 1,kfound;
		for(ULL a = 0 ; a < known.size() ; a++){
			ULL k = convdec(known[a].second , known[a].first);
			if(k != -1){check = k;kfound = 1;break;}
		}
        if(kfound){
        	for(ULL i = 0 ; i < known.size() ; i++){
			ULL k = convdec(known[i].second , known[i].first);
			if(check != k){poss = 0;check = -1;break;}
		    }
        }
		if(poss){
		    if(check != -1){
		    	for(ULL i = 0 ; i < unknown.size() && poss; i++){
		    		int hua = 0;
		    		for(int j = 2 ; j <= 36 ; j++){
		    			if(check == convdec(unknown[i],j)){hua = 1;break;} 
		    		}if(hua == 0) poss = 0;
		    	}
			}else if(unknown.size()){
				 vector<ULL> a1,a2,a3;ULL k; 
				 for(ULL i = 2 ; i <= 36 ; i++){
				 	k = convdec(unknown[0] , i);
				 	if(k != -1)a1.push_back(k);
				 }
				 for(ULL i = 1 ; i < unknown.size() ; i++){
				 	for(int j = 2 ; j <= 36 ; j++){
				 		k = convdec(unknown[i] ,j);
				 	    if(k != -1)a2.push_back(k);
				 	}
				 	for(auto p = a1.begin() ; p != a1.end() ; p++){
				 		bool exist = false;
				 		for(auto l = a2.begin() ; l != a2.end() ; l++){
				 			if(*p == *l){exist = true;break;}//Intersection.
				 		}
				 		if(exist) a3.push_back(*p);
				 	}
				 	a1.clear();a1 = a3;a3.clear();a2.clear();
            	 }
				 sort(a1.begin(),a1.end());
				 if(a1.size()) check = a1[0];
				 else poss = 0;
			}
		}
		if(poss)cout<<check<<'\n';
		else cout<<-1<<'\n';
		known.clear();unknown.clear();
	}
	return 0;
} 
