#include <iostream>
#include "pacientes.h"
#include "auditoria.h"

void exibirMenuPacientes() {
    std::cout << "============= GERENCIAMENTO DE PACIENTES =============\n";
    std::cout << "1. Adicionar novo paciente\n";
    std::cout << "2. Listar todos os pacientes\n";
    std::cout << "3. Buscar paciente por CPF\n";
    std::cout << "4. Editar paciente\n";
    std::cout << "5. Remover paciente\n";
    std::cout << "6. Carregar pacientes de arquivo\n";
    std::cout << "7. Salvar pacientes em arquivo\n";
    std::cout << "0. Voltar ao menu principal\n";
    std::cout << "=====================================================\n";
    std::cout << "Escolha uma opção: ";
}

void menuPacientes(GerenciamentoPacientes& gerenciamentoPacientes, const std::string& nomeArquivo) {
    int opcaoPacientes;
    Auditoria auditoria;
    do {
        exibirMenuPacientes();
        std::cin >> opcaoPacientes;

        switch (opcaoPacientes) {
            case 1: {
                // Adicionar paciente
                std::string nome, cpf, genero;
                int idade;

                std::cout << "Digite o nome do paciente: ";
                std::cin.ignore();
                std::getline(std::cin, nome);

                std::cout << "Digite o CPF do paciente: ";
                std::getline(std::cin, cpf);

                std::cout << "Digite a idade do paciente: ";
                std::cin >> idade;

                std::cout << "Digite o gênero do paciente: ";
                std::cin.ignore();
                std::getline(std::cin, genero);

                Paciente paciente(nome, cpf, idade, genero);
                gerenciamentoPacientes.adicionarPaciente(paciente);

                std::cout << "Paciente adicionado com sucesso!\n";
                auditoria.registrarAtividade("Adicinando paciente!");
                break;
            }
            case 2: {
                // Listar todos os pacientes
                auto pacientes = gerenciamentoPacientes.listarPacientes();
                if (pacientes.empty()) {
                    std::cout << "Nenhum paciente cadastrado.\n";
                } else {
                    std::cout << "Lista de pacientes cadastrados:\n";
                    for (const auto& paciente : pacientes) {
                        std::cout << "- Nome: " << paciente.getNome()
                                  << ", CPF: " << paciente.getCpf()
                                  << ", Idade: " << paciente.getIdade()
                                  << ", Gênero: " << paciente.getGenero() << "\n";
                    }
                }
                auditoria.registrarAtividade("Listando agendamentos!");
                break;
            }
            case 3: {
                // Buscar paciente por CPF
                std::string cpf;
                std::cout << "Digite o CPF do paciente: ";
                std::cin.ignore();
                std::getline(std::cin, cpf);

                try {
                    Paciente paciente = gerenciamentoPacientes.buscarPacientePorCpf(cpf);
                    std::cout << "Paciente encontrado:\n";
                    std::cout << "- Nome: " << paciente.getNome()
                              << ", CPF: " << paciente.getCpf()
                              << ", Idade: " << paciente.getIdade()
                              << ", Gênero: " << paciente.getGenero() << "\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                auditoria.registrarAtividade("Buscando pacientes por CPF...");
                break;
            }
            case 4: {
                // Editar paciente
                std::string cpf;
                std::cout << "Digite o CPF do paciente a ser editado: ";
                std::cin.ignore();
                std::getline(std::cin, cpf);

                try {
                    Paciente paciente = gerenciamentoPacientes.buscarPacientePorCpf(cpf);

                    std::string novoNome, novoGenero;
                    int novaIdade;

                    std::cout << "Digite o novo nome (ou pressione Enter para manter): ";
                    std::getline(std::cin, novoNome);

                    std::cout << "Digite a nova idade (ou -1 para manter): ";
                    std::cin >> novaIdade;

                    std::cout << "Digite o novo genero (ou pressione Enter para manter): ";
                    std::cin.ignore();
                    std::getline(std::cin, novoGenero);

                    if (!novoNome.empty()) paciente.setNome(novoNome);
                    if (novaIdade >= 0) paciente.setIdade(novaIdade);
                    if (!novoGenero.empty()) paciente.setGenero(novoGenero);

                    gerenciamentoPacientes.editarPaciente(cpf, paciente);
                    std::cout << "Paciente editado com sucesso!\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                auditoria.registrarAtividade("Buscando pacientes editado por CPF...");
                break;
            }
            case 5: {
                // Remover paciente
                std::string cpf;
                std::cout << "Digite o CPF do paciente a ser removido: ";
                std::cin.ignore();
                std::getline(std::cin, cpf);

                try {
                    gerenciamentoPacientes.removerPaciente(cpf);
                    std::cout << "Paciente removido com sucesso!\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                auditoria.registrarAtividade("Removendo paciente!");
                break;
            }
            case 6: {
                // Carregar pacientes de arquivo
                try {
                    gerenciamentoPacientes.carregarPacientesDoArquivo(nomeArquivo);
                    std::cout << "Pacientes carregados do arquivo com sucesso!\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                auditoria.registrarAtividade("Carregando pacientes do arquivo...");
                break;
            }
            case 7: {
                // Salvar pacientes no arquivo
                try {
                    gerenciamentoPacientes.salvarPacientesNoArquivo(nomeArquivo);
                    std::cout << "Pacientes salvos no arquivo com sucesso!\n";
                } catch (const std::runtime_error& e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                auditoria.registrarAtividade("Salvando pacientes no arquivo!");
                break;
            }
            case 0:
                std::cout << "Voltando ao menu principal...\n";
                break;
            default:
                std::cerr << "Opção inválida! Tente novamente.\n";
        }
    } while (opcaoPacientes != 0);
}
