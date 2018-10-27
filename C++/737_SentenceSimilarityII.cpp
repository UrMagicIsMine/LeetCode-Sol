/*
Given two sentences words1, words2 (each represented as an array of strings),
and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama",
"talent"] are similar, if the similar word pairs are pairs = [["great", "good"],
["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and
"good" are similar, and "fine" and "good" are similar, then "great" and "fine"
are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is
the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 =
["great"], words2 = ["great"], pairs = [] are similar, even though there are no
specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words.
So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].

*/



#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class UnionFindSet {

public:

	UnionFindSet(int n) : _par(n, 0), _rank(n, 0) {
		for (int i = 0; i < n; i++) {
			_par[i] = i;
		}
	}

	int find(int x) {
		if (x == _par[x])
			return x;
		else
			return _par[x] = find(_par[x]);
	}

	bool Union(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;

		if (_rank[x] < _rank[y]) {
			_par[x] = y;
		}
		else {
			_par[y] = x;
			if (_rank[x] == _rank[y]) {
				_rank[x]++;
			}
		}
		return true;
	}

private:

	vector<int> _par;
	vector<int> _rank;
};


bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
	if (words1.size() != words2.size())
		return false;

	unordered_map<string, int> hashtbl;
	int idx = 0;
	for (auto &p : pairs) {
		auto it = hashtbl.find(p.first);
		if (it == hashtbl.end())
			hashtbl[p.first] = idx++;
		it = hashtbl.find(p.second);
		if (it == hashtbl.end())
			hashtbl[p.second] = idx++;
	}

	UnionFindSet s(idx);
	for (auto &p : pairs) {
		s.Union(hashtbl[p.first], hashtbl[p.second]);
	}

	for (int i = 0; i < words1.size(); i++) {

		if (words1[i] == words2[i])
			continue;

		auto it1 = hashtbl.find(words1[i]);
		if (it1 == hashtbl.end())
			return false;
		auto it2 = hashtbl.find(words2[i]);
		if (it2 == hashtbl.end())
			return false;
		if (s.find(it1->second) != s.find(it2->second))
			return false;
	}
	return true;
}

int main()
{
	vector<string> words1 = { "an", "extraordinary", "meal" };
	vector<string> words2 = { "one", "delicious", "dinner" };
	vector<pair<string, string>> pairs = {{"great", "good"}, {"extraordinary", "good"},
    {"well", "good"}, {"wonderful", "good"}, {"excellent", "good"}, {"fine", "good"},
    {"nice", "good"}, {"any", "one"}, {"some", "one"}, {"unique", "one"}, {"the", "one"},
    {"an", "one"}, {"single", "one"}, {"a", "one"}, {"truck", "car"}, {"wagon", "car"},
    {"automobile", "car"}, {"auto", "car"}, {"vehicle", "car"}, {"entertain", "have"},
    {"drink", "have"}, {"eat", "have"}, {"take", "have"}, {"fruits", "meal"}, {"brunch", "meal"},
    {"breakfast", "meal"}, {"food", "meal"}, {"dinner", "meal"}, {"super", "meal"},
    {"lunch", "meal"}, {"possess", "own"}, {"keep", "own"}, {"have", "own"},
    {"extremely", "very"}, {"actually", "very"}, {"really", "very"}, {"super", "very"}};
	bool ret = areSentencesSimilarTwo(words1, words2, pairs);
	return 0;
}
