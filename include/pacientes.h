#ifndef PACIENTES_H
#define PACIENTES_H

#include <string>
#include <vector>

// Classe Paciente
class Paciente {
public:
    // Construtores
    Paciente();
    Paciente(const std::string& nome, const std::string& cpf, int idade, const std::string& genero);

    // Getters e Setters
    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getCpf() const;
    void setCpf(const std::string& cpf);

    int getIdade() const;
    void setIdade(int idade);

    std::string getGenero() const;
    void setGenero(const std::string& genero);

private:
    std::string nome;
    std::string cpf;
    int idade;
    std::string genero;
};

// Classe de Gerenciamento de Pacientes
class GerenciamentoPacientes {
public:
    // Função para adicionar um paciente
    void adicionarPaciente(const Paciente& paciente);

    // Função para editar um paciente
    void editarPaciente(const std::string& cpf, const Paciente& paciente);

    // Função para remover um paciente
    void removerPaciente(const std::string& cpf);

    // Função para listar todos os pacientes
    std::vector<Paciente> listarPacientes() const;

    // Função para buscar um paciente pelo CPF
    Paciente buscarPacientePorCpf(const std::string& cpf) const;

    // Função para carregar pacientes de um arquivo CSV (exemplo)
    void carregarPacientesDoArquivo(const std::string& nomeArquivo);

    // Função para salvar pacientes em um arquivo CSV (exemplo)
    void salvarPacientesNoArquivo(const std::string& nomeArquivo) const;

private:
    std::vector<Paciente> pacientes;
};

#endif // PACIENTES_H
