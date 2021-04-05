/*

replace inbuilt function
str.replace(start_index,no_of_chars,new_word);

Input:
My name is Mohit Kumar
My name is Rohit Kumar
*/



#include <iostream>
using namespace std;
int main() {
    // Replace Mohit with Rohit
    string sentence="My name is Mohit Kumar";
    string old="Mohitt";
    string neww="Rohit";

    // First check if old word exists or not

    int idx=sentence.find(old);

    if(idx<sentence.length())
        sentence.replace(idx,old.length(),neww);
        
    cout<<sentence<<endl;

    
    
}
