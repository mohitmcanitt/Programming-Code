 /* Leetcode 295 : https://leetcode.com/problems/find-median-from-data-stream/
    
    Time Complexity: O(n Log n). 
    Time Complexity to insert element in min heap is log n. So to insert n element is O( n log n).
    
    Auxiliary Space : O(n). 
    The Space required to store the elements in Heap is O(n)
    
    We will take two heap 
    first heap is max heap which store element left of median
    second heap is min heap which store element right of median
        
    Insertion:
    
    case 1: By default , if both is empty... put it inside first heap1
    case 2: if heap 2 is empty and num is greater than heap1 top ,push it into heap2
    case 3: if heap2 is empty and num is smaller than heap1 top,,push it into heap1
    
    Above three cases, only when heap is empty
    
    case 4: if num is greater than top element of heap2, insert into heap2
    case 5: if num is smaller than top element of heap2, insert into heap1
    
    if difference of sizes of heap1,heap2 is greater than 1 , shift one element to heap which is having lesser element
    
    
    Finding Median:
    
    case 1:if size of heap1 and heap2 is equal than , average of top of both heap
    case 2: else which having more number of elements
    */

class MedianFinder {
public:
    priority_queue<int>pq_max;
    priority_queue<int,vector<int>,greater<int>>pq_min;
    
    void addNum(int num) {
        if(pq_max.empty() and pq_min.empty())  // By default , if both is empty... put it inside first heap1
            pq_max.push(num);
        else if(pq_min.empty() and num>pq_max.top()) //if heap 2 is empty and num is greater than heap1 top ,push it into heap2
            pq_min.push(num);
         else if(pq_min.empty() and num<=pq_max.top())// if heap2 is empty and num is smaller than heap1 top,,push it into heap1
            pq_max.push(num);
        else if(num>pq_min.top()) // if num is greater than top element of heap2, insert into heap2
            pq_min.push(num);
        else if(num<=pq_min.top()) // if num is smaller than top element of heap2, insert into heap1
            pq_max.push(num);
        int diff=pq_min.size()>pq_max.size()?pq_min.size()-pq_max.size():pq_max.size()-pq_min.size(); 
        // if difference of sizes of heap1,heap2 is greater than 1 , shift one element 
        if(diff>1)
        {
            if(pq_max.size()>pq_min.size())
            {
                int num=pq_max.top();
                pq_max.pop();
                pq_min.push(num);
            }
            else
            {
                int num=pq_min.top();
                pq_min.pop();
                pq_max.push(num);
            }
         }
        
    }
        
    
    double findMedian() {
        if(pq_min.size()==pq_max.size())  // if size of heap1 and heap2 is equal than , average of top of both heap
            return (pq_min.top()+pq_max.top())/2.0;
        else
            return (pq_min.size()>pq_max.size()?pq_min.top():pq_max.top()); // else which having more number of elements
    }
};
