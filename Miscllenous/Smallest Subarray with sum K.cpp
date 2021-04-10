/*
Window Technique:
step 1: Intialiaze variables like window_start=0 and window_end=0 , It is used to know the current length of window

int size=INT_MAX,win_Sum=0,win_End=0,win_Start=0,i=0;

step 2: create a window whose sum is just smaller or equal to target -- Not greater.

  while(win_Sum+arr[i]<=x)
        {
            win_Sum+=arr[i];
            win_End++;
            i++;
        }

step 3: Start adding remaining each element one by one 
  case 1: if(win_sum>target)
        delete element from front until window sum doesnt becomw equal or smaller to target
          if(win_Sum>x)
            {
                    while(win_Sum>x)
                    {
                        win_Sum-=arr[win_Start];
                        win_Start++;
                    }  
             }    
   case 2: if(win_sum==target)
        Update your ans
    increment window_end;    
      

Input :
  1,2,3,4,5  target 3;
  ans 1



*/


int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int size=INT_MAX,win_Sum=0,win_End=0,win_Start=0,i=0;
        
        while(win_Sum+arr[i]<=x)
        {
            win_Sum+=arr[i];
            win_End++;
            i++;
        }
        if(win_Sum==x)
            size=min(size,win_End-win_Start+1);
        for(int i=win_End;i<n;i++)
        {
            win_Sum+=arr[i];
            if(win_Sum>x)
            {
                    while(win_Sum>x)
                    {
                        win_Sum-=arr[win_Start];
                        win_Start++;
                    }  
             }    
            if(win_Sum==x)
                size=min(size,win_End-win_Start+1);  
            win_End++;    
         }
        return size;
    }
