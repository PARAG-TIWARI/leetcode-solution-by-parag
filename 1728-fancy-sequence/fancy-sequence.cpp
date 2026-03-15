class Fancy {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> seq;
    long long mul = 1, add = 0;

    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long v = (val - add) % MOD;
        if (v < 0) v += MOD;
        v = (v * modPow(mul, MOD - 2)) % MOD; // modular inverse
        seq.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * mul % MOD + add) % MOD;
    }
};