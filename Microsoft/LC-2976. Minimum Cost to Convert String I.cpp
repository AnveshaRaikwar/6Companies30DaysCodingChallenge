class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));

        // Distance from a character to itself is always 0
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // Populate the distance matrix based on the given transformations
        for (size_t i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            dist[from][to] = min(dist[from][to], (long long)cost[i]);
        }

        // Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
        for (int node = 0; node < 26; node++) {
            for (int u = 0; u < 26; u++) {
                for (int v = 0; v < 26; v++) {
                    if (dist[u][node] != LLONG_MAX && dist[node][v] != LLONG_MAX) {
                        dist[u][v] = min(dist[u][v], dist[u][node] + dist[node][v]);
                    }
                }
            }
        }

        // Calculate the minimum cost to convert source to target
        long long ans = 0;
        for (size_t i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) continue;
            int from = source[i] - 'a';
            int to = target[i] - 'a';

            // If no valid transformation is possible, return -1
            if (dist[from][to] == LLONG_MAX) return -1;

            ans += dist[from][to];
        }

        return ans;
    }
};