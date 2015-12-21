@echo off
cd /d "%~dp0"
cd ..
echo Compiling...
g++ -std=c++14 -c -o ./.test-result/utilities.o ./utilities.hpp
