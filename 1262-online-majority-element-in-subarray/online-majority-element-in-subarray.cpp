class MajorityChecker {
    unordered_map<int,vector<int>> mp ;
    vector<int> v ; 
    int trial = 30 ;
public:
    MajorityChecker(vector<int>& arr) {
        srand(time(NULL));
        trial = 20 ;
        int n = arr.size() ;
        v.clear();
        mp.clear() ;
        for(int i = 0 ; i< n ; ++i ){
            mp[arr[i]].push_back(i) ;
            v.push_back(arr[i]) ;
        }
    }
    
    int query(int left, int right, int threshold) {
        for(int i = 0 ; i< trial ; ++i ){
            
            int r_el = v[left + rand()% (right - left + 1 ) ] ;
            cout<<r_el<<" ";
            // auto it = mp[r_el].second ; 
            int cnt = upper_bound(mp[r_el].begin() , mp[r_el].end() , right) - upper_bound(mp[r_el].begin() , mp[r_el].end() , left -1 ) ;
            if( cnt >= threshold ) return r_el ;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
 