#include <iostream>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_ALL,"Rus");
    int num, sum = 0, a, i = 1;
    cout << "Г‚ГўГҐГ¤ГЁГІГҐ Г·ГЁГ±Г«Г®: ";
    cin >> num;
    while(num != 0){
        a = num % 10;
        num = (num - a) / 10;
        sum = sum + a;
        }
    cout << sum  << endl;

    system("pause");
    return 0;
}
