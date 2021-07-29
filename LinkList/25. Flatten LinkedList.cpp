// watch this video : https://www.youtube.com/watch?v=ysytSSXpAI0
Node *merge(Node *l1,Node *l2)
{
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    
    if(l1->data>l2->data)
        swap(l1,l2);
    Node *res=l1;
    while(l1 and l2)
    {
        Node *temp=NULL;
        while(l1 and l1->data<=l2->data)
        {
            temp=l1;
            l1=l1->bottom;
        }
        temp->bottom=l2;
        swap(l1,l2);
    }
    return res;
        
}
    
Node *flatten(Node *root)
{
   // Your code here
   if(root->next==NULL)
    return root;
    
    Node *second=flatten(root->next); // recur for list on right 
    Node *new_list=merge(root,second); // now merge last two linklist
    new_list->next=NULL;  // newly created linklist->next will be point to NULL
    return new_list;    
}
