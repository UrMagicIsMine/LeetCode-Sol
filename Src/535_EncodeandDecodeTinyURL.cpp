/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as
https://leetcode.com/problems/design-tinyurl and it returns a short URL such as
http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no
restriction on how your encode/decode algorithm should work. You just need to
ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded
to the original URL.
*/

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        const static string __sz = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        const static int N = 62;
        auto it = _url2code.find(longUrl);
        if( it != _url2code.end()){
            return it->second;
        }
        while( _url2code.find(longUrl) == _url2code.end() ){
            string code;
            for(int i = 0; i < 6; i++){
                code += __sz[rand()%N];
            }
            if(_code2url.find(code) == _code2url.end()){
                _code2url[code] = longUrl;
                _url2code[longUrl] = code;
            }
        }
        return string("http://tinyurl.com/") + _url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string sz = shortUrl.substr(19,6);
        auto it = _code2url.find(sz);
        if( it == _code2url.end())
            return "";
        else
            return it->second;
    }


private:

    unordered_map<string, string> _url2code;
    unordered_map<string, string> _code2url;
};
