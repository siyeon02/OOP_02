#define _CRT_SECURE_NO_WARNINGS
#include "inf_int.h"
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>



template <typename T>
std::string MyToString(T value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}



std::string reverseString(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

/*void inf_int::normalize() {
    // Remove leading zeros
    while (length > 1 && digits[length - 1] == '0') {
        length--;
    }
    if (length == 1 && digits[0] == '0') {
        thesign = true; // Zero is always positive
    }
}*/

inf_int::inf_int() {
    digits = new char[2];
    digits[0] = '0';
    digits[1] = '\0';
    length = 1;
    thesign = true;
}

inf_int::inf_int(int num) {
    thesign = num >= 0;
    num = std::abs(num);
    std::string str = std::to_string(num);
    length = str.length();
    digits = new char[length + 1];
    strcpy(digits, str.c_str());
}

inf_int::inf_int(const char* str) {
    if (str[0] == '-') {
        thesign = false;
        str++; // Skip the negative sign
    }
    else {
        thesign = true;
    }
    length = strlen(str);
    digits = new char[length + 1];
    strcpy(digits, str);
}

inf_int::inf_int(const inf_int& other) {
    length = other.length;
    thesign = other.thesign;
    digits = new char[length + 1];
    strcpy(digits, other.digits);
}

inf_int::~inf_int() {
    delete[] digits;
}

inf_int& inf_int::operator=(const inf_int& other) {
    if (this == &other) {
        return *this;
    }
    delete[] digits;
    length = other.length;
    thesign = other.thesign;
    digits = new char[length + 1];
    strcpy(digits, other.digits);
    return *this;
}

bool operator==(const inf_int& a, const inf_int& b) {
    if (a.thesign != b.thesign) {
        return false;
    }
    if (a.length != b.length) {
        return false;
    }
    return (strcmp(a.digits, b.digits) == 0);
}

bool operator!=(const inf_int& a, const inf_int& b) {
    return !(a == b);
}

bool operator>(const inf_int& a, const inf_int& b) {
    if (a.thesign && !b.thesign) {
        return true; // Positive is greater than negative
    }
    else if (!a.thesign && b.thesign) {
        return false; // Negative is smaller than positive
    }

    if (a.thesign && b.thesign) {
        if (a.length > b.length) {
            return true;
        }
        else if (a.length < b.length) {
            return false;
        }
        else {
            return strcmp(a.digits, b.digits) > 0;
        }
    }
    else {
        if (a.length > b.length) {
            return false;
        }
        else if (a.length < b.length) {
            return true;
        }
        else {
            return strcmp(a.digits, b.digits) < 0;
        }
    }
}

bool operator<(const inf_int& a, const inf_int& b) {
    if (a == b) {
        return false;
    }
    return !(a > b);
}

inf_int operator+(const inf_int& a, const inf_int& b) {
    inf_int result;
    // TODO: Implement addition logic here
    return result;
};

inf_int operator-(const inf_int&, const inf_int&) {
    inf_int result;
    // TODO: Implement addition logic here
    return result;
};

inf_int operator*(const inf_int&, const inf_int&) {
    inf_int result;
    // TODO: Implement addition logic here
    return result;
};

// Implement subtraction (-) and multiplication (*) operators here

std::ostream& operator<<(std::ostream& out, const inf_int& num) {
    if (!num.thesign) {
        out << '-';
    }
    out << num.digits;
    return out;
}