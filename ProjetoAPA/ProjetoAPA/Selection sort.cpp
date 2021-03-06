// ProjetoAPA.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::ifstream arquivo;
std::vector<int> vetor;


int main() {
	std::string arquivoname;
	std::cout << "Selection Sort:" << std::endl << "Digite o nome do arquivo(ex. exemplo.txt): ";
	std::cin >> arquivoname;

	arquivo.open(arquivoname.data());
	if (!arquivo.is_open()) {
		system("pause");
		return -1;
	}
	int i, j, aux;
	std::string stringer;
	while(!arquivo.eof()){
		std::getline(arquivo, stringer);
		int num = std::stoi(stringer);
		vetor.push_back(num);
	}
	for (i = 0; i < vetor.size() - 1; i++) {
		int min;
		min = i;
		for (j = i + 1; j < vetor.size(); j++) {
			if (vetor[j] < vetor[min])
				min = j;
		}
		if (min != i) {
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
		}
	}
	for (i = 0; i < vetor.size(); i++) {
		std::cout << vetor[i] << " " << std::endl;
	}
	system("pause");
	return 0;
}

