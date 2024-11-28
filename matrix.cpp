#include <iostream>
class Matrix{
    private:
        double *ar;
        int n;
        
    public:
        Matrix();
        double *ma;
        void print(){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    std::cout<<ma[i*n+j] << '\t';
                }
                std::cout<<std::endl;
            }

        }
        int index(int row, int col, int size) {
            return row * size + col;
        }

        double determinant(const double *matrix, int size) {
            if (size == 0) {
                return -1;
            }

            if (size == 1) {
                return matrix[0];
            }

            if (size == 2) {
                return matrix[0] * matrix[3] - matrix[1] * matrix[2];
            }

            double det = 0.0;

            for (int c = 0; c < size; c++) {
                // Создание подматрицы
                double* submatrix = new double[(size - 1) * (size - 1)];

                for (int i = 1; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (j < c) {
                            submatrix[index(i - 1, j, size - 1)] = matrix[index(i, j, size)];
                        } else if (j > c) {
                            submatrix[index(i - 1, j - 1, size - 1)] = matrix[index(i, j, size)];
                        }
                    }
                }

                // Рекурсивный вызов для вычисления детерминанта подматрицы
                det += (c % 2 == 0 ? 1 : -1) * matrix[index(0, c, size)] * determinant(submatrix, size - 1);

                delete[] submatrix;  
            }

            return det;
        }
        Matrix(const char* fl){
            FILE* f = fopen(fl,"r");
            fscanf(f,"%d\n", &n);
            ma = new double[n*n];
            for( int i=0;i<n;i++){
                for(int j =0;j<n;j++){
                    fscanf(f,"%lf",&ma[i*n+j]);
                }
            }
            fclose(f);
            //memcpy(ma,m1,c*r*4);

        }
        int getSize(){
            return n;
        }
        Matrix* operator + (Matrix* newS){
            if(this->n != newS->getSize()){
                return 0;
            }
            double * NEWM = new double[n*n];
            for(int i =0;i <n*n;i++){
                NEWM[i] = ma[i] + newS-> ma[i];
            }

            return new Matrix( NEWM, n); 

        }

        Matrix* operator * (Matrix* newP){
            if(this -> n !=newP->getSize()){
                return 0;
            }
            double * TEMPM = new double[n*n];
            for(int i=0;i<n;i++){
                for(int j = 0; j<n;j++){
                    double tempd =0;		
                    for(int f=0;f<n;f++){
                        tempd += ma[i*n + f] *  newP->ma[j + f*n];
                    }
                    TEMPM[i*n + j]= tempd;
                }
            }	
            return new Matrix(TEMPM,n);



        }
        
        Matrix(double* ar,int n1){
            n =n1;
            ma = new double[n*n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    ma[i*n+j] = ar[i*n+j];
                }
            }
        }
        ~Matrix();
};



int main(){
    class Matrix *ma = new Matrix("matrix.txt");
    ma->print();


    std::cout<<ma->determinant(ma->ma,3)<<std::endl;




    class Matrix *ma1 = new Matrix("matrix.txt");

    class Matrix *plussedm = *ma + ma1;
    class Matrix *multedm = *ma * ma;
    std::cout<<"Сложенные матрицы"<<std::endl;
    plussedm->print();
    std::cout<<"Умноженные матрицы "<<std::endl;
    multedm->print();


    return 0;
}
