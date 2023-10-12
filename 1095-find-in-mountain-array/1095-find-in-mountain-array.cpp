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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 0, l = mountainArr.length() - 1, mid;
		
		// Binary Search Peak element
        while(s < l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) s = mid + 1;
            else l = mid;
        }
        
        // cout << mountainArr.get(s) << endl;
        
        int peak = s;
        
		// Binary Search in First Half
        s = 0; l = peak;
        bool flagL = false, flagR = false;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagL = true;
                break;
            }
            else if(mountainArr.get(mid) < target) s = mid + 1;
            else l = mid - 1;
        }
        // cout << flagL << " " << mountainArr.get(mid) << endl;
        if(flagL) return mid;
        
		// Binary Search in second Half
        s = peak + 1; l = mountainArr.length() - 1;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(mountainArr.get(mid) == target){
                flagR = true;
                break;
            }
            else if(mountainArr.get(mid) > target) s = mid + 1;
            else l = mid - 1;
        }
        // cout << flagR << " " << mountainArr.get(mid) << endl;
        if(flagR) return mid;
        
        return -1;
    }
};