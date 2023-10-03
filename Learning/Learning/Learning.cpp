#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <cinttypes>
#include <cmath>
#include <numeric>

using namespace std;

//Multiply
int multiply(int a, int b)
{
    return a * b;
}

//Even or Odd
string even_or_odd(int number)
{
    if (number % 2 == 0)
        return "Even";
    else
        return "Odd";
}

//Convert a Number to a String!
string number_to_string(int num) {
    string convNum = to_string(num);
    return convNum;
}

//Opposite number
int opposite(int number)
{
    return (0 - number);
}

//Convert boolean values to strings 'Yes' or 'No'.
string bool_to_word(bool value)
{
    return (value == true) ? "Yes" : "No";
}

//Return Negative
int makeNegative(int num)
{
    return (num < 0) ? num : -num;
}

//String repeat
string repeat_str(size_t repeat, const string& str) {
    string newStr;
    for (int i = 0; i < repeat; i++)
        newStr += str;
    return newStr;
}

//Square(n) Sum
int square_sum(const vector<int>& numbers)
{
    int tempSum = 0;
    if (!numbers.empty())
    {

        for (size_t i = 0; i != numbers.size(); i++)
        {
            tempSum += numbers[i] * numbers[i];
        };
    };
    return tempSum;
}

//Find the smallest integer in the array
int findSmallest(vector <int> list)
{
    int smallestValue = list[0];
    if (!list.empty())
    {
        for (size_t i = 0; i != list.size(); i++)
        {
            if (smallestValue > list[i]) smallestValue = list[i];
        };
    };
    return smallestValue;
}

//Vowel Count
int getCount(const string& inputStr) {
    int num_vowels = 0;
    char words[5] = { 'a', 'e', 'i', 'o', 'u' };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < inputStr.length(); j++)
        {
            if (inputStr[j] == words[i]) num_vowels++;
        }
    }
    return num_vowels;
}

//Disemvowel Trolls
bool is_vowel(const char p_char)
{
    constexpr char vowels[] = { 'a', 'e', 'i', 'o', 'u','A','E','I','O','U' };
    return find(begin(vowels), end(vowels), p_char) != end(vowels);
}

string disemvowel(const string& str) {
    string tempStr = str;
    auto to_erase = remove_if(tempStr.begin(), tempStr.end(), is_vowel);
    tempStr.erase(to_erase, tempStr.end());
    return tempStr;
}

//Square Every Digit
int square_digits(int num)
{
    int remainder = num;
    int result_digits = 1;
    int divider = 10;
    int result = 0;
    int current_digit = 0;
    int temp_number = 0;

    while (remainder > 0)
    {
        current_digit = remainder % divider;
        remainder = remainder - current_digit;
        current_digit = current_digit / (divider / 10);
        temp_number = current_digit * current_digit;
        result = result + (temp_number * result_digits);

        if (temp_number / 10 > 0)
        {
            result_digits = result_digits * 100;
        }
        else
        {
            result_digits = result_digits * 10;
        }
        divider = divider * 10;
    }
    return result;
}

//Descending Order
uint64_t descendingOrder(uint64_t a)
{
    uint64_t number = a;
    uint64_t sorted = 0;
    uint64_t digits = 10;
    uint64_t sortedDigits = 1;
    bool first = true;

    while (number > 0)
    {
        uint64_t digit = number % 10;
        if (!first)
        {
            uint64_t tmp = sorted;
            uint64_t toDivide = 1;
            for (int i = 0; i < sortedDigits; i++)
            {
                uint64_t tmpDigit = tmp % 10;
                if (digit <= tmpDigit)
                {
                    sorted = sorted / toDivide * toDivide * 10 + digit * toDivide + sorted % toDivide;
                    break;
                }
                else if (i == sortedDigits - 1)
                {
                    sorted = digit * digits + sorted;
                }
                tmp /= 10;
                toDivide *= 10;
            }
            digits *= 10;
            sortedDigits += 1;
        }
        else
        {
            sorted = digit;
        }
        first = false;
        number = number / 10;
    }

    return sorted;
}

//Sum of two lowest positive integers
long sumTwoSmallestNumbers(vector<int> numbers)
{
    int sum = 0;
    vector<int> copyInput(numbers);
    for (int i = 0; i < 2; ++i)
    {
        vector<int>::iterator tempNumber = min_element(copyInput.begin(), copyInput.end());
        sum += *tempNumber;
        cout << sum << endl;
        copyInput.erase(tempNumber);
    }

    return sum;

}

//Growth of a Population
class Arge
{
public:
    static int nbYear(int p0, double percent, int aug, int p);
};

int Arge::nbYear(int p0, double percent, int aug, int p)
{
    int year = 0;
    for (int i = 0; p0 < p; i++)
    {
        p0 = p0 + (p0 * (percent / 100)) + aug;
        year += 1;
    }
    return year;
}

//Sort Numbers
vector<int> solution(vector<int> nums) {
    if (nums.empty())
    {
        return nums;
    }
    else
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
}

//Sum of a sequence
int sequenceSum(int start, int ending, int step)
{
    int res = start;
    int result = 0;
    int tempNum = start;
    if (start <= ending)
    {
        while ((tempNum + step) < ending)
        {
            tempNum += step;
            res += tempNum;
            cout << tempNum << endl;
        }
        if ((tempNum + step) != ending)
        {
            result = res;
        }
        else result = res + ending;
        return result;
    }
    else return 0;
}

//Leap Year
bool leapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else return false;
}


//Sum of positive
int positive_sum(const vector<int> arr)
{
    vector <int>posVector = {};
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            posVector.push_back(arr[i]);
        }
    }
    for (int n : posVector)
        cout << n << endl;
    int sum_of_elements = accumulate(posVector.begin(), posVector.end(), 0);
    return sum_of_elements;
}

//Reversed Strings
#include <string>
#include <algorithm>
using namespace std;

string reverseString(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return temp;
}

//Count by X
vector<int> countBy(int x, int n)
{
    vector<int>result = {};
    for (int i = 1; i <= n; i++)
    {
        result.push_back(x * i);
    }
    for (int n : result)
        cout << n << endl;

    return result;
}

//Greatest common divisor
long long mygcd(long long a, long long b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

//Grasshopper - Summation
int summation(int num)
{
    int sum = 1;
    int temp = 0;
    for (int i = 0; sum <= num; i++)
    {
        temp += sum;
        sum += 1;
    }
    return temp;
}

//Largest Square Inside A Circle
int area_largest_square(int r)
{
    return 2 * (r * r);
}

//Perimeter sequence
int perimeter_sequence(int a, int n) {
    return (a * 4) * n;
}

//Speed Control

class GpsSpeed
{
public:
    static int gps(int s, vector<double>& x);
};

int GpsSpeed::gps(int s, vector<double>& x)
{
    if (x.size() <= 1)
    {
        return 0;
    }

    double maxAverageSpeed = 0;

    for (int i = 0; i < (x.size() - 1); i++)
    {
        double deltaDistance = x[i + 1] - x[i];
        double averageSpeed = (3600 * deltaDistance) / s;

        if (averageSpeed > maxAverageSpeed)
        {
            maxAverageSpeed = averageSpeed;
        }
    }
    return floor(maxAverageSpeed);
}


int main()
{
   
    return 0;
}