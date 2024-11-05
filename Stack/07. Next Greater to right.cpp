/*
Input  : 4, 15, 2, 14, 12,8
Output : 15 -1 14 -1 -1 -1 
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterToLeft(const vector<int>& arr) {
    stack<int> st;
    vector<int> result(arr.size());

    for (int i = arr.size()-1; i >=0 ; i--) {
        // Pop elements from the stack until we find a greater element or the stack is empty
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element to the left
        if (st.empty()) {
            result[i]=-1;
        } else {
            result[i]=st.top();
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 15, 2, 14, 12,8};
    
    vector<int> result = nextGreaterToRight(arr);
    
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
