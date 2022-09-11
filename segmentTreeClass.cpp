class SegmentTree {
public:
	int* tree;
	SegmentTree(int n) {
		tree = new int[4 * n + 5]();
		for (int i = 0; i < (4 * n + 5); i++ ) tree[i] = -inf;

	}
	int left(int x) {
		return 2 * x + 1;
	}
	int right(int x) {
		return 2 * x + 2;
	}
	int operate(int a, int b) {
		return max(a, b);
	}
	void pull(int node) {
		tree[node] = operate(tree[left(node)], tree[right(node)]);
	}
	void buildTree(int low, int high, int node) {
		if (low == high) {
			tree[node] = 0;
			return;
		}
		int mid = low + (high - low) / 2;
		buildTree(low, mid, left(node));
		buildTree(mid + 1, high, right(node));
		pull(node);
	}
	int query(int low, int high, int node, int qlow, int qhigh) {

		if (qlow > high || qhigh < low || qhigh < qlow) return -inf;
		if (qlow <= low && qhigh >= high) {
			return tree[node];
		}
		int mid = low + (high - low) / 2;
		int l = query(low, mid, left(node), qlow, qhigh);
		int r = query(mid + 1, high, right(node), qlow, qhigh);
		return operate(l, r);
	}
	void update(int low, int high, int node, int idx, int val) {
		if (low == high) {
			tree[node] = max(val, tree[node]);
			return;
		}
		int mid = low + (high - low) / 2;
		if (mid >= idx)update(low, mid, left(node), idx, val);
		else update(mid + 1, high, right(node), idx, val);
		pull(node);

	}

};
