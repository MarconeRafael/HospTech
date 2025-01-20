#include "inventario.h"
#include <iostream>
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
}

void Inventario::atualizarItem(const std::string& nome, int quantidade) {
    auto it = std::find_if(itens.begin(), itens.end(), [&nome](const Item& item) {
        return item.getNome() == nome;
    });

    if (it != itens.end()) {
        it->setQuantidade(quantidade);
    } else {
        std::cerr << "Item não encontrado!" << std::endl;
    }
}

void Inventario::buscarItem(const std::string& nome) {
     for (const auto& item : itens) { 
        if (item.getNome() == nome) { std::cout << "Item encontrado: " << item.getNome() << ", Quantidade: " << item.getQuantidade() << ", Descrição: " << item.getDescricao() << "\n"; 
        return; 
        } 
    } std::cout << "Item não encontrado.\n"; 
}
void Inventario::listarItens() const {
    for (const auto& item : itens) {
        std::cout << "Nome: " << item.getNome() << ", Quantidade: " << item.getQuantidade() << ", Descrição: " << item.getDescricao() << std::endl;
    }
}
