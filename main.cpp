#include <iostream>
#include<map>
using namespace std;

bool checkValidityOfNumeral(char numeral) { //UNUSED FUNCTION, could have been used to check if the number you submitted was a roman numeral
    if (numeral =! 'I' || 'V' || 'X' || 'L' || 'C' || 'D' || 'M') {
        return false;
    }
}

int romanToDecimal(string givenNumeral) {
    // PAIR MAP FROM ROMAN NUMERALS TO THEIR COORESPONDING NUMBERS
    map<char, int> numeralMap = { //map for basic key-value pairs of roman numerals to decimal numbers.
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
             {'M', 1000}
    };
    int numDecimal = 0;
//map : map<key, value> name = ...

   for (int i = 0; i < givenNumeral.length(); i++) {
       //cout << numeralMap[givenNumeral[i]] << endl;

       /*for (i = 0; i < givenNumeral.size(); i++){
           if (checkValidityOfNumeral(givenNumeral[i]) == false) {
               cout << "Invalid numeral";
               exit(0); //just terminates program, so you can re-run it
           }
       }*/
       if (numeralMap[givenNumeral[i]] < numeralMap[givenNumeral[i + 1]]) { //if the current numeral is less than the next numeral...
           numDecimal = numDecimal - numeralMap[givenNumeral[i]]; //subtract them. else...
       } else {
           numDecimal = numDecimal + numeralMap[givenNumeral[i]]; //add them
       }
   }
    return numDecimal;
}

string decimalToNumeral(int decimal) {
    string roman = "";
    int tempDecimal;
    map<int, string, greater<int>> decimalMap = { //how do I make the map in descending order? USE greater<int>
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
    };
    for (auto [number, numeral] :decimalMap) { //iterates through map
        while (decimal >= number) {
            roman += numeral;   //adds numerals as many times as necessary for the given number
            decimal -= number;  //subtracts value of number
        /* The math behind this vvv
         3999 - 1000 - 1000 - 1000 = 999 = 'MMM'
            ' ' + 'M' + 'M' + 'M' = 'MMM' = 3000
         999 - 900 = 99 = 'CM'
            'MMM' + 'CM' = 3900 = 'MMMCM'
         99 - 90 = 9 = 'XC'
            'MMMCM + 'XC' = 3990 = 'MMCMXC'
         9 - 9 = 0 = 'IX'
            'MMCMXC' + 'IX' = 3999 = 'MMMCMXCIX'
         */

        }
    }

    //cout << tempDecimal << endl;

    return roman;
}

int main() {
    string numeral = "MMMCMXCIX"; //for 3,999
    int number = 3999;

    cout << "Enter a roman numeral you want converted to a decimal number" << endl;
    getline(cin, numeral);
    int finalDecimal = romanToDecimal(numeral);
    cout << numeral << " in decimal is " << finalDecimal << endl;

    cout << "Enter a decimal number you want converted to roman numerals" << endl;
    cin >> number;
    string finalNumeral = decimalToNumeral(number);
    cout << number << " in decimal number is " << finalNumeral << endl;


    cout << "Have a nice day!";
    return 0;

}

/*
1. Normally, values are combined by adding the values of the symbol together.
For example, III = 3, VII = 7, CLXV = 165.
2. Roman numerals also involve subtractive notation.
If symbol A is less than the symbol immediately following it (B), A is subtracted from B and AB is treated as a
unit to add to the total. Thus, IV = 4, XL = 40, XC = 90.
3. Subtractive notation only ever involves two symbols.
So, for example, XIV = 14, not 4, and XCIV = 94 ((V – I) + (C– X))
instead of 84 (C – X – V – I).
4. A symbol representing 10x may not precede any symbol larger than 10x+1.
For example, C cannot be preceded by I or V, only by X (or, of course, by a symbol representing a value equal
to or larger than C).
*/