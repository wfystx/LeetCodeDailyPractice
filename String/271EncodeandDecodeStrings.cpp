class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string;
        for(string str:strs)
            encoded_string += to_string(str.size()) + "@" + str;
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int i(0), j(0);
        for(; i<s.size(); i++){
            if(s[i] == '@'){
                int len = stoi(s.substr(j, i-j));
                j = i + 1;
                strs.push_back(s.substr(j, len));
                j += len;
                i = j;
            }
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));