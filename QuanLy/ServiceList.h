#pragma once
#include "Service.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "RoomList.h"
#include "Service.h"
#include "Service.h"
using namespace std;
#define MAX 250
char tam[MAX];
class ServiceList
{
public:
	int maxService;
	class ServiceNode {
	public:
		Service data;
		ServiceNode* next;

		ServiceNode(Service data)
		{
			this->data = data;
			next = nullptr;
		}
	};
	ServiceNode* head;
	ServiceList()
	{
		this->head = nullptr;
		this->fInputServices();
		this->maxService = this->GetMaxService();
	}



	int LaySoLuongHangDangCo(string id)
	{
		int soLuong;
		ServiceNode* temp = head;
		while (temp != nullptr)
		{
			if (id.compare(temp->data.id) == 0)
			{
				soLuong = temp->data.quatity;
				return soLuong;
			}
			temp = temp->next;
		}
	}

	void UpdateServiceThem(string id, int n)
	{
		string nhanhieu;
		int k, SoLuongNow;
	NHAPIDSERVICE:
		try
		{
			cout << "Nhap ID cua service sau khi duoc them hang: ";
			cin >> id;

			int SoLuongNow = LaySoLuongHangDangCo(id);
			if (!(id[0] == 'T' || id[0] == 'S' && id.length() == 1 || id[0] == 'O' || id[0] == 'P'))
				throw "ID service khong hop le";

			cout << "Nhap so luong hang them:";
			cin >> n;
			ServiceNode* servicenode = head;
			while (servicenode != nullptr)
			{
				if (servicenode->data.id.compare(id) == 0)
				{
					if (id[0] == 'T') nhanhieu = "tra da";
					else if (id[0] == 'S')
					{
						nhanhieu = "suoi";
					}
					else if (id[0] == 'O')
					{
						nhanhieu = "o long";
					}
					else
					{
						nhanhieu = "pepsi";
					}
					cout << "So luong hien tai: " << SoLuongNow << endl;
					cout << "So luong sau khi cap nhat: " << (SoLuongNow + n) << endl;
					UpdateState(id, SoLuongNow + n);
					fOutputServices();
					return;
				}
				servicenode = servicenode->next;
			}
			throw "Khong co id dich vu";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai ID dich vu" << endl;
			goto NHAPIDSERVICE;
		}
	}
	void UpdateState(string id, int k)
	{
		ServiceNode* temp = head;
		while (temp != nullptr)
		{
			if (id.compare(temp->data.id) == 0)
			{
				temp->data.quatity = k;
				cout << "Da cap nhat so luong dich vu ==> " << (k > 0 ? "con hang" :
					"het hang") << endl;
				this->fOutputServices();
				return;
			}
			temp = temp->next;
		}
	}
	bool IsEmptyService(string id) // Cac dich vu da het so luong
	{
		ServiceNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.id.compare(id) == 0)
			{
				if (temp->data.quatity < 0)
					return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool IsHaveService(string id) // Cac dich vu da het so luong
	{
		ServiceNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.id.compare(id) == 0)
			{
				if (temp->data.quatity > 0)
					return true;
			}
			temp = temp->next;
		}
		return false;
	}


	bool IsHaveService(char type)
	{
		ServiceNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.id[0] == type && temp->data.quatity > 0)
				return true;
			temp = temp->next;
		}
		return false;
	}

	void PrintServiceList()
	{
		ServiceNode* temp = this->head;
		cout << "Thong tin cua tung dich vu" << endl;
		memset(tam, '=', 38);
		cout << right << setw(60) << "" << tam << endl;
		cout << right << setw(60) << "" << "|" << left << setw(10) << " Ma dich vu";
		cout << "|" << left << setw(12) << " Ten dich vu";
		cout << "|" << left << setw(12) << " Trang thai" << "|" << endl;
		memset(tam, '=', 38);
		cout << right << setw(60) << "" << tam << endl;
		while (temp != nullptr)
		{
			cout << right << setw(60) << "" << "|  " << left << setw(8) << temp->data.id;
			if (temp->data.id[0] == 'S')
			{
				cout << "|  " << left << setw(10) << "Nuoc suoi";
				if (temp->data.quatity > 0)
					cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
				else
					cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
			}
			else if (temp->data.id[0] == 'T')
			{
				cout << "|  " << left << setw(10) << "Tra da";
				if (temp->data.quatity > 0)
					cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
				else
					cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
			}
			else if (temp->data.id[0] == 'O')
			{
				cout << "|  " << left << setw(10) << "Olong";
				if (temp->data.quatity > 0)
					cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
				else
					cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
			}
			else
			{
				cout << "|  " << left << setw(10) << "Pepsi";
				if (temp->data.quatity > 0)
					cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
				else
					cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
			}
			memset(tam, '-', 38);
			cout << right << setw(60) << "" << tam << endl;
			temp = temp->next;
		}
		memset(t, NULL, MAX);
	}
	void PrintFullServiceList()//true
	{
		ServiceNode* temp = this->head;
		cout << "Thong tin cua tung dich vu trong" << endl;
		memset(tam, '=', 38);
		cout << right << setw(60) << "" << tam << endl;
		cout << right << setw(60) << "" << "|" << left << setw(10) << " Ma dich vu";
		cout << "|" << left << setw(12) << " Ten dich vu";
		cout << "|" << left << setw(12) << " Trang thai" << "|" << endl;
		memset(tam, '=', 38);
		cout << right << setw(60) << "" << tam << endl;
		while (temp != nullptr)
		{
			if (temp->data.quatity > 0)
			{
				cout << right << setw(60) << "" << "|  " << left << setw(8) << temp->data.id;
				if (temp->data.id[0] == 'S')
				{
					cout << "|  " << left << setw(10) << "Nuoc suoi";
					if (temp->data.quatity > 0)
						cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
					else
						cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
				}
				else if (temp->data.id[0] == 'T')
				{
					cout << "|  " << left << setw(10) << "Tra da";
					if (temp->data.quatity > 0)
						cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
					else
						cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
				}
				else if (temp->data.id[0] == 'O')
				{
					cout << "|  " << left << setw(10) << "Olong";
					if (temp->data.quatity > 0)
						cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
					else
						cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
				}
				else
				{
					cout << "|  " << left << setw(10) << "Pepsi";
					if (temp->data.quatity > 0)
						cout << "|  " << left << setw(10) << "Con hang" << "|" << endl;
					else
						cout << "|  " << left << setw(10) << "Het hang" << "|" << endl;
				}
				memset(tam, '-', 38);
				cout << right << setw(60) << "" << tam << endl;
			}
			temp = temp->next;
		}
		memset(t, NULL, MAX);
	}
	bool IsExistService(string id)//true
	{
		ServiceNode* temp = this->head;
		while (temp != nullptr)
		{
			if (id.compare(temp->data.id) == 0)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	int GetMaxService() //So luong dich vu
	{
		int count = 0;
		ServiceNode* temp = this->head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void AddHead(Service data)
	{
		ServiceNode* serviceNode = new ServiceNode(data);
		if (this->head == nullptr)
		{
			this->head = serviceNode;
		}
		else
		{
			serviceNode->next = this->head;
			this->head = serviceNode;
		}
		this->fOutputServices();
	}
	void DetroyServiceList()//true
	{
		ServiceNode* temp = this->head;
		while (this->head != nullptr)
		{
			this->head = temp->next;
			delete temp;
			temp = this->head;
		}
	}
	bool IsNoMoreHaveService()
	{
		ServiceNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.quatity > 0)
				return false;
			temp = temp->next;
		}
		return true;
	}

	Service fInputService(ifstream& filein, bool k)
	{
		Service service;
		if (k)
		{
			string temp;
			getline(filein, temp, '\n'); // loai bo ki tu xuong hang
		}
		getline(filein, service.id, ',');
		filein >> service.quatity;
		return service;
	}

	void fInputServices()
	{
		ifstream filein;
		Service service;
		bool k = false;
		filein.open("DANHSACHDICHVU.TXT", ios::in);
		while (!filein.eof())
		{
			service = fInputService(filein, k);
			k = true;
			AddHead(service);
		}
		filein.close();
	}


	void fOutputServices()// true
	{
		ofstream fileout;
		fileout.open("DANHSACHDICHVU.TXT", ios::out);
		ServiceNode* temp = head;
		while (temp->next != nullptr)
		{
			fileout << temp->data.id << ',' << temp->data.quatity << endl;
			temp = temp->next;
		}
		fileout << temp->data.id << ',' << temp->data.quatity;
		fileout.close();
	}



	void UpdateDatDichVu()
	{
		string nhanhieu;
		int k, SoLuongNow, n;
		string id;
		RoomList* roomList = new RoomList();

	NHAPIDSERVICE:
		try
		{
			cout << "Nhap ID cua service muon dat hang: ";
			cin >> id;

			cout << "Nhap so luong: ";
			cin >> n;
			int SoLuongNow = LaySoLuongHangDangCo(id);
			if (!(id[0] == 'T' || id[0] == 'S' && id.length() == 1 || id[0] == 'O' || id[0] == 'P'))
				throw "ID service khong hop le";

			cout << "So luong hien tai: " << SoLuongNow << endl;

		NHAPSOLUONGN:

			try
			{

				cout << "Nhap so luong: ";
				cin >> n;

				if (SoLuongNow < n)
				{
					throw "So luong vuot qua so luong dang co";
				}
			}
			catch (const char* msg)
			{
				cout << msg << endl;
				goto NHAPSOLUONGN;
			}
			ServiceNode* servicenode = head;
			while (servicenode != nullptr)
			{
				if (servicenode->data.id.compare(id) == 0)
				{
					if (id[0] == 'T') nhanhieu = "tra da";
					else if (id[0] == 'S')
					{
						nhanhieu = "suoi";
					}
					else if (id[0] == 'O')
					{
						nhanhieu = "o long";
					}
					else
					{
						nhanhieu = "pepsi";
					}

					cout << "So luong sau khi cap nhat: " << (SoLuongNow - n) << endl;
					UpdateState(id, (SoLuongNow - n));
					fOutputServices();
					return;
				}
				servicenode = servicenode->next;
			}
			throw "Khong co id dich vu";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai ID dich vu" << endl;
			goto NHAPIDSERVICE;
		}

	}

};