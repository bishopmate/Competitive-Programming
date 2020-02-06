#include<bits/stdc++.h>
#define speed ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
ll powerer(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=ans*a;
        }
        b=b>>1;
        a=a*a;
    }
    return ans;
}
int main(){
    speed;// I love Cars Movie
    ll monsters,me_hp,opp_hp,chances;
    cin>>monsters>>me_hp>>opp_hp>>chances;
    // Taking Input the hp(health_points of monsters)
    ll monsters_hp[monsters];
    ll no_of_chances[monsters];
    // We will need to use the chances only when the monster dies at the hand of my opponents 
    // Let's DRY Run through an attack on a monster 
    // My hp_attack - 2, Opponent hp_attack - 3
    // Monster hp - 20, 
    //     1st attack Damage dealt - 2, Monster_hp remaining = 18 Turn->Ours
    //     2nd attack Damage dealt - 3, Monster_hp remaining = 15 Turn->Opponent
    //     3rd attack Damage dealt - 2, Monster_hp remaining = 13 Turn->Ours
    //     4th attack Damage dealt - 3, Monster_hp remaining = 10 Turn->Opponent
    //     5th attack Damage dealt - 2, Monster_hp remaining = 8 Turn->Ours
    //     6th attack Damage dealt - 3, Monster_hp remaining = 5 Turn->Opponents
    //     7th attack Damage dealt - 2, Monster_hp remaining = 3 Turn->Ours
    //     8th attack Damage dealt - 3, Monster_hp remaining = 0 Turn->Opponents
    //          Opponent dies at the hand of our opponent, so we don't get any point
    ll last_round;
    for(int i = 0; i<monsters; ++i){
        cin>>monsters_hp[i];
        last_round = monsters_hp%(me_hp+opp_hp);
        if(last_round==0){
            monsters_hp[i] = me_hp+opp_hp;
        }else{
            monsters_hp[i] = last_round;
        }
        no_of_chances[i] = ceil(monsters_hp[i]/me_hp) - 1;

    }
    sort(no_of_chances,no_of_chances+monsters);
    ll i = 0;
    ll points = 0;
    while((chances-no_of_chances[i])>0){
        chances = chances - no_of_chances[i];
        ++points;
    }
    cout<<points<<"\n";
    return 0;
}
