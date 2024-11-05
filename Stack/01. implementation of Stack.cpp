#include <iostream>

template <typename T>
class Stack
{
  int size_;
  T *arr_;
  int top_;

public:
  // Constructor
  Stack(int size) : size_(size), arr_(new T[size]), top_(-1) {}

  // Destructor to prevent memory leaks
  ~Stack()
  {
    delete[] arr_;
  }

  bool push(T ele)
  {
    if (isFull())
    {
      std::cout << "Overflow" << std::endl;
      return false;
    }
    arr_[++top_] = ele;
    return true;
  }

  void pop()
  {
    if (isEmpty())
    {
      std::cout << "Underflow" << std::endl;
    }
    else
    {
      top_--;
    }
  }

  void top_element() const
  {
    if (isEmpty())
      std::cout << "Underflow" << std::endl;
    else
      std::cout << "Top element is " << arr_[top_] << std::endl;
  }

  bool isEmpty() const
  {
    return top_ == -1;
  }

  bool isFull() const
  {
    return top_ == size_ - 1;
  }

  void print() const
  {
    for (int i = top_; i >= 0; i--)
    {
      std::cout << arr_[i] << " ";
    }
    std::cout << std::endl;
  }
};

int main()
{
  Stack<int> st1(5);
  st1.push(34);
  st1.push(30);
  st1.push(20);
  st1.push(15);
  st1.push(10);
  st1.push(5); // This should print "Overflow"
  st1.print();
  return 0;
}
