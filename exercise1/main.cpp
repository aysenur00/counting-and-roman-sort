#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

bool Reading_Numbers(vector<int>& vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void OutputResultToFile(int* arr, unsigned int size) {
    ofstream output("out.txt");

    for (int i = 0; i < size; i++)
        output << arr[i] << ' ';
}


int main(int argc, const char* argv[]) {
    vector<int> A;

    if (argc < 3) return 0;
    if (!Reading_Numbers(A, argv[2])) return 0;

    if (argv[1][0] == '0') {
        //Counting Sort
        vector<int>B(A.size(), 0);
        //int min = 0; //***
        int max = 0;



        for (unsigned int m = 0; m < A.size(); m++)
        {
            if (A[m] > max)
                max = A[m];
        }
        int min= max;
        for (unsigned int m = 0; m < A.size(); m++)
        {
            if (A[m] < min)
                min = A[m];
        }

        for (unsigned int m = 0; m < A.size(); m++)
        {
            A[m]=A[m]-min;
        }

        vector<int> C(max - min +  1, 0);

        for (int i = 0; i < A.size(); i++) {
            C[A[i] - min] = C[A[i] - min] + 1;


        }

        for (int i = 1; i < C.size(); i++) {
            C[i] = C[i] + C[i - 1];


        }

        for (int i = A.size() - 1; i > -1; i--)
        {
            B[C[A[i] - min] - 1] = A[i];
            C[A[i] - min] = C[A[i] - min] - 1;

        }
        for (unsigned int m = 0; m <B.size(); m++)
        {
            B[m]=B[m]+min;
        }

        for (int i = 0; i < A.size(); i++) {

            cout << B[i] << " " << endl;


            A[i] = B[i];

        }
    }
    else {
        //Roman sort
        vector<int>B(A.size(), 0);
        int min = 0;
        int max = 0;
        int counter=0;

        for (unsigned int m = 0; m < A.size(); m++)
        {
            if (A[m] < min)
                min = A[m];
        }

        for (unsigned int m = 0; m < A.size(); m++)
        {
            A[m]=A[m]-min;
        }

        for (unsigned int m = 0; m < A.size(); m++)
        {
            if (A[m] < min)
                min = A[m];
        }
        int tmp = min;

        for (unsigned int m = 0; m < A.size(); m++)
        {
            if (A[m] > max)
                max = A[m];
        }


        vector<int> C(max - min + 1, 0);

        for (int i = 0; i < A.size(); i++) {
            C[A[i] - min] = C[A[i] - min] + 1;


        }
        cout << endl;

        for(int i = 0; i < C.size(); i++)
        {
            if(C[i] != 0)
            {
                for(int j = 0; j < C[i]; j++)
                {
                    B[counter] = tmp;
                    counter++;
                }
            }
            tmp++;
        }

        for (unsigned int m = 0; m <B.size(); m++)
        {
            B[m]=B[m]+min;
        }

        for (int i = 0; i < A.size(); i++) {

            cout << B[i] << " " << endl;


            A[i] = B[i];

        }

    }
    OutputResultToFile(&A[0], A.size());

    return 0;
}