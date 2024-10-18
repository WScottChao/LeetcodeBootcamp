class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int size = s.length();

        while(i < size && s[i] == ' '){
            i++;
        }

        int sign = 1;
        if(i < size && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long result = 0;
         while (i < size && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if (result * sign >= INT_MAX) {
                return INT_MAX;
            } else if (result * sign <= INT_MIN) {
                return INT_MIN;
            }
            i++;

         }
         return static_cast<int>(result * sign);
    }
};