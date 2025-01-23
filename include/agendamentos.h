#ifndef AGENDAMENTOS_H
#define AGENDAMENTOS_H

#include <string>
#include <vector>

class Agendamento {
public:
    Agendamento();
    Agendamento(const std::string& paciente, const std::string& data, const std::string& hora, const std::string& tipo);

    std::string getPaciente() const;
    std::string getData() const;
    std::string getHora() const;
    std::string getTipo() const;

private:
    std::string paciente;
    std::string data;
    std::string hora;
    std::string tipo;
};

class Agenda {
public:
    void adicionarAgendamento(const Agendamento& agendamento);
    void listarAgendamentos() const;
    void salvarAgendamentos() const;
    void carregarAgendamentos();
    void gerenciarAgendamentos(Agenda& agenda);
    void excluirAgendamento(const std::string& paciente, const std::string& data, const std::string& hora);

    void atualizarAgendamento(const std::string& paciente, const Agendamento& novoAgendamento);

private:
    std::vector<Agendamento> agendamentos;
    const std::string caminhoArquivo = "data/agendamentos.csv";
    bool verificarConflito(const std::string& data, const std::string& hora, const std::string& tipo) const;
};

#endif // AGENDAMENTOS_H
