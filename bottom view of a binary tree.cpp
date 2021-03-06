
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lli long long int
#define mod 1000000007
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vc vector<char>
#define vlli vector<long long int>
#define vvi vector<vector<int>>
#define uos unordered_set<int>
#define min_heap priority_queue<int,vector<int>,greater<int>>
#define max_heap priority_queue<int>
#define pii pair<int,int>
#define F first
#define S second
#define loop(a,b) for(lli i=a;i<=b;i++)
#define endl '\n'

class Node
{
public:
	int data;
	int hd;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		hd = INT_MAX;
		left = right = nullptr;
	}
};

void bottom_view(Node *root)
{
	if(root == nullptr)
		return;

	queue<Node*> Q;
	map<int,int> mp;

	int hd = 0;
	Q.push(root);

	while(!Q.empty())
	{
		Node *temp = Q.front();
		Q.pop();

		hd = temp->hd;

		mp[hd] = temp->data;

		if(temp->left)
		{
			temp->left->hd = hd-1;
			Q.push(temp->left);
		}

		if(temp->right)
		{
			temp->right->hd = hd+1;
			Q.push(temp->right);
		}
	}

	for(auto i = mp.begin(); i != mp.end(); i++)
		cout<<i->second<<" ";
}

void solve()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;
		
		Node *root = new Node(20);
	    root->left = new Node(8);
	    root->right = new Node(22);
	    root->left->left = new Node(5);
	    root->left->right = new Node(3);
	    root->right->left = new Node(4);
	    root->right->right = new Node(25);
	    root->left->right->left = new Node(10);
	    root->left->right->right = new Node(14);

	    bottom_view(root);
	}
}

int main()
{
	fast_io;

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif

	solve();

	return 0;
}
