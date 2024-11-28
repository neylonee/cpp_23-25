#include <iostream>
#include <string>
class Filo {
private:
    char* data;        
    int maxSize;     
    int topIndex;  

public:

    Filo(int size) : maxSize(size), topIndex(-1) { 
        data = new char[maxSize]; 
    }
    Filo(){
        data = new char[128];
        maxSize = 128;
    }
    Filo(int size, int* data): maxSize(size), topIndex(-1){
        data = data;
    }


    ~Filo() {
        delete[] data; 
    }

    int push(int value) {
        if (topIndex >= maxSize - 1) {
            std::cout<<"FULL"<<std::endl;
            return -1;
        }
        data[++topIndex] = value; 
        return 0;
    }

    int pop() {
        if (topIndex < 0) {
            std::cout<<"Error"<<std::endl;
            return -1;

        }
        return data[topIndex--];
    }

    // Получение верхнего элемента стека без удаления
    int top() const {
        if (topIndex < 0) {
            std::cout<<"Error"<<std::endl;
            return -1;
        }
        return data[topIndex];
    }

    bool empty() const {
        return topIndex < 0;
    }

    // Получение текущего размера стека
    int size() const {
        return topIndex + 1;
    }

    bool getCorrectBrackets(const std::string &str) {
        Filo bracketStack;

        for (char ch : str) {
            std::cout<<ch;
            // если символ открывающая скобка пиздуй в стек 
            if (ch == '(' || ch == '[' || ch == '{') {
                bracketStack.push(ch);
            } 
            // tсли символ закрывающая скобка
            else if (ch == ')' || ch == ']' || ch == '}') {
                // сть ли в стеке соответствующая открывающая скобка
                if (bracketStack.empty()) {
                    return false; // kишняя закрывающая скобка
                }
                char top = bracketStack.top();
                bracketStack.pop(); // кик ласт открывающую скобку из стека

                //соответствуют ли открывающая и закрывающая скобки
                if ((ch == ')' && top != '(') ||
                        (ch == ']' && top != '[') ||
                        (ch == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return bracketStack.empty();
    }
};






int main() {
    std::cout << "Введите строку со скобками: ";
    std::string input;
    std::cin>>input;
    class Filo *brackets = new Filo;
 //   FILO.push('(');
 //   FILO.push('(');
 //   FILO.push(')');
 //   FILO.push(')');
 //   FILO.push('[');
 //   FILO.push(']');




    if(brackets->getCorrectBrackets(input))   {

        std::cout << "Скобки расставлены правильно." << std::endl;
    } else {
        std::cout << "Скобки расставлены неправильно." << std::endl;
    }

    return 0;
}

