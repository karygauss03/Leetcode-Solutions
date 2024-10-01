#include <bits/stdc++.h>

using namespace std;

class StringHashing {
    public:
        /*
            4 possible values => first 2 primes greater than 4 are 5 and 7 => a1=5 a2=7;
            h[0] = s[0]-'A'
            h[k] = (h[k-1]*a + s[k]-'A')%m

            p[0] = 1
            p[k] = (p[k-1]*a)%m

            substr(a, b) = (h[b] - h[a-1]*p[b-a+1])%m
        */

        int a1 = 5, a2 = 7, m1 = 1e9 + 7, m2 = 1e9 + 9;
        vector<int> k1;
        vector<int> k2;
        vector<int> p1;
        vector<int> p2;
        string s;
        int n;

        StringHashing(string str) {
            s = str;
            n = s.size();
            k1.resize(n);
            k2.resize(n);
            p1.resize(n);
            p2.resize(n);

            fill(k1.begin(), k1.end(), 0);
            fill(k2.begin(), k2.end(), 0);
            fill(p1.begin(), p1.end(), 0);
            fill(p2.begin(), p2.end(), 0);
        
            build();
        }

        void generate_hash_data(vector<int> &k, vector<int> &p, int a, int m)
        {
            k[0] = s[0]-'a'+1;
            p[0] = 1;
            int n = s.size();
            for (int i=1 ; i<n ; i++)
            {
                k[i] = (k[i-1]*1ll*a + s[i]-'a'+1)%m;
                p[i] = (p[i-1]*1ll*a)%m;
            }
        }

        void build() {
            int n = s.size();
            generate_hash_data(k1, p1, a1, m1);
            generate_hash_data(k2, p2, a2, m2);
        }

        int get(vector<int> &k, vector<int> &p, int &m, int a, int b) {
            int res = k[b];
            if (a)
                res = (res - k[a-1]*1ll*p[b-a+1])%m;

            if (res < 0)
                res += m;

            return res;
        }

        int get1(int a, int b) {
            return get(k1, p1, m1, a, b);
        }

        int get2(int a, int b) {
            return get(k2, p2, m2, a, b);
        }
};

class Solution {
public:
    int minStartingIndex(string ch, string p) {
        int n = ch.size();
        int m = p.size();

        StringHashing hs = StringHashing(ch);
        StringHashing hp = StringHashing(p);

        for (int i=0 ; i<=n-m ; i++) {
            int s = 0;
            int e = m;

            while(s<e) {
                int l = (s+e+1)/2;
                int sg1 = hs.get1(i, i+l-1);
                int sg2 = hs.get2(i, i+l-1);

                int pg1 = hp.get1(0, l-1);
                int pg2 = hp.get2(0, l-1);

                if (pg1 == sg1 && pg2 == sg2) {
                    s = l;
                } else {
                    e = l-1;
                }
            }

            if (s >= m-1)
                return i;

            int j = i+s+1;
            int r = m-s-1;
            int sg1 = hs.get1(j, j+r-1);
            int sg2 = hs.get2(j, j+r-1);

            int pg1 = hp.get1(s+1, s+r);
            int pg2 = hp.get2(s+1, s+r);

            if (pg1 == sg1 && pg2 == sg2)
                return i;

        }
    
        return -1;
    }
};