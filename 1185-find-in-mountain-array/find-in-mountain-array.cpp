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
     int findPeak(MountainArray &mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    int binarySearchIncreasing(int target, MountainArray &mountainArr,
                               int low, int high) {

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int binarySearchDecreasing(int target, MountainArray &mountainArr,
                               int low, int high) {

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val < target)
                high = mid - 1;  // target is on LEFT
            else
                low = mid + 1;   // target is on RIGHT
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        // Search increasing part first
        int ans = binarySearchIncreasing(
            target, mountainArr, 0, peak
        );

        if (ans != -1)
            return ans;

        // Search decreasing part
        return binarySearchDecreasing(
            target, mountainArr, peak + 1, mountainArr.length() - 1
        );
    }
};