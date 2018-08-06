/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns
3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads
n characters from the file.

Note:
The read function may be called multiple times.

Example 1:

Given buf = "abc"
read("abc", 1) // returns "a"
read("abc", 2); // returns "bc"
read("abc", 1); // returns ""
Example 2:

Given buf = "abc"
read("abc", 4) // returns "abc"
read("abc", 1); // returns ""

*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        while( cnt < n ){
            if(_idx == _nbry){
                _idx = 0;
                _nbry = read4(_buff);
                if(_nbry == 0)
                    break;
            }
            buf[cnt++] = _buff[_idx++];
        }
        return cnt;
    }

    char _buff[4];
    int _idx = 0;
    int _nbry = 0;
};
