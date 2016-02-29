/*
    Краткое описание основных циклов.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
    Ниже представленная функция демонстрирует использование логического выражения.
*/
double sum_or_substract(double number1, double number2)
{
    double result;

    /*
        В языке С++ аналогично С любое значение считается истинным за исключением нуля (и значений, которые могут быть приведены к нулю).
        В тоже время, был введён специальный тип данных - bool (логический тип данных, имеющий два значений - истина и ложь.
        Переменная типа bool может быть равна двум значения - true и false.

        В языке определены следующие операторы сравнения: ==, >, <, >=, <=, !=. (равенство, больше, меньше, больше или равно, меньше или равно, неравенство). Например, a != b, num1 == num2, num1 >= num2. Данные операторы возращают 1, если условие выполняется и 0 в противоположном случае.

        В логических выражениях условия могут комбинироваться с помощью двух логических операторов:
            && - логическое и;
            || - логическое или.

        Также существует унарный оператор отрицания: !. Выражение вида "!a" можно читать как "not a".
        Например:
            int a = 1;
            if ( !a ) { printf("a is equal to zero"); } // данная строка не напечатается, поскольку значение 1 считается за истину, а её отрицание образует ложное утверждение (фактически, !a == 1).
            if ( !!a ) { printf("a is not zero") } // а эта - напечатается, поскольку !a == 0, а !(!a) == 1.

    */
    if ( (number1 > 0 && number2 < number1) || (number2 + number1 < 25) ) {
        result = number1 + number2;
    } else {
        result = number2 - number1;
    }


    return result;
}


/*
    Небольшая функция для демонстрации тернарного оператора: "?:". Его общая форма может быть представлена в виде:
        <условие> ? <значение, когда истинное> : <значение, когда ложное>;

    Обычно используется при присвоении переменных, когда условие не слишком велико для записи и когда нужно выбрать одно из двух значений.
    Для сложных условий использование выражения if ... else - предпочтительнее.
*/
int dummy_random(int number)
{
    // круглые скобки являются опциональными
    return ( number > 30 ) ? 7 : 4;
}


int main()
{
    int number;
    /*
        Ниже приводятся примеры и кратокое описание всех имеющихся в языке циклов.
        В качестве примера приводится проверка, является ли введённое пользователем целое число - простым.
    */
    cout << "Enter the number: ";
    cin >> number;

    // несколько разных иструкций можно в if-выражении записать и так:
    if ( number < 0 ) { cout << "Number must be positive"; return 0; }
    // но лучше не лениться переносить инструкции выражений
    if ( number <= 3 ) {
        cout << "Number is prime";
        return 0;
    }


    /*
        Цикл for.
        Общая форма:
            for (<инициализация>; <условие выхода>; <действия на каждой итерации>)
                <тело цикла>

        Обязательными являются только два значка точки с запятой - ";".
            <инициализация> - набор выражений, которые будут выполнены один раз до начала исполнения цикла for.
            <условие выхода> - логическое выражение, условие прекращения итераций цикла.
            <действия на каждой итерации> - выражения, вычисляющиеся на каждой итерации.
        Пример:
            for (int i = 0; i < 10; i++)
                cout << "i*i = ", i * i << endl;

        В первом и последнем блоках могут стоять более чем одно выражение, разделённые запятой. Пример:
            for (int x = 0, int y = 10; (x <= 10) && (y > -2); x += 2, y -= 3)
                cout << "x = " << x << ", y = " << y << endl;

        Цикл for без трёх блоков представляет собой бесконечный цикл:
            for (;;)
                cout << "*"; // данному циклу никогда не надоест печатать звёздочку.

        Для управления ходом цикла используются ключевые слова: continue и break.
            continue - принудительно начинает слудующую операцию
            brteak   - принудительно завершает цикл.

        Как пример:
            int i;
            for (i = 0; i < 100; i++) {
                if ( i % 2 == 0 ) continue; // пропускаем чётные числа
                if ( i > 88 ) break; // принудительно прерываем цикл до выполнения условия выхода
            }

        Далее - проверка является ли число простым через цикл for.
    */

    // В отличие от классического паскаля, переменные в С++ могут быть объявлены в любом месте функции
    int denominator;
    bool is_prime = true;

    // ниже int( sqrt(number) ) - это преобразование вещественного числа, получаемого функцией взятия квадрата sqrt, в целое
    // путём отсекания дробной части. Важно: округление не используется.
    // В С такое преобразование типов записывается так: (int) sqrt(number). Такую форму можно использовать и в С++
    for (denominator = 2; denominator <=  int( sqrt(number) ); denominator++) {
        if ( (number % denominator) == 0) {
            cout << "Number " << number << " is not prime, denominator is " << denominator << endl << endl;
            is_prime = false;
            break;
        }
    }
    if ( is_prime ) {
        cout << "Number " << number <<" is prime" << endl << endl;
    }

    /*
        Цикл while:
            while ( <условие> )
                <тело цикла>

        Данный цикл исполняет выражения в его теле до тех пор, пока <условие> не стане ложным. Несколько примеров:

            while (1)
                printf("$"); // бесконечный цикл

            while (0)
                printf("$"); // бессмысленный цикл, printf не выполнится никогда

        Аналогично циклу for могут применяться инструкции break / continue.
    */
    is_prime = 1;
    denominator = 2;
    while ( denominator <= (int) sqrt(number) ) {
        if ( (number % denominator) == 0) {
            cout << "Number " << number << " is not prime, denominator is " << denominator << endl << endl;
            is_prime = false;
            break;
        }
        denominator++;
    }
    if ( is_prime ) {
        cout << "Number " << number <<" is prime" << endl << endl;
    }


    /*
        Цикл do ... while:

            do
              <тело цикла>
            while ( <условие> );

        Аналогичен while за исключением того, что данные цикл гарантирует, что как минимум одна итерация будет выполнена.
        Примеры:

            int i = 0;
            // можно писать без заключения тела цикла в блок {...}
            do
                printf("i = %d\n", i);
            while ( i++ < 10 );

            // однако, такой синтаксис компилятор не пропустит
            i = 0;
            do
                printf("i = %d\n", i);
                i++;
            while ( i < 10 );

            // поэтому одна из лучших форм с точки зрения читаемости:
            do {
                printf("i = %d\n", i);
                i++;
            } while ( i < 10 );
    */
    is_prime = 1;
    denominator = 2;
    do {
        if ( (number % denominator) == 0) {
            cout << "Number " << number << " is not prime, denominator is " << denominator << endl << endl;
            is_prime = false;
            break;
        }
        denominator++;
    } while ( denominator <= int( sqrt(number) ) );
    if ( is_prime ) {
        cout << "Number " << number <<" is prime" << endl << endl;
    }

    return 0;
}