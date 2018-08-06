/*
In this chapter, we discuss the problem of Segment Tree: A data structure which
can efficiently answer dynamic range queries.
*/

class SegmentTree {

public:

	SegmentTree(int n) {
		_n = 1;
		while (_n < n) {
			_n *= 2;
		}

		_num.assign(2 * _n - 1, INT_MAX);
	}

	// update k-th (0-indexed) value to val;
	void update(int k, int val) {
		k += _n - 1;
		_num[k] = val;

		while (k > 0) {
			k = (k - 1) / 2; // get parent
			_num[k] = min(_num[k * 2 + 1], _num[k * 2 + 2]);
		}
		return;
	}

	// get the minimal of [l, r)
	int query(int l, int r) {
		return query(l, r, 0, 0, _n);
	}

private:

	// get the minimal of [a, b)
	int query(int a, int b, int k, int l, int r) {
		// if [a, b) and [l, r) have no intersection
		if (r <= a || b <= l) return INT_MAX;

		// if [l, r) is inside [a, b)
		if (a <= l && r <= b) return _num[k];

		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}

private:

	vector<int> _num;
	int _n;

};
