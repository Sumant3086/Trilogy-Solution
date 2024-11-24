// You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.

// Example

// For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
// solution(a, b) = [9876, 5434, 0].

// Explanation: 987654321999 + 18001 = 987654340000.

// For a = [123, 4, 5] and b = [100, 100, 100], the output should be
// solution(a, b) = [223, 104, 105].

// Explanation: 12300040005 + 10001000100 = 22301040105.

// Input/Output

// [execution time limit] 0.5 seconds (cpp)

// [memory limit] 1 GB

// [input] linkedlist.integer a

// The first number, without its leading zeros.

// Guaranteed constraints:
// 0 ≤ a size ≤ 104,
// 0 ≤ element value ≤ 9999.

// [input] linkedlist.integer b

// The second number, without its leading zeros.

// Guaranteed constraints:
// 0 ≤ b size ≤ 104,
// 0 ≤ element value ≤ 9999.

// [output] linkedlist.integer

// The result of adding a and b together, returned without leading zeros in the same format.

// [C++] Syntax Tips

// // Prints help message to the console
// // Returns a string
// string helloWorld(string name) {
//     cout << "This prints to the console when you Run Tests" << endl;
//     return "Hello, " + name;
// }

// 1234567891011121314151617181920212223242526272829
// // Singly-linked lists are already defined with this interface:
// // template<typename T>
// // struct ListNode {
// //   ListNode(const T &v) : value(v), next(nullptr) {}
// //   T value;
// //   ListNode *next;
// // };
// //
// ListNode<int> * solution(ListNode<int> * a, ListNode<int> * b) {
//    stack<int> firstN, secondN;

// Tests
// Custom Tests


// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * a, ListNode<int> * b) {
   stack<int> firstN, secondN;
   for (ListNode<int>* curr = a; curr; curr = curr->next) {
       firstN.push(curr->value);
   }   
   for (ListNode<int>* curr = b; curr; curr = curr->next) {
       secondN.push(curr->value);
   }
   ListNode<int>* res = nullptr;
   int plus = 0;
   while (!firstN.empty() || !secondN.empty() || plus) {
       int val1 = !firstN.empty() ? firstN.top() : 0;
       int val2 = !secondN.empty() ? secondN.top() : 0;
       if (!firstN.empty()) firstN.pop();
       if (!secondN.empty()) secondN.pop();
       int currSum = val1 + val2 + plus;
       plus = currSum / 10000;
       ListNode<int>* newNode = new ListNode<int>(currSum % 10000);
       newNode->next = res;
       res = newNode;
   }  
   return res;
}