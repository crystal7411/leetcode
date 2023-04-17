#include<vector>
#include<queue>
#include<map>

using namespace std;

// BFS로 구하면 됨
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == NULL) return NULL;

		queue<Node*> q;
		map<int, Node*> m; // mapper of clone node 

		if (m.find(node->val) == m.end()) {
			m[node->val] = new Node(node->val);
		}

		q.push(node);
		while (!q.empty()) {
			Node* origin = q.front(); q.pop();

			for (Node* adj : origin->neighbors) {
				if (m.find(adj->val) == m.end()) {
					m[adj->val] = new Node(adj->val);
					q.push(adj);
				}
				m[origin->val]->neighbors.push_back(m[adj->val]);
			}
		}

		return m[1];
	}
};