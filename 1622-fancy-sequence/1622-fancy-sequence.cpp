class Fancy {
private:
    vector<long long> seq;
    const int MOD = 1e9 + 7;
    long long mul = 1, add = 0;
    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    Fancy() { seq.clear(); }

    void append(int val) {
        long long inv = modPow(mul, MOD - 2);
        long long stored = ((val - add + MOD) % MOD) * inv % MOD;
        seq.push_back(stored);
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m) {
        mul = ((mul % MOD) * m) % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size())
            return -1;
        return ((seq[idx] % MOD) * (mul % MOD) % MOD + add % MOD) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */