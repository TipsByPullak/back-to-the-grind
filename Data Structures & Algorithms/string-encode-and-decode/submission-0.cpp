class Solution {
public:

    std::string encode(const std::vector<std::string>& strs) {
        std::string encoded;
        for (const std::string& s : strs) {
            encoded += std::to_string(s.size()) + '#' + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> decoded;
        size_t i = 0;
        const size_t n = s.size();

        while (i < n) {
            // Find the delimiter '#' separating length and payload
            size_t slash_pos = s.find('#', i);
            
            // Extract the length integer
            int len = std::stoi(s.substr(i, slash_pos - i));
            
            // Extract the actual payload
            size_t payload_start = slash_pos + 1;
            decoded.push_back(s.substr(payload_start, len));
            
            // Move pointer past the extracted string
            i = payload_start + len;
        }

        return decoded;
    }
};
