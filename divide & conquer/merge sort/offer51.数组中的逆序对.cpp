class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int left_index, cur, right_index;
        queue<int> left, right;

        for(int i = 1; i < n; i<<=1){
            cur = 0;
            while(cur < n){
                left_index = cur;
                // left
                right_index = Cut(nums, left, left_index, i);
                // right
                cur = Cut(nums, right, right_index, i);
                // merge
                Merge(nums, left_index, left, right);
            }
        }

        return m_total;
    }

    int Cut(vector<int> &src, queue<int> &dst, int index, int size){
        int i = 0;
        while(index < src.size() && i < size){
            dst.push(src[index]);
            ++index;
            ++i;
        }
        return index;
    }

    void Merge(vector<int> &src, int index, queue<int> &left, queue<int> &right){
        int l, r;
        while(!left.empty() && !right.empty()){
            l = left.front();
            r = right.front();
            if (l > r){
                m_total += left.size();
                src[index] = r;
                right.pop();
            }else{
                src[index] = l;
                left.pop();
            }
            ++index;
        }

        while(!left.empty()){
            l = left.front();
            src[index] = l;
            left.pop();
            ++index;
        }
        while(!right.empty()){
            r = right.front();
            src[index] = r;
            right.pop();
            ++index;
        }
    }

private:
    int m_total = 0;
};