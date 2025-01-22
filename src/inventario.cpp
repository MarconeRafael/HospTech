#include "inventario.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

Item::Item(const std::string& nome, int quantidade, const std::string& descricao)
    : nome(nome), quantidade(quantidade), descricao(descricao) {}

std::string Item::getNome() const {
    return nome;
}

int Item::getQuantidade() const {
    return quantidade;
}

std::string Item::getDescricao() const {
    return descricao;
}

void Item::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

void Inventario::adicionarItem(const Item& item) {
    itens.push_back(item);
    salvarInventario();
}

void Inventario::atualizarItem(const std::string& nome, int quantidade) {
    auto it = std::find_if(itens.begin(), itens.end(), [&nome](const Item& item) {
        return item.getNome() == nome;
    });

    if (it != itens.end()) {
        it->setQuantidade(quantidade);
        salvarInventario();
    } else {
        std::cerr << "Item não encontrado!" << std::endl;
    }
}

void Inventario::buscarItem(const std::string& nome) {
    for (const auto& item : itens) {
        if (item.getNome() == nome) {
            std::cout << "Item encontrado: " << item.getNome() << ", Quantidade: " << item.getQuantidade() << ", Descrição: " << item.getDescricao() << "\n";
            return;
        }
    }
    std::cout << "Item não encontrado.\n";
}

void Inventario::listarItens() const {
    for (const auto& item : itens) {
        std::cout << "Nome: " << item.getNome() << ", Quantidade: " << item.getQuantidade() << ", Descrição: " << item.getDescricao() << std::endl;
    }
}

void Inventario::salvarInventario() const {
    std::ofstream arquivo(caminhoArquivo);
    if (arquivo.is_open()) {
        for (const auto& item : itens) {
            arquivo << item.getNome() << "," << item.getQuantidade() << "," << item.getDescricao() << "\n";
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo para salvar o inventário." << std::endl;
    }
}

void Inventario::carregarInventario() {
    std::ifstream arquivo(caminhoArquivo);
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string nome, descricao;
            int quantidade;
            std::getline(ss, nome, ',');
            ss >> quantidade;
            ss.ignore();
            std::getline(ss, descricao);
            itens.push_back(Item(nome, quantidade, descricao));
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo para carregar o inventário." << std::endl;
    }
}
