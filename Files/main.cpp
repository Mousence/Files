#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
//#define FromTxtToDHCPD
//#define Reverse_IP_MAC

int main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout; // Создаем поток
	fout.open("File.txt", std::ios_base::app); // Открываем поток
	fout << "Hello Files "; // Пишем в поток
	fout << "Сам привет!\n";
	cout << "Hello Files";
	fout.close(); // Когда поток уже не нужен, его обязательно нужно закрыть.

	system("notepad File.txt");
#endif
#ifdef READ_FROM_FILE
	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open()) {
	//TODO: read file
		const int SIZE = 10240;
		char sz_buffer[SIZE] = {};
		while (!fin.eof()) { //eof -end of file
			
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else {
		std::cerr << "Erroe: File not found" << endl;
	}
#endif
#ifdef FromTxtToDHCPD
	setlocale(LC_ALL, "");

	std::ifstream inputFile("201 RAW.txt");
	std::ofstream outputFile("201.dhcpd");

	if (!inputFile.is_open()) {
		std::cerr << "Error: File doesnt exist!" << endl;
		return 0;
	}
	if (!outputFile.is_open()) {
		std::cerr << "Error: File doesnt exist!" << endl;
		return 0;
	}

	std::string line;
	int i = 0;
	while (std::getline(inputFile, line)) {
		std::string ip;
		std::string mac;
		std::istringstream iss(line);
		iss >> ip >> mac;

		i++;
		outputFile << "host 201-" << i << "\n{" << "\thardware ethernet\t" << mac << ";\n\tfixed-address\t" << ip << ";\n}" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
#endif
#ifdef Reverse_IP_MAC
	std::ifstream inputFile("201 RAW.txt");
	std::ofstream outputFile("201 ready.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Error: File doesnt exist!" << endl;
		return 0;
	}
	if (!outputFile.is_open()) {
		std::cerr << "Error: File doesnt exist!" << endl;
		return 0;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		std::string ip;
		std::string mac;
		std::istringstream iss(line);
		iss >> ip >> mac;

		outputFile << mac << "\t" << ip << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
#endif // Reverse_IP_MAC


}