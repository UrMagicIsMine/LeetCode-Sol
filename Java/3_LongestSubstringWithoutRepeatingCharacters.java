/* Given a string, find the length of the longest substring without repeating
* characters.
*
* Examples:
*
* Given "abcabcbb", the answer is "abc", which the length is 3.
*
* Given "bbbbb", the answer is "b", with the length of 1.
*
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer
* must be a substring, "pwke" is a subsequence and not a substring.
*/

public int lengthOfLongestSubstring(String s) {
    HashMap<Character, Integer> char_table = new HashMap<>();
    int front = 0, back = 0, ret = 0;
    for(; front < s.length(); front++) {
        Integer it = char_table.get(s.charAt(front));
        if (it == null || it < back) {
            ret = Math.max(ret, front - back + 1);
        } else {
            back = it + 1;
        }
        char_table.put(s.charAt(front), front);
    }
    return ret;
}
