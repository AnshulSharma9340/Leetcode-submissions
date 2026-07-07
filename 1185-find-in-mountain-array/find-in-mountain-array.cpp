/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &mountainArr, int left, int right, int target, bool isAscending) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            if (isAscending) {
                if (value < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (value < target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        int peak = low;
        int ans = binarySearch(mountainArr, 0, peak, target, true);
        if (ans != -1)
            return ans;

        return binarySearch(mountainArr, peak + 1, n - 1, target, false);
    }
};