#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct Date
{
    int day;
    char* month;
    int year;
};

struct FIO
{
    char* surname;
    char* name;
};

struct Credit
{
    struct Date vp;
    struct FIO gg;
    int number;
    double sum;
    int percent;
    int skam;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Menu(int* c)
{
    cout << "Диалоговое окно:" << endl;
    cout << "0)Не надо паники" << endl;
    cout << "1)Обновить таблицу" << endl;
    cout << "2)Добавить новый счет" << endl;
    cout << "3)Распечатать информацию о счете в табличном виде" << endl;
    cout << "4)Найти все счета  и общую сумму кредитов у заданного клиента (клиент – это фамилия + имя), результат вывести на экран;" << endl;
    cout << "5)Определить всех клиентов с заданным процентом по кредиту" << endl;
    cout << "6)Поиск клиентов с просроченными платежами" << endl;
    cout << "7)Сохранить" << endl;
    cout << "8)Завершить работу" << endl;
    cout << "Введите число от 1 до 8" << endl;
    cin >> *(c);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Zero(Credit* Obj, int amount){

    ofstream m2;

    cout << setw(5) << setprecision(3) << "Номер счета\t"<< ' '
         << setw(15)<< setprecision(3) << "Фамилия"
         << setw(15)<< setprecision(3) << "Имя\t"
         << setw(18) << setprecision(3) << "Сумма кредита\t"
         << setw(12) << setprecision(3) << "Процент по окредиту\t"
         << setw(12) << setprecision(3) << "Число\t"
         << setw(15) << setprecision(3) << "Месяц\t"
         << setw(12) << setprecision(3) << "Год\t"
         << setw(12) << setprecision(3) << "Срок возврата\t" << endl;

    string line;
    ifstream myfile("/Users/mak71m/Desktop/m2.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            cout << line << endl;
        }
        myfile.close();
    }

    else cout << "Сломався...(";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Seven(Credit* Obj, int amount) {
        ifstream m1;
        m1.open("/Users/mak71m/Desktop/m1.txt", ios::out);
        ofstream m2;
        m2.open("/Users/mak71m/Desktop/m2.txt", ios::app);
        string line;

        if (m1.is_open())
        {
            while (! m1.eof() )
            {
                getline (m1,line);
                m2 << line << endl;
            }
            m1.close();
            m2.close();
        }
        else cout << "Сломався...(";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Three(Credit* Obj, int amount)
{
    int s;
    cout << "Введите номер счета:" << endl;
    cin >> s;
    while(s<=0)
    {
        cout << "Введите номер счета (положительное число):" << endl;
        cin >> s;
    }
    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].number == s)
        {
            cout << setw(12)<< setprecision(3) << "Фамилия\t"
            << setw(13)<< setprecision(3) << "Имя\t" << ' '
            << setw(18) << setprecision(3) << "Сумма кредита\t"
            << setw(12) << setprecision(3) << "Процент по окредиту\t" << endl;
            cout << "====================================================="<< endl;
            cout << setw(7) << setprecision(3) << Obj[i].gg.surname << '\t'
            << setw(15)<< setprecision(3) <<Obj[i].gg.name << '\t'
            << setw(8) << setprecision(3) << Obj[i].sum << '\t'
            <<setw(12)<<setprecision(3)<< Obj[i].percent << endl;
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Four(Credit* Obj, int amount)
{
    int Summa = 0;
    char n[32];
    cout << "Введите фамилию:" << endl;
    cin.get();
    cin.getline(n, 32, '\n');


    char m[32];
    cout << "Введите имя:" << endl;
    cin.getline(m, 32, '\n');


    cout << "Все счета:" << endl;
    for (int i = 0; i < amount; i++)
    {
        if (strcmp(Obj[i].gg.surname, n) == 0 && strcmp(Obj[i].gg.name, m) == 0)
        {
            cout << Obj[i].number << endl;
            cout << "========================" << endl;
            Summa += Obj[i].sum;
        }
    }
    cout << "Сумма всех кредитов = " << Summa << endl << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Five(Credit* Obj, int amount) {
    int k;
    cout << "Введите процент:" << endl;
    cin >> k;
    while(k<=0)
    {
        cout << "Введите процент (положительное число):" << endl;
        cin >> k;
    }
    int counter = 0;
    cout << setw(10) << setprecision(3) << "Фамилия\t"
    << setw(15) << setprecision(3) << "Имя\t" << endl;
    for (int i = 0; i < amount; i++) {
        if (Obj[i].percent == k) {
            counter++;
            cout << setw(6) << setprecision(3) << Obj[i].gg.surname << '\t'
            << setw(17) << setprecision(3) << Obj[i].gg.name
                 << endl;
            cout << "====================================" << endl;
        }
    }
    string *array = new string[counter];
    for (int i = 0; i < amount; i++) {
        if (Obj[i].percent == k) {
            array[i] = Obj[i].gg.surname;
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//bool Dolg(Credit* Obj, int amount)
//{
//    return (c == (Obj[i].vp.year + y) and b == m and a > Obj[i].vp.day) or (c == (Obj[i].vp.year + y) and b > m) or c > (Obj[i].vp.year + y);
//}

void Six(Credit* Obj, int amount)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    for (int i = 0; i < amount; i++){
        int k;
        int m = stoi(Obj[i].vp.month)+Obj[i].skam;
        int y=0;
        if (m>12){
            y+=m/12;
            m=abs(m-12*y);
            if (m>=12){
                k=m/12;
                y+=k;
                m=m%12;
            }
        }
        int a=ltm->tm_mday;
        int b=(ltm->tm_mon)+1;
        int c=(ltm->tm_year)+1900;
        if (m > 12) {
            m = m % 12;
        }

        if ((c == (Obj[i].vp.year + y) and b == m and a > Obj[i].vp.day) or (c == (Obj[i].vp.year + y) and b > m) or c > (Obj[i].vp.year + y))
        {

            cout << "Номер: " << Obj[i].number << endl;
            cout << "Фамилия: " << Obj[i].gg.surname << endl;
            cout << "Имя: " << Obj[i].gg.name << endl;
        }
        else cout<< "Должников нет" <<endl;
    }
    cout<<"*************************************************"<<"\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Credit* AddStruct(Credit* Obj,int amount)
{
    if (amount == 0)
    {
        Obj = new Credit[amount + 1];
    }
    else
    {
        Credit* tempObj = new Credit[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i];
        }
        delete[] Obj;

        Obj = tempObj;
    }
    return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Input(Credit* Obj,int amount)
{
    cout << "Номер счета: ";
    cin >> Obj[amount].number;
    while(Obj[amount].number<=0)
    {
        cout << "Номер счета (положительное число): ";
        cin >> Obj[amount].number;
    }

    cout << "Фамилия: ";
    cin.get();
    Obj[amount].gg.surname=new char[30];
    cin.getline(Obj[amount].gg.surname, 32);

    cout << "Имя: ";
    Obj[amount].gg.name=new char[30];
    cin.getline(Obj[amount].gg.name, 32);

    cout << "Сумма кредита: ";
    cin >> Obj[amount].sum;
    while(Obj[amount].sum<=0)
    {
        cout << "Сумма кредита (положительное число): ";
        cin >> Obj[amount].sum;
    }

    cout << "Процент по кредиту: ";
    cin >> Obj[amount].percent;
    while(Obj[amount].percent<=0)
    {
        cout << "Процент по кредиту (положительное число): ";
        cin >> Obj[amount].percent;
    }

    cout << "Число: ";
    cin >> Obj[amount].vp.day;
    while(Obj[amount].vp.day<=0)
    {
        cout << "Число (положительное число): ";
        cin >> Obj[amount].vp.day;
    }

    cout << "1-Январь 2-Февраль 3-Март 4-Апрель "
            "5-Май 6-Июнь 7-Июль 8-Август "
            "9-Сентябрь 10-Октябрь 11-Ноябрь 12-Декабрь\n"
            "Номер месяца: ";
    Obj[amount].vp.month=new char[30];
    cin.get();
    cin.getline(Obj[amount].vp.month, 32);
    while(stoi(Obj[amount].vp.month)<=0 or stoi(Obj[amount].vp.month)>12)
    {
        cout << "1-Январь 2-Февраль 3-Март 4-Апрель "
                "5-Май 6-Июнь 7-Июль 8-Август "
                "9-Сентябрь 10-Октябрь 11-Ноябрь 12-Декабрь\n"
                "Номер месяца: ";
        Obj[amount].vp.month=new char[30];
        cin.getline(Obj[amount].vp.month, 32);
    }

    cout << "Год: ";
    cin >> Obj[amount].vp.year;
    while(Obj[amount].vp.year<=0)
    {
        cout << "Год (положительное число): ";
        cin >> Obj[amount].vp.year;
    }

    cout << "Срок возврата(в месяцах): ";
    cin >> Obj[amount].skam;
    while(Obj[amount].skam<=0)
    {
        cout << "Срок возврата (положительное число): ";
        cin >> Obj[amount].skam;
    }
    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Conclusion(Credit* Obj,int amount)
{
    ofstream m1;
    m1.open("/Users/mak71m/Desktop/m1.txt", ios::out);

    cout << setw(5) << setprecision(3) << "Номер счета\t"<< ' '
         << setw(15)<< setprecision(3) << "Фамилия"
         << setw(15)<< setprecision(3) << "Имя\t"
         << setw(18) << setprecision(3) << "Сумма кредита\t"
         << setw(12) << setprecision(3) << "Процент по окредиту\t"
         << setw(12) << setprecision(3) << "Число\t"
         << setw(15) << setprecision(3) << "Месяц\t"
         << setw(12) << setprecision(3) << "Год\t"
         << setw(12) << setprecision(3) << "Срок возврата\t" << endl;

    cout << "==============================================================================================================================" << endl;

    for (int i = 0; i < amount; i++)
    {
        cout << setw(5) << setprecision(3) <<  Obj[i].number
            << setw(16) << setprecision(3) << Obj[i].gg.surname
            << '\t' << setw(8)<< setprecision(3) <<Obj[i].gg.name
            << '\t'<< setw(9) << setprecision(5) << Obj[i].sum
            << '\t' <<setw(12)<<setprecision(3)<< Obj[i].percent
            << '\t' <<setw(12)<<setprecision(3)<< Obj[i].vp.day
            << '\t' <<setw(9)<<setprecision(3)<< Obj[i].vp.month
            << '\t' <<setw(9)<<setprecision(3)<< Obj[i].vp.year
            << '\t' <<setw(8)<<setprecision(3)<< Obj[i].skam<< endl;

        m1 << setw(5) << setprecision(3) <<  Obj[i].number
            << setw(16) << setprecision(3) << Obj[i].gg.surname
            << '\t' << setw(8)<< setprecision(3) <<Obj[i].gg.name
            << '\t'<< setw(9) << setprecision(5) << Obj[i].sum
            << '\t' <<setw(12)<<setprecision(3)<< Obj[i].percent
            << '\t' <<setw(12)<<setprecision(3)<< Obj[i].vp.day
            << '\t' <<setw(9)<<setprecision(3)<< Obj[i].vp.month
            << '\t' <<setw(9)<<setprecision(3)<< Obj[i].vp.year
            << '\t' <<setw(8)<<setprecision(3)<< Obj[i].skam<< endl;
    }
    m1.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
    setlocale(LC_ALL, "rus");
    Credit* OurCredit = 0;
    int creditAmount = 0;
    int YesOrNot = 0;

    do
    {
        OurCredit = AddStruct(OurCredit, creditAmount);
        Input(OurCredit, creditAmount);
        creditAmount++;
        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
        cin.get();
    } while (YesOrNot != 0);

    Conclusion(OurCredit, creditAmount);
    int c;
    do {
        Menu(&c);
        switch (c)
        {
            case 0:
                Zero(OurCredit,creditAmount);
                break;
            case 1:
                Conclusion(OurCredit, creditAmount);
                break;
            case 2:
                OurCredit = AddStruct(OurCredit, creditAmount);
                Input(OurCredit, creditAmount);
                creditAmount++;
                break;
            case 3:
                Three(OurCredit,creditAmount);
                break;
            case 4:
                Four(OurCredit, creditAmount);
                break;
            case 5:
                Five(OurCredit, creditAmount);
                break;
            case 6:
                Six(OurCredit, creditAmount);
                break;
            case 7:
                Seven(OurCredit, creditAmount);
                break;
        }

    } while (c!=8);
    return 0;
}