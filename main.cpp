#include <iostream>
#include <math.h>


using namespace std;

string to16xfrom10(string x16, int ost)
{
    switch( ost ) {
        case 10:
            x16 += "A";
            break;
        case 11:
            x16 += "B";
            break;
        case 12:
            x16 += "C";
            break;
        case 13:
            x16 += "D";
            break;
        case 14:
            x16 += "E";
            break;
        case 15:
            x16 += "F";
            break;

        default:
            x16 += to_string(ost);
    }
    return x16;
}

int to10from2(int r)
{
    int num = 1 * pow(2, r);
    return num;
}

int main() {
    cout << "Введите число в двоичной: ";
    string TwoxNum = "";
    cin >> TwoxNum;

    const int len = TwoxNum.length();


    int index = len-1;
    int number = 0;
    for (int i = 0; i < len; i++ )
    {

        if (TwoxNum[i] == '1' )
        {
            number += to10from2( index );
        }
        index--;
    }

    int ost = 0;
    string x16 = "";

    while (number / 16 != 0)
    {
        ost = number % 16;
        number /= 16;
        x16 = to16xfrom10(x16, ost);
    }

    x16 = to16xfrom10(x16, number);


    reverse( x16.begin(), x16.end() ); 
    cout << "Число в 16-ой:            " << x16 << endl;

    return 0;
}