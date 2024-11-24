// Your task is to find the sum of two fractions, expressed in the form X/Y and U/V, where X, Y, U, and V are four integers. Compute their sum and reduce it to its lowest indivisible state: A/B.

// For example:

// 2/6+2/6 equals 4/6, which should be reduced to 2/3.
// 7/10+13/10 equals 20/10 which should be reduced to 2/1.
// You are given an array of strings, which contains several expressions in the form "X/Y+U/V". Return a string array, where the ith element is the result for the ith expression in the form "A/B".

// Example

// For fractions = ["2/6+2/6", "7/10+13/10"], the output should be
// solution(fractions) = ["2/3", "2/1"].

// Input/Output

// [execution time limit] 0.5 seconds (cpp)

// [memory limit] 1 GB

// [input] array.string fractions

// An array of strings, where each string contains an expression that represents the sum of two fractions, given in the form "X/Y+U/V".

// Guaranteed constraints:
// 1 ≤ fractions.length ≤ 500,
// fractions[i] has the form "X/Y+U/V" where X, Y, U, V are integers,
//  1 ≤ X, Y, U, V ≤ 2000.

// [output] array.string

// An array of strings, where the ith element is the result for the ith expression in the form "A/B".

// [C++] Syntax Tips

// // Prints help message to the console
// // Returns a string
// string helloWorld(string name) {
//     cout << "This prints to the console when you Run Tests" << endl;
//     return "Hello, " + name;
// }


pair<int, int> getF(const string& fraction) {
   size_t pos = fraction.find('/');
   int num = stoi(fraction.substr(0, pos));
   int den = stoi(fraction.substr(pos + 1));
   return {num, den};
}
pair<int, int> simplify(int num, int den) {
   int g = abs(std::gcd(num, den));
   return {num / g, den / g}; 
}
vector<string> solution(vector<string> fractions) {
   vector<string> result;
   for(const string& exp : fractions) {
       size_t pos = exp.find('+');
       string f1 = exp.substr(0, pos);
       string f2 = exp.substr(pos + 1);
       auto [n1, d1] = getF(f1);
       auto [n2, d2] = getF(f2);
       int lcm = std::lcm(d1, d2);
       int m1 = lcm / d1;
       int m2 = lcm / d2;
       int resN = n1 * m1 + n2 * m2;
       int desD = lcm;
       auto [finalNum, finalDen] = simplify(resN, desD);
       result.push_back(to_string(finalNum) + "/" + to_string(finalDen));
   }
   return result;
}