#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

#define int long long
#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define ld long double

#define pii pair<int, int>
#define stlloop(x) for (__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define CLR(p) memset(p, 0, sizeof(p))
#define sp(x) std::cout << std::fixed << std::setprecision(x)

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b))/gcd(a, b)

#define PI acos(-1)
#define N 10000000
const int INF = 0x3f3f3f3f;
const int mod = 100000007;


void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

class node{
public:
    int data;
    node* left;
    node* right;

    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};



// O(n) solution
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        return max(lDepth, rDepth)+1;
    }
}

// O(n^2) solution
bool isBalanced(node* node)
{
    if (node == NULL)
        return true;
    
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    if(abs(lDepth-rDepth)>1) return false;
    
    bool left=isBalanced(node->left);
    bool right=isBalanced(node->right);
    
    if(!left or !right) return false;
    return true;
}


signed main()
{
    fast
    node* root = new node(1);
 
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "Height of tree is " << maxDepth(root);
    return 0;
}