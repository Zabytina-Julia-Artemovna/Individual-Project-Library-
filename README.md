**Выбранная предметная область:** БИБЛИОТЕКА

**Цель работы:** реализовать программное обеспечения для мониторинга читателей, книг и работников библиотеки.
**Задачи проекта:**
1.	Реализовать программное обеспечение для учета информации о читателях, читательских билетах, сотрудниках, книгах.
2.	Приложение должно обеспечивать возможность библиотекарю-администратору быстро и легко выполнять свои функции:
-	создавать и заполнять читательские билеты
-	добавлять читателей в систему
-	удалять читателей из системы
-	следить за состоянием книг и изменять, актуализировать информацию о них (выдана, зарезервирована, в наличии)
-	отслеживать информацию о посетителях и сотрудниках библиотеки
  
**Функциональные требования:**
Приложение реализуется в виде windows-приложения с удобным навигационным меню и качественным отображением информации.
*Основные возможности, которые будут предусмотрены приложением:*
1.	Приложение реализуется с авторизацией  библиотекаря-администратора по паролю.
2.	Основной режим работы приложения упрощает работу библиотекаря-администратора, предоставляет все необходимые ему функции (см. задачи проекта), однако ограничивает доступ к изменению информации о сотрудниках (информация о сотрудниках доступна администратору только для просмотра). 
3.	Доступ к особому режиму добавления/удаления сотрудников, назначения им окладов, будет осуществляться по особому паролю, который будет выдан заведующему библиотекой.
4.	Все данные будут храниться в csv-формате и подтягиваться при очередном запуске приложения.
   
**В рамках проекта будет реализован контейнер данных TVector**

**1. Класс должен отвечать требованиям:**
  - обязан быть шаблонным и иметь возможность хранить
 всевозможные виды объектов (в том числе для задач текущего и
 следующего семестра);
   - реализация должна соответствовать принципам ООП;
   - функции класса должны реализовывать эффективные алгоритмы;
   - хранение элементов обрабатывается автоматически, расширяясь по мере
 необходимости, класс обязан гарантировать отсутствие утечек
 памяти;
  - класс должен быть проверен целиком
 на работоспособность (покрыт «тестами»);
  - код должен быть «чистым»;
  - стиль кодирования должен успешно
 проходить проверку скриптом cpplint.py;
**2. Функциональные требования. Класс TVector обязан реализовывать следующие функциональные возможности:**
    - возможность создания
 a) пустого вектора по умолчанию;
 b) вектора заданного размера;
 c) вектора, созданного на основе переданного массива данных;
 d) конструктор копирования + иные необходимые на ваш взгляд способы создания вектора,
 а также его уничтожения;
  - функции: data(), size(), capacity(), front(), back() + функции begin(), end();
  - Функция проверки на пустоту is_empty();
  - стандартные функции вставки: push_front(), push_back(), insert();
  - стандартные функции удаления: pop_front(), pop_back(), erase();
  - функция замены значения emplace();
  - функция присваивания assign(), функция обращения по индексу at() с проверкой допустимости индекса,
 функция очистки вектора clear();
  - функция shrink_to_fit() для возврата дополнительной памяти в систему. Функция резервирования памяти
 заданного размера reserve() (если меньше текущей памяти, то ничего не происходит), функция изменения размера
 массива resize() с заполнителем и без (работает как на расширение памяти, так и на сжатие);
  - должны быть перегружены операторы: присваивания = , сравнения != , == , оператор [];
**3.  Обязательный служебный функционал:**
   - функции работы с памятью в массиве;
   - функция проверки на заполненность is_full();
**4. Вне класса TVector будут реализованы дружественные функции:**
  - функция перемешивания (например, через алгоритм Фишера - Йейтса)
  - эффективный способ сортировки массива (например, сортировка Хоара)
  - поиск элементов с заданными свойствами (первого, последнего элемента, всех элементов)

Также возможна реализация других необходимых пользовательских и служебных функций, перегрузок операторов.

**Исследовательская работа:**
[Исследование принципов работы контейнера std::vector (PDF)](source/STL_vector.pdf)
