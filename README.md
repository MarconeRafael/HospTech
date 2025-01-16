
# HospTech - Sistema de Gestão Hospitalar

HospTech é um sistema de gerenciamento hospitalar modular que visa automatizar e otimizar diversas áreas de um hospital, incluindo o controle de pacientes, agendamentos, inventário médico, financeiro, prescrição de medicamentos e muito mais. O sistema foi projetado para ser escalável, com uma estrutura modular que permite o fácil acréscimo de novas funcionalidades.

## Funcionalidades

O sistema possui diversos módulos para atender a diferentes necessidades de um hospital:

- **Gerenciamento de Pacientes**: Cadastro, edição e consulta de informações dos pacientes.
- **Gerenciamento Financeiro**: Controle de faturamento, cobranças e pagamentos dos pacientes.
- **Controle de Inventário Médico**: Registro e controle de estoque de materiais e medicamentos.
- **Controle de Agendamentos**: Agendamento e gerenciamento de consultas e exames médicos.
- **Controle de Leitos**: Monitoramento de ocupação e disponibilidade de leitos no hospital.
- **Gestão de Prescrições Eletrônicas (PEP)**: Registro e gestão de prescrições de medicamentos.
- **Sistema de Autenticação**: Controle de acessos e logins com diferentes níveis de permissão.

## Estrutura de Diretórios

A estrutura do projeto é organizada da seguinte forma:

```
hosptech/
│
├── build/                 # Arquivos de compilação gerados pelo CMake
├── include/               # Arquivos de cabeçalho (.h) do sistema
├── src/                   # Implementações em .cpp de cada funcionalidade
├── config/                # Arquivo de configuração principal
├── data/                  # Dados persistentes (pacientes, inventário, etc.)
├── docs/                  # Documentação do projeto
├── CMakeLists.txt         # Arquivo de configuração do CMake
└── README.md              # Documentação principal do projeto
```

## Tecnologias Utilizadas

- **C++**: Linguagem de programação principal para desenvolvimento do sistema.
- **CMake**: Ferramenta para gerenciar o processo de construção e compilação.
- **SQLite** ou **Arquivos CSV**: Para armazenamento de dados persistentes (dependendo da complexidade desejada).
- **Doxygen**: Ferramenta para gerar documentação automática do código.

## Como Rodar o Projeto

### Pré-requisitos

- **CMake** instalado no sistema.
- **Compilador C++** (GCC, Clang ou equivalente).
- **SQLite** (se optar por usar banco de dados, caso contrário, arquivos CSV serão usados).

### Passos

1. Clone este repositório:

   ```bash
   git clone https://github.com/usuario/hosptech.git
   cd hosptech
   ```

2. Crie os arquivos de build:

   ```bash
   cmake -S . -B build
   ```

3. Compile o projeto:

   ```bash
   cmake --build build
   ```

4. Execute o programa:

   ```bash
   ./build/hosptech
   ```

## Estrutura de Dados

Os dados do sistema são armazenados na pasta `data/` em arquivos CSV. A estrutura de arquivos inclui:

- **pacientes.csv**: Contém informações dos pacientes.
- **inventario.csv**: Controle de itens no inventário.
- **agendamentos.csv**: Dados de consultas e exames agendados.
- **leitos.csv**: Estado dos leitos do hospital.
- **prescricao.hgm**: Prescrições dos pacientes.
- **relatorios/**: Pasta contendo relatórios gerados pelo sistema.

## Contribuindo

Se você deseja contribuir para o projeto, siga os passos abaixo:

1. Fork este repositório.
2. Crie uma branch para a sua funcionalidade ou correção (`git checkout -b feature/nome-da-funcionalidade`).
3. Faça as alterações e commit (`git commit -am 'Adiciona nova funcionalidade'`).
4. Faça push para a branch (`git push origin feature/nome-da-funcionalidade`).
5. Abra um Pull Request.

## Licença

Este projeto está licenciado sob a **MIT License** - veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## Contato

Para dúvidas ou mais informações, entre em contato com os desenvolvedores.
