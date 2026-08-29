class UnionFind {
public:
    unordered_map<int, int> parent;

    UnionFind(vector<int>& nums) {
        for (int num : nums) {
            parent[num] = num;
        }
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void unionSets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        UnionFind uf(nums);

        for (int i = 1; i < sortedNums.size(); i++) {
            if (sortedNums[i] - sortedNums[i - 1] <= limit) {
                uf.unionSets(sortedNums[i], sortedNums[i - 1]);
            }
        }

        unordered_map<int, queue<int>> groupToQueue;
        for (int num : sortedNums) {
            groupToQueue[uf.find(num)].push(num);
        }

        vector<int> result;
        for (int num : nums) {
            int group = uf.find(num);
            result.push_back(groupToQueue[group].front());
            groupToQueue[group].pop();
        }

        return result;
    }
};