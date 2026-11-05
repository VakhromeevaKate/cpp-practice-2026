#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. Загрузка изображения
    // Укажите путь к вашему изображению. Например, "image.jpg"
    cv::Mat image = cv::imread("/Users/evakhromeeva/Projects/cpp-practice-2026/practice8/lena.jpg");

    // Проверка, удалось ли загрузить изображение
    if (image.empty()) {
        std::cerr << "Ошибка: не удалось загрузить изображение!" << std::endl;
        return -1;
    }

    // 2. Преобразование в оттенки серого
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);

    // 3. Сохранение результата
    cv::imwrite("gray_output.jpg", gray_image);

    // 4. Отображение (опционально)
    // cv::imshow("Оригинал", image);
    // cv::imshow("Оттенки серого", gray_image);
    // cv::waitKey(0); // Ожидание нажатия клавиши

    std::cout << "Изображение обработано и сохранено как gray_output.jpg" << std::endl;
    return 0;
}

/**
 mkdir build
 cd build
 cmake ..
 make
 ./my_lab
 * 
 */