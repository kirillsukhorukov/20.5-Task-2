#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Функция ввода и проверки целого положительного числа
int int_input()
{
    string str;
    bool error = false;
    do
    {
        //Сброс ошибки
        error = false;

        getline(cin, str);

        //Проверка длины строки с числом
        if (str.length() > 9)
        {
            cerr << "Error! Repeat input." << endl;
            error = true;
        }
        else 
        {
            //Проверка что все символы являются числами
            for (int i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                {
                    cerr << "Error! Repeat input." << endl;
                    error = true;
                    i = str.length() - 1;
                }
            }
        }
    } while (error);
    
    //Возврат целого числа
    int num = stoi(str);
    return num;
}

//Функция ввода размера картины (введено ограничение максимального размера maxSize)
void size_input (int &width, int &height)
{
    //флаг ошибки ввода
    bool error = false;
    
    //Ограничение максимального размера картинки
    int maxSize=1000;
    
    //Ввод ширины картины
    do
    {
        //Сброс ошибки
        error = false;

        //Ввод и проверка ширины картины
        cout << "Enter the width of the painting in pixels (from 1 to " << maxSize << "): ";
        width = int_input();
        if (width<1 || width>maxSize)
        {
            cerr << "The width of the picture is entered incorrectly. Retype!" << endl;
            error=true;
        }
    } while (error);
    
    //Ввод высоты картины
    do
    {
        //Сброс ошибки
        error = false;

        //Ввод и проверка высоты картины
        cout << "Enter the height of the painting in pixels (from 1 to " << maxSize << "): ";
        height = int_input();
        if (height<1 || height>maxSize)
        {
            cerr << "The height of the picture is entered incorrectly. Retype!" << endl;
            error=true;
        }
    } while (error);
    
    
}

//Функция записи случайных чисел в файл
void draw_rand (ofstream &file,  int const &width, int const &height)
{
    //Открытие файла
    file.open ("pic.txt", ios::binary);

    //Проверка что файл открыт
    file.is_open() ? cout << endl <<"---Data recorded!---\n" << endl : cerr << "---Data not recorded! File not found!---\n" << endl;

    //Запись в файл случайных чисел
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            bool pixel = rand()%2;
            file << pixel;
        }
        file << endl;
    }
    
    //Закрытие файла
    file.close();
}

int main()
{
    cout <<"-----Program for drawing random pictures-----\n" << endl;

    //Задание начального зерна случайных чисел
    srand(time(nullptr));

    int width=1;
    int height=1;

    //Вызов функции ввода ширины и высоты картины
    size_input (width, height);

    ofstream pic;
    
    //Вызов функции рисования картины
    draw_rand (pic, width, height);

    cout << endl << "Program completed. Press any key...";
    cin.get();
}