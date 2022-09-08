class Solution {
public:
    int findMax(vector<int> &col){
        int max = 0, index = -1;
        for(int i = 0; i<col.size(); i++){
            if(col[i] > max){
                max = col[i];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int s = 0, e = mat.size()-1, peak;
            int index=0;
            while(s<=e){
                int mid = (s+e)/2;
                peak = findMax(mat[mid]);
                int low_left = (mid==0 or mat[mid][peak]>mat[mid-1][peak]);
                int up_right = (mid==mat.size()-1 or mat[mid][peak]>mat[mid+1][peak]);
                if(low_left and up_right){
                    return {mid,peak};
                }
                else if(mat[mid][peak] < mat[mid+1][peak])s= mid + 1;
                else index=mid,e=mid-1;
            }
        
            int peakVal = findMax(mat[index]);
            return {index, peakVal};
            
    }
};