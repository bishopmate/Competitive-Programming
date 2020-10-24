#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define PI 3.14159265
const int mod = 1000000009;
#define fi(i,start,end) for(int i=0; i<n; i++)
#define pb(x) push_back(x)
#define int long long
#define eb emplace_back
#define VI vector<int>
#define VII vector<vector<int>>
#define all(v) v.begin(), v.end()
#define endl cout<<"\n" 
#define dbg(x) cout<<#x<<" "<<x;endl;
#define bye endl;return
using namespace __gnu_pbds;
using namespace std;
template<typename T>

int countBits(int n){
	int count = 0;
	while(n>0){
		if(n&1)
			count++;
		n = n>>1;
	}
	return count;
}
bool isValid(int i, int j, int n, int m){
    return (i>=0 && i<n && j>=0 && j<m);
}
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

bool isOverflow(int a, int b){
    if (a == 0 || b == 0)  
        return false; 
      
    
    if(b > 0 && a > 18446744073709551615U / b)
        return true; 
   
    return false; 
}
int gcdBinary(int a, int b, int res){
  if(a == b){
    return a * res;
  }
  if(a == 0){
    return b*res;
  }else if(b == 0){
    return a*res;
  }
  if(!(a&1) && !(b&1)){
    return gcdBinary((a >> 1), (b >> 1), res*2);
  }else if(!(a&1)){
    return gcdBinary((a >> 1), b, res);
  }else if(!(b&1)){
    return gcdBinary(a, (b >> 1), res);
  }else if(a > b){
    return gcdBinary(a-b, b, res);
  }else{
    return gcdBinary(a, b-a, res);
  }
}
int powerer(int a,int b){
    int ans=1;
    while(b>0){
        if(b&1){
            ans=ans*a;
        }
        b=b>>1;
        a=a*a;
    }
    return ans;
}
int set_bits(int n){ 
     int p;
     int i = 0;
     while(n>0){
         p = (n & -n);
         n = n-p;++i;
     }
     return i;// Time Complexity-> O(k) where k =  no. of set bits
}
vector<int> prime_factors(int n){
    vector<int> primeFactors;
    while(n%2==0){
        primeFactors.push_back(2);
        n = n/2;
    }
    for(int i = 3;i<= sqrt(n); i+=2){
        while(n%i==0){
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    if(n>2){
        primeFactors.push_back(n);
    }
    return primeFactors;
}
int fastModExp(int a,int b,int m){
    int res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}
vector<int> divisors(int n){
    
    vector<int> divs;
    for(int i=1; i*i<=n; ++i){
        
        if((n%i)==0){
            divs.pb(i);
            if(i != (n/i)){
                divs.pb(n/i);
            }
        }
        
    }
    sort(divs.begin(),divs.end());
    return divs;
    
}
int primeFactors(int n) 
{ 
	 
	int count = 0;
  	while (n % 2 == 0) 
	{ 
		// cout << 2 << " ";
        count++; 
		n = n/2; 
	} 

	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
 
		while (n % i == 0) 
		{ 
			// cout << i << " ";
            count++;
			n = n/i; 
		} 
	} 
 
	if (n > 2){ 
		// cout << n << " ";
    	count++;
    } 
  return count;
} 
bool isPrime(int a){
    int helper = primeFactors(a);
    if(helper==1)
        return true;
    return false;
}
string decToBin(int n){
    string s;
    while(n>0){
        if(n&1) s.push_back('1');
        else    s.push_back('0');

        n = n/2;
        
    }
    reverse(s.begin(), s.end());
    return s;
}
int binToDec(string s){
    int ans = 0;
    for(int i=(int)(s.size()) - 1, j=0; i >=0;j++, i--){
        if(s[i]=='1'){
            ans += powerer(2,j);
        }
    }
    return ans;
    
}
int binomialCoeff(int n, int k) 
{ 
    int C[n + 1][k + 1]; 
    int i, j; 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    } 
    return C[n][k]; 
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    
    return 0;
}
