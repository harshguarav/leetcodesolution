class Solution {
public:
   const long long MOD = 1e9 + 7;

long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<long long> powers;
    for (int bit = 0; bit <= 31; bit++) {
        if (n & (1 << bit)) powers.push_back(1LL << bit);
    }
    
    int m = powers.size();
    vector<long long> prefix(m);
    prefix[0] = powers[0] % MOD;
    for (int i = 1; i < m; i++) {
        prefix[i] = (prefix[i-1] * powers[i]) % MOD;
    }
    
    vector<int> ans;
    for (auto &q : queries) {
        int l = q[0], r = q[1];
        long long res;
        if (l == 0) res = prefix[r];
        else res = (prefix[r] * modPow(prefix[l-1], MOD-2)) % MOD;
        ans.push_back(res);
    }
    return ans;
}
};