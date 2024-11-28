#include <iostream>
#include <string>
#include <vector>

struct Data{
    std::string filename;
    std::string way;
    int size;
    int typefile;
    char *md5;
    Data(std::string name,std::string put){
        filename = name;
        way = put;
        size = 1024;
        md5 = nullptr;
    }
};



struct Node{
    std::vector<Node*> leafs;
    Data* data;
    Node(){
        
    }

};

class Tree{
    private:
        Node* root;
        Data* d;
    public:
        void add(Data* d){

            





        }
        int deleted(Data*d,bool delete_child = true){
            return 0;
        }
        int getElement(contd::string& filename, std::vector<Data*>*element){








            //я люблю Максима Варламова, когда он сосёт леденец. от Панамы... член у Макса небольшой, но зато комфортный.


            return 0;
        }
        
};

int main(){

    return 0;
}
