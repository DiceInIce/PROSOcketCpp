#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

struct Product
{
	int id = 1;
	string name;
	double price;
	int quantity;
	string category;

	string to_string_custom() const {
		return to_string(id) + " | " + name + " | " + to_string(price) + " | " + to_string(quantity) + " | " + category;
	}

	static Product from_string(const string& str) {
		Product p;
		size_t pos1 = str.find('|');
		size_t pos2 = str.find('|', pos1+1);
		size_t pos3 = str.find('|', pos2 + 1);
		size_t pos4 = str.find('|', pos3 + 1);

		p.id = stoi(str.substr(0, pos1));
		p.name = str.substr(pos1 + 1, pos2 - pos1 - 1);
		p.price = stod(str.substr(pos2 + 1, pos3 - pos2 - 1));
		p.quantity = stoi(str.substr(pos3 + 1, pos4 - pos3 - 1));
		p.category = str.substr(pos4 + 1);
		return p;
	}

	void print() {
		cout << "ID: " << this->id << endl;
		cout << "��������: " << this->name << endl;
		cout << "����: " << this->price << endl;
		cout << "����������: " << this->quantity << endl;
		cout << "���������: " << this->category << endl;
	}

	void validate() {
		if (id <= 0) throw invalid_argument("ID ������ ������ ���� �������������!");
		if (name.empty()) throw invalid_argument("�������� ������ �� ������ ���� ������!");
		if (price <= 0) throw invalid_argument("���� ������ ������ ���� �������������!");
		if (quantity <= 0) throw invalid_argument("���������� ������ �� ������ ���� �������������!");
		if (category.empty()) throw invalid_argument("��������� ������ �� ����� ���� ������!");

	}

	static Product input_product(bool requiredId = true) {
		Product p;

		if (requiredId) {
			cout << "������� ID ������: ";
			cin >> p.id;
		}

		cout << "������� ������������ ������: ";
		cin >> p.name;

		cout << "������� ���� ������: ";
		cin >> p.price;

		cout << "������� ���������� ������: ";
		cin >> p.quantity;

		cout << "������� ��������� ������: ";
		cin >> p.category;

		return p;
	}

};


#endif // PRODUCT_H
