#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <clocale>

using namespace std;

class CFlat
{
private:
 vector <string> HumansName;
 int time,
  Square,
  electricity,
  water,
  gas;
public:
  CFlat(int set_time, int set_Square, int set_electricity, int set_water, int set_gas)
  {
   setstate(set_time, set_Square, set_electricity, set_water, set_gas);
  }
  void addHuman()
  {
   cout << "Введіть ім'я" << endl;
   string name;
   cin >> name;
   HumansName.push_back(name);
  }
  void viewHuman()
  {
   for (unsigned int i = 0; i < HumansName.size(); i++)
   {
    cout << i << "\t" << HumansName[i] << endl;
   }
  }
  int getCountPeople()
  {
   return HumansName.size();
  }
  void delHuman()
  {
   viewHuman();
   cout << "Введіть номер" << endl;
   int k;
   cin >> k;
   HumansName.erase(HumansName.begin() + k);
  }
  void setstate(int time, int Square, int electricity, int water, int gas)
  {
   this->time = time;
   this->Square = Square;
   this->electricity = electricity;
   this->water = water;
   this->gas = gas;
  }
  void currentstate()
  {
   cout << "Термін експлуатації квартири: " << time << " дн" << endl;
   cout << "Площа: " << Square << "м3" << endl;
   cout << "Кількість спожитої електроенергії: " << electricity << " Вт/г" << endl;
   cout << "Кількість спожитої води: " << water << " л" << endl;
   cout << "Кількість спожитого газу: " << gas << " кб" << endl;
   system("pause");
  }
  double price()
  {
   return electricity * 1.2 + water * 2.1 + gas * 1.5;
  }
};

CFlat N1(50, 15, 7, 50, 80);

void mainScreen()
{
 system("cls");
 cout << "Виберіть дію" << endl;
 cout << "1. Заселити мешканця" << endl;
 cout << "2. Переглянути імена мешканців" << endl;
 cout << "3. Переглянути кількість мешканців" << endl;
 cout << "4. Виселити мешканця" << endl;
 cout << "5. Переглянути поточний стан" << endl;
 cout << "6. Змінити стан" << endl;
 cout << "7. Розрахувати вартість" << endl;
 cout << "8. Вихід" << endl;
 int ch;
 cin >> ch;
 switch (ch)
 {
 case 1:
  system("cls");
  N1.addHuman();
  mainScreen();
 case 2:
  system("cls");
  N1.viewHuman();
  system("pause");
  mainScreen();
 case 3:
  system("cls");
  cout << "Кількість мешканців: " << N1.getCountPeople() << endl;
  system("pause");
  mainScreen();
 case 4:
  system("cls");
  N1.delHuman();
  mainScreen();
 case 5:
  system("cls");
  N1.currentstate();
  mainScreen();
 case 6:
  system("cls");
  int  time, Square, electricity, water, gas;
  cout << "Введіть термін експлуатації квартири: " << endl;
  cin >> time;
  cout << "Введіть площу: " << endl;
  cin >> Square;
  cout << "Введіть кількість спожитої електроенергії: " << endl;
  cin >> electricity;
  cout << "Введіть кількість спожитої води: " << endl;
  cin >> water;
  cout << "Введіть кількість спожитого газу: " << endl;
  cin >> gas;
  N1.setstate(time, Square, electricity, water, gas);
  mainScreen();
 case 7:
  system("cls");
  cout << "Вартість спожитих ресурсів: " << N1.price() << "грн" << endl;
  system("pause");
  mainScreen();
 default:
  exit(0);
 }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    mainScreen();
    return 0;
}
