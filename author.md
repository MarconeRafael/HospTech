# Introduction
    Estrutura Geral

    Modularização: Divida o projeto em módulos:
        Pacientes: Gerenciamento de registros de pacientes.
        Financeiro: Gerenciamento de faturamento.
        Inventário: Controle de inventário médico.
        Agendamentos: Controle de consultas e exames.
        Leitos: Controle de ocupação e disponibilidade de leitos.
        Prescrições e PEP: Gestão de prescrições e prontuário eletrônico.
        Autenticação: Sistema de logins com diferentes níveis de acesso.

    Banco de Dados:
        Use um arquivo de texto ou banco de dados SQLite para armazenar as informações, dependendo do nível de complexidade desejado.

    Interface:
        Implementar uma interface básica no terminal utilizando menus interativos.

    Fluxo do Sistema:
        Criação e login de usuários.
        Navegação pelos módulos com base no nível de acesso.
# Estrutura de Diretórios:

    hosptech/
    │
    ├── build/
    │   ├── <arquivos de compilação gerados pelo CMake>
    │   ├── executáveis e binários intermediários
    │   ├── outros arquivos temporários
    │
    ├── include/
    │   ├── pacientes.h          # Declarações relacionadas ao gerenciamento de pacientes
    │   ├── financeiro.h         # Declarações para gerenciamento de faturamento
    │   ├── inventario.h         # Declarações para controle de inventário médico
    │   ├── agendamentos.h       # Declarações para controle de agendamentos
    │   ├── leitos.h             # Declarações para controle de leitos
    │   ├── prescricao.h         # Declarações para gestão de prescrições eletrônicas
    │   ├── usuario.h            # Declarações para controle de login e permissões de acesso
    │   ├── relatorios.h         # Declarações para geração de relatórios
    │   ├── notificacoes.h       # Declarações para envio de notificações
    │   └── utils.h              # Funções auxiliares e utilitárias
    │
    ├── src/
    │   ├── pacientes.cpp        # Implementação do gerenciamento de pacientes
    │   ├── financeiro.cpp       # Implementação do gerenciamento de faturamento
    │   ├── inventario.cpp       # Implementação do controle de inventário médico
    │   ├── agendamentos.cpp     # Implementação do controle de agendamentos
    │   ├── leitos.cpp           # Implementação do controle de leitos
    │   ├── prescricao.cpp       # Implementação da gestão de prescrições eletrônicas
    │   ├── usuario.cpp          # Implementação do controle de login e permissões de acesso
    │   ├── relatorios.cpp       # Implementação da geração de relatórios
    │   ├── notificacoes.cpp     # Implementação do envio de notificações
    │   └── main.cpp             # Ponto de entrada do programa
    │
    ├── config/
    │   └── hosptech.ini         # Arquivo de configuração principal para personalização do sistema
    │
    ├── data/
    │   ├── pacientes.csv        # Dados de pacientes
    │   ├── inventario.csv       # Dados de inventário
    │   ├── agendamentos.csv     # Dados de agendamentos
    │   ├── leitos.csv           # Dados de leitos disponíveis e ocupados
    │   ├── prescricao.hgm       # Arquivo para armazenamento de prescrições
    │   └── relatorios/          # Pasta para relatórios gerados
    │       ├── relatorio_2024.csv
    │       ├── ...
    │
    ├── docs/
    │   ├── Doxyfile             # Configuração para geração automática de documentação com Doxygen
    │   └── manual.md            # Manual do usuário
    │
    ├── CMakeLists.txt           # Arquivo de configuração para o CMake
    └── README.md                # Arquivo principal de documentação do projeto

    Explicação das Pastas

        build/: Diretório gerado automaticamente pelo CMake, contendo os arquivos de compilação.
        include/: Contém todos os arquivos de cabeçalho (.h) para a estrutura modular do sistema.
        src/: Contém os arquivos de implementação (.cpp) de cada funcionalidade.
        config/: Arquivo de configuração principal, onde os parâmetros do sistema são definidos.
        data/: Contém arquivos de dados persistentes, como informações de pacientes e inventário.
        docs/: Arquivos de documentação, incluindo configuração do Doxygen e manuais.
        CMakeLists.txt: Arquivo de configuração para compilar o projeto com o CMake.
        README.md: Documentação inicial para orientação sobre o projeto.


# Author(s)
Marcone Rafael do Nascimento Junior - marconerafael2017@gmail.com

José Wenderson da Cunha Silva - 
Roniel Santos de Lima  - 
# Problems found or limitations

<!-- TODO -->

Lista aqui os problemas encontrados (se houve algum) e as
possíveis limitações do programa.

# Grading

<!-- TODO -->

Preencha os itens que você implementou, indicando qual a nota esperada para cada item.
# Status do Projeto HospTech

| **Item**                                           | **Feito** | **Ações Propostas**                                                                            |
|----------------------------------------------------|-----------|-----------------------------------------------------------------------------------------------|
| Gerenciar registro de pacientes                    | sim       | Criar classes `Paciente` e `GestorPacientes`. Implementar funções para adicionar, editar e listar. |
| Gerenciar registro de faturamento                  | Não       | Criar classe `Financeiro`. Gerenciar cobranças e pagamentos por paciente.                     |
| Gerenciar registro de inventário médico            | Não       | Criar classe `Inventario`. Registrar, buscar e atualizar itens do estoque.                    |
| Logins de diferentes níveis de acesso              | Não       | Criar classe `Usuario` com níveis de acesso e autenticação.                                    |
| Área de pagamento                                  | Não       | Integrar com o módulo financeiro e gerar recibos.                                             |
| Contabiliza e acumula os pontos de várias partidas | Não       | Implementar função de relatório para visualização de estatísticas do hospital.                |
| Gestão de Agendamentos                             | Não       | Criar classe `Agendamento` para consultas e exames.                                           |
| Controle de Leitos                                 | Não       | Implementar monitoramento de ocupação e liberação de leitos.                                  |
| Prontuário Eletrônico do Paciente (PEP)            | Não       | Criar classe para histórico médico e consultas.                                               |
| Gestão de Prescrições Eletrônicas                  | Não       | Registrar e gerenciar prescrições associadas aos pacientes.                                   |
| Sistema de Relatórios                              | Não       | Gerar relatórios detalhados para pacientes, faturamento, inventário e desempenho geral.       |
| Notificações                                       | Não       | Enviar notificações sobre consultas, medicamentos ou faturamento pendente.                   |
| Dashboard para Administradores                     | Não       | Criar interface para visualização rápida de informações importantes, como ocupação e receitas. |
| Controle de Funcionários                           | Não       | Gerenciar cadastro e permissões dos profissionais de saúde.                                   |
| Integração com APIs Externas                       | Não       | Permitir integração com APIs de fornecedores ou sistemas externos.                            |
| Auditoria e Logs                                   | Não       | Registrar todas as atividades realizadas no sistema.                                          |
| Agendamento Automático de Consultas                | Não       | Implementar sugestões de horários disponíveis com base na agenda dos profissionais.           |
| Gestão de Medicamentos Controlados                 | Não       | Incluir controle especial para medicamentos de alta restrição, com permissões específicas.    |
| Histórico de Alterações nos Registros              | Não       | Permitir visualizar alterações feitas em registros.                                           |
| Controle de Recursos do Hospital                   | Não       | Gerenciar equipamentos, salas de cirurgia e outros recursos importantes.                      |


# Compiling and Runnig

<!-- TODO -->



cmake -S . -B build

cmake --build build

./build/hosptech