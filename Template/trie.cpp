struct Trie {
    struct Node {
        int nxt[26];
        bool end;

        Node() {
            fill(nxt, nxt + 26, -1);
            end = false;
        }
    };

    vector<Node> tr;

    Trie() {
        tr.push_back(Node()); // root = 0
    }

    void insert(const string &s) {
        int cur = 0;

        for (char c : s) {
            int x = c - 'a';

            if (tr[cur].nxt[x] == -1) {
                tr[cur].nxt[x] = tr.size();
                tr.push_back(Node());
            }

            cur = tr[cur].nxt[x];
        }

        tr[cur].end = true;
    }

    bool search(const string &s) {
        int cur = 0;

        for (char c : s) {
            int x = c - 'a';

            if (tr[cur].nxt[x] == -1)
                return false;

            cur = tr[cur].nxt[x];
        }

        return tr[cur].end;
    }

    bool startsWith(const string &s) {
        int cur = 0;

        for (char c : s) {
            int x = c - 'a';

            if (tr[cur].nxt[x] == -1)
                return false;

            cur = tr[cur].nxt[x];
        }

        return true;
    }
};