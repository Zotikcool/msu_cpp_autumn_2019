#include <iostream>
#include <cctype>
#include <string.h>

char *x;
 
void pass_space(){
    while (isspace((unsigned)*x)) {
        x++;
    }
}

void inc_exp(){
    std::cout << "ERROR: incorrect expression.\n";
    std::exit(1);
}
 
 
int parseFactor() {
    pass_space();
    int value = 0, sign = 1;
    if (*x == '+' || *x == '-') {
        if (*x == '-') {
            sign = -1;
        }
        x++;
    }
    pass_space();
    if (isdigit(*x)) {
        while (isdigit(*x)) {
            value = value * 10 + *x - '0';
            x++;
        }
        return sign * value;
    }
    else {
        inc_exp();
    }
}
 
int parseMultDiv() {
    pass_space();
    int fac1 = parseFactor();
   
    pass_space();
    while (*x == '*' || *x == '/') {
        char temp = *x;
        x++;
        pass_space();
        int fac2 = parseFactor();
        if (temp == '*') {
            fac1 *= fac2;
        }
        else {
            if (fac2 == 0) inc_exp();
            fac1 /= fac2;
        }
        pass_space();
    }
    return fac1;
}
 
int parseSumSub() {
    pass_space();
    int pro1 = parseMultDiv();
    pass_space();
    while (*x == '+' || *x == '-') {
        int sign = 1;
        if (*x == '-') sign = -1;
        ++x;
        int pro2 = parseMultDiv();
        pro1 = pro1 + sign * pro2;
        pass_space();
    }
    if (*x != '\0') {
        inc_exp();
    }
    return pro1;
}
 
int main(int argc, char **argv) {
    if (argc != 2) {
        inc_exp();
    }
    x = argv[1];
    std::cout << parseSumSub() << std::endl;
    return 0;
}

