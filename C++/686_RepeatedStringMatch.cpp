/*
Given two strings A and B, find the minimum number of times A has to be repeated
such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring
of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

#include <string>

int repeatedStringMatch(string A, string B) {
    for(auto i = 0, j = 0; i < A.size(); i++){
        for(j = 0; j < B.size() && A[(i+j)%A.size()] == B[j]; j++){
        }

        if(j == B.size()){
            int num = (i+j)/A.size();
            if((i+j)%A.size() != 0)
                num++;
            return num;
        }

    }
    return -1;
}
