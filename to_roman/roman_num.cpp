/*
    ローマ数字
    I = 1
    V = 5
    X = 10
    L = 50
    C = 100
    D = 500
    M = 1000
    
    ex) 
        42 -> XLII
        6 -> XI
*/

#include <iostream>

#include <string>
#include <vector>
#include <cstdint>
std::string to_roman_num(uint32_t x) {
    const std::vector<std::pair<uint32_t, std::string>> roman{
        { 1000,  "M" },
        { 900 , "CM" },
        { 500 ,  "D" },
        { 400 , "CD" },
        { 100 ,  "C" },
        {  90 , "XC" },
        {  50 ,  "L" },
        {  40 , "XL" },
        {  10 ,  "X" },
        {   9 , "IX" },
        {   5 ,  "V" },
        {   4 , "IV" },
        {   1 ,  "I" }
    };

    std::string ret;
    for (const auto& [num, str] : roman) {
        while (x >= num) {
            ret += str;
            x -= num;
        }
    }
    return ret;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid argument\n";
        std::cerr << "Usage: ./a.out [number]\n";
        return 1;
    }

    #include <cstdlib>
    uint32_t x = std::atoi(argv[1]);
    if (x == 0) {
        // fprintf(stderr, "cannot convirt %s to int", argv[1]);
        std::cerr << "cannot convirt " << argv[1] << " to int\n";
        return 1;
    }

    std::cout << to_roman_num(x) << "\n";
    return 0;
}