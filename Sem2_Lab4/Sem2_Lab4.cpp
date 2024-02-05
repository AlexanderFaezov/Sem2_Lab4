#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    using namespace std;

    const int n = 10;
    int a[n];
    int k;
    int temp;
    int max;
    int maxCount = 0;

    cout << "Введите k: ";
    cin >> k;

    //Заполнение массива рандомными значениями
    srand(time(0));
    cout << "Начальный массив: ";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << " ";
    }
    cout << endl;

    //Реазилация двунаправленного колца
    //кольцо влево
    cout << "Кольцо влево:     ";
    for (int i = 0; i < k; i++)
    {
        temp = a[0];
        for (int j = 0; j < (n-1); j++)
        {
            a[j] = a[j + 1];
        }
        a[n - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    max = a[0];
    //Удаление совпадающих максимальных значений
    //Нахождение максимального числа
    for (int i = 0; i < n; i++)
    {
        if (max <= a[i])
        {
            max = a[i];
        }
    }
    cout << "Максимальное число: " << max << endl;
    //Удаление повторяющегося максимального числа
    for (int i = 0; i < n; i++)
    {
        if (a[i] == max)
        {
            if (maxCount > 0)
            {
                a[i] = 0;
            }
            maxCount++;
        }
    }

    //кольцо вправо
    cout << "Кольцо вправо:    ";
    for (int i = 0; i < k; i++)
    {
        temp = a[n-1];
        for (int j = n-1; j > 0; j--)
        {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

}