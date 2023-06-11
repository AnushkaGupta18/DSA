//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private: 
    bool knows(vector<vector<int>> &M, int a, int b) {
        
        if(M[a][b] == 1) {
            return true; 
        }
        
        return false; 
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st; 
        //step: put all elements into the stack 
        for(int i = 0; i < n; i++) {
            st.push(i);
        }
        //step: start a while loop 
        while(st.size() != 1) {
            //step: taking two elements out of the stack to compare them 
            int a = st.top(); 
            st.pop(); 
            int b = st.top(); 
            st.pop(); 
            
            //step: checking if a knows b; or if b knows a 
            if(knows(M, a, b)) {
                st.push(b); 
            }
            else {
                st.push(a); 
            }
        }
        
        //step: when only one element is present in stack 
        //checking if the element is a celebrity 
        int ans = st.top(); 
        
        //rowcheck, all values of row must be 0 
        bool rowCheck = false; 
        int zeroCount = 0; 
        
        for(int i =0; i < n; i++) {
            if(M[ans][i] == 0) {
                zeroCount++;
            }
        }
        
        if(zeroCount == n) {
            rowCheck = true; 
        }
        
        //columncheck, all values must be 1 except the diagonal element 
        bool colCheck = false; 
        int oneCount = 0;  
        
        for(int i = 0; i<n; i++) {
            if(M[i][ans] == 1) {
                oneCount++;
            }
        }
        
        //n-1 because the diagnol element is not included
        if(oneCount == n-1) {
            colCheck = true; 
        }
        
        if(rowCheck == true && colCheck == true) {
            return ans; 
        }
        else {
            return -1; 
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends