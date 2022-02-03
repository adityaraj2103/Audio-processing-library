#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <array>
#include <string>
using namespace std;

vector<string> fileCopy(string t1) {
    fstream f;
    string temp;
    vector<string> g;
    f.open(t1, ios::in);
    while (true)
    {
        f >> temp;
        if(f.eof())
            break;
        g.push_back(temp);
    }
    f.close();
    return g;
}

void fullyConnected(string f1, string f2, string f3) {
    vector<string> im = fileCopy(f1);
    int lim = im.size();
    string arrim[lim];
    for (int i = 0; i < lim; i++) {
        arrim[i] = im[i];
    }

    vector<string> wm = fileCopy(f2);
    int lwm = wm.size();
    string arrwm[lwm];
    for (int j = 0; j < lwm; j++) {
        arrwm[j] = wm[j];
    }

    vector<string> bm = fileCopy(f3);
    int lbm = bm.size();
    string arrbm[lbm];
    for (int k = 0; k < lbm; k++) {
        arrbm[k] = bm[k];
    }

    int R1 = stoi(arrim[1]);
    int C1 = stoi(arrim[0]);
    int R2 = stoi(arrwm[1]);
    int C2 = stoi(arrwm[0]);
    float input[R1][C1];
    int count = 2;
    for (int p = 0; p < C1; p++)
    {
        for (int q = 0; q < R1; q++)
        {
            input[q][p] = stof(arrim[count]);
            count++;
        }
    }

    float weight[R2][C2];
    count = 2;
    for (int p = 0; p < C2; p++)
    {
        for (int q = 0; q < R2; q++)
        {
            weight[q][p] = stof(arrwm[count]);
            count++;
        }
    }

    float output[R1][C2];
    for (int a = 0; a < R1; a++) {
        for (int b = 0; b < C2; b++) {
            output[a][b] = 0;
            for (int c = 0; c < R2; c++) {
                output[a][b] += input[a][c] * weight[c][b];
            }
        }
    }
    
    int R3 = stoi(arrbm[1]);
    int C3 = stoi(arrbm[0]);
    float bias[R3][C3];
    count = 2;
    for (int p = 0; p < C3; p++)
    {
        for (int q = 0; q < R3; q++)
        {
            bias[q][p] = stof(arrbm[count]);
            count++;
        }
    }
    
    count = 2;
    for (int p = 0; p < R1; p++)
    {
        for (int q = 0; q < C2; q++)
        {
            output[p][q] += bias[p][q];
            count++;
        }
    }
    
    ofstream myfile ("sample.txt");
    if (myfile.is_open())
    {
        myfile << C3 << endl;
        myfile << R3 << endl;
        for (int p = 0; p < R1; p++)
        {
            for (int q = 0; q < C2; q++)
            {
                myfile << output[p][q] << endl;
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void activation(string g1, string ty) {
    vector<string> im = fileCopy(g1);
    int lim = im.size();
    string arrim[lim];
    for (int i = 0; i < lim; i++) 
    {
        arrim[i] = im[i];
        cout << arrim[i] << endl;
    }
    int R1 = stoi(arrim[1]);
    int C1 = stoi(arrim[0]);
    float input[R1][C1];
    int count = 2;
    for (int p = 0; p < C1; p++)
    {
        for (int q = 0; q < R1; q++)
        {
            input[q][p] = stof(arrim[count]);
            count++;
        }
    }
    for (int p = 0; p < C1; p++)
    {
        for (int q = 0; q < R1; q++)
        {
            cout << input[q][p] << endl;
        }
        
    }
    
    float output[R1][C1];
    if (ty == "relu")
    {
        float z = 0;
        for (int p = 0; p < C1; p++)
        {
            for (int q = 0; q < R1; q++)
            {
                output[q][p] = max(input[p][q], z);
            }
        }
    }
    else if (ty == "tanh")
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Please input correct activation function name";
    }
    ofstream myfile ("sample.txt");
    if (myfile.is_open())
    {
        myfile << C1 << endl;
        myfile << R1 << endl;
        for (int p = 0; p < C1; p++)
        {
            for (int q = 0; q < R1; q++)
            {
                myfile << output[q][p] << endl;
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void pooling() {

}

void probability() {
    
}

int main() {
    string funcType, file1, file2, file3, type;
    cout << "Enter the Function Number: ";
    cin >> funcType;
    if (funcType == "0")
    {
        file1 = "a1a.inputmatrix.txt";
        file2 = "a1a.weightmatrix.txt";
        file3 = "a1a.biasmatrix.txt";
        fullyConnected(file1, file2, file3); 
    }
    else if (funcType == "1")
    {
        file1 = "a2a.inputmatrix.txt";
        type = "relu";
        activation(file1, type);
    }
    else
    {
        cout << "Wrong Input";
    }
    return 0;
}