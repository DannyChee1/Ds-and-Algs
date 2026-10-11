#include <bits/stdc++.h>
using namespace std;

struct Trie {
    vector<array<int, 26>> ch{{}};
    vector<bool> end{false};

    void insert(const string &s) {
        int u = 0;
        for (char c : s) {
            int i = c - 'a';
            if (!ch[u][i]) { ch[u][i] = ch.size(); ch.push_back({}); end.push_back(false); }
            u = ch[u][i];
        }
        end[u] = true;
    }
    int walk(const string &s) {
        int u = 0;
        for (char c : s) if (!(u = ch[u][c - 'a'])) return -1;
        return u;
    }
    bool search(const string &s) { int u = walk(s); return u != -1 && end[u]; }
    bool startsWith(const string &s) { return walk(s) != -1; }
};

int main() {
    Trie t;
    t.insert("apple");
    assert(t.search("apple") && !t.search("app") && t.startsWith("app") && !t.startsWith("b"));
    t.insert("app");
    assert(t.search("app"));
    cout << "ok\n";
}
