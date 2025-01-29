class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* temp1=head;
        Node* previous=NULL;
        while(temp1!=NULL){
            for(int i=0; i<m; i++){
                if(!temp1) return head;
                previous = temp1;
                temp1 = temp1->next;
                }
            if(!temp1) return head;
            
            for(int i=0; i<n && temp1; i++){
                Node* temp = NULL;
                
                temp = temp1;
                temp1 = temp1->next;
                temp->next=NULL;
                delete temp;
                
            }
        
            previous->next=temp1;
        }
       
        
        return head;
    }
};