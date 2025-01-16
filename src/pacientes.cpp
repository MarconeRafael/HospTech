#include "pacientes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

// Implementação da classe Paciente

Paciente::Paciente() : nome(""), cpf(""), idade(0), genero("") {}

Paciente::Paciente(const std::string& nome, const std::string& cpf, int idade, const std::string& genero)
    : nome(nome), cpf(cpf), idade(idade), genero(genero) {}

std::string Paciente::getNome() const {
    return nome;
}

void Paciente::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Paciente::getCpf() const {
    return cpf;
}

void Paciente::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

int Paciente::getIdade() const {
    return idade;
}

void Paciente::setIdade(int idade) {
    this->idade = idade;
}

std::string Paciente::getGenero() const {
    return genero;
}

void Paciente::setGenero(const std::string& genero) {
    this->genero = genero;
}

// Implementação da classe GerenciamentoPacientes

void GerenciamentoPacientes::adicionarPaciente(const Paciente& paciente) {
    pacientes.push_back(paciente);
}

void GerenciamentoPacientes::editarPaciente(const std::string& cpf, const Paciente& paciente) {
    for (auto& p : pacientes) {
        if (p.getCpf() == cpf) {
            p = paciente;
            return;
        }
    }
    throw std::invalid_argument("Paciente com CPF " + cpf + " não encontrado.");
}

void GerenciamentoPacientes::removerPaciente(const std::string& cpf) {
    for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
        if (it->getCpf() == cpf) {
            pacientes.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Paciente com CPF " + cpf + " não encontrado.");
}

std::vector<Paciente> GerenciamentoPacientes::listarPacientes() const {
    return pacientes;
}

Paciente GerenciamentoPacientes::buscarPacientePorCpf(const std::string& cpf) const {
    for (const auto& p : pacientes) {
        if (p.getCpf() == cpf) {
            return p;
        }
    }
    throw std::invalid_argument("Paciente com CPF " + cpf + " não encontrado.");
}

void GerenciamentoPacientes::carregarPacientesDoArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo " + nomeArquivo);
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string nome, cpf, genero;
        int idade;
        std::getline(ss, nome, ',');
        std::getline(ss, cpf, ',');
        ss >> idade;
        ss.ignore(); // Ignorar a vírgula
        std::getline(ss, genero);
        
        pacientes.push_back(Paciente(nome, cpf, idade, genero));
    }
}

void GerenciamentoPacientes::salvarPacientesNoArquivo(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo " + nomeArquivo);
    }

    for (const auto& p : pacientes) {
        arquivo << p.getNome() << ","
                << p.getCpf() << ","
                << p.getIdade() << ","
                << p.getGenero() << "\n";
    }
}
