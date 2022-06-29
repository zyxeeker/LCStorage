/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

/**
 * @brief 分治,递归 源于算法导论(3)
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int t1 = 0, t2 = 0;
        int res = FindSubMax(nums, 0, nums.size() - 1, t1, t2);
        return res;
    }

    /**
     * @brief 分治后局部和最大数组
     * 
     * @param src 原数据
     * @param low 下界
     * @param high 上界
     * @param low_dst 返回下界
     * @param high_dst 返回上界
     * @return int 返回最大数组和
     */

    int FindSubMax(vector<int> &src, int low, int high, int& low_dst, int& high_dst){
        if (low == high){
            low_dst = low;
            high_dst = high;
            return src[low];
        }else{
            int mid = (low + high)/2;
            // left
            int left_low, left_high;
            int left_sum = FindSubMax(src, low, mid, left_low, left_high);
            // right
            int right_low, right_high;
            int right_sum = FindSubMax(src, mid + 1, high, right_low, right_high);
            // cross
            int cross_low, cross_high;
            int cross_sum = FindCrossMax(src, low, mid, high, cross_low, cross_high);

            if (left_sum >= right_sum && left_sum >= cross_sum){
                low_dst = left_low;
                high_dst = left_high;
                return left_sum;
            }else if (right_sum >= left_sum && right_sum >= cross_sum){
                low_dst = right_low;
                high_dst = right_high;
                return right_sum;
            }else{
                low_dst = cross_low;
                high_dst = cross_high;
                return cross_sum;
            }
        }
    }

    /**
     * @brief 查找跨越上下界中点的和最大数组
     * 
     * @param src 原数据
     * @param low 下界
     * @param mid 中点
     * @param high 上界
     * @param low_dst 返回下界
     * @param high_dst 返回上界
     * @return int 返回最大数组和
     */
    int FindCrossMax(vector<int>& src, int low, int mid, int high, int& low_dst, int& high_dst){
        int left_sum = 0, left_total = INT_MIN;
        // left
        for(int i = mid; i >= low; --i){
            left_sum += src[i];
            if (left_sum > left_total){{}
                left_total = left_sum;
                low_dst = i;
            }
        }
        
        //right
        int right_sum = 0, right_total = -1e4 - 1;
        for(int i = mid + 1; i <= high; ++i){
            right_sum += src[i];
            if (right_sum > right_total){
                right_total = right_sum;
                high_dst = i;
            }
        }
        return left_total + right_total;
    }
};
// @lc code=end

