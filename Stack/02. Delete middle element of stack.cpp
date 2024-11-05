#include <iostream>
#include <stack>

using namespace std;

void helper(stack<int> &s, int k)
{
  if (k == 0)
  {
    s.pop();
    return;
  }
  int temp = s.top();
  s.pop();
  helper(s, k - 1);
  s.push(temp);
}

void deleteMiddleElement(stack<int> &s)
{
  if (s.empty())
    return;
  helper(s, s.size() / 2);
}

void print(stack<int> st)
{
  /*
  Range based loop is not allowed
  for(auto x:st) cout<<x<<" ";
  */
  while (!st.empty())
  {
    std::cout << st.top() << " ";
    st.pop();
  }
  std::cout << std::endl;
}

int main()
{
  // stack<int>s{10,20,30,40,50}; Not allowed
  stack<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.push(50);

  cout << "Original stack: ";
  print(s1); // Prints: 50 40 30 20 10

  deleteMiddleElement(s1);

  cout << "After deleting middle element: ";
  print(s1); // Prints: 50 40 20 10

  // Test Case 2: Stack with even number of elements
  stack<int> s2;
  s2.push(10);
  s2.push(20);
  s2.push(30);
  s2.push(40);

  cout << "Original stack: ";
  print(s2); // Prints: 40 30 20 10

  deleteMiddleElement(s2);

  cout << "After deleting middle element: ";
  print(s2); // Prints: 40 30 10

  return 0;
}
