#include <iostream>
#include <vector>
#include <string>

bool isOper(char);

int toInt(std::string);

bool operation(std::vector<int> &, char);

int main(/*int argc, char* argv[]*/) {
    std::vector<int> ans;
    std::string str, num;
    std::cout << "Input expression: ";
    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ')
            if (!isOper(str[i])) {
                while (str[i] != ' ') {
                    num += str[i];
                    i++;
                }
                ans.push_back(toInt(num));
                num = "";
            } else {
                if (operation(ans, str[i])) {
                    std::cout << "Incorrect input. Not enough numbers. " << std::endl;
                    return 1;
                }
                operation(ans, str[i]);
            }
    }

    if (ans.size() == 1)
        std::cout << ans.back() << std::endl;
    else
        std::cout << "Superfluous number." << std::endl;

    return 0;
}

int toInt(std::string num) {
    int x = 0, r = 1;
    for (int i = num.length() - 1;
         i >= 0;
         i--) {
        x += (num[i] - '0') * r;
        r *= 10;
    }

    return x;
}

bool isOper(char sym) {
    std::string ops = "+-*/";
    return ops.find(sym) != -1;
}

bool operation(std::vector<int> &ans, char sym) {
    if (ans.size() < 2)
        return 1;

    switch (sym) {
        case '/': {
            if (ans.back() != 0)
                ans[ans.size() - 2] /= ans.back();
            else {
                std::cout << "Division by zero.";
                return 1;
            }
            break;
        }
        case '*': {
            ans[ans.size() - 2] *= ans.back();
            break;
        }
        case '-': {
            ans[ans.size() - 2] -= ans.back();
            break;
        }
        case '+': {
            ans[ans.size() - 2] += ans.back();
        }
    }

    ans.pop_back();

    return 0;
}
