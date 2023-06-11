class Solution {
private: 
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
     vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
    int largestRectangleArea(vector<int> heights) {
        
        int n = heights.size(); 
        
        //two arrays to store the smaller elements ka index
        vector<int> next(n); 
        vector<int> prev(n); 
        
        next = nextSmallerElement(heights, n); 
        prev = prevSmallerElement(heights, n); 
        
        int area = INT_MIN; 
        
        for(int i = 0; i < n; i++) {
            int length = heights[i]; 
            
            //if all the elements of the array are equal, then our next will go 'n' instead of throwing a   negative value of n
            if(next[i] == -1) {
                next[i] = n; 
            }
            
            int breadth = next[i] - prev[i] - 1; 
            int newArea = length*breadth; 
            
            area = max(area, newArea); 
        }
        
        return area; 
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
//         int rows = sizeof(matrix)/sizeof(matrix[0]); 
//         int cols = sizeof(matrix[0])/sizeof(matrix[0][0]); 
        
//         //computing the area of the first row 
//         int area = largestRectangleArea(matrix[0], rows); 
        
//         //updating all the rows with the sum of the previous row 
//         //agar current row mein koi element 0 hai, toh sum 0 hi daaldenge  
//         for(int i = 1; i < rows; i++) {
//             for(int j = 0; j < cols; j++) {        
//                 if(matrix[i][j] != '0') {
//                     matrix[i][j] = matrix[i][j] + matrix[i-1][j];
//                 }
//                 else {
//                     matrix[i][j] = 0; 
//                 }
//             }
            
//             area = max(area, largestRectangleArea(matrix[i], rows))
//         }
        
//         return area; 
        
        vector<vector<int>> v(matrix.size());
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[i].size();j++){
               if(matrix[i][j]=='0')
                    v[i].push_back(0);
               else v[i].push_back(1);
           }
       } 
       int first= largestRectangleArea(v[0]);
        for(int i=1;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]!=0){
                    v[i][j]=v[i-1][j]+v[i][j];
                }
                else v[i][j]=0;
            }
            
            int a=  largestRectangleArea(v[i]);
            first= max(first,a);
        }
        
        return first;
    }
};