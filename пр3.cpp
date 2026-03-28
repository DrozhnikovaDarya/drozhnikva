#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool UserInput(string input) {
    if (input.empty()) return false; 

    try {
        size_t pos;
        stoi(input, &pos); 
        return pos == input.length();
    }
    catch (...) { 
        return false; 
    }
}

int EnterNumber(string label) {
    string raw_input;
    cout << endl << label << "";
    getline(cin, raw_input); 
    while (!UserInput(raw_input)) { 
        cout << label << "";
        getline(cin, raw_input);
    }

    return stoi(raw_input); 
}

void task1() {
    int M =  EnterNumber("Введите значение M:");
    int N =  EnterNumber("Введите значение N:\n");
    cin >> N;
    if (M%2==1){M++;}
    if (M>N){
      cout << "ошибка \n";
    }
    else{
      while (M<=N){
          cout << M << " ";
          M+=2;
      }
    }

}

void task2(){
    int n = EnterNumber("Введите значение n:\n");
    int sum;
    int a;
    
    for (int i = 1; i <= n; i++) {
        cin >> a;
        
        if (i == 1 || i == 2) {sum += a;}
        else {
            if (i % 2 == 1) {sum += a;} 
            else {sum -= a;} }
    }
    
    cout << "Сумма последовательности: " << sum << endl;
}

void task3(){
    int start = EnterNumber("");
    int end  = EnterNumber("");
    int shag  = EnterNumber("");

    double F;
    cout << "x   F "<< endl;
  for (int i = start; i <= end; i += shag) {
        F = (81 * log(9))/(log(i*i - 4*i + 2));
        cout << i << "  " << F << endl;
    }
}

void task4(){
    double F = 0;  
    
    for (int i = 1000; i >= 1; i--) {  
        if (i % 2 == 0) {F -= (1.0 / i);}
        else {F += (1.0 / i);}
    }
    cout << F << endl;
    /*
    double F = 0;  
    
    for (int i = 1; i<= 1000; i+=2) {  
       F += (1.0 / i);}
    for (int i=2; i<= 1000; i+=2){
    F -= (1.0 / i);}
    cout << F << endl;
    */
}

void task5(){
    int a = EnterNumber("");
    int k=0;

   for (int i=2; i<a; i++){
       for (int t=2; t<=i; t++){
           if (i%t == 0 && a%t == 0){
               k+=1;
                break;}
           
       }
   }
   if (k==0){cout << a << endl;}
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int funcSelect;
    cin >> funcSelect;
    for (;;){
        if (funcSelect == 0) break; 
        switch (funcSelect) 
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            default:
                cout << "Ошибка: выберите номер от 1 до 5 или 0 для выхода." << endl;
                break;
        }
    }
    return 0;
}
