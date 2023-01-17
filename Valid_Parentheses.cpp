20. Valid Parentheses
Easy
17.6K
965
Companies
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


//Time - O(n)
//Space - O(n)
class Solution {
    public boolean isValid(String s) {
            Stack<Character> stk = new Stack<>();
            for(int i=0;i<s.length();i++){
                if(!stk.isEmpty() && (s.charAt(i) == ')' || s.charAt(i) == '}' || s.charAt(i) == ']') ){
                    Character temp = stk.peek();
                    if(temp == '(' && s.charAt(i) == ')') stk.pop();
                    else if(stk.peek() == '[' && s.charAt(i) == ']') stk.pop();
                    else if (stk.peek()== '{' && s.charAt(i) == '}') stk.pop();
                    else stk.push(s.charAt(i));
                }
                else stk.push(s.charAt(i));
            }
            return stk.isEmpty();
    }
}
