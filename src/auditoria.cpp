#include "auditoria.h"
#include <iostream>
#include <fstream>
#include <ctime>


void Auditoria::registrarAtividade(const std::string& atividade) {
    std::ofstream arquivo("data/auditoria.csv", std::ios::app);
    if (arquivo.is_open()) {
        std::time_t agora = std::time(nullptr);
        std::tm* tempoLocal = std::localtime(&agora);
        arquivo << (tempoLocal->tm_year + 1900) << "-"
                << (tempoLocal->tm_mon + 1) << "-"
                << tempoLocal->tm_mday << ", "
                << tempoLocal->tm_hour << ":"
                << tempoLocal->tm_min << ":"
                << tempoLocal->tm_sec << ", "
                << atividade << std::endl;
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo de log." << std::endl;
    }
}

void Auditoria::listarAtividades() {
    std::ifstream arquivo("data/auditoria.csv");
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo de log." << std::endl;
    }
}

void Auditoria::carregarAtividades() {
    std::ifstream arquivo("data/auditoria.csv");
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            // Apenas carregar as atividades, sem imprimir
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo de log." << std::endl;
    }
}
