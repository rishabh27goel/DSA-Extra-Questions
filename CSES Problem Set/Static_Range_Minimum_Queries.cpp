#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long int

void createSegmentTree(ll node, vector<ll> &arr, ll start, ll end, vector<ll> &tree){

    if(start == end){

        tree[node] = arr[start];
    }
    else{

        ll mid = start + (end - start) / 2;

        // Left Tree
        createSegmentTree(2 * node, arr, start, mid, tree);

        // Right Tree
        createSegmentTree(2 * node + 1, arr, mid+1, end, tree);

        // Store values of left and right tree
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

ll query(ll node, vector<ll> &tree, ll start, ll end, ll l, ll r){

    // Base Case
    if(end < l || start > r)
        return INT_MAX;

    // If node is in range
    if(l <= start && end <= r)
        return tree[node];


    ll mid = start + (end - start) / 2;

    ll part1 = query(2 * node, tree, start, mid, l, r);
    ll part2 = query(2 * node + 1, tree, mid+1, end, l, r);
    

    return min(part1, part2);
}

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);

    for(ll i=0; i<n; i++){

        cin >> arr[i];
    }

    // Create Segment Tree
    vector<ll> tree(n * 2, INT_MAX);

    createSegmentTree(1, arr, 0, n-1, tree);


    // Queries
    for(ll i=0; i<q; i++){

        ll l, r;
        cin >> l >> r;

        ll value = query(1, tree, 0, n-1, l-1, r-1);

        cout << value << endl;
    }


    cout << endl;
    return 0;
}