// A cryptarithm is a mathematical puzzle where the goal is to find the correspondence between letters and digits such that the given arithmetic equation consisting of letters holds true.

// Given a cryptarithm as an array of strings crypt, count the number of its valid solutions.

// The solution is valid if each letter represents a different digit, and the leading digit of any multi-digit number is not zero.
// crypt has the following structure: [word1, word2, word3], which stands for the word1 + word2 = word3 cryptarithm.

// Example

// For crypt = ["SEND", "MORE", "MONEY"], the output should be
// solution(crypt) = 1, because there is only one solution to this cryptarithm:
// O = 0, M = 1, Y = 2, E = 5, N = 6, D = 7, R = 8, and S = 9 (9567 + 1085 = 10652).
// For crypt = ["GREEN", "BLUE", "BLACK"], the output should be
// solution(crypt) = 12, because there are 12 possible valid solutions:
// 54889 + 6138 = 61027
// 18559 + 2075 = 20634
// 72449 + 8064 = 80513
// 48229 + 5372 = 53601
// 47119 + 5261 = 52380
// 36887 + 4028 = 40915
// 83447 + 9204 = 92651
// 74665 + 8236 = 82901
// 65884 + 7308 = 73192
// 57883 + 6408 = 64291
// 57881 + 6428 = 64309
// 83441 + 9264 = 92705
// For crypt = ["ONE", "TWO", "THREE"], the output should be solution(crypt) = 0, because there are no valid solutions.
// Input/Output

// [execution time limit] 0.5 seconds (cpp)

// [memory limit] 1 GB

// [input] array.string crypt

// Array of three non-empty strings containing only uppercase English letters.

// Guaranteed constraints:
// 1 ≤ crypt[i].length ≤ 35.

// [output] integer

// The number of valid solutions.

// [C++] Syntax Tips

// // Prints help message to the console
// // Returns a string
// string helloWorld(string name) {
//     cout << "This prints to the console when you Run Tests" << endl;
//     return "Hello, " + name;
// }

#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> crypt) {
    unordered_map<char, int> c2i;
    unordered_map<int, char> i2c;
    int ans = 0;
    int limit = crypt[2].length(); 
    for (auto& w : crypt)
        if (w.length() > limit) return 0; 
    for (auto& w : crypt)
        reverse(w.begin(), w.end()); 
    function<bool(int, int, int)> helper = [&](int digit, int widx, int sum) {
        if (digit == limit) {
            ans += (sum == 0);
            return sum == 0;
        }

        if (widx == 2) { 
            if (!c2i.count(crypt[2][digit]) && !i2c.count(sum % 10)) {
                if (sum % 10 == 0 && digit + 1 == limit) return false;
                c2i[crypt[2][digit]] = sum % 10;
                i2c[sum % 10] = crypt[2][digit];

                bool tmp = helper(digit + 1, 0, sum / 10);

                c2i.erase(crypt[2][digit]);
                i2c.erase(sum % 10);
                return tmp;
            } else if (c2i.count(crypt[2][digit]) && c2i[crypt[2][digit]] == sum % 10) {
                if (digit + 1 == limit && c2i[crypt[2][digit]] == 0) return false; 
                return helper(digit + 1, 0, sum / 10);
            } else {
                return false;
            }
        }

        if (digit >= crypt[widx].length()) {
            return helper(digit, widx + 1, sum);
        }

        if (c2i.count(crypt[widx][digit])) {
            if (digit + 1 == crypt[widx].length() && crypt[widx].length() > 1 && c2i[crypt[widx][digit]] == 0)
                return false; 
            return helper(digit, widx + 1, sum + c2i[crypt[widx][digit]]);
        }

        for (int i = 0; i < 10; i++) {
            if (digit + 1 == crypt[widx].length() && i == 0 && crypt[widx].length() > 1) continue; 
            if (i2c.count(i)) continue;

            c2i[crypt[widx][digit]] = i;
            i2c[i] = crypt[widx][digit];

            bool tmp = helper(digit, widx + 1, sum + i);

            c2i.erase(crypt[widx][digit]);
            i2c.erase(i);
        }

        return false;
    };

    helper(0, 0, 0);

    return ans;
}

int main() {
    vector<string> crypt = {"AABC", "DE", "FCCEE"}; 
    cout << solution(crypt) << "\n";
    return 0;
}
