# App-with-films
Приложение для просмотра фильмов списком, учебный проект созданный для отработки навыков c++ сделанный в QTCREATOR 

Проект сделан в QTcreator основной интерфейс реализован в mainwindow.ui
База данных SQLLITE
Реализация добавления нового фильма: dialogadmin.cpp 

<img width="800" height="600" alt="MainWindow 06 06 2026 11_06_40" src="https://github.com/user-attachments/assets/50581e40-aeb8-4f84-b098-98a7433167ce" />

Также в проекте реализованна диалоговое окно добавления нового фильма:

<img width="666" height="541" alt="MainWindow 06 06 2026 11_07_34" src="https://github.com/user-attachments/assets/048fefd7-494f-4766-bb95-dc89b18da941" />

И реализация фильтрации фильмов в отдельном диалоговом окне, средством нажатия кнопок:

<img width="589" height="513" alt="MainWindow 06 06 2026 11_07_42" src="https://github.com/user-attachments/assets/0dafddd1-f584-46e2-bfcd-3a59e0d91475" />

Стек приложения :
C++ и QTcreator

Сборка и запуск
Требования

C++17 или новее
CMake 3.16+
QTcreator 18.0.2
Сборка

git clone <repo>
cd <repo>
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

