const int INF = 1e18;

// for max query
struct ST {
	typedef int T;
	T unit = -INF;
	T f(T a, T b) { return max(a, b); }
	vector<T> s; int n;
	ST(int n = 0, T def = -INF) : s(2*n, def), n(n), unit(def) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	ST tree;
	
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N), pos(N), tree(N) { 
		dfsSz(0); 
		dfsHld(0); 
	}
	
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v]);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v]);
	}
	
	void modifyNode(int u, int val) {
		tree.update(pos[u], val);
	}
	
	int queryPath(int u, int v) {
		int res = -INF;
		process(u, v, [&](int l, int r) {
			res = max(res, tree.query(l, r + 1));
		});
		return res;
	}
	
	int querySubtree(int v) {
		return tree.query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};