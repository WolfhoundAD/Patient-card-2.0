#ifndef list1_H //����� ���������
#define list1_H
#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>


using namespace std;
class list {
public:

	class item {
	private:

		int item_num;     //����� ����������� �����

		string item_name;  // �������
		string item_name1; //��� 
		string item_name2; //��������
		string item_address; //�����
		string item_diagnosis; //�������
		string item_namedoctor; //������� �����

		item* prev;
		item* next;
	
	public:
		//�����������
		item(int i_num = 0, string i_name = 0, string i_name1 = 0, string i_name2 = 0, string i_adress = 0, string i_diagnosis = 0, string i_namedoctor = 0);
		


		//��������� ������� �������
		int get_item_num() const;
		string get_item_name() const;
		string get_item_name1() const;
		string get_item_name2() const;
		string get_item_address() const;
		string get_item_diagnosis() const;
		string get_item_namedoctor() const;



		item* get_prev() const;
		item* get_next() const;

		// ��������� �������� ������� �������
		void set_item_num(int new_item_num);
		void set_item_name(string new_item_name);
		void set_item_name1(string new_item_name1);
		void set_item_name2(string new_item_name2);
		void set_item_address(string new_item_address);
		void set_item_diagnosis(string new_item_diagnosis);
		void set_item_namedoctor(string new_item_namedoctor);

		void set_prev(item* new_prev);
		void set_next(item* new_next);
	};
private:
	item* pbeg, * pend; //��������� �� ������ � ����� ������
public:
	list() { pbeg = 0; pend = 0; } //�����������
	~list(); //����������


	//����� �������� ������ �� �������
	bool is_empty();

	//����� ������������� �������
	void add_sort(int i_num, string i_name, string i_name1, string i_name2, string i_adress, string i_diagnosis, string i_namedoctor);

	//����� ������ �� �����
	item* find(int i_num);

	//����� ������ �� ���������� �����
	bool find_data(string field_name, string key);

	//����� �������� 
	bool remove(int key);

	//����� ������
	void show();
private:
	//����� �����
	void hline();
};
#endif /* list1_H */
