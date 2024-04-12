#include <iostream>
#include <stack>
#include <cmath>
#include <cfloat>
#include <string>

#ifdef _WIN32

#include <windows.h> // For the GetUserName function

#else
#include <unistd.h> // For the getlogin() function
#endif

void GreetUser() {
    char username[256];

    // Retrieve the username
#ifdef _WIN32
    DWORD username_len = sizeof(username);
    if (GetUserNameA(username, &username_len)) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        WORD saved_attributes = consoleInfo.wAttributes;

        // Greet the user with colored formatting
        std::cout << "\n    Hello, ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED); // Purple color
        std::cout << username;
        SetConsoleTextAttribute(hConsole, saved_attributes); // Reset color

        std::cout << "! Welcome to the calculator.\n";
        std::cout << "    Read the documentation before using this program: \n"
                     "     -> https://github.com/kamozi2k/console_calc <-\n";

        // Prompt the user to enter a mathematical expression
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN); // Orange color
        std::cout << "\n"
                     "    Enter a mathematical expression: ";
        SetConsoleTextAttribute(hConsole, saved_attributes); // Reset color
    } else {
        std::cerr << "\n    Failed to retrieve the user name.\n";
    }
#else
    if (getlogin_r(username, sizeof(username)) == 0) {
            // Greet the user without colored formatting
            std::cout << "\n    Hello, " << username << "! Welcome to the calculator.\n";
            std::cout << "    Read the documentation before using this program: \n"
                        "     -> https://github.com/kamozi2k/console_calc <-\n";

            // Prompt the user to enter a mathematical expression
            std::cout << "\n"
                        "    Enter a mathematical expression: ";
        } else {
            std::cerr << "\n    Failed to retrieve the user name.\n";
        }
#endif
}


// Constants
const double Pi = M_PI;
const double Pi_2 = M_PI_2;
const double Exp = M_E;


// Math functions
double Sin(double x) {
    if (fabs(fmod(x, Pi)) < DBL_EPSILON) {
        return 0;
    } else {
        return sin(x);
    }
}

double Cos(double x) {
    if (fabs(fmod(x - Pi_2, Pi)) < DBL_EPSILON) {
        return 0;
    } else {
        return cos(x);
    }
}


// Struct for dividing characters into Numbers or Operators
struct Lexeme {
    char type; // '0' for Numbers and 'operators_symbols' for Operators
    double value; // only for Numbers
};

// Function for performing mathematical operations
bool Maths(std::stack<Lexeme> &Numbers, std::stack<Lexeme> &Operators, Lexeme &Item) {
    double num1, num2, result;
    num1 = Numbers.top().value;
    Numbers.pop();
    switch (Operators.top().type) {
        case '+':
            num2 = Numbers.top().value;
            Numbers.pop();
            result = num1 + num2;
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;

        case '-':
            num2 = Numbers.top().value;
            Numbers.pop();
            result = num2 - num1;
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;

        case '*':
            num2 = Numbers.top().value;
            Numbers.pop();
            result = num1 * num2;
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;

        case '/':
            num2 = Numbers.top().value;
            if (num1 == 0 && num2 == 0) {
                std::cerr << "\n"
                             "    Uncertainty of the form 0 / 0.\n";
                return false;
            } else if (num1 == 0) {
                std::cerr << "\n"
                             "    Division by zero.\n";
                return false;
            } else {
                Numbers.pop();
                result = num2 / num1;
                Item.type = '0';
                Item.value = result;
                Numbers.push(Item);
                Operators.pop();
                break;
            }

        case '^':
            num2 = Numbers.top().value;
            Numbers.pop();
            if (num1 == 0 && num2 == 0) {
                std::cerr << "\n"
                             "    Uncertainty of the form 0 ^ 0.\n";
                return false;
            } else {
                result = pow(num2, num1);
                Item.type = '0';
                Item.value = result;
                Numbers.push(Item);
                Operators.pop();
                break;
            }

        case 's':
            result = Sin(num1);
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;

        case 'c':
            result = Cos(num1);
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;

        case 't':
            if (Cos(num1) == 0) {
                std::cerr << "\n"
                             "    Invalid argument for \"tan\".\n";
                return false;
            } else {
                if (Sin(num1) == 0) {
                    result = 0;
                } else {
                    result = Sin(num1) / Cos(num1);
                }
                Item.type = '0';
                Item.value = result;
                Numbers.push(Item);
                Operators.pop();
                break;
            }

        case 'g':
            if (Sin(num1) == 0) {
                std::cerr << "\n"
                             "    Invalid argument for \"cot\".\n";
                return false;
            } else {
                if (Cos(num1) == 0) {
                    result = 0;
                } else {
                    result = Cos(num1) / Sin(num1);
                }
                Item.type = '0';
                Item.value = result;
                Numbers.push(Item);
                Operators.pop();
                break;
            }

        case 'b':
            if (num1 > 0) {
                result = log2(num1);
            } else {
                std::cerr << "\n"
                             "    Invalid argument for \"lb\".\n";
                return false;
            }
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;

        case 'n':
            if (num1 > 0) {
                result = log(num1);
            } else {
                std::cerr << "\n"
                             "    Invalid argument for \"ln\".\n";
                return false;
            }
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;

        case 'l':
            if (num1 > 0) {
                result = log10(num1);
            } else {
                std::cerr << "\n"
                             "    Invalid argument for \"lg\".\n";
                return false;
            }
            result = log10(num1);
            Item.type = '0';
            Item.value = result;
            Numbers.push(Item);
            Operators.pop();
            break;
    }
    return true;
}

// Function for getting the priority of mathematical operations
int GetRank(char &Ch) {
    if (Ch == '+' || Ch == '-') return 1;
    else if (Ch == '*' || Ch == '/') return 2;
    else if (Ch == '^') return 3;
    else if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'b' || Ch == 'n' || Ch == 'l') return 4;
    return 0;
}


int main() {
    char Ch;
    double value;
    bool isUnary = true;


    std::stack<Lexeme> Numbers;
    std::stack<Lexeme> Operators;
    Lexeme Item{};


    GreetUser();


    while (true) {
        Ch = std::cin.peek();
        if (Ch == '\n') break;
        if (Ch == ' ') {
            std::cin.ignore();
            continue;
        }
        if (Ch == '-' && isUnary) {
            std::cin.ignore();
            Ch = std::cin.peek();
            if (isdigit(Ch)) {
                std::cin >> value;
                Item.type = '0';
                Item.value = -value;
                Numbers.push(Item);
                isUnary = false;
                continue;
            } else if (Ch == 'e') {
                Item.type = '0';
                Item.value = Exp * -1;
                Numbers.push(Item);
                isUnary = false;
                std::cin.ignore();
                continue;
            } else if (Ch == 'p') {
                Item.type = '0';
                Item.value = Pi * -1;
                Numbers.push(Item);
                isUnary = false;
                std::cin.ignore();
                continue;
            } else {
                if (Operators.empty()) {
                    Item.type = Ch;
                    Item.value = 0;
                    Operators.push(Item);
                    std::cin.ignore();
                    continue;
                }
            }
        }

        if (Ch == 'p') {
            Item.type = '0';
            Item.value = Pi;
            Numbers.push(Item);
            isUnary = false;
            std::cin.ignore();
            continue;
        }
        if (Ch == 'e') {
            Item.type = '0';
            Item.value = Exp;
            Numbers.push(Item);
            isUnary = false;
            std::cin.ignore();
            continue;
        }
        if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e') {
            char arr[3];
            for (char &i: arr) {
                i = std::cin.peek();
                std::cin.ignore();
            }
            if (arr[0] == 's' && arr[1] == 'i' && arr[2] == 'n') { // sin()
                Item.type = 's';
                Item.value = 0;
                Operators.push(Item);
                continue;
            }
            if (arr[0] == 'c' && arr[1] == 'o' && arr[2] == 's') { // cos()
                Item.type = 'c';
                Item.value = 0;
                Operators.push(Item);
                continue;
            }
            if (arr[0] == 't' && arr[1] == 'a' && arr[2] == 'n') { // tan()
                Item.type = 't';
                Item.value = 0;
                Operators.push(Item);
                continue;
            }
            if (arr[0] == 'c' && arr[1] == 'o' && arr[2] == 't') { // cot()
                Item.type = 'g';
                Item.value = 0;
                Operators.push(Item);
                continue;
            }
        }
        if (Ch == 'l') {
            char arr[2];
            for (char &i: arr) {
                i = std::cin.peek();
                std::cin.ignore();
            }
            if (arr[0] == 'l' && arr[1] == 'n') {
                Item.type = 'n';
                Item.value = 0;
                Operators.push(Item);
                continue;
            }
            if (arr[0] == 'l' && arr[1] == 'b') {
                Item.type = 'b';
                Item.value = 0;
                Operators.push(Item);
                continue;
            }
            if (arr[0] == 'l' && arr[1] == 'g') {
                Item.type = 'l';
                Item.value = 0;
                Operators.push(Item);
                continue;
            }
        }
        if (Ch >= '0' && Ch <= '9' || Ch == '-' && isUnary) {
            std::cin >> value;
            Item.type = '0';
            Item.value = value;
            Numbers.push(Item);
            isUnary = false;
            continue;
        }
        if (Ch == '+' || Ch == '-' && !isUnary || Ch == '*' || Ch == '/' || Ch == '^') {
            if (Operators.empty()) {
                Item.type = Ch;
                Item.value = 0;
                Operators.push(Item);
                std::cin.ignore();
                continue;
            }
        }
        if (Ch == '(') {
            Item.type = Ch;
            Item.value = 0;
            Operators.push(Item);
            std::cin.ignore();
            isUnary = true;
            continue;
        }
        if (Ch == ')') {
            while (Operators.top().type != '(') {
                if (!Maths(Numbers, Operators, Item)) {
                    return 1;
                }
            }
            Operators.pop();
            std::cin.ignore();
            continue;
        }
        if (!Operators.empty()) {
            if (GetRank(Ch) > GetRank(Operators.top().type)) {
                Item.type = Ch;
                Item.value = 0;
                Operators.push(Item);
                std::cin.ignore();
                continue;
            } else {
                if (!Maths(Numbers, Operators, Item)) {
                    return 1;
                }
            }
        } else {
            std::cerr << "\n"
                         "    Operation \"" << Ch << "\" not defined.\n";
            return 1;
        }
    }
    while (!Operators.empty()) { // This cycle catches the ERROR
        if (!Maths(Numbers, Operators, Item)) {
            return 1;
        }
    }
    if (Numbers.empty()) {
        std::cerr << "\n"
                     "    No input provided.\n";
        return 1;
    }
    std::cout << "    Result is: " << Numbers.top().value << std::endl;
    return 0;
}
