class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
         stack<int> st;
	int i = 0, size = ast.size();
	while (i < size) {
		if (st.empty())
			st.push(ast[i++]);
		else {
			if (st.top() > 0 && ast[i] < 0) {
				if (st.top() > abs(ast[i]))
					i++;
				else if (st.top() < abs(ast[i]))
					st.pop();
				else {
					i++;
					st.pop();
				}
			}
			else
				st.push(ast[i++]);
		}
	}
	vector<int> result(st.size(), 0);
	for (int i = result.size() - 1; i >= 0; i--) {
		result[i] = st.top();
		st.pop();
	}
	return result;

    }
};
