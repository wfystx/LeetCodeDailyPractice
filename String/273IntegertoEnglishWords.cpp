class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        return num ? helper(num).substr(1) : "Zero";
    }
    string helper(int n){
        if(n>=1000000000) return helper(n/1000000000) + " Billion" + helper(n%1000000000);
        if(n>=1000000) return helper(n/1000000) + " Million" + helper(n%1000000);
        if(n>=1000) return helper(n/1000) + " Thousand" + helper(n%1000);
        if(n>=100) return helper(n/100) + " Hundred" + helper(n%100);
        if(n>=20) return " " + tens[n/10] + helper(n%10);
        if(n>=1) return " " + ones[n];
        return "";
    }
};