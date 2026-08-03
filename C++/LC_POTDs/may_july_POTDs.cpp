#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


class Solution22 {
  int MOD = 1e9 + 7;
  int LOG ;
  vector<vector<int>> ancestorTable;
  vector<int> depthTable;

 private:
  void buildAncestorTable(vector<vector<int>>& adj,int n) {
    // fill ancestor[v][0] and depth via BFS, then powers in a second pass
    vector<int> order;                    // BFS order, parents before children
    order.reserve(n);
    queue<int> q; q.push(1);
    ancestorTable[1][0] = -1; depthTable[1] = 0;
    vector<bool> seen(n + 1, false); seen[1] = true;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop(); 
        order.push_back(u);
        for (int c : adj[u]) if (!seen[c]) {
            seen[c] = true;
            ancestorTable[c][0] = u;
            depthTable[c] = depthTable[u] + 1;
            q.push(c);
        }
    }
    for (int j = 1; j < LOG; j++)
        for (int u : order)
            ancestorTable[u][j] = (ancestorTable[u][j-1] == -1) ? -1
                                : ancestorTable[ancestorTable[u][j-1]][j-1];
  }

  int getLCA(int u, int v) {
    if (depthTable[u] < depthTable[v]) swap(u, v);

    int diff = depthTable[u] - depthTable[v];

    for (int i = 0; i < LOG; i++)
      if (diff & (1 << i)&&ancestorTable[u][i]!=-1) {
        u = ancestorTable[u][i];
      }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
      if (ancestorTable[u][i] != ancestorTable[v][i] && ancestorTable[u][i]!=-1 && ancestorTable[v][i]!=-1) {
        u = ancestorTable[u][i];
        v = ancestorTable[v][i];
      }
    }
    return ancestorTable[u][0];
  }

  int distanceBetweenNodes(int u, int v) {
    int lca = getLCA(u, v);

    int distance = depthTable[v] + depthTable[u] - 2 * depthTable[lca];
    return distance;
  }

  int binaryModularExponentiation(int n, int exp) {
    if(exp<0)
        return 0;
    long result = 1;
    while (exp>0) {
      if (exp & 1) result = (result * n) % MOD;
      n =  (1L *n * n) % MOD;
      exp >>= 1;
    }
    return (int)result;
  }

 public:
  vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int n = edges.size() + 1;
    LOG = max(1, (int)ceil(log2(n)) + 1);
    ancestorTable.assign(n+1, vector<int>(LOG));
    depthTable.assign(n+1, 0);
    vector<vector<int>> adj(n + 1);
    
     for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

    buildAncestorTable(adj, n);
    vector<int> result;
    
    vector<int> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) pow2[i] = (1LL * pow2[i-1] * 2) %MOD ;

    
    for (auto& query : queries) {
      int distance = distanceBetweenNodes(query[0], query[1]);
      result.push_back((distance >= 1) ? pow2[distance - 1] : 0);
    }
    return result;
  }
};

class TreeAncestor {
    vector<vector<int>>ancestorTable;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestorTable.assign(n,vector<int>(20,-1));
        for(int i=0;i<n;i++)
            ancestorTable[i][0]=parent[i];
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(ancestorTable[i][j-1]!=-1)
                    ancestorTable[i][j]=ancestorTable[ancestorTable[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){
            if(k&(1<<i))
                node=ancestorTable[node][i];
            if(node==-1)
                return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */





struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solutionsd {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head, *fast=head;
        stack<ListNode*>st;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        int result=INT_MIN;
        while(fast){
            result=max(result,st.top()->val+fast->val);
            fast=fast->next;
        }
        return result;
    }
};

typedef long long ll ;
class Solutiosn {
public:
    char processStr(string s, long long k) {
        ll len=0;
        for(char &c:s){
            if(c=='*')
                len=len>0?len-1:len;
            else if(c=='#')
                len*=2;
            else if(c!='%')
                len++;
        }
        if(k>=len)
            return '.';
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='*')
                len++;
            else if (s[i]=='#'){
                len=len/2;
                k=k>=len?k-len:k;
            }else if(s[i]=='%')
                k=len-k-1;
            else 
                len--;
            if(k==len)
                return s[i];
        }
        return s[0];
    }
};

class Solutionsds {
public:
    double angleClock(int hour, int minutes) {
        int totalMinutes=hour*60+minutes;
        float hourAngle=(360.00*totalMinutes)/720.00;
        float minuteAngle=(360.00*minutes)/60.00;
        
        float angleDiff=abs(hourAngle-minuteAngle);
        return min(angleDiff,360.00f-angleDiff);
    }
};

class Solutiodawn {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(begin(restrictions),end(restrictions));

        for(int i=1;i<restrictions.size();i++){
            int prevPos=restrictions[i-1][0],prevHeight=restrictions[i-1][1];
            int currPos=restrictions[i][0],currHeight=restrictions[i][1];
            restrictions[i][1]=min(currHeight,prevHeight+(currPos-prevPos));
        }
        
        for(int i=restrictions.size()-2;i>=0;i--){
            int nextPos=restrictions[i+1][0],nextHeight=restrictions[i+1][1];
            int currPos=restrictions[i][0];
            restrictions[i][1]=min(restrictions[i][1],nextHeight+(nextPos-currPos));
        }
        
        int res=0;
        int prevHeight=0,prevPos=0;
        
        
        for(vector<int>&restriction:restrictions){
            int currPos=restriction[0],restrictedHeight=restriction[1];
        
            int steps=currPos-prevPos;
            
            int peakH=(steps+prevHeight+restrictedHeight)/2;
            
            res=max(res,peakH);
            
            prevPos=currPos;
            prevHeight=restrictedHeight;
            
        }
        res=max(res,n-prevPos+prevHeight);
        
        return res;
    }
};



class Solutionda {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int ans=1,prev=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-prev<=0){
                ans=arr[i];
                prev=arr[i];
            }else{
                ans=prev+1;
                prev++;
            }
        }
        return ans;
    }
};


class Solutiondas {
    bool isABC(char c){
        return c=='a'||c=='b'||c=='c';
    }
public:
    int numberOfSubstrings(string s) {
        int map[26]={0};
        int res=0;
        for(int i=0,j=0;i<s.size();i++){
            map[s[i]-'a']++;
            while(j<=i){
                if(isABC(s[j])&&map[s[j]-'a']>1){
                    map[s[j]-'a']--;
                }
                j++;
            }
            if(map[0]&&map[1]&&map[2]){
                res+=j+1;
            }
        }
        return res;
    }
};



class LRUCache {
    struct Node{  
        int val;
        int key;
        Node *next;
        Node *prev;
        
        Node(int k,int value,Node*nxt,Node*pre){
            key=k;
            val=value;
            next=nxt;
            prev=pre;
        }
    };
    
    // Map Key->*Node
    unordered_map<int,Node*>map;
    Node *start, *end;
    int slotsLeft;
    
    // Insert in DLL start
    Node* insertNodeAtStart(int key,int val){
        Node *temp=start->next;
        Node* newNode=new Node(key,val,temp,start);
        start->next=newNode;
        temp->prev=newNode;
        return newNode;
    }
        
    
    // Delete a Node
    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        delete node;
    }
    
    void markNodeAsLRU(Node* node){
        // Remove connection from prev location
        node->prev->next=node->next;
        node->next->prev=node->prev;
        
        // Add node in new location
        Node *temp=start->next;
        start->next=node;
        temp->prev=node;
        
        node->next=temp;
        node->prev=start;
    }
    
    
public:
    LRUCache(int capacity) {
        start=new Node(-1,-1,NULL,NULL);
        end=new Node(-1,-1,NULL,end);
        start->next=end;
        slotsLeft=capacity; 
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }
        Node *node=map[key];
        markNodeAsLRU(node);
        return node->val;
    }
    
    /*
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    */
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            Node *node=map[key];
            node->val=value;
            markNodeAsLRU(node);
            return;
        }else if(slotsLeft==0){
            map.erase(end->prev->key);
            deleteNode(end->prev);
            slotsLeft++;
        }
        slotsLeft--;
        map[key]=insertNodeAtStart(key, value);   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



class Solutioasn {
    int cords[5]={0,1,0,-1,0};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<tuple<int,int,int>>pq;
        vector<vector<int>>remainingHealth(n,vector<int>(m,INT_MAX));   
        
        remainingHealth[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        
        while(!pq.empty()){
            
            auto [h,i,j]=pq.top();
            pq.pop();
            
            if(i==n-1&&j==m-1)
                return true;
                
            for(int k=0;k<4;k++){
                int x=i+cords[k], y=j+cords[k+1];
                if(x>=0&&x<n&&y>=0&&y<m&&h-grid[x][y]>=0&&h-grid[x][y]>remainingHealth[x][y]){
                    remainingHealth[x][y]=h-grid[x][y];
                    pq.push({h-grid[x][y],x,y});
                }
            }
            
        }
        return false;
    }
};



class Solutiosadn {
    
    bool isValid(vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k, int maxAllowed){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        int n=online.size();
        vector<long long>minCost(n,LLONG_MAX);
        pq.push({0,0});
        while(!pq.empty()){
            auto [totalCost,u]=pq.top();
            pq.pop();
            if(u==n-1){
                return true;
            }
            if (totalCost >= minCost[u]) continue;
            minCost[u] = totalCost;
            for(auto &[v,c]:adj[u]){
                // int nextMin=min(c,minEdgeScore);
                if(c>=maxAllowed&&online[v]&&c+totalCost<=k){
                    pq.push({totalCost+c,v});
                }
            }
        }
        return false;
    }
    
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
       int n=online.size(),low=INT_MAX,high=INT_MIN;
        vector<vector<pair<int, int>>>adj(n,vector<pair<int, int>>());
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            low=min(low,edge[2]);
            high=max(high,edge[2]);
        }
        
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(isValid(adj, online, k, mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};


class Solutiondsd {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>());
        for(auto edge:roads){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<bool>visited(n+1,0);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        int res=INT_MAX;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &[v,d]:adj[u]){
                if(!visited[v]){
                    res=min(res,d);
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        return res;
    }
};






class Solutiadson {
    int MOD=1e9+7;
    pair<int,int>getVal(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first)
            return {a.first,(1L*a.second+b.second)%MOD};
        else if(a.first>b.first)
            return a;
        else return b;
    }
    
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        pair<int,int> dp[202][202];
        memset(dp, -1, sizeof dp);
        dp[0][0]={0,1};
        int n=board.size(), m=board[0].size();
        
        for(int i=1;i<m;i++){
            if(board[i][0]=='X')
                break;
            dp[i][0].first=dp[i-1][0].first+(board[i][0]-'0');
            dp[i][0].second=1;    
        }
        
        for(int j=1;j<n;j++){
            
            if(board[0][j]=='X')
                break;
            dp[0][j].first=dp[0][j-1].first+(board[0][j]-'0');
            dp[0][j].second=1;
        }
            
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(board[i][j]=='X')
                    continue;
                pair<int,int>temp=dp[i][j];
                // Up
                temp=getVal(temp, dp[i-1][j]);
                // Left
                temp=getVal(temp, dp[i][j-1]);
                // up-left
                temp=getVal(temp, dp[i-1][j-1]);
                if(i!=n-1||j!=m-1)
                    temp.first+=board[i][j]-'0';   
                // cout<<temp.first<<" "<<temp.second<<" ";
                dp[i][j]=temp;
            }
            // cout<<endl;
        }
        if(dp[n-1][m-1].second<0)
            return {0,0};
        return {dp[n-1][m-1].first,dp[n-1][m-1].second};
    }
};



/**

return a[1]>b[1]||a[0]<b[0];
return a[0]<b[0]||a[1]>b[1];
return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];


*/


class Soludastion {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a, const vector<int>&b){
            return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        });
        int prevInterval=0;
        for(int i=1;i<intervals.size();i++){
            int a=intervals[prevInterval][0],b=intervals[prevInterval][1],c=intervals[i][0],d=intervals[i][1];
            if(a<=c&&d<=b)
                n--;
            else
                prevInterval=i;
        }
        return n;
    }
};


class Solutidasdon {
 int MOD=1e9+7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>prefixNums(n+1,0),count(n+1,0),pow10(n+1,1),nonZeroDigits(n+1,0);
        for(int i=0;i<n;i++){
            int c=s[i]-'0';
            if(c==0){
                pow10[i+1]=pow10[i];
                prefixNums[i+1]=prefixNums[i];
                count[i+1]=count[i];
                nonZeroDigits[i+1]=nonZeroDigits[i];
            }else{
                prefixNums[i+1]=(1L*prefixNums[i]*10+c)%MOD;
                count[i+1]=(1L*count[i]+c)%MOD;
                pow10[i+1]=(1L*pow10[i]*10)%MOD;
                nonZeroDigits[i+1]=nonZeroDigits[i]+1;
            }
        }
        vector<int>res;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            int activeDigits=nonZeroDigits[r+1]-nonZeroDigits[l];
            int fullVal=prefixNums[r+1];
            cout<<activeDigits<<" ";
            int leftOffset=(1LL*prefixNums[l]*pow10[activeDigits])%MOD;
            
            int sum=(fullVal-leftOffset+MOD)%MOD;
            int cnt=(1LL*count[r+1]-count[l]+MOD)%MOD;
            res.push_back((1LL*sum*cnt)%MOD);
        }
        return res;
    }
};



class Solutiodsadn {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int, int>parent;
        int i=0;
        while(i<nums.size()){
            int p=i;
            parent[p]=p;
            while(i<nums.size()-1&&nums[i+1]-nums[i]<=maxDiff){
                parent[i+1]=p;
                i++;
            }
            i++;
        }
        vector<bool>res;
        for(auto &q:queries){
            int pA=parent[q[0]], pB=parent[q[1]];
            res.push_back(pA==pB);
        }
        return res;
    }
};


class Solutidwqon {
    int customUpperBound(vector<pair<int,int>>&arr,int target){
        int n=arr.size();
        int l=0,r=n-1,result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid].first<=target){
                result=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return result;
    }
public:
    int rows;
    int cols;
    vector<vector<int>>ancestorTable;
    

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr(n);
        for(int i=0;i<nums.size();i++)
            arr[i]={nums[i],i};
        sort(arr.begin(),arr.end());
        vector<int>nodeToIndex(n);
        for(int i=0;i<n;i++){
            int node=arr[i].second;
            nodeToIndex[node]=i;
        }
        
        rows=n;
        cols=log2(n)+1;
        ancestorTable.resize(rows,vector<int>(cols,0));
        
        for(int node=0;node<n;node++){
            int farthestIdxOnJump=customUpperBound(arr,arr[node].first+maxDiff);
            ancestorTable[node][0]=farthestIdxOnJump;
        }
        
        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
            }
        }
        
        vector<int>res(queries.size());
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            
            int a=nodeToIndex[u];
            int b=nodeToIndex[v];
            if(a==b){
                res[i]=0; 
                continue;
            }
            
            if(a>b)
                swap(a,b);

            int curr=a,jumps=0;
            
            for(int j=cols-1;j>=0;j--){
                if(ancestorTable[curr][j]<b){
                    curr=ancestorTable[curr][j];
                    jumps+=(1<<j);
                }
            }
            
            if(ancestorTable[curr][0]>=b)
                res[i]=jumps+1;
            else
                res[i]=-1;   
        }
        return res;
    }
};

class Solutisadon {
    
    bool isCompleteComponent(vector<vector<int>>&adj,int node,vector<bool>&visited){
        
        queue<pair<int,int>>q;
        q.push({node,0});
        visited[node]=true;
        // vector<int>nodes;
        int maxEdgeLen=INT_MIN,minEdgeLen=INT_MAX,nodeCount=0;
        // nodes.push_back(node);
        while(!q.empty()){
            auto [u,d]=q.front();
            maxEdgeLen=max(maxEdgeLen,(int)adj[u].size());
            minEdgeLen=min(minEdgeLen,(int)adj[u].size());
            q.pop();
            for(int v:adj[u]){
                if(!visited[v]){
                    // nodes.push_back(v);
                    nodeCount++;
                    visited[v]=true;
                    q.push({v,d+1});
                }
            }
        }
        // for(int nd:nodes){
        //     if(adj[nd].size()!=nodes.size()-1)
        //         return 0;
        // }
        // return true;
        
        
        // method 2
        return maxEdgeLen==minEdgeLen&&maxEdgeLen==nodeCount-1;
        
        
    }
    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n,vector<int>());
        
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool>visited(n,false);
        int res=0;
        for(int i=0;i<n;i++){
            if(!visited[i]&&isCompleteComponent(adj, i, visited))
                res++;
        }
        return res;
    }
};


class Solutiodsan {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res;
        vector<int>copyArr=arr;
        sort(copyArr.begin(),copyArr.end());
        unordered_map<int, int>ranks;
        int x=1;
        for(int i:copyArr)
            if(ranks.find(i)==ranks.end())
                ranks[i]=x++;

        for(int i:arr){
            res.push_back(ranks[i]);
        }
        return res;
    }
};

class Solutiodswn {
    int dp[201][201][201]={};
    int MOD=1e9+7;
    int precious(int idx,int gcd1,int gcd2,vector<int>&nums){
        if(idx==nums.size())
            return gcd1!=0&&gcd1==gcd2;
        if(dp[idx][gcd1][gcd2]!=-1)
            return dp[idx][gcd1][gcd2];
        long res=0;
        
        res=(res+precious(idx+1, gcd1, gcd2, nums)
            +precious(idx+1, gcd(gcd1,nums[idx]), gcd2, nums)
            +precious(idx+1, gcd1, gcd(gcd2, nums[idx]), nums))%MOD;
        
        return dp[idx][gcd1][gcd2]=res;        
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return precious(0, 0, 0, nums);
    }
};

class Solutidsason {
    int gcd(int a,int b){
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum=(n*(2+(n-1)*2))/2;
        int evenSum=(n*(4+(n-1)*2))/2;
        if(oddSum<evenSum)
            swap(oddSum,evenSum);
        return gcd(evenSum,oddSum);
    }
}; 


class Solutdasdion {
    int gcd(int a,int b){
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGcds;
        int mx=-1;
        for(int x:nums){
            mx=max(mx,x);
            prefixGcds.push_back(gcd(mx, x));
        }
        sort(prefixGcds.begin(),prefixGcds.end());
        
        long long res=0;
        for(int i=0;i<nums.size()/2;i++){
            res+=gcd(prefixGcds[i], prefixGcds[nums.size()-i-1]);
        }
        return res;
    }
};

class Solsaution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(begin(nums), end(nums));
        // TC: O(N)

        vector<int> factorFreq(maxVal + 1, 0);
        // TC: O(maxVal)

        // TC: O(N * sqrt(maxVal))
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    factorFreq[j]++;
                    if (num / j != j)
                        factorFreq[num / j]++;
                }
            }
        }

        vector<long long> pairsWithGCD(maxVal + 1, 0);
        // TC: O(maxVal)

        // TC: O(maxVal * log(maxVal))  — harmonic series: maxVal/1 + maxVal/2 + ... ≈ maxVal * ln(maxVal)
        for (int f = maxVal; f >= 0; f--) {
            long long count = factorFreq[f];
            pairsWithGCD[f] = count * (count - 1) / 2;

            for (int mult = 2 * f; mult <= maxVal; mult += f) {
                pairsWithGCD[f] -= pairsWithGCD[mult];
            }
        }

        // TC: O(maxVal)
        vector<long long> prefixCountGCD(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) {
            prefixCountGCD[i] = prefixCountGCD[i - 1] + pairsWithGCD[i];
        }

        // TC: O(Q * log(maxVal))
        vector<int> result;
        for (long long q : queries) {
            int l = 1, r = maxVal;
            int temp = 1;
            while (l <= r) {
                int mid_gcd = l + (r - l) / 2;
                if (prefixCountGCD[mid_gcd] > q) {
                    temp = mid_gcd;
                    r = mid_gcd - 1;
                } else {
                    l = mid_gcd + 1;
                }
            }
            result.push_back(temp);
        }
        return result;
        // TC: O(Q * log(maxVal))
    }
};

class Solutiasdon {
    int gcd(int a,int b){
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
public:
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN,mini=INT_MAX;
        for(int x:nums){
            maxi=max(maxi,x);
            mini=min(mini,x);
        }
        return gcd(mini,maxi);
    }
};

class Solutiodsaawn {
public:
    string smallestSubsequence(string s) {
        int freq[26]={0};
        bool added[26]={0};
        for(char c:s)
            freq[c-'a']++;
        stack<int>st;
        for(char c:s){
            freq[c-'a']--;
            if(added[c-'a'])
                continue;
            while(!st.empty()&&st.top()>c&&freq[st.top()-'a']>0){
                added[st.top()-'a']=false;
                st.pop();
            }
            added[c-'a']=true;
            st.push(c);
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};




class Sodslution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int x=m*n;
        k=(k%x);
        vector<vector<int>>res(m,vector<int>(n));
        for(int i=0;i<x;i++){
            int ii=((i-k+x)%x)/n,jj=((i-k+x)%x)%n;
            res[i/n][i%n]=grid[ii][jj];
        }
        return res;
    }
};

class Soladsasdution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int,int>>occurences;
        char prev=s[0];
        int cnt=0;
        for(char c:s){
            if(c==prev){
                cnt++;
            }else{
                occurences.push_back({cnt,prev-'0'});
                prev=c;
                cnt=1;
            }
        }
        occurences.push_back({cnt,prev-'0'});
        int res=0;
        int maxZeroes=0;
        for(int i=0;i<occurences.size();i++){
            if(occurences[i].second==0)
                continue;
            res+=occurences[i].first;
            if(i>1||i<occurences.size()-1)
                maxZeroes=max(occurences[i-1].first,occurences[i+1].first);
        }
        return res+maxZeroes;
    }
};




class Solutsdadion {
    void buildSegmenttree(int i,int l,int r,int segementTree[],int arr[]){
        if(l==r){
            segementTree[i]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildSegmenttree(i*2+1, l, mid, segementTree, arr);
        buildSegmenttree(i*2+2, l, mid, segementTree, arr);
        segementTree[i]=max(segementTree[i*2+1],segementTree[i*2+2]);
    }
    
    int* constructST(int n,int arr[]){
        int* segementTree=new int[4*n];
        buildSegmenttree(0, 0, n-1, segementTree, arr);
        return segementTree;
    }
    
    int queryInST(int start,int end,int i,int l,int r,int segmentTree[]){
        if(l>end||r<start){
            return INT_MIN;
        }
        if(l>=start&&r<=end){
            return segmentTree[i];
        }
        
        int mid=l+(r-l)/2;
        return max(queryInST(start, end, 2*i+1, l, mid, segmentTree),
                    queryInST(start, end, 2*i+2, mid+1, r, segmentTree));
    }
    
    int RMQ(int st[],int l,int r,int n){
        return queryInST(0, n-1, 0, l, r, st);
    }
    
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int activeCount=count(begin(s),end(s),'1');
        vector<int>blockStart,blockEnd,blockSize;
        
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n&&s[i]=='0')
                    i++;
                blockStart.push_back(start);
                blockEnd.push_back(i-1);
                blockSize.push_back(i-start);
            }else{
                i++;
            }
        }
        
        int m=blockStart.size();
        
        if(m<2){
            return vector<int>(queries.size(),activeCount);
        }
        
        int N=m-1;
        vector<int>pairSum(N);
        for(int i=0;i<N;i++)
            pairSum[i]=blockSize[i]+blockSize[i+1];
            
        int *st=constructST(N, pairSum.data());
        
        vector<int>result;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            int low=lower_bound(begin(blockEnd),end(blockEnd),l)-begin(blockEnd);
            int high=upper_bound(begin(blockStart),end(blockStart),r)-begin(blockStart)-1;
            
            int maxPairSum=0;
            if(low<high){
                int firstLen=blockEnd[low]-max(blockStart[low],l)+1;
                int lastLen=min(blockEnd[high],r)-blockStart[high]+1;
                
                if(high-low==1){
                    maxPairSum=firstLen+lastLen;
                }else{
                    int pair1=firstLen+blockSize[low+1];
                    int pair2=lastLen+blockSize[high-1];
                    int RMQ_MaxPairSum=RMQ(st, low+1, high-2, N);
                    maxPairSum=max({pair1,pair2,RMQ_MaxPairSum});
                }
            }
            result.push_back(maxPairSum+activeCount);
        }
        return result; 
    }
};

class Soludsdastion {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<3)
            return nums.size();
        int x=nums.size()+1;
        int bitsCount=log2(x)+1;
        return 1<<bitsCount;
    }
};

class Solutisdadon {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>set;
        for(int i=0;i<nums.size();i++){ 
            for(int j=0;j<nums.size();j++)
                set.insert(nums[i]^nums[j]);
        }
        unordered_set<int>res;
        for(auto it:set){
            for(int i=0;i<nums.size();i++)
                res.insert(it^nums[i]);
        }
        return res.size();
    }
};


class Soluadasdtion {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx=*max_element(begin(nums),end(nums));
        int sz=1;
        while(sz<=mx)
            sz=sz<<1;
        vector<bool>set(sz,0);
        
        for(int i=0;i<nums.size();i++)
            for(int j=i;j<nums.size();j++)
                set[nums[i]^nums[j]]=1;
        vector<bool>set2(sz);
        for(int i=0;i<sz;i++){
            if(set[i]==0)
                continue;
            for(int x:nums){
                set2[x^i]=1;
            }
        }
        int res=0;
        for(int i:set2)
            if(i)
                res++;
        return res;
    }
};

class Solutidsaaon {
public:
    int maxProduct(int n) {
        int8_t m1=INT_MIN,m2=INT_MIN;
        while(n){
            int x=n%10;
            if(x>m1){
                m2=m1;
                m1=x;
            }else if(x>m2){
                m2=x;
            }
        }
        return m1*m2;
    }
};


class Solutidsadaon {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums),end(nums),[](const int &a,const int &b){
            if(a<0&&b<0)
                return a>b;
            return a>b;
        });
        int res=INT_MIN,n=nums.size();
        for(int i=0;i<nums.size()*2-2;i++){
            res=max(res,nums[i%n]*nums[(i+1)%n]*nums[(i+2)%n]);
        }
        return res;
    }
};



class Solutdsadasdion {
public:
    string smallestPalindrome(string s) {
        int freq[26]={};
        int n=s.size();
        for(char c:s)
            freq[c-'a']++;
        string res(n,' ');
        for(int i=0,j=0;i<26;i++){
            while(freq[i]>0){
                if(freq[i]==1){
                    res[n/2]=(char)('a'+i);
                    freq[i]--;
                    continue;
                }
                res[j]=res[n-j-1]=(char)('a'+i);
                freq[i]-=2;
                j++;
            }
        }
        return res;
    }
};


class Solutsdasd2ion {
    int dp[21][21]={};
    int max_a_score(vector<int>&nums,int i,int j,bool turn){
        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=max(nums[i]-max_a_score(nums, i+1, j, !turn),nums[j]-max_a_score(nums, i, j-1, !turn));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return max_a_score(nums, 0, nums.size()-1, 1)>=0;
    }
};



class Solution {
    int dp[50001]={};
    int solve(vector<int>&stones,int i){
        if(i==stones.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int maxi=INT_MIN;
        int sum=0;
        for(int j=i;j<i+3&&j<stones.size();j++){
            sum+=stones[j];
            maxi=max(maxi,sum-solve(stones, j+1));
        }
        return dp[i]=maxi;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        int scoreDiff=solve(stoneValue, 0);
        return scoreDiff==0?"Tie":(scoreDiff>0?"Alice":"Bob");
    }
};
int main() {
    // run(1e4);
    // run(1e4);
    // run(1e12);
    // run(LONG_LONG_MAX);
    printf("Hello, World!");
    return 0;
}












