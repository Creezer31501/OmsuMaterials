/*
    Основной материал по основам указателей в C/C++ расположен по адресу: https://github.com/posgen/OmsuMaterials/wiki/Variables-and-ponters:-basic

    Желательно ознакомиться с файлом part1_pointers.cpp в той же директории, что и данный файл.

    Теория повторяет файл part2_dynamic_array.cpp, за исключением раздела про выделение динамической памяти.

    Для повторения: массив - это набор элементов, к каждому из которых имеется доступ по индексу.
    В языке C++ массиивы являются:
        1) типизированными, то есть могут содержать в себе только элементы одного конкретного типа (int, float, double, char);
        2) непрерывно расположенными в памяти. Гарантируется, что все элементы массива идут друг за другом в некотором блоке оперативной памяти.

    Пункт 2) позволяет использовать указатели для работы с масивами.
    Рассмотрим статический массив целых чисел из 5 элементов:
        int arr[] = {1, 3, 5, 7, 9};

    Графически расположение этого массива в памяти можно представить вот так (для тех, кому лень было статью выше открывать):
        < 1 >< 3 >< 5 >< 7 >< 9 >
    Здесь треугольные скобки означают блок памяти, необходимый для хранения переменной определённого типа. В примере - тип int.
    То есть - это не синтаксис языка, это просто ассоциативная картинка. И она как раз показывает тот факт, что все
    элементы расположены в памяти последовательно. Размер конкретного блока равен размеру переменной конкретного типа.

    Каждый отдельный элемент массива - arr[0], arr[1], arr[2] - по сути является отдельной переменной, поэтому
    у него можно получить адрес. А раз можно получить адрес, значит можно сохранить его в указатель
        int *p_arr;
        p_arr = &arr[1];

    Здесь мы записываем адрес второго (arr[1]) элемента массива в указатель p_arr. Теперь всё выглядит примерно так:
        < 1 >< 3 >< 5 >< 7 >< 9 >
             ^
             |
           p_arr

    Через указатель p_arr и его разыменование можно изменить значение конкретного элемента массива, но всё это уже было (pointers.c).

    Следующая операция, применяемая к указателям - прибавление целого числа (как положительного, так и отрицательного).
    Например:
        p_arr++; // или p_arr += 1;

    В этом случае адрес указателя меняется путём прибавления к нему sizeof(int) байт. И p_arr теперь указывает на
    третий элемент массива:
        < 1 >< 3 >< 5 >< 7 >< 9 >
                  ^
                  |
                p_arr

    При прибавлении отрицательного числа (или вычитании положительного), адрес указателя уменьшается на
    соотвествующее число байт. Так
        p_arr -= 2; // отнимаем целое число 2 от значения указателя
    приводит к тому, что в p_arr хранится адрес первого элемента массива arr:
        < 1 >< 3 >< 5 >< 7 >< 9 >
        ^
        |
      p_arr

    Здесь стоит добавить, что за изменением адресов памяти должен следить только автор программы, сам язык
    не проверяет - содержит ли указатель корректный адрес или нет.

    Далее следует следующий факт: переменная статического массива (в рассматриваемом случае - arr) по сути
    является постоянным (в смысле - неизменным) указателем на первый элемент массива. То есть:
        < 1 >< 3 >< 5 >< 7 >< 9 >
        ^
        |
       arr

    Это легко подтверждается, попыткой вывести адрес:
        cout << "The address of arr is " << arr << endl;
        cout << "The address of first element is " << &arr[0] << endl;
    Обе функции printf выведут один и тот же адрес.

    То, что arr является неизменным указателем на первый элемент массива, приводит к следующщему сакральному знанию,
    почему индексы элементов начинаются с нуля: фактически индекс является смещением на определённое количество байт
    относительно первого элемента массива.

    Операция индексации применима и к указателю:
        p_arr[0];
        p_arr[1];
    Причём, сам язык не делает никаких проверок - действительно ли ваш указатель связан с массивом или нет.
    Индексация и разыменование указателей связаны следующим образом:
        p_arr[1] это *(p_arr + 1) // что означает прибавление целого числа к указателю - смотреть выше.

    ************************************************************

    Динамические массивы.

    Статические массивы - это неплохо, но не всегда возможно определить - какого размера понадобится массив под конкретную задачу.
    Для решения этой проблемы, язык С++ предоставляет операторы для динамического выделения блоков памяти. Формально,
    они объявлены в заголовочном файле <new>. Однако, он неявно подставляется в любую программу на C++, так что нет
    особой необходимости указывать его в явном виде. Основными операторами выделения динамической памяти являются:
        new и new[] - это разные штуки.

    Они объявляются как:
        new <type> - выделение динамической памяти под одну переменную типа type. В отличии от C, не нужно
                    высчитывать конкретный размер памяти.

        new <type>[size] - выделение динамической памяти под массив из size элементов типа type


    Освобождается память (удаляется ранее выделенный блок памяти) с помощью операторов delete и delete[]:
        delete *ptr - если для выделения использвался new
        delete[] * ptr - если для выделения использовался new[]

    В тоже время, функции malloc/calloc/realloc/free доступны в C++ через стандартную библиотеку C. Объявлены они
    в заголовочном файле <cstdlib>. Однако, не следует смешивать между собой выделение памяти C-ными функциями
    и освобождение C++-операторами. И наоборот.
*/

#include <iostream>
#include <cstdlib> // используется для функций srand, rand
#include <ctime> // используется для инициализации генератора псевдослучайных чисел

using namespace std;

void examples_with_static_arrays()
{
    // Определяем статический массив и указатель на int
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *p_int;

    // записываем в p_int адрес пятого элемента
    p_int = &arr[4];

    // печатаем пятый элемент через указатель и разыменование
    cout << "Current value of p_int is " << *p_int << endl;

    // печатаем седьмой элемент через указатель и индексацию
    // p_int[2] - сдвиг вправо на 2 позиции относительно начального положения p_int
    cout << "Current value of p_int[2] is " << p_int[2] << endl;

    // печатаем четвёртый элемент через указатель и индексацию. Да, индекс может быть отрицательным
    cout << "Current value of p_int[-1] is " << p_int[-1] << endl;
}

// Передаём в функцию 2 аргумента: размер массива типа float и размер массива типа int
void examples_of_dynamic_arrays(unsigned int float_arr_size, unsigned int int_arr_size)
{
    // Для работы с динамическим массивом необходим указатель
    float *f_arr;
    int *i_arr1;
    unsigned int index;

    /*
        Выделяем блок памяти под массив из float_arr_size элементов.

        В современном C++, вместо C-шного макроса NULL было введено ключевое слово nullptr для обозначения
        нулевого указателя.

        Ниже используется также конструкция - (nothrow). Она связана с механизмом исключений в C++.
        В данном случае, гарантируется, что если память невозможно выделить, будет возращён нулевой указатель
    */
    f_arr = new (nothrow) float[float_arr_size];
    if ( f_arr == nullptr ) {
        cerr << "Error with memory initialization (1)"; // печатаем сообщение в стандартный поток для ошибок
        return; // выходим принудительно из функции
    }

    // Аналогичное выделение динамического массива под массив типа int
    i_arr1 = new (nothrow) int[int_arr_size];
    if ( i_arr1 == nullptr) {
        delete[] f_arr; // если до сюда дошло, то массив под f_arr был выделен успешно, поэтому надо его удалить из памяти
        cerr << "Error with memory initialization (2)"; // печатаем сообщение в стандартный поток для ошибок
        return; // выходим принудительно из функции
    }

    // заполняем и печатаем выше выделенные массивы значениями
    cout << "\nFloat array:\n";
    for (index = 0; index < float_arr_size; ++index) {
        f_arr[index] = (float) rand() / RAND_MAX; // используется явное приведение к типу float - (float) - для того,
                                                  // чтобы операция деления была не целочисленной
        cout << f_arr[index] << " ";
    }

    cout << "\nInt array:\n";
    for (index = 0; index < int_arr_size; ++index) {
        i_arr1[index] = rand() % 55;

        cout << "i_arr1[" << index << "] = " << i_arr1[index] << endl;
    }

    // Освобождение памяти
    delete[] f_arr;
    delete[] i_arr1;
}

int main()
{
    srand( time(nullptr) );
    examples_with_static_arrays();

    examples_of_dynamic_arrays(10, 20);
    return 0;
}