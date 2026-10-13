class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int sum = 0;
        int largest = 0;
        int count = 0;
        for(auto it: piles)
        {
            sum += it;
            largest = max(largest, it);
            ++count;
        }

        if (count > h) return -1;
        if (count == h) return largest;

        int l = 1, mid = 1, r = largest;
        int hrs;

        while(l < r)
        {
            hrs = 0;

            for(auto it: piles)
            {
                int indiv = ceil((float)it/(float)mid);
                hrs += indiv;
                cout << indiv << "|" << endl;
            }
            cout << hrs << endl;

            if (hrs < h) 
            {
                return mid;
            }
            else
            {
                mid = floor((float)l + ((float)r - (float)l)/2.00);
                l = mid + 1;
            }
        }

        return mid;
    }
};
