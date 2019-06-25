class Solution {
public:
    int lastRemaining(int n) {
        int rest = n, head = 1, step = 1;
        bool left = true;
        while(rest > 1){
            if(left || rest % 2 == 1) head = head + step;
            step *= 2;
            rest /= 2;
            left = !left;
        }
        return head;
    }
};