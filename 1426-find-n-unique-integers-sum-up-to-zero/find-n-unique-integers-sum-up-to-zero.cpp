class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        if(n%2==0){
            int m=n/2;
            for(int i=1;i<m+1;i++){
                arr.push_back(i);
                arr.push_back(i*-1);
            }

        }
        else{
            int m=n/2;
            arr.push_back(0);
            for(int i=1;i<m+1;i++){
                arr.push_back(i);
                arr.push_back(i*-1);
            }

        }
        return arr;
       
        
    }
};