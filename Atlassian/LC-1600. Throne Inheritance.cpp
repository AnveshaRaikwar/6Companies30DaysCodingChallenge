class ThroneInheritance {
public:

    map<string,list<string>> mp;
    string root;
    set<string> st;

    ThroneInheritance(string kingName) {
        root = kingName;

    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);

    }
    
    void death(string name) {
        st.insert(name);
    }
    
    void dfs(string root, vector<string>& ans){
        
        
        if(st.find(root) == st.end()){
            ans.push_back(root);
        }
        for(auto child:mp[root]){
            dfs(child,ans);
        }
        
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(root,ans);
        return ans;
    }
};
