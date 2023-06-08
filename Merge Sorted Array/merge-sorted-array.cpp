class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int arr[m+n]; 
        int k = 0, j = 0, i = 0; 

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                arr[k++] = nums1[i];
                i++;
            }
            else {
                arr[k++] = nums2[j];
                j++;
            }
        }

        while (i < m) {
            arr[k] = nums1[i];
            k++;
            i++;
        }

        while (j < n) {
            arr[k] = nums2[j];
            k++;
            j++;
        }

        for (int i = 0; i < m+n; i++) {
            nums1[i] = arr[i];
        }
    }
};