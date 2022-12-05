// #include <iostream>
// #include <vector>
// using namespace std;

#define ll long long int

// int main()
// {
//     ll n, q;
//     cin >> n >> q;

//     vector<ll> arr(n);

//     vector<ll> prefix(n);
//     long sum = 0;

//     for(ll i=0; i<n; i++){

//         cin >> arr[i];
    
//         sum += arr[i];
//         prefix[i] = sum;
//     }

//     for(ll j=0; j<q; j++){

//         ll a, b;
//         cin >> a >> b;

//         ll result;

//         if(a - 2 >= 0)
//             result = prefix[b-1] - prefix[a - 2];
//         else    
//             result = prefix[b-1];

//         cout << result << endl;
//     }

//     cout << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void createSegmentTree(ll node, vector<ll> &arr, int start, int end, vector<ll> &tree){

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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(ll node, vector<ll> &tree, ll start, ll end, ll l, ll r){

    // Base Case
    if(end < l || start > r)
        return 0;

    // If node is in range
    if(l <= start && end <= r)
        return tree[node];


    ll mid = start + (end - start) / 2;

    ll part1 = query(2 * node, tree, start, mid, l, r);
    ll part2 = query(2 * node + 1, tree, mid+1, end, l, r);
    

    return part1 + part2;
}

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    // Create Segment Tree
    vector<ll> tree(n * 4, 0);

    createSegmentTree(1, arr, 0, n-1, tree);


    // Queries
    for(int i=0; i<q; i++){

        ll l, r;
        cin >> l >> r;

        ll value = query(1, tree, 0, n-1, l-1, r-1);

        cout << value << endl;
    }


    cout << endl;
    return 0;
}