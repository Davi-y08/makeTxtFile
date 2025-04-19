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
    vector<string> extensoesInuteis = { ".tmp", ".log", ".bak", ".old", ".dmp", ".swp", ".swo", ".~",
        ".class", ".obj", ".o", ".pyc", ".pyo", ".cache", ".temp", ".aux",
        ".DS_Store", "Thumbs.db" };

    for (fs::recursive_directory_iterator i(pathForAnalyse); i != end; i++) 
    {
        fs::path pathAtual = i->path();

         if (pathAtual.has_extension()){

             string extensao = pathAtual.extension().string();
             string nomeArquivo = pathAtual.filename().string();
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

             for (const auto& lixo : extensoesInuteis) {
                 if (extensao == lixo || nomeArquivo == lixo) {
                     fs::remove(pathAtual);
                     break;
                 }
             }

        }
    }

    return extensoes;
}

int main()
{\
    string caminho = "C:\\Users\\oisyz\\OneDrive\\Documentos";
    vector<string> extensoes = porcentagem(caminho);
    
    for (string item : extensoes) {
        cout << item << ", ";
    }

    vector<string> extensoesApos = porcentagem(caminho);

    cout << "\n" << "Apos a limpeza: ";

    for (string item : extensoesApos) {
        
        cout << item << ", ";
    }

    return 0;
}
