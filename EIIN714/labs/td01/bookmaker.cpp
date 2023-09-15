//
// Created by Maxime BILLY on 15/09/2023.
//

#include <iostream>
#include <fstream>

struct BookRecord {
    std::string name;
    int price;
};

std::ostream& operator<<(std::ostream& os, const BookRecord& record) {
    os << "BookRecord <Name: \"" << record.name << "\", Price: " << record.price << ">" << std::endl;
    return os;
}

std::vector<BookRecord> read_records() {
    std::vector<BookRecord> records;
    std::string name;
    int price;

    std::ifstream file("/Users/ozeliurs/Desktop/Polytech/EIIN714/labs/td01/records.txt");

    while (file >> name >> price) {
        records.push_back(BookRecord{name, price});
    }

    return records;
}

void display_client(std::vector<BookRecord> records, std::string name) {
    int total = 0;

    for (auto record : records) {
        if (record.name == name) {
            std::cout << record;
            total += record.price;
        }
    }

    std::cout << std::endl << "Total: " << total << std::endl;
}

int main() {
    std::vector<BookRecord> records = read_records();

    for (auto record : records) {
        std::cout << record;
    }

    std::string name;

    std::cout << std::endl << "Veuillez entrer un nom: ";
    std::cin >> name;

    display_client(records, name);
}
