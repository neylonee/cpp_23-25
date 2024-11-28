#include <iostream>
#include <string>

class FILO






bool getCorrectBrackets(const std::string &str) {
    std::stack<char> bracketStack;

    for (char ch : str) {
        // Если символ открывающая скобка, помещаем её в стек
        if (ch == '(' || ch == '[' || ch == '{') {
            bracketStack.push(ch);
        } 
        // Если символ закрывающая скобка
        else if (ch == ')' || ch == ']' || ch == '}') {
            // Проверяем, есть ли в стеке соответствующая открывающая скобка
            if (bracketStack.empty()) {
                return false; // Лишняя закрывающая скобка
            }
            char top = bracketStack.top();
            bracketStack.pop(); // Убираем последнюю открывающую скобку из стека

            // Сравниваем, соответствуют ли открывающая и закрывающая скобки
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false; // Несоответствие типам скобок
            }
        }
    }

    return bracketStack.empty();
}

int main() {
    std::string input;
    std::cout << "Введите строку со скобками: ";
    std::getline(std::cin, input);

    if (getCorrectBrackets(input)) {
        std::cout << "Скобки расставлены правильно." << std::endl;
    } else {
        std::cout << "Скобки расставлены неправильно." << std::endl;
    }

    return 0;
}

