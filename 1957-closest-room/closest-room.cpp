class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rm, vector<vector<int>>& q) 
    {
        for(int i=0;i<rm.size();i++)
            swap(rm[i][0],rm[i][1]);
        sort(rm.begin(),rm.end(),greater<vector<int>>());
        for(int i=0;i<q.size();i++)
            q[i].push_back(i),swap(q[i][0],q[i][1]);
        sort(q.begin(),q.end(),greater<vector<int>>());
        vector<int> ans(q.size());
        set<int> s;
        for(int i=0,j=0;j<q.size();j++)
        {
            while(i<rm.size() && rm[i][0]>=q[j][0])
                s.insert(rm[i][1]),i++;
            
            auto it=s.lower_bound(q[j][1]);
            auto tp=it;
            int d1=1e9,d2=1e9;
            if(it!=s.end()) d2=(*it)-q[j][1];
            if(it!=s.begin()) --it,d1=q[j][1]-(*it);
            
            if(d1==1e9 && d2==1e9) ans[q[j][2]]=-1;
            else if(d1<=d2) ans[q[j][2]]=(*it);
            else ans[q[j][2]]=(*tp);
        }
        return ans;
    }
};