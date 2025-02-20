#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdio.h>
#include <conio.h>
using namespace std;
namespace fs = std::filesystem;

ifstream in_file;
const string mainPath = "C:\\Users\\oisyz\\OneDrive\\Desktop\\arquivostxt\\";

void edit() {
	fs::path pathEdit(mainPath);
	fs::recursive_directory_iterator end;
	int counterEdit = 0;

	for (fs::recursive_directory_iterator i(pathEdit); i != end ; i++)
	{
		counterEdit++;
		cout << counterEdit << " - Arquivo: " << i->path().filename().string() << endl;
	}

	if (fs::exists(mainPath))
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string newContent;
		string nameEdit;
		string line;
		cout << "Digite o nome do arquivo que deseja editar(sem .txt): \n";
		getline(cin, nameEdit);
		in_file.open(mainPath + nameEdit + ".txt");
		
		if (in_file)
		{
			getline(in_file, line);
			in_file >> line;
			cout << "Conteudo escrito: " << endl;
			cout << "'" << line << "'" << endl;

			cout << "\n" << "digite o novo conteudo do arquivo: ";
			getline(cin, newContent);

			if (newContent != "")
			{
				ofstream streamEdit(mainPath + nameEdit + ".txt");

				if (streamEdit.is_open())
				{
					streamEdit << newContent;
					streamEdit.close();
					in_file.close();
					cout << "Arquivo criado com sucesso!";
					system("clear");
				}
			}
		}
	}
}

//function for notexists exception in deleteArch
void deleteException() {
	cerr << "Arquivo nao encontrado";

	string nameDelete;
	cout << "\n" << "Digite o nome do arquivo novamente: ";
	cin >> nameDelete;

	fs::path pathDelete(mainPath + nameDelete + ".txt");

	//verify if pathdelete exists
	if (!fs::exists(pathDelete))
	{
		deleteException();
		cout << "Arquivo deletado com sucesso! ";
	}
}

void deleteArch() {
	fs::path path(mainPath);
	fs::recursive_directory_iterator end;
	
	int counter = 1;

	for (fs::recursive_directory_iterator i(path); i != end; ++i)
	{
		cout << counter << " - Arquivo: " << i -> path().filename().string() << endl;
		counter++;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string nameDelete;
	cout << "Digite o nome do arquivo que você quer deletar (sem .txt): ";
	getline(cin, nameDelete);
	
	fs::path pathDelete(mainPath + nameDelete + ".txt");

	if (!fs::exists(pathDelete))
	{
		deleteException();
	}

	else
	{
		remove(pathDelete);
		cout << "Arquivo deletado com sucesso";
	}
}

void create() {
	string nameArch;
	string content;

	cout << "Write a name for the archive: ";
	cin >> nameArch;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Write the content: ";
	getline(cin, content);

	ofstream stream(mainPath + nameArch + ".txt");

	if (stream.is_open())
	{
		cout << "Arquivo criado com sucesso!";
		stream << content;
		stream.close();
	}

	else cout << "failed to create the archive";
}

int main()
{	
	int numeros;
	int opt;
		cout << "\n Type a option: \n 1 - Create \n 2 - Edit \n 3 - Edit \n 4 - Exit \n:";
		cin >> opt;
		switch (opt)
		{
		case 1:
			create();
			main();
		case 2:
			edit();
			main();
		case 3:
			deleteArch();
			main();
		case 4:
			EXIT_SUCCESS;
		default:
			cout << "digite uma entrada válida: ";
		}	
}
