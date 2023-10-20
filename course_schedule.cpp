#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define ss second
#define ff first
#define sum(vec) accumulate(vec.begin(), vec.end())
#define win(vec) vec.begin(), vec.end()
#define rwin() vec.rbegin(), vec.rend()
// 2^k--->(n && (!(n & (n - 1))))  ---(n & (n-1))
// string ip = x.substr(x.length() - 3);
// x.erase(x.length() - 2);
//-- -- -- -- -- --Sieve------------- //
vector<int> sieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    vector<int> primes;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; ++p)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; ++p)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
    return primes;
}
// transformation
vector<int> DfsOfGraph(int V, vector<int> adj[], map<int, vector<int>> &mp, vector<int> &result)
{
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            mp[i].push_back(j);
        }
    }
    return result;
}
//-------------------main-------------------//
int main()
{
    ll t;
    cin >> t;

    return 0;
}