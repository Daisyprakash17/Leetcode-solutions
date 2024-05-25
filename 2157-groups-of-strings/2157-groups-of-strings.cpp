class Solution {
public:
    unordered_map<int, int> par;
    unordered_map<int, int> rank;

    int findpar(int n) {
        if (par[n] == n)
            return n;
        return par[n] = findpar(par[n]); // Path compression
    }

    void unionjoin(int a, int b) {
        int pa = findpar(a);
        int pb = findpar(b);
        // Union by rank
        if (pa != pb) {
            if (rank[pa] > rank[pb]) {
                par[pb] = pa;
            } else if (rank[pa] < rank[pb]) {
                par[pa] = pb;
            } else {
                par[pb] = pa;
                rank[pa]++;
            }
        }
    }

    void process(int n) {
        vector<int> bits;
        for (int i = 0; i < 26; ++i) {
            if ((n & (1 << i)) == 0) {
                bits.push_back(i);
            }
        }

        // Adding one character
        for (int i : bits) {
            int temp = n | (1 << i);
            if (par.count(temp)) {
                unionjoin(temp, n);
            }
        }

        // Deleting one character
        for (int i = 0; i < 26; ++i) {
            if ((n & (1 << i)) != 0) {
                int temp = n & ~(1 << i);
                if (par.count(temp)) {
                    unionjoin(temp, n);
                }
            }
        }

        // Replacing one character
        for (int i = 0; i < 26; ++i) {
            if ((n & (1 << i)) != 0) {
                int temp = n & ~(1 << i);
                for (int j : bits) {
                    int supertemp = temp | (1 << j);
                    if (par.count(supertemp)) {
                        unionjoin(supertemp, n);
                    }
                }
            }
        }
    }

    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int, int> counts;
        vector<int> temps;

        for (const string& word : words) {
            int temp = 0;
            for (char ch : word) {
                temp |= 1 << (ch - 'a');
            }
            if (!par.count(temp)) {
                par[temp] = temp;
                rank[temp] = 0;
            }
            counts[temp]++;
            temps.push_back(temp);
        }

        for (int i : temps) {
            process(i);
        }

        unordered_map<int, int> m;
        int ma = 0;
        for (const auto& p : counts) {
            int temppar = findpar(p.first);
            m[temppar] += p.second;
            ma = max(ma, m[temppar]);
        }

        vector<int> myans;
        myans.push_back(m.size());
        myans.push_back(ma);
        return myans;
    }
};