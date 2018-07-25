/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

*/

bool isVow(char c){
    switch(c){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
    }
}

string reverseVowels(string s) {
    int i = 0, j = (int)s.length() - 1;
    while(i < j){
        while(i < j && !isVow(s[i]))
            i++;
        while(i < j && !isVow(s[j]))
            j--;
        if( i < j )
            swap(s[i++], s[j--]);
    }
    return s;
}
