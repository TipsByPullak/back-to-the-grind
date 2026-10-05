class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        if (rows == 0) return false;

        const int columns = matrix[0].size();
        if (columns == 0) return false;

        int l = 0, r = (rows * columns) - 1;

        while(l <= r)
        {
            int mid = l + (r - l)/2;

            int rMid = mid / columns;
            int cMid = mid % columns;

            cout << rMid << " " << cMid << "|" << endl;

            int curr = matrix[rMid][cMid];

            if(curr == target) return true;
            else if (curr > target) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};
