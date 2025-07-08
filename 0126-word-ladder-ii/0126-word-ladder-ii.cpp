class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!dict.count(endWord)) return result;

        // Store parents to reconstruct paths
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel{beginWord};
        unordered_set<string> visited;

        bool found = false;

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            for (auto word : currentLevel) dict.erase(word); // mark as visited

            for (const auto& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) continue;
                        temp[i] = c;
                        if (dict.count(temp)) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }

            currentLevel = nextLevel;
        }

        if (!found) return result;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

    void backtrack(string word, string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            result.push_back(validPath);
            return;
        }

        for (const auto& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
