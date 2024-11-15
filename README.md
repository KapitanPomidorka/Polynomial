# Polynomial
Exercises (C++)
Задача для С++. Реализуйте шаблонный класс Polynomial (Многочлен от одной переменной) на основе контейнера std::vector. Тип коэффициентов многочлена передавайте в качестве параметра шаблона. Хранение коэффициентов должно быть плотным (то есть должны храниться все коэффициенты, в том числе и промежуточные нулевые).
Сделайте следующее:
1) Напишите конструктор, создающий многочлен по заданному вектору коэффициентов (коэффициенты задаются от младшего к старшим).
2) Перегрузите операторы == и !=. Ваш код должен быть очень простым.
3) Перегрузите операторы +, – и *, а также соответствующие операторы +=, -= и *=. Учтите, что должны быть определены и такие арифметические операции, в которых один из аргументов является скаляром.
4) Перегрузите оператор [] для получения коэффициента многочлена перед заданной степенью переменной. Оператор должен работать для любых степеней (в том числе больших текущей максимальной). Напишите также функцию Degree для вычисления степени многочлена (считайте, что у нулевого многочлена степень равна -1).
5) Перегрузите оператор () для вычисления значения многочлена в точке. Постарайтесь написать эффективный код.
6) Перегрузите оператор << для печати многочлена в поток вывода. При этом следует учитывать знаки коэффициентов, совпадение коэффициентов с 1 или -1, степень монома и т. д. Печататься должны только ненулевые коэффициенты многочлена начиная со старшей степени. Пример формата вывода: -x^3+4x^2+x-1.
7) Предусмотрите функции для доступа к константным итераторам, позволяющим перебрать коэффициенты многочлена (это могут быть просто итераторы вектора).
8) Перегрузите операторы / и % для вычисления неполного частного и остатка от деления многочленов (считайте, что в этом случае деление коэффициентов допустимо). Перегрузите также оператор “запятая” для вычисления наибольшего общего делителя. Так как НОД многочленов определен с точностью до обратимого коэффициента, считайте, что его старший коэффициент равен единице. Считайте также, что все операции деления над коэффициентами выполняются точно.

# Замечания
Проверки работоспособности неполные. Возможно, не все задания выполнены в полном объеме и корректно, т.к. это мое первое полноценное приложение на C++.
