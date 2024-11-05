/*
Input  : 4, 15, 2, 14, 12,8
Output : -1 -1 15 15 14 12 
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterToLeft(const vector<int>& arr) {
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Pop elements from the stack until we find a greater element or the stack is empty
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element to the left
        if (st.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(st.top());
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    
    vector<int> result = nextGreaterToLeft(arr);
    
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
