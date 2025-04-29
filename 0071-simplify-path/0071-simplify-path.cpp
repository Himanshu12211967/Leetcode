class Solution {
public:

    string simplifyPath(string path) {
    vector<string> stack;
    string dir;
    int i = 0;
    int n = path.size();

    while (i < n) {
        // Skip multiple slashes
        while (i < n && path[i] == '/') i++;

        // Get the next part
        dir = "";
        while (i < n && path[i] != '/') {
            dir += path[i];
            i++;
        }

        if (dir == "" || dir == ".") {
            continue;  // Skip empty or current directory
        } else if (dir == "..") {
            if (!stack.empty()) stack.pop_back();  // Go up one level
        } else {
            stack.push_back(dir);  // Valid directory name
        }
    }

    // Build the canonical path
    if (stack.empty()) return "/";

    string result = "";
    for (const string& d : stack) {
        result += "/" + d;
    }

    return result;
}
};