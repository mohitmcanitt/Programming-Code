//Method 1: 0(n2) 0(1)

     int majorityElement(int v[], int n)
    {
        
        // your code here
        int winner=v[0];
        int max_vote=1;
    
        for(int i=0;i<n-1;i++)
        {
            int count=1;
            for(int j=i+1;j<n;j++)
                if(v[j]==v[i])
                    count++;
            if(count>max_vote)  
            {
                winner=v[i];
                max_vote=max(max_vote,count);
            }      
       
          }
    
        return max_vote>(n/2)?winner:-1;
    }
 
// Method 2 : 0(nlogn) 0(1)


int majorityElement(int v[], int n)
    {
        
        // your code here
        int winner=v[0];
        int max_vote=1;
        sort(v,v+n);
        int count=1;
        for(int i=1;i<n;i++)
        {
           if(v[i]==winner)
                count++;
            else
            {
                winner=v[i];
                max_vote=max(max_vote,count);
                count=1;
            }
       
         }
        max_vote=max(max_vote,count);
        return max_vote>(n/2)?winner:-1;
    }
  
// Method 3: o(n) and 0(1)
   int majorityElement(int v[], int n)
    {
        unordered_map<int,int>um;
        for(int i=0;i<n;i++)
           um[v[i]]++;
            
        int winner=-1;
        for(auto x:um)
        {
            if(x.second>n/2)
                winner=x.first;
        }
        return winner;
    }

 // Method 4: 0(n) and 0(1)
    
   int majorityElement(int a[], int size)
    {
        
        // your code here
        int winner=a[0];
        int vote=1;
        for(int i=1;i<size;i++)
        {
            if(winner==a[i])
                vote++;
            else 
                vote--;
            if(vote==0)
            {
                winner=a[i];
                vote++;
            }
        }
        int frequency=0;
        for(int i=0;i<size;i++)
            if(a[i]==winner)
                frequency++;
        return frequency>(size/2)?winner:-1;
        
    }
  
