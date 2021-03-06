# EngineModel

Необходимо разработать консольное приложение, которое рассчитывает и выводит время,
которое пройдет от старта двигателя внутреннего сгорания до момента его перегрева, в
зависимости от заданной температуры окружающей среды. Приложение должно принимать с
консоли пользовательский ввод температуры окружающей среды в градусах Цельсия, и выводить
на консоль время до перегрева в секундах. Рассчитывать время точно, аналитическим путем не
нужно, интересует получение этого времени методом симуляции (разумеется, таким образом
время будет вычислено с определенной погрешностью).
Приложение должно состоять из трех логических блоков:
1. Симуляция двигателя внутреннего сгорания
Требуется упрощенно симулировать изменение скорости вращения коленвала и температуры
охлаждающей жидкости двигателя, работающего без нагрузки, с течением времени. Входные
параметры:
 Момент инерции двигателя I (кг∙м 2 )
 Кусочно-линейная зависимость крутящего момента M, вырабатываемого двигателем, от
скорости вращения коленвала V (крутящий момент в Н∙м, скорость вращения в
радиан/сек)
 Температура перегрева T перегрева (C 0 )
 Коэффициент зависимости скорости нагрева от крутящего момента H M
 Коэффициент зависимости скорости нагрева от скорости вращения коленвала H V
 Коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей
среды C
Так как двигатель работает без нагрузки, то весь вырабатываемый момент идет на раскрутку
коленвала, и его ускорение вычисляется просто: a = M × I
Специальной логики старта двигателя не требуется. Считаем, что при старте он просто начинает
вырабатывать крутящий момент по заданному графику начиная с нулевой скорости вращения.
Скорость нагрева двигателя рассчитывать как V H = M × H M + V 2 × H V (С 0 /сек)

2

Скорость охлаждения двигателя рассчитывать как V C = C × (T среды - Т двигателя ) (С 0 /сек)
Температура двигателя до момента старта должна равняться температуре окружающей среды.
Нагрев и охлаждение, рассчитанные по формулам выше, действуют на двигатель постоянно,
одновременно и независимо друг от друга.
2. Логика тестирования двигателя на перегрев
Требуется реализовать «тестовый стенд», исследующий поданный на вход двигатель. Тестовый
стенд должен включать двигатель, следить за его температурой, и в момент перегрева
прекращать тест и возвращать время, прошедшее с момента старта до перегрева.
3. Консольный ввод-вывод, задание исходных данных и запуск теста
Эта часть приложения содержит точку входа, и должна обеспечивать весь ввод/вывод на консоль,
а так же задание всех исходных данных и запуск теста двигателя. Все исходные данные, кроме
температуры окружающей среды, нужно задать в коде или в конфигурационном файле:
I = 0.1
M = { 20, 75, 100, 105, 75, 0 } при V = { 0, 75, 150, 200, 250, 300 } соответственно
T перегрева = 110
H M = 0.01
H V = 0.0001
C = 0.1
