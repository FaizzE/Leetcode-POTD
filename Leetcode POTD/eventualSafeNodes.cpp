class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, vector<bool>& stack) {
        if (stack[node]) return true;
        if (visit[node]) return false;
        visit[node] = true;
        stack[node] = true;
        for (int neighbor : adj[node]) {
            if (dfs(neighbor, adj, visit, stack)) return true;
        }
        stack[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n), stack(n);
        for (int i = 0; i < n; i++) dfs(i, graph, visit, stack);
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!stack[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
