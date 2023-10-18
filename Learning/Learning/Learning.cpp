#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <cinttypes>
#include <cmath>
#include <random>
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

//Who likes it?
string likes(const vector<string>& names)
{
    string result{};
    string message{ "no one likes this" };
    string lenForFour = to_string(names.size() - 2);

    if (names.size() == 0)
        return message;
    else if (names.size() == 1)
    {
        result = { names[0] + " likes this" };
        return result;
    }
    else if (names.size() == 2)
    {
        result = { names[0] + " and " + names[1] + " like this" };
        return result;
    }
    else if (names.size() == 3)
    {
        result = { names[0] + ", " + names[1] + " and " + names[2] + " like this" };
        return result;
    }
    else if (names.size() >= 4)
    {
        result = { names[0] + ", " + names[1] + " and " + lenForFour + " others like this" };
        return result;
    }
    else
        return 0;
}

//Multiples of 3 or 5
int solution(int number) //multiply 3 and 5
{
    int mult1 = 3;
    int mult2 = 5;
    int temp = 0;
    int num = number - 1;
    if (number < mult1 || number < 0)
        return 0;
    while (num != 0)
    {
        if ((num % mult1) == 0 || (num % mult2) == 0)
        {
            temp += num;
            num--;
        }
        else
            num--;
    }
    return temp;
}

//Create Phone Number
string createPhoneNumber(const int arr[10]) {
    string result = "";
    result = { "(" + (to_string(arr[0])) + (to_string(arr[1])) + (to_string(arr[2])) + ") " + (to_string(arr[3])) + (to_string(arr[4])) + (to_string(arr[5])) + '-' + (to_string(arr[6])) + (to_string(arr[7])) + (to_string(arr[8])) + (to_string(arr[9])) };
    return result;
}

//FindOdd
int findOdd(const vector<int>& numbers) 
{
    int counter = 0;
    int maxCounter = 0;
    int result = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        counter = count(numbers.begin(), numbers.end(), numbers[i]);
        if ((counter % 2) != 0)
        {
            if (counter > maxCounter)
            {
                maxCounter = counter;
                result = numbers[i];
            }
        }
    }
    return result;
}

//DigitalRoot
int digital_root(int n) 
{
    int remainder = n;
    int sum = 0;
    int bufRem = remainder;
    int counterOne = 0;
    int counterTwo = 0;
    int counterThree = 0;
    int digitalRoot = 0;
    int digit = 0;
    int temp = 0;
    int temp2 = 0;
    int sum2 = 0;

    while (remainder != 0)
    {
        remainder = remainder / 10;
        counterOne++;
    }
    cout << counterOne << endl;

    for (int i = 0; i < counterOne; i++)
    {
        digit = bufRem % 10;
        sum += digit;
        bufRem /= 10;
        counterTwo++;
    }
    cout << sum << endl;
    cout << counterTwo << endl;

    for (int j = 0; j < counterTwo; j++)
    {
        temp = sum % 10;
        sum2 = sum2 + temp;
        sum /= 10;
        counterThree++;
    }
    cout << "Sum2: " << sum2 << endl;
    for (int k = 0; k < counterThree; k++)
    {
        temp2 = sum2 % 10;
        digitalRoot = digitalRoot + temp2;
        sum2 /= 10;
    }
    return digitalRoot;
}

//Duplicate_encoder !!!!!NOT FINISHED!!!!!!
/*string duplicate_encoder(const string& word)
{
    string inputWord = word;
    string resultWord = "";
    size_t secondChar = 0;
    size_t lastChar = 0;
    size_t firstChar = 0;
    char charForSearch = ' ';

    transform(inputWord.begin(), inputWord.end(), inputWord.begin(),
        [](unsigned char c) { return tolower(c); });

    for (int i = 0; i < inputWord.length(); i++)
    {
        charForSearch = inputWord[i];
        secondChar = inputWord.find(charForSearch, i + 1);
        if (inputWord[i] == inputWord[secondChar])
        {
            inputWord[i] = ')';
        }
        else
            inputWord[i] = '(';
    }

    for (int i = 0; i < inputWord.length(); i++)
    {
        firstChar = inputWord.find(inputWord[i]);
        secondChar = inputWord.find(inputWord[i], i + 1);
        if (firstChar != string::npos && secondChar != string::npos)
        {
            resultWord.push_back(')');
        }

        if (secondChar == inputWord.length() - 1)
        {
            lastChar = secondChar;
        }
        if (i == inputWord.length() - 1 && lastChar != 0)
        {
            resultWord.push_back(')');
            break;
        }
        if (secondChar != string::npos)
        {
            resultWord.push_back(')');
        }
        else
            resultWord.push_back('(');
        cout << inputWord[i] << endl;
        cout << secondChar << endl;
        cout << resultWord << endl;
        cout << lastChar << "\n\n";
    }
  
    return inputWord;
}*/

//Find The Parity Outlier
int FindOutlier(vector<int> arr)
{
    size_t evenCounter = 0;
    size_t oddCounter = 0;
    int result = 0;

    for (int n = 0; n < arr.size(); n++)
    {
        if (arr[n] % 2 == 0)
        {
            evenCounter++;
        }
        else
            oddCounter++;
    }

    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] % 2 == 0 && evenCounter == 1)
            result = arr[j];
        else if (arr[j] % 2 != 0 && oddCounter == 1)
            result = arr[j];
    }

    return result;
}

//Replace With Alphabet Position !!!!NOT FINISHED!!!!
string alphabet_position(const string& text)
{
    string inputText = text;
    string resultSeq = "";
    transform(inputText.begin(), inputText.end(), inputText.begin(),
        [](unsigned char c) { return std::tolower(c); });
    
    inputText.erase(remove(inputText.begin(), inputText.end(), ' '), inputText.end());
    inputText.erase(remove(inputText.begin(), inputText.end(), '\''), inputText.end());
    
    for (int i = 0; i < inputText.length(); i++)
    {
        switch (inputText[i])
        {
        case 'a':
            resultSeq.append(" 1");
            break;
        case 'b':
            resultSeq.append(" 2");
            break;
        case 'c':
            resultSeq.append(" 3");
            break;
        case 'd':
            resultSeq.append(" 4");
            break;
        case 'e':
            resultSeq.append(" 5");
            break;
        case 'f':
            resultSeq.append(" 6");
            break;
        case 'g':
            resultSeq.append(" 7");
            break;
        case 'h':
            resultSeq.append(" 8");
            break;
        case 'i':
            resultSeq.append(" 9");
            break;
        case 'j':
            resultSeq.append(" 10");
            break;
        case 'k':
            resultSeq.append(" 11");
            break;
        case 'l':
            resultSeq.append(" 12");
            break;
        case 'm':
            resultSeq.append(" 13");
            break;
        case 'n':
            resultSeq.append(" 14");
            break;
        case 'o':
            resultSeq.append(" 15");
            break;
        case 'p':
            resultSeq.append(" 16");
            break;
        case 'q':
            resultSeq.append(" 17");
            break;
        case 'r':
            resultSeq.append(" 18");
            break;
        case 's':
            resultSeq.append(" 19");
            break;
        case 't':
            resultSeq.append(" 20");
            break;
        case 'u':
            resultSeq.append(" 21");
            break;
        case 'v':
            resultSeq.append(" 22");
            break;
        case 'w':
            resultSeq.append(" 23");
            break;
        case 'x':
            resultSeq.append(" 24");
            break;
        case 'y':
            resultSeq.append(" 25");
            break;
        case 'z':
            resultSeq.append(" 26");
            break;
 
        }
    }
    auto start = resultSeq.find_first_not_of(' ');
    auto end = resultSeq.find_last_not_of(' ');
    string trimmedString = "";
    trimmedString = resultSeq.substr(start, (end - start) + 1);
    return trimmedString;
}

//Take a Ten Minutes Walk
bool isValidWalk(vector<char> walk)
{
    int axisX = 0;
    int axisY = 0;

    for (auto i = 0; i < walk.size(); i++)
    {
        if (walk.size() == 10)
        {
            switch (walk[i])
            {
            case 'n':
                axisY++;
                break;
            case 's':
                axisY--;
                break;
            case 'e':
                axisX++;
                break;
            case 'w':
                axisX--;
                break;
            default:
                return false;
            }
        }
        else
            return false;
    }
    if (axisX == 0 && axisY == 0)
        return true;
    else
        return false;
}

//Persistent Bugger
int persistence(long long n)
{
    long long inputNum = n;
    cout << inputNum << endl;

    long long tempNum = 1;
    int counter = 0;
    if (inputNum / 10 == 0)
    {
        return 0;
    }
    else
    {
        do
        {
            int divider = 10;
            int currentDigit = 0;
            tempNum = 1;
            while (inputNum > 0)
            {
                currentDigit = inputNum % divider;
                inputNum = inputNum - currentDigit;
                currentDigit = currentDigit / (divider / 10);
                tempNum *= currentDigit;
                divider = divider * 10;
            }
            inputNum = tempNum;
            if (tempNum == 10)
            {
                counter++;
            }
            else if (tempNum == 0 && counter != 0)
            {
                counter++;
            }
            else if (tempNum == 0)
            {
                counter = 1;
                break;
            }
            else
                counter++;

        } while (tempNum > 9);
    }
    return counter;
}

//Convert string to camel case
string to_camel_case(string text)
{
    string inputText = text;
    string separators{ "-_" };
    size_t startPos{ inputText.find_first_not_of(separators) };

    while (startPos != string::npos)
    {
        if (startPos != 0)
        {
            inputText[startPos] = toupper(inputText[startPos]);
            cout << inputText[startPos] << endl;
        }
        size_t endPos = inputText.find_first_of(separators, startPos + 1);
        if (endPos == string::npos)
        {
            endPos = inputText.length();
        }
        startPos = inputText.find_first_not_of(separators, endPos + 1);

    }

    while (inputText.find_first_of(separators) != string::npos)
    {
        inputText.erase(inputText.find_first_of(separators), 1);
    }
    return inputText;
}

//Build tower
vector <string> towerBuilder(unsigned nFloors)
{
    vector <string> result = {};
    int symCount = 1;
    char symbol = '*';
    string floorTemp = "";
    int symForReplace = 1;
    string spaces = " ";

    for (auto i = 1; i < nFloors; i++)
    {
        symCount += 2;
    }

    for (auto j = nFloors; j > 0; j--)
    {
        
        for (auto k = 0; k < symCount; k++)
        {
            floorTemp.push_back(symbol);
        }
        if (j != nFloors)
        {
                floorTemp.replace(0, symForReplace, spaces);
                floorTemp.replace(floorTemp.size() - symForReplace, symForReplace, spaces);
                symForReplace++;
                spaces += " ";
                result.push_back(floorTemp);
        }
        else
            result.push_back(floorTemp);
        floorTemp = "";
        /*for (auto n : result)
        cout << n << endl;*/
       
    }
    reverse(result.begin(), result.end());
    /*for (auto n : result)
        cout << n << endl;*/
    return result;
    
}

//Does my number look big in this?
bool narcissistic(int value)
{
    int inputNum = value;
    int currentDigit = 0;
    int divider = 10;
    int tempNum = 0;
    size_t counterPow = 0;
    int powDigit = 1;

    while (inputNum > 0)
    {
        currentDigit = inputNum % divider;
        inputNum = inputNum - currentDigit;
        currentDigit = currentDigit / (divider / 10);
        divider = divider * 10;
        counterPow++;
    }

    inputNum = value;
    currentDigit = 0;
    divider = 10;

    while (inputNum > 0)
    {
        currentDigit = inputNum % divider;
        inputNum = inputNum - currentDigit;
        currentDigit = currentDigit / (divider / 10);
        for (auto i = 0; i < counterPow; i++)
        {
            powDigit *= currentDigit;
        }
        tempNum += powDigit;
        divider = divider * 10;
        powDigit = 1;
    }
    inputNum = value;

    if (inputNum == tempNum)
        return true;
    else
        return false;
}

//Mexican Wave
vector<string> wave(string y)
{
    vector <string> result = {};
    string inputWord = y;
    string resultWord = "";
    for (size_t i = 0; i < inputWord.length(); i++)
    {
        resultWord = inputWord;

        if (inputWord[i] == ' ')
        {
            resultWord[i + 1] = toupper(inputWord[i + 1]);
            continue;
        }
        else
        {
            resultWord[i] = toupper(inputWord[i]);
        }
        result.push_back(resultWord);
        resultWord = "";
    }
    for (auto n : result)
        cout << n << endl;
    return result;
}

//The Supermarket Queue
long queueTime(vector<int> customers, int n)
{
    vector <int> inputSeq = customers;
    int tills = n;
    long maxTime = 0;
    int minSum = 99999;
    vector<int>times(tills);
    size_t lastIndex = inputSeq.size() - 1;
    size_t minSumIndex = 0;

    if (inputSeq.size() < 1)
        return maxTime;
    for (auto i = 0; i < tills; i++)
    {
        times[i] = inputSeq[i];
        if (minSum > times[i])
        {
            minSum = times[i];
            minSumIndex = i;
        }
    }

    if (lastIndex <= tills)
    {
        for (auto k = 0; k < inputSeq.size(); k++)
        {
            if (maxTime < inputSeq[k])
                maxTime = inputSeq[k];
        }
    }
    else
    {
        for (auto i = tills; i < inputSeq.size(); i++)
        {
            for (auto n = 0; n < tills; n++)
            {
                if (minSum > times[n])
                {
                    minSum = times[n];
                    minSumIndex = n;
                }
            }
            times[minSumIndex] += inputSeq[i];
            minSum = 99999;
            minSumIndex = 0;
        }
        for (auto i = 0; i < times.size(); i++)
        {
            if (maxTime < times[i])
            {
                maxTime = times[i];
            }
        }
    }
    return maxTime;
}

//Buying a car
class BuyCar
{

public:
    static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

vector <int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
    int monthCounter = 0;
    double savings = 0;
    double newPercent = percentLossByMonth / 100;
    double newCarPrice = startPriceNew;
    double oldCarPrice = startPriceOld;
    double moneyCalc = 0;
    int moneyRemaining = 0;

    if (oldCarPrice >= newCarPrice)
    {
        moneyRemaining = oldCarPrice - newCarPrice;
        return { monthCounter, moneyRemaining };
    }
    else
    {
        while (moneyRemaining <= 0)
        {
            if (monthCounter % 2)
            {
                newPercent += 0.005;
            }
            newCarPrice -= (newCarPrice * newPercent);
            oldCarPrice -= (oldCarPrice * newPercent);
            savings += savingperMonth;
            moneyCalc = ((savings + oldCarPrice) - newCarPrice);
            moneyRemaining = round(moneyCalc);
            monthCounter++;
            cout << "New Car Price = " << newCarPrice << endl;
            cout << "Old Car Price = " << oldCarPrice << endl;
            cout << "Savings = " << savings << endl;
            cout << "Money Remaining = " << moneyRemaining << endl;
            cout << "Month = " << monthCounter << endl;
            cout << "New Percent = " << newPercent << endl;
        }

        return { monthCounter, moneyRemaining };
    }
}

//ballUpwards
int maxBall(int v0)
{
    float gravity = 9.81;
    float height = 0;
    float speed = v0 / 3.6;
    float maxHeight = 0;
    float maxTime = 0;

    for (float time = 0.1; time > maxTime; time += 0.1)
    {
        maxHeight = height;
        height = (speed * time) - (0.5 * gravity * time * time);
        if (maxHeight > height)
        {
            maxTime = time - 0.1;
            break;
        }
    }
    return round(maxTime *= 10);
}

//Image host filename generator
string generateName()
{
    string result = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 25);
    for (auto i = 0; i < 6; i++)
    {
        result.push_back(alphabet[dis(gen)]);
    }
    return result;
}

//Mutual Recursion
int F(int);
int M(int);

int F(int n) {
    if (n == 0)
        return 1;
    else
        return (n - M(F(n - 1)));
}

int M(int n) {
    if (n == 0)
        return 0;
    else
        return (n - F(M(n - 1)));
}

//Hamming Distance
unsigned hamming(const std::string& a, const std::string& b)
{
    string firstWord = a;
    string secondWord = b;
    int counter = 0;
    for (auto n = 0; n < firstWord.length(); n++)
    {
        if (firstWord[n] != secondWord[n])
            counter++;
    }
    return counter;
}

//Sum of Two Integers
int Add(int x, int y)
{
    return fma(1, x, y);
}

int main()
{
    cout<<maxBall(37);
    return 0;
}