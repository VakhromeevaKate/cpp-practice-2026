cmake_minimum_required(VERSION 3.10)
project(MyOpenCVLab)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Ищем OpenCV
find_package(OpenCV REQUIRED)

# Добавляем наш исполняемый файл
add_executable(my_lab lab.cpp)

# Линкуем библиотеки OpenCV
target_link_libraries(my_lab ${OpenCV_LIBS})