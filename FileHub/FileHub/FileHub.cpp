#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdio.h>
#include <vector>
#include <conio.h>
using namespace std;
namespace fs = std::filesystem;

ifstream inf_file;

vector<string> porcentagem(string pathAnalyse) {
    fs::path pathForAnalyse(pathAnalyse);
    fs::recursive_directory_iterator end;
    vector<string> extensoes;
    vector<int> quantidades;
    for (fs::recursive_directory_iterator i(pathForAnalyse); i != end; i++) 
    {
        fs::path pathAtual = i->path();

         if (pathAtual.has_extension()){

             string extensao = pathAtual.extension().string();
             bool Notexists = true;

             for (int j = 0; j < extensoes.size(); ++j) {

                if(extensoes[j] == extensao) {
                    quantidades[j] += 1;
                    Notexists = false;
                    break;
                }
             }

             if (Notexists) {
                 extensoes.push_back(extensao);
                 quantidades.push_back(1);
             }

        }
    }

    return extensoes;
}

int main()
{
    string caminho = "C:\\Users\\oisyz\\OneDrive\\Desktop";
    vector<string> extensoes = porcentagem(caminho);
    
    for (string item : extensoes) {
        cout << item << ", ";
    }

    return 0;
}
