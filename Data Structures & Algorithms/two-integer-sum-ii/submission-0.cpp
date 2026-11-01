class Solution {
public:
    int binarySearch(vector<int>& numbers,int target, int left, int right){
        
    while (left <= right) {
        // Prevents potential integer overflow compared to (left + right) / 2
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (numbers[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (numbers[mid] < target) {
            left = mid + 1;
        } 
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // Target was not present in the vector
    return -1;

    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++){
          int j =  target - numbers[i] ;
          int res = binarySearch(numbers,j,i+1,numbers.size()-1);
          if(res!=-1){
            return {i+1,res+1};
          }
        }
        
    }
};
