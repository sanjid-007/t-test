#include<stdio.h>
#include<iostream>
#include<climits>
#include<map>
#include<cmath>
#include<algorithm>
#include<set>
#include<stack>
#include<deque>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<utility>
#include<queue>
using namespace std;
typedef long long ll;
typedef    long double   ld;
#define f(i,a,b) for(ll i = a; i < b; i++)
#define F(i,a,b) for(ll i = b-1; i >= a; i--)
#define op(x) cout<<x<<kl;
#define ol(x) cout<<x<<" ";
#define cu continue
#define br break
#define ins insert
#define ft front
#define bk back
#define bb begin
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ff first
#define ss second
#define rr return
#define kl    '\n'
#define go(i, a) for (auto &i : a)
#define inf             1e18
#define sz(obj) (int(obj.size()))
typedef vector <ll> vll;
#define vvll vector<vll>
#define unset(x, i) (x & ~(1 << i))
#define set(x, i) (x | ((1 << i)))
#define check(x, i) (x & (1 << i))
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define fastio()                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const ll N = 5e5 + 5;
ll b[N];
ll c;
ll mn;
vll v[N];
ll n;
void g(ll x, ll pr){
	b[x] = 1;
	ll p = 0;
	for(ll d = 0;d<sz(v[x]);d++){
		ll i = v[x][d];
		if(i == pr) cu;
		g(i,x);
		b[x]+=b[i];
		p = max(p,b[i]);
	}
	p = max(p,n - b[x]);
	if(p <mn) mn = p,c = x;
	else if(p == mn) c = min(c,x);
	
	

}



void sol(){
	cin>>n;
	f(i,0,n+1){
		v[i].clear();
		b[i] = 0;

	}
	mn = inf;
	c = inf;
	f(i,0,n-1){
		ll x,y; cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	g(1,0);
	ol(c);
	op(mn); 
}
int main()
{
   fastio();
  ll t = 1;
  cin>>t;
  while(t--)
  {
     sol();
  }
  return 0;
}