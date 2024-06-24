#include <iostream>
#include <vector>
#include <algorithm>
#include <memory> // Для использования умных указателей
#include <thread>
#include <future>
#include <tuple>
#include <chrono>
#include <functional>
#include <initializer_list> 

// C++11: больше необязательно добавлять пробелы между закрывающими угловыми скобками
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "Matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// C++11: Лямбда-функция и auto
void lambdaExample() {
    auto vec = std::vector<int>{ 1, 2, 3, 4, 5 }; //auto позволяет компилятору выводить тип переменной, упрощая синтаксис и уменьшая количество шаблонного кода
    std::for_each(vec.begin(), vec.end(), [](int n) { //Лямбда-функции позволяют определять анонимные функции, улучшая читаемость и локализацию кода
        std::cout << n << " ";
        });
    std::cout << std::endl;
}

// C++11: Умный указатель std::unique_ptr
void uniquePtrExample() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10); //std::unique_ptr автоматически управляет временем жизни динамически выделенного объекта, предотвращая утечки памяти
    std::cout << "Unique Ptr value: " << *ptr << std::endl;
}

// C++11: Многопоточность std::thread
void threadExample() {
    auto hello = []() {
        std::cout << "Hello from thread!" << std::endl;
        };
    std::thread t(hello); //std::thread предоставляет простой и переносимый интерфейс для создания и управления потоками, улучшая поддержку многозадачности
    t.join(); // Ждем завершения потока
}

// C++11: std::async и std::future позволяют запускать задачи асинхронно и получать их результаты, улучшая поддержку асинхронного программирования
void asyncFutureExample() {
    auto asyncTask = [](int x) -> int {
        return x * x;
        };
    std::future<int> result = std::async(std::launch::async, asyncTask, 5);
    std::cout << "Async result: " << result.get() << std::endl;
}

// C++11: std::tuple
void tupleExample() {
    std::tuple<int, std::string, double> t = std::make_tuple(1, "Hello", 3.14); //std::tuple позволяет хранить несколько значений разных типов вместе и предоставляет удобные методы для доступа к ним
    std::cout << "Tuple values: " << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << std::endl;
}

// C++11: std::chrono предоставляет удобные и типобезопасные методы для работы с временем и временными интервалами
void chronoExample() {
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}

// C++11: std::function позволяет хранить и вызывать любые функциональные объекты, включая лямбда-функции и указатели на функции
void functionExample() {
    std::function<int(int, int)> add = [](int a, int b) {
        return a + b;
        };
    std::cout << "Function result: " << add(2, 3) << std::endl;
}

// C++11: Инициализаторы списков позволяют легко инициализировать контейнеры и другие агрегаты значениями, улучшая читаемость и удобство кода
void initializerListExample() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

// C++14: Усовершенствованные возвращаемые типы функций
auto autoReturnTypeExample() { //auto в возвращаемых типах функций позволяет компилятору выводить тип возвращаемого значения, упрощая определение функций
    return 42;
}

// C++14: Обобщённые захваты переменных в лямбда-выражениях позволяют захватывать переменные в лямбда-функциях с помощью более сложных выражений, улучшая гибкость и читаемость кода
void generalizedLambdaCaptureExample() {
    int x = 10;
    auto lambda = [y = x + 1]() {
        std::cout << "Captured value: " << y << std::endl;
        };
    lambda();
}

int main() {

    // Двоичные литералы: удобный способ представления base-2 чисел с разделителем ' (C++14)
    0b110; // (== 6)
    0b1111'1111; // (== 255) улучшает читаемость двоичного числа

    // Демонстрация вложенного вектора без пробелов между закрывающими угловыми скобками (C++11)
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Вызов функции для вывода элементов матрицы
    printMatrix(matrix);

    // Демонстрация лямбда-функции и auto (C++11)
    lambdaExample();

    // Демонстрация умного указателя std::unique_ptr (C++11)
    uniquePtrExample();

    // Демонстрация многопоточности std::thread (C++11)
    threadExample();

    // Демонстрация std::async и std::future (C++11)
    asyncFutureExample();

    // Демонстрация std::tuple (C++11)
    tupleExample();

    // Демонстрация std::chrono (C++11)
    chronoExample();

    // Демонстрация std::function (C++11)
    functionExample();

    // Демонстрация инициализаторов списков (C++11)
    initializerListExample();

    // Демонстрация усовершенствованных возвращаемых типов функций (C++14)
    std::cout << "Auto return type result: " << autoReturnTypeExample() << std::endl;

    // Демонстрация обобщённых захватов переменных в лямбда-выражениях (C++14)
    generalizedLambdaCaptureExample();

    return 0;
}
