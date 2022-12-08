
#include "list1.h"

using namespace std;


		//��������� ������� �������
list::item::item(int i_num, string i_name, string i_name1, string i_name2, string i_adress, string i_diagnosis, string i_namedoctor)
{
	item_num = i_num;
	item_name = i_name;
	item_name1 = i_name1;
	item_name2 = i_name2;
	item_address = i_adress;
	item_diagnosis = i_diagnosis;
	item_namedoctor = i_namedoctor;

	next = 0; prev = 0;
}


		int list::item::get_item_num() const { return item_num; }
		string list::item::get_item_name() const { return item_name; }
		string list::item::get_item_name1() const { return item_name1; }
		string list::item::get_item_name2() const { return item_name2; }
		string list::item::get_item_address() const { return item_address; }
		string list::item::get_item_diagnosis() const { return item_diagnosis; }
		string list::item::get_item_namedoctor() const { return item_namedoctor; }


		list::item* list::item::get_prev() const { return prev; }
		list::item* list::item::get_next() const { return next; }

		// ��������� �������� ������� �������
		void list::item::set_item_num(int new_item_num) { item_num = new_item_num; }
		void list::item::set_item_name(string new_item_name) { item_name = new_item_name; }
		void list::item::set_item_name1(string new_item_name1) { item_name1 = new_item_name1; }
		void list::item::set_item_name2(string new_item_name2) { item_name2 = new_item_name2; }
		void list::item::set_item_address(string new_item_address) { item_address = new_item_address; }
		void list::item::set_item_diagnosis(string new_item_diagnosis) { item_diagnosis = new_item_diagnosis; }
		void list::item::set_item_namedoctor(string new_item_namedoctor) { item_namedoctor = new_item_namedoctor; }

		void list::item::set_prev(item* new_prev) { prev = new_prev; }
		void list::item::set_next(item* new_next) { next = new_next; }
	
	//��������� �� ������ � ����� ������
	list::item * pbeg, * pend; 



	//���������� ������ �������� ������ �� �������
	bool list::is_empty()
	{
		if (!pbeg) return true;
		else
			return false;
	}

	//���������� ������ ������������ �������
	void list::add_sort(int i_num, string i_name, string i_name1, string i_name2, string i_adress, string i_diagnosis, string i_namedoctor)
	{
		item* pv = new item(i_num, i_name, i_name1, i_name2, i_adress, i_diagnosis, i_namedoctor);
		if (!pbeg) //������� ������� ��������
		{
			pbeg = pend = pv;
			pv->set_prev(0);
		}
		else
		{
			item* pt = pbeg;
			while (pt) { //�������� ������
				if (i_num < pt->get_item_num())
				{
					pv->set_next(pt);
					if (pt == pbeg) //������� � ������
					{
						pv->set_prev(0);
						pbeg = pv;
					}
					else //������� � ��������
					{
						(pt->get_prev())->set_next(pv);
						pv->set_prev(pt->get_prev());
					}
					pt->set_prev(pv);
					return;
				}
				pt = pt->get_next();
			}
			pv->set_next(0); //������� � �����
			pv->set_prev(pend);
			pend->set_next(pv);
			pend = pv;
		}
	}

	//���������� ������ ������ �� �����
	list::item* list::find(int i_num)
	{
		item* pv = pbeg;
		while (pv) {
			if (pv->get_item_num() == i_num)
				break;
			pv = pv->get_next();
		}
		return pv;
	}

	//���������� ������ ������ �� ���������� �����
	bool list::find_data(string field_name, string key)
	{
		bool find = false;
		item* pv = pbeg;
		while (pv)
		{

			if ((field_name == "item_name" && pv->get_item_name() == key) || (field_name == "item_name" && pv->get_item_name1() == key) || (field_name == "item_name" && pv->get_item_name2() == key) ||
				(field_name == "item_name" && pv->get_item_address() == key) || (field_name == "item_name" && pv->get_item_diagnosis() == key) || (field_name == "item_name" && pv->get_item_namedoctor() == key))
			{
				find = true;
				cout << endl << "��������� ������:" << endl;
				cout << "����� ���. �����:" << pv->get_item_num() << endl;
				cout << "������� ��������:" << pv->get_item_name() << endl;
				cout << "��� ��������:" << pv->get_item_name1() << endl;
				cout << "�������� ��������:" << pv->get_item_name2() << endl;
				cout << "����� �������:" << pv->get_item_address() << endl;
				cout << "�������:" << pv->get_item_diagnosis() << endl;
				cout << "������� �������� �����:" << pv->get_item_namedoctor() << endl;
			}
			pv = pv->get_next();
		}
		return find;
	}

	//���������� ������ ��������
	bool list::remove(int key)
	{
		if (item* pkey = find(key))
		{
			if (pbeg == pend)
			{
				pbeg = pend = 0;
			}
			else
				if (pkey == pbeg)
				{
					pbeg = pbeg->get_next();
					pbeg->set_prev(0);
				}
				else
					if (pkey == pend)
					{
						pend = pend->get_prev();
						pend->set_next(0);
					}
					else
					{
						(pkey->get_prev())->set_next(pkey->get_next());
						(pkey->get_next())->set_prev(pkey->get_prev());
					}
			delete pkey;
			return true;
		}
		else
			return false;
	}


	//���������� ������ ������
	void list::show()
	{
		cout << "\n                ���������� � ��������     \n";
		hline();
		cout << "| ����� ���. ����� |   �������   |    ���     |   ��������   |    A����    | ������� | ������� ���. ����� |" << endl;
		hline();
		item* pv = pbeg;
		while (pv)
		{
			cout << "|" << setw(18) << pv->get_item_num();
			cout << "|" << setw(13) << pv->get_item_name();
			cout << "|" << setw(12) << pv->get_item_name1();
			cout << "|" << setw(14) << pv->get_item_name2();
			cout << "|" << setw(13) << pv->get_item_address();
			cout << "|" << setw(9) << pv->get_item_diagnosis();
			cout << "|" << setw(20) << pv->get_item_namedoctor() << "|" << endl;
			pv = pv->get_next();
		}
		hline();
	}
	
	//���������� ������ �����
	void list::hline()
	{
		const int m = 107;
		for (int i = 0; i < m; i++)
			cout << "-";
		cout << endl;
	}

	//���������� �����������
	list::~list()
	{
		if (pbeg != 0)
		{
			item* pv = pbeg;
			while (pv)
			{
				pv = pv->get_next();
				delete pbeg;
				pbeg = pv;
			}
		}
	}
		