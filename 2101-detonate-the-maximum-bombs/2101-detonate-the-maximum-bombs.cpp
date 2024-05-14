class Solution {
public:

    int isOverlap(vector<int> bomb1, vector<int> bomb2){
        long long int x1 = bomb1[0];
        long long int y1 = bomb1[1];
        long long int r1 = bomb1[2];

        long long int x2 = bomb2[0];
        long long int y2 = bomb2[1];
        long long int r2 = bomb2[2];

        if((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= r1*r1)
            return true;
        return false;
    }

    int dfs(int node, vector<int>& isVisited, vector<vector<int>>& graph){
        isVisited[node] = 1;

        int sum = 0;
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if(!isVisited[next])
                sum += dfs(next, isVisited, graph);
        }
        return 1 + sum;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int N = bombs.size();
        vector<vector<int>> graph(N);

        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(isOverlap(bombs[i], bombs[j])){
                    graph[i].push_back(j);
                }
                if(isOverlap(bombs[j], bombs[i])){
                    graph[j].push_back(i);
                }
            }
        }

        int result = 0;
        for(int i = 0; i < N; i++){
            vector<int> isVisited(N, 0);
            result = max(result, dfs(i, isVisited, graph));
        }
        return result;
    }
};