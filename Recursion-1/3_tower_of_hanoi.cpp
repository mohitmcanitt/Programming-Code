/*
You are given three rods and n disks of different sizes, which can slide onto any rod. 
The disks are initially stacked on the first rod, in increasing size from top to bottom (smallest on top).

🔁 Goal:
Move all the disks from the first rod to the third rod, following these rules:

📏 Rules:
Only one disk can be moved at a time.
You can only move the top disk from one rod to another.
No larger disk may be placed on top of a smaller disk.

https://youtu.be/QDBrZFROuA0?si=aWi5RZtFXE8YKA67

  */

#include <iostream>
using namespace std;

void toh(int n,string src,string dest,string helper){
    if(n==0) return;
    toh(n-1,src,helper,dest);
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
    toh(n-1,helper,dest,src);  
}

int main() {
    toh(3,"A","B","C");
}
