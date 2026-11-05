# OpenCV

### Установка OpenCV:
```sudo apt install libopencv-dev```  Unix - Linux
```brew install cmake pkg-config opencv``` Mac OS
```vcpkg install opencv4``` Windows

### Как собрать приложения:
1. ```g++ check.cpp -o check 'pkg-config --cflags --libs opencv4'```
```./check```

2. ```mkdir build```
```cd build```
```cmake ..```
```make```
```./my_lab```

