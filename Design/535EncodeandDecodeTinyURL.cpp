class Solution {
public:
    unordered_map<int,string> m;
    int cnt = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m[cnt] = longUrl;
        return "http://tinyurl.com/#" + to_string(cnt++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[stoi(shortUrl.substr(shortUrl.find("#")+1))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));