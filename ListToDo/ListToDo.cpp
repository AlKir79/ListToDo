// ListToDo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
using namespace std;

//struct dte
//{
//    int day;
//    int mounth;
//    int year;
//};
//
//struct tme
//{
//    int hour;
//    int min;
//};

struct ToDo
{
    char title[20]=" ";
    int prioritet =0;
    char description[30] = " ";
    char dte;
    char tme;
};

void sortPrior(ToDo* arr, int& size)
{
    ToDo temp;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size-i; j++)
        {
            if (arr[j].prioritet < arr[j + 1].prioritet) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//void sortDate(ToDo* arr, int& size)
//{
//    ToDo temp;
//    for (size_t i = 0; i < size; i++)
//    {
//        for (size_t j = 0; j < size - i; j++)
//        {
//            if (arr[j].dte < arr[j + 1].dte)
//            {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
void printList(ToDo* list, int& size, bool& sortDay, int& spisok)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << list[i].title << "  " << list[i].prioritet << "  " << list[i].description << "  " << list[i].dte << "  " << list[i].tme;
        cout << endl;
    }
}
void addDeal(ToDo* arr, int& size)
{
    system("cls");
    ToDo* temp = new ToDo[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    cout << "====== Планирование новой задачи ======" << endl;
    cout << endl;
    cout << "Введите название задачи (не более 20 символов)";
    cin.getline(temp[size].title, 20);
    cout << "Введите описание задачи (не более 30 символов)";
    cin.getline(temp[size].description, 20);
    cout << "Введите приоритет задачи (от 1 до 10)";
    cin>> temp[size].prioritet;
    //cout << "Введите дату выполнения задачи";
    //cin.getline(temp[size].dte, 20);
    //cout << "Введите время выполнения задачи";
    //cin.getline(temp[size].tme, 20);
    delete[] arr;
    arr = temp;
    size++;
}

void delDeal(ToDo* arr, int& size)
{
    if (size == 0) { cout << "У Вас нет списка дел!" << endl; return; }
    ToDo* temp = new ToDo[size-1];
    int str;
    int count = 0;
    cout << "Введите номер строки, которую хотите удалить";
    cin >> str; str++;
    for (size_t i = 0; i < size; i++)
    {
        if (i == str) continue;
        temp[count] = arr[i];
        count++;
    }
    delete[]arr;
    arr = temp;
    size--;
}

void reFreshConsole(ToDo* list, int& size, bool& sortDay, int& spisok)
{
    char x;
    system("cls");
    cout << "=============== Список задач ================" << endl << endl;
    cout << "1 - Добавить   2 - Удалить   3 - Редактировать   ";
    if (sortDay) cout << "4 - Сортировка приоритет   ";
    else cout << "4 - Сортировка день/время  ";
    if (spisok == 1) cout << "5 - Список день ";
    if (spisok == 2) cout << "5 - Список месяц";
    if (spisok == 3) cout << "5 - Список год  ";
    cout << "6 - Выход";
    cout << endl << endl;
    cout << "====================================================================================================="<< endl;
    cout << "| Название           |  Приоритет | Описание                               | Дата      | Время      |" << endl;
    printList(list, size, sortDay, spisok);
    x =_getch();
 //   cin >> x;
    if (x == '1') { addDeal(list, size); reFreshConsole(list, size, sortDay, spisok); }
    if (x == '2') { delDeal(list,size); reFreshConsole(list, size, sortDay, spisok); }
  //  if (x == '3') editDeal;
//    if (x == '4') { sortDay = !sortDay; sortDate(list, size); reFreshConsole(list, size, sortDay, spisok); }
    if (x == '5') {
        spisok++;
        if (spisok == 4) spisok = 1;
        sortPrior(list, size);
        reFreshConsole(list, size, sortDay, spisok);
    }
}
int main()
{
    bool sortDay = true;
    int spisok = 1;
    int size = 1;
    ToDo* list = new ToDo[size];
    setlocale(LC_ALL,"");
    reFreshConsole(list, size, sortDay,spisok);
}

