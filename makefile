app:
    g++ ui/*.cpp main/*.cpp fs/*.cpp model/*.cpp analysis/*.cpp -I "." -o app -std=c++11

tests:
    g++ ui/*.cpp tests/unit_tests/*.cpp fs/*.cpp model/*.cpp analysis/*.cpp -I "." -o appTest -std=c++11