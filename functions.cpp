#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <typeinfo>
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

void fullyConnected(string f1, string f2, string f3, string f4) {
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
    
    ofstream myfile (f4);
    if (myfile.is_open())
    {
        myfile << C3 << endl;
        myfile << R3 << endl;
        for (int p = 0; p < C2; p++)
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

void activation(string ty, string g1, string of) {
    vector<string> im = fileCopy(g1);
    int lim = im.size();
    string arrim[lim];
    for (int i = 0; i < lim; i++) 
    {
        arrim[i] = im[i];
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
    float output[R1][C1];
    if (ty == "relu")
    {
        float z = 0;
        for (int p = 0; p < C1; p++)
        {
            for (int q = 0; q < R1; q++)
            {
                output[q][p] = max(input[q][p], z);
            }
        }
    }
    else if (ty == "tanh")
    {
        for (int p = 0; p < C1; p++)
        {
            for (int q = 0; q < R1; q++)
            {

                output[q][p] = (exp(2*input[q][p]) - 1)/(exp(2*input[q][p]) + 1);
            }
        }
    }
    else
    {
        cout << "Please input correct activation function name";
    }
    ofstream myfile (of);
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
    else cout << "Error: File not found";
}

void pooling(string m1, string m2, string m3, string m4) {
    cout << "Not implemented yet";
}

void probability(string typ, string k1, string of) {
    vector<string> iv = fileCopy(k1);
    int liv = iv.size();
    string arriv[liv];
    for (int i = 0; i < liv; i++) 
    {
        arriv[i] = iv[i];
    }
    int L1 = stoi(arriv[0]);
    float output[L1+1];
    output[0] = L1;
    if (typ == "softmax")
    {
        float sum = 0;
        for (int i = 1; i < (L1+1); i++)
        {
            sum = sum + exp(stof(arriv[i]));
        }
        for (int i = 1; i < L1+1; i++)
        {
            output[i] = exp(stof(arriv[i]))/sum;
        }   
    }
    else if (typ == "sigmoid")
    {
        for (int i = 1; i < L1+1; i++)
        {
            output[i] = 1/(1+exp(-stof(arriv[i])));
        }   
    }
    else cout << "Incorrect Function" << endl;
    ofstream myfile (of);
    if (myfile.is_open())
    {
        for (int i = 0; i < L1+1; i++)
        {
            myfile << output[i] << endl;
            
        }
        myfile.close();
    }
    else cout << "Error: File not found" << endl;
}

int main(int argc, char** argv) {
    string sc[argc];
    for (int i = 0; i < argc; ++i)
    {
        char* c = argv[i];
        string s(c);
        sc[i] = s;
    }
    if (argc == 5)
    {
        if (sc[1] == "activation")
        {
            activation(sc[2],sc[3],sc[4]);
        }
        else if (sc[1] == "probability")
        {
            probability(sc[2],sc[3],sc[4]);
        }
        else
        {
            cout << "Wrong parameters entered" << endl;
        }
    }
    else if (argc == 6)
    {
        if (sc[1] == "fullyconnected")
        {
            fullyConnected(sc[2],sc[3],sc[4],sc[5]);
        }
        else if (sc[1] == "pooling")
        {
            pooling(sc[2],sc[3],sc[4],sc[5]);
        }
        else
        {
            cout << "Wrong parameters entered" << endl;
        }
    }
    else
    {
        cout << argc << "   Not enough arguments" << endl;
    }
    return 0;
}
