// Problem Link - https://codeforces.com/contest/1348/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    if(s[0]!=s[k-1]){
        cout<<s[k-1]<<"\n";
        return;
    }
    cout<<s[0];
    if(s[k]!=s[n-1]){
        for(int i=k;i<n;++i)
            cout<<s[i];    
        cout<<"\n";
    }else{
        for(int i=k;i<n;i+=k)
            cout<<s[i];
        cout<<"\n";
    }
    return;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/* Editorial
We first try to assign one letter to each string a[i]. Let's denote the smallest letter in s as c. If there exists at least k 
occurrences of c in s, we will assign c as the first letter of each string ai. Otherwise, the minimal solution is the kth 
smallest letter in s. For example, if s=aabbb and k=3, the 3rd smallest letter is b and that will be the answer.
Otherwise, we consider the letters that are left in s.If they are all the same letter (or there are no letters left 
because n=k), we split the remaining letters as evenly as possible among ai. If not, we will show that it is optimal to sort 
the remaining letters in s and append them to arbitrary a[i].

For example, let's suppose after assigning a letter to each a[i] that the remaining letters in s are aaabb. We want to 
assign the bs as late as possible, so any string ai that receives a b should have some number of as before. It makes sense in
fact that the string that receives a b should receive all the as, because if not it will be lexicographically larger. It can 
then be shown that all remaining larger letters should be sorted and added to the same string a[i]to minimize the answer.

Time complexity for each test case: O(nlogn)
(for sorting s)
*/
