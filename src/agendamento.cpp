#include "agendamentos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

Agendamento::Agendamento() : paciente(""), cpf(""), data(""), hora(""), tipo("") {}

Agendamento::Agendamento(const std::string& paciente, const std::string& cpf, const std::string& data, const std::string& hora, const std::string& tipo)
    : paciente(paciente), cpf(cpf), data(data), hora(hora), tipo(tipo) {}

std::string Agendamento::getPaciente() const {
    return paciente;
}
std::string Agendamento::getCPF() const {
    return cpf;
}
std::string Agendamento::getData() const {
    return data;
}

std::string Agendamento::getHora() const {
    return hora;
}

std::string Agendamento::getTipo() const {
    return tipo;
}

void Agenda::adicionarAgendamento(const Agendamento& agendamento) {
    if (verificarConflito(agendamento.getData(), agendamento.getHora(), agendamento.getTipo())) {
        std::cerr << "Esse horário já não possui vagas!" << std::endl;
        return;
    }
    agendamentos.push_back(agendamento);
    salvarAgendamentos();
}
void Agenda::listarAgendamentos() const {
    for (const auto& agendamento : agendamentos) {
        std::cout << "Paciente: " << agendamento.getPaciente() << ", CPF: " << agendamento.getCPF() << ", Data: " << agendamento.getData() << ", Hora: " << agendamento.getHora() << ", Tipo: " << agendamento.getTipo() << std::endl;
    }
}

void Agenda::salvarAgendamentos() const {
    std::ofstream arquivo(caminhoArquivo);
    if (arquivo.is_open()) {
        for (const auto& agendamento : agendamentos) {
            arquivo << agendamento.getPaciente() << "," << agendamento.getCPF() << "," << agendamento.getData() << "," << agendamento.getHora() << "," << agendamento.getTipo() << "\n";
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo para salvar os agendamentos." << std::endl;
    }
}

void Agenda::carregarAgendamentos() {
    std::ifstream arquivo(caminhoArquivo);
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string paciente, cpf, data, hora, tipo;
            std::getline(ss, paciente, ',');
            std::getline(ss, cpf, ',');
            std::getline(ss, data, ',');
            std::getline(ss, hora, ',');
            std::getline(ss, tipo);
            agendamentos.push_back(Agendamento(paciente, cpf, data, hora, tipo));
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo para carregar os agendamentos." << std::endl;
    }


}
void Agenda::excluirAgendamento(const std::string& cpf, const std::string& data, const std::string& hora) {
    auto it = std::remove_if(agendamentos.begin(), agendamentos.end(), [&cpf, &data, &hora](const Agendamento& agendamento) {
        return agendamento.getCPF() == cpf && agendamento.getData() == data && agendamento.getHora() == hora;
    });

    if (it != agendamentos.end()) {
        agendamentos.erase(it, agendamentos.end());
        salvarAgendamentos();
        std::cout << "Agendamento excluído com sucesso!" << std::endl;
    } else {
        std::cerr << "Agendamento não encontrado!" << std::endl;
    }
}

void Agenda::atualizarAgendamento(const std::string& cpf, const std::string& novaData, const std::string& novaHora) {
    for (auto& agendamento : agendamentos) {
        if (agendamento.getCPF() == cpf) {
            agendamento = Agendamento(agendamento.getPaciente(), cpf, novaData, novaHora, agendamento.getTipo());
            salvarAgendamentos();
            std::cout << "Agendamento atualizado com sucesso!" << std::endl;
            return;
        }
    }
    std::cerr << "Agendamento não encontrado!" << std::endl;
}

bool Agenda::verificarConflito(const std::string& data, const std::string& hora, const std::string& tipo) const {
    for (const auto& agendamento : agendamentos) {
        if (agendamento.getData() == data && agendamento.getHora() == hora && agendamento.getTipo() == tipo) {
            return true;
        }
    }
    return false;
}
void Agenda::gerenciarAgendamentos(Agenda& agenda) {
    int opcao = 0;
    do {
        std::cout << "Controle de Agendamentos\n";
        std::cout << "1. Adicionar Agendamento\n";
        std::cout << "2. Listar Agendamentos\n";
        std::cout << "3. Excluir Agendamento\n";
        std::cout << "4. Atualizar Agendamento\n";
        std::cout << "5. Voltar ao Menu Principal\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        if (std::cin.fail()) { 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Digite um numero!\n"; 
            continue; 
        }
        std::string paciente, cpf, data, hora, tipo;
        
        bool pacienteEncontrado = false;
        switch (opcao) {
            case 1:
                std::cout << "Nome do paciente: ";
                std::getline(std::cin >> std::ws, paciente);
                std::cout << "CPF do paciente: ";
                std::getline(std::cin, cpf);
                std::cout << "Data (DD/MM/AAAA): ";
                std::getline(std::cin, data);
                std::cout << "Hora (HH:MM): ";
                std::getline(std::cin, hora);
                std::cout << "Tipo (Consulta/Exame): ";
                std::getline(std::cin, tipo);

                agenda.adicionarAgendamento(Agendamento(paciente, cpf, data, hora, tipo));
                break;
            case 2:
                agenda.listarAgendamentos();
                break;
            case 3:
                std::cout << "CPF do paciente: ";
                std::getline(std::cin >> std::ws, cpf);
                std::cout << "Data (DD/MM/AAAA): ";
                std::getline(std::cin, data);
                std::cout << "Hora (HH:MM): ";
                std::getline(std::cin, hora);
                agenda.excluirAgendamento(cpf, data, hora);
                break;
            case 4:
                std::cout << "CPF do paciente: ";
                std::cin >> cpf;
                for (const auto& agendamento : agenda.agendamentos) {
                    if (agendamento.getCPF() == cpf) {
                        pacienteEncontrado = true;
                        break;
                    }
                }
                if (!pacienteEncontrado) {
                    std::cerr << "Paciente não encontrado!" << std::endl;
                    break;
                }
                std::cout << "Nova data (DD/MM/AAAA): ";
                std::cin >> data;
                std::cout << "Nova hora (HH:MM): ";
                std::cin >> hora;
                atualizarAgendamento(cpf, data, hora);
                break;
            case 5:
                std::cout << "Voltando ao Menu Principal...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 5);
}