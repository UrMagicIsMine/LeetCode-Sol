/* In the following, every capital letter represents some hexadecimal digit from
*  0 to f.
*
* The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.
* For example, "#15c" is shorthand for the color "#1155cc".
*
* Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is
* -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.
*
* Given the color "#ABCDEF", return a 7 character color that is most similar to
* #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"
*
* Example 1:
* Input: color = "#09f166"
* Output: "#11ee66"
* Explanation:
* The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2
*                   = -64 -9 -0 = -73.
* This is the highest among any shorthand color.
* Note:
*
* -- color is a string of length 7.
* -- color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from
*    0 to f
* -- Any answer which has the same (highest) similarity as the best answer will
*    be accepted.
* -- All inputs and outputs should use lowercase letters, and the output is 7
*    characters.
*/

#include <string>
#include <map>
#include <cassert>
using namespace std;


string _getRGB(string sz) {

	static char itoc[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	static map<char, int> ctoi = { { '0',0 },{ '1',1 },{ '2',2 },{ '3',3 },
	{ '4',4 },{ '5',5 },{ '6',6 },{ '7',7 },
	{ '8',8 },{ '9',9 },{ 'a',10 },{ 'b',11 },
	{ 'c',12 },{ 'd',13 },{ 'e',14 },{ 'f',15 } };

	int num = ctoi[sz[0]] * 16 + ctoi[sz[1]];

	int min = INT_MAX, min_i = -1;
	for (int i = 0; i < 16; i++)
	{
		int num_i = i * 16 + i;
		if (abs(num - num_i) < min) {
			min = abs(num - num_i);
			min_i = i;
		}
	}
	return string(2, itoc[min_i]);
}

string similarRGB(string color) {

	string ret = "#";
	ret += _getRGB(color.substr(1, 2)) + _getRGB(color.substr(3, 2)) + _getRGB(color.substr(5, 2));
	return ret;
}

int main()
{
	string ret = similarRGB("#09f166");
	string ans = "#11ee66";
	assert(ret == ans);
	return 0;
}
