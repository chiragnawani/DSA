class Solution {
public:
    bool binarySearch(vector<vector<int>>& arr, int j, int low, int high, int x) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[j][mid] == x)
                return true;
            else if (arr[j][mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;

        int j = -1;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] <= target)
                j = i;
            else
                break;
        }

        if (j == -1) return false;

        int m = matrix[j].size();
        return binarySearch(matrix, j, 0, m - 1, target);
    }
};