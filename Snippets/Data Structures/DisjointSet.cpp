class DisjointSet{
    public:
        int subsets;
        vector<int> parent;
        DisjointSet(int n){
            for (int i=0; i<n; i++)
            {
                parent.push_back(-1);
            }
            subsets = n;
        }
        
        int Find(int a){        //finds the representative of a's set
            if (parent[a] == -1){
                return a;
            }
            
            else{
                int result = Find(parent[a]);
                parent[a] = result;
                return result;
            }
        }
        
        void JoinSet(int a, int b){     //joins the set of a to set of b
            int a_rep = Find(a);
            int b_rep = Find(b);
            parent[a_rep] = b_rep;
            subsets --;
        }
        
        bool IsSameSet(int a, int b){
            if(Find(a) == Find(b))
            return true;
            else return false;
        }
};