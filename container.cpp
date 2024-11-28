#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ostream>
#include <string_view>
void print_map(std::string_view comment, const std::map<std::int, std::vector<int>>& m){
    std::cout << comment;
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";
    std::cout << '\n';
}

void print_hunya(const std::map<int,std::vector<std::pair<char,int>>>){
}



int main(){
    std::map<int,std::vector<std::pair<char,int>>> to_print;
    std::map<int,std::vector<int>>m{{100,1},{200,2},{300,3}};
    print_map("1) Initial map: ", m);


//    for(int i = 0; i < std::size(to_print);i++){
//        for(int j = 0; j < std::size(to_print[i]); j++){
//            std::cout<<to_print[i][j]'\n'<<std::endl;
//        }
//    }

    
    
    
    


    return 0;

}
