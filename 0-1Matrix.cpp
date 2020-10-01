class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
       
        
        int m=matrix.size();
        int n=matrix[0].size();
        int i,j;
        queue<pair<int,int>> temp;
           vector<vector<int> > dist(m,vector<int>(n,-1));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    pair<int,int> t1=make_pair(i,j);
                    dist[i][j]=0;
                    temp.push(t1);
                }
            }
        }
        
        while(!temp.empty())
        {
            cout<<"hello"<<endl;
            pair<int,int> t1=temp.front();
            temp.pop();
            
            int a=t1.first;
            int b=t1.second;
            
            if(a-1>=0 && dist[a-1][b]==-1)
            {
                cout<<"a"<<endl;
                dist[a-1][b]=dist[a][b]+1;
                pair<int,int> t;
                t=make_pair(a-1,b);
                temp.push(t);
                
            }
          //  cout<<"cc"<<endl;
            if(b-1>=0 && dist[a][b-1]==-1)
            {
                cout<<"b"<<endl;
                dist[a][b-1]=dist[a][b]+1;
                 pair<int,int> t;
                t=make_pair(a,b-1);
                temp.push(t);
            }
             // cout<<"cc"<<endl;
            
            if(a+1<m && dist[a+1][b]==-1)
            {
                cout<<"c"<<endl;
                dist[a+1][b]=dist[a][b]+1;
                 pair<int,int> t;
                t=make_pair(a+1,b);
                temp.push(t);
            }
             // cout<<"cc"<<endl;
            if(b+1<n && dist[a][b+1]==-1)
            {
                cout<<"hello"<<endl;
                dist[a][b+1]=dist[a][b]+1;
                 pair<int,int> t;
                t=make_pair(a,b+1);
                temp.push(t);
            }
            cout<<"amrit"<<endl;
            
        }
        
        return dist;
        
        
    }
};