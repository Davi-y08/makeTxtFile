#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdio.h>
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
		string nameEdit;
		string line;
		cout << "Digite o nome do arquivo que deseja editar(sem .txt): \n";
		getline(cin, nameEdit);
		in_file.open(mainPath + nameEdit + ".txt");
		
		if (in_file)
		{
			getline(in_file, line);
			in_file >> line;
			cout << line;
			cout << "No arquivo";
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
	int opt;
	cout << "Type a option: 1 - Create, 2 - delete, 3 - edit, 4 - exit: ";
	cin >> opt;
	
	switch (opt)
	{
	case 1:
		create();
	case 2:
		deleteArch();
	case 3: 
		edit();
	}
}
