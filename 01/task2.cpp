#include <iostream>
#include <cctype>
#include <string.h>

void pass_space(const char **x){
    while (isspace((unsigned)**x)) {
        ++*x;
    }
}

int parseFactor(const char **x, int &iserror) {
    pass_space(x);
    int value = 0, sign = 1;
    if (**x == '+' || **x == '-') {
        if (**x == '-') {
            sign = -1;
        }
        ++*x;
    }
    pass_space(x);
    if (isdigit(**x)) {
        while (isdigit(**x)) {
            value = value * 10 + **x - '0';
            ++*x;
        }
        return sign * value;
    }
    else {
        iserror = 1;
        return 1;
    }
}

int parseMultDiv(const char **x, int &iserror) {
    pass_space(x);
    int fac1 = parseFactor(x, iserror);
    if (iserror) return 1;
    pass_space(x);
    while (**x == '*' || **x == '/') {
        char temp = **x;
        ++*x;
        pass_space(x);
        int fac2 = parseFactor(x, iserror);
        if (iserror) return 1;
        if (temp == '*') {
            fac1 *= fac2;
        }
        else {
            if (fac2 == 0) {
                iserror = 1;
                return 1;
            }
            fac1 /= fac2;
        }
        pass_space(x);
    }
    return fac1;
}

int parseSumSub(const char *x, int &iserror) {
    pass_space(&x);
    int pro1 = parseMultDiv(&x, iserror);
    if (iserror) return 1;
    pass_space(&x);
    while (*x == '+' || *x == '-') {
        int sign = 1;
        if (*x == '-') sign = -1;
        ++x;
        int pro2 = parseMultDiv(&x, iserror);
        if (iserror) return 1;
        pro1 = pro1 + sign * pro2;
        pass_space(&x);
    }
    if (*x != '\0') {
        iserror = 1;
        return 1;
    }
    return pro1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "error" << "\n";
        return 1;
    }
    int iserror = 0;
    int ans = parseSumSub(argv[1], iserror);
    if (iserror) {
        std::cout << "error" << std::endl;
        return 1;
    }
    std::cout << ans << std::endl;
    return 0;
}
