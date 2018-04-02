// 这个限定了num在1~3999中

class Solution {
public:
    string intToRoman(int num) {
        // vector<string> num4 = {"","M","MM","MMM"};
        // vector<string> num3 = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        // vector<string> num2 = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        // vector<string> num1 = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        // return num4[num/1000] + num3[(num%1000)/100] + num2[(num%100)/10] + num1[(num%10)];
        string num4[] = {"","M","MM","MMM"};
        string num3[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string num2[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string num1[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        return num4[num/1000] + num3[(num%1000)/100] + num2[(num%100)/10] + num1[(num%10)];

    }
};
