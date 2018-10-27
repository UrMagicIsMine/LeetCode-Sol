/* Equations are given in the format A / B = k, where A and B are variables
* represented as strings, and k is a real number (floating point number). Given
* some queries, return the answers. If the answer does not exist, return -1.0.
*
* Example:
* Given a / b = 2.0, b / c = 3.0.
* queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
* return [6.0, 0.5, -1.0, 1.0, -1.0 ].
*
* The input is: vector<pair<string, string>> equations, vector<double>& values,
* vector<pair<string, string>> queries , where equations.size() == values.size(),
* and the values are positive. This represents the equations. Return vector<double>.
*
* According to the example above:
*
* equations = [ ["a", "b"], ["b", "c"] ],
* values = [2.0, 3.0],
* queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
* The input is always valid. You may assume that evaluating the queries will result
* in no division by zero and there is no contradiction.
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <map>
#include <set>
#include <cassert>
using namespace std;

bool _DFS(unordered_map<string, map<string, double>>& graph, unordered_map<string, bool>& visited, string &iNode, string &target, double& val) {

	if (iNode == target)
		return true;
	visited[iNode] = true;
	for (auto &p : graph[iNode]) {
		string nxtNode = p.first;
		if (!visited[nxtNode]) {
			val *= p.second;
			int ret = _DFS(graph, visited, nxtNode, target, val);
			if (ret == true)
				return true;
			val /= p.second;
		}
	}
	visited[iNode] = false;
	return false;
}

vector<double> calcEquation(vector<pair<string, string>>& equations, vector<double>& values, vector<pair<string, string>>& queries) {

	unordered_map<string, map<string, double>> graph;
	for (int i = 0; i < equations.size(); i++) {
		graph[equations[i].first].insert(make_pair(equations[i].second, values[i]));
		graph[equations[i].second].insert(make_pair(equations[i].first, 1.0 / values[i]));
	}

	int N = queries.size();
	vector<double> resl(N, -1.0);

	unordered_map<string, bool> visited;

	int i = -1;
	for (auto &pss : queries) {
		i++;
		if (graph.find(pss.first) == graph.end() || graph.find(pss.second) == graph.end())
			continue;

		for (auto &p : graph)
			visited[p.first] = false;
		double val = 1.0;
		if (_DFS(graph, visited, pss.first, pss.second, val)) {
			resl[i] = val;
		}

	}
	return resl;
}

int main()
{
	vector<pair<string, string>> equations = { {"a", "b"},{"b", "c"} };
	vector<double> values = { 2.0, 3.0 };
	vector<pair<string, string>> queries = { {"a", "c"},{"b", "c"},{"a", "e"},{"a", "a"},{"x", "x"} };
	vector<double> ret = calcEquation(equations, values, queries);
	vector<double> ans = {6.0, 3.0, -1.0, 1.0, -1.0};
	assert(ret == ans);
	return 0;
}
