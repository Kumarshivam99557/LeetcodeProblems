class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        stack<pair<char,int>> q;

        for(int i=0;i<typed.size();i++){
            if(q.size()==0)
            q.push({typed[i],1});


           else if(q.top().first==typed[i]){
               int k=q.top().second;
               q.pop();
               k++;
               q.push({typed[i],k});

           }

           else{
               q.push({typed[i],1});
           }

        }
    stack<pair<char,int>> q1;

        for(int i=0;i<name.size();i++){
            if(q1.size()==0)
            q1.push({name[i],1});


           else if(q1.top().first==name[i]){
               int k=q1.top().second;
               q1.pop();
               k++;
               q1.push({name[i],k});

           }

           else{
               q1.push({name[i],1});
           }

        }
   
  if(q.size()!=q1.size()) return false;
  while(q.size()>0 && q1.size()>0){
            if(q.top().first==q1.top().first){
                       
                        if(q.top().second<q1.top().second){
                            return false;
                        }
            }
            else if(q.top().first!=q1.top().second){
                return false;
            }
        q.pop();
        q1.pop();

  }



   return true;


        
    }
};