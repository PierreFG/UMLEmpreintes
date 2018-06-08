.PHONY: app tests

app:
	g++ ui/*.cpp main/Main.cpp fs/*.cpp model/*.cpp analysis/*.cpp -I "." -o app -std=c++11

tests:
	g++ ui/*.cpp tests/unit_tests/*.cpp fs/*.cpp model/*.cpp analysis/*.cpp -I "." -o appTest -std=c++11 -D "TEST"
