#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <random>
#include "Customer.h"
#include "FullName.h"
#include "Date.h"
#include "RoomList.h"
using namespace std;

class CustomerList
{
public:
	class CustomerNode {
	public:
		Customer data;
		CustomerNode* next;
		CustomerNode(Customer data)
		{
			this->data = data;
			this->next = nullptr;
		}
	};
	CustomerNode* head;
	CustomerList()
	{
		this->head = nullptr;
		this->fInputCustomers();

	}
	void fOutputApp(Customer data)
	{
		ofstream fileout;
		ifstream filein;
		filein.open("KHACHHANG.TXT", ios::in);
		fileout.open("KHACHHANG.TXT", ios::app);
		if (!filein.fail())
		{
			fileout << '\n';
		}
		fileout << data.id << ";" << data.fullName.lastName << ";" << data.fullName.firstName << ";";
		data.dateOfBirth.fOuputDate(fileout, data.dateOfBirth);
		fileout << ";" << data.sex << ";" << data.phoneNumber << ";";
		fileout << data.address;
		filein.close();
		fileout.close();
	}
	inline bool IsExistCustomer()
	{

		return false;
	}
	Customer ReturnById(string id)
	{
		Customer customer;
		CustomerNode* temp = this->head;
		while (temp != nullptr)
		{
			if (id.compare(temp->data.id) == 0)
			{
				customer = temp->data;
				break;
			}
			temp = temp->next;
		}
		return customer;
	}
	void DetroyCustomerList()//true
	{
		CustomerNode* temp = this->head;
		while (this->head != nullptr)
		{
			this->head = temp->next;
			delete temp;
			temp = this->head;
		}
	}
	bool IsExitCustomer(string id)
	{
		CustomerNode* customerNode = this->head;
		while (customerNode != nullptr)
		{
			if (customerNode->data.id.compare(id) == 0)
			{
				cout << "Da co du lieu \n";
				return true;
			}
			customerNode = customerNode->next;
		}
		return false;
	}
	Customer InputCustomer() //// true
	{
		Customer customer;
	NHAPLAICMND:
		try
		{
			cout << "Nhap CMND/CCCD cua khach hang: ";
			cin.ignore();
			cin >> customer.id;
			for (int i = 0; i < customer.id.length(); i++)
			{
				if (!(customer.id[i] <= '9' && customer.id[i] >= '0'))
					throw "CMND/CCCD phai la so";
			}
			if (!(customer.id.length() == 9 || customer.id.length() == 12))
			{
				throw "CMND/CCCD phai co do dai la 9 hoac 12 ki tu so";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap CMND/CCCD" << endl;
			goto NHAPLAICMND;
		}
		if (IsExitCustomer(customer.id))
		{
			return ReturnById(customer.id);
		}

	NHAPLAIHO:
		try
		{
			cout << "Nhap ho va ten lot khach hang: ";
			cin.seekg(1);
			getline(cin, customer.fullName.lastName);
			if (customer.fullName.CheckLastName() == false)
				throw "Ho khong hop le!";
			transform(customer.fullName.lastName.begin(), customer.fullName.lastName.end(), customer.fullName.lastName.begin(), toupper);
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai ho ten bang chu!" << endl;
			goto NHAPLAIHO;
		}
	NHAPLAITEN:
		try
		{
			cout << "Nhap ten khach hang: ";
			getline(cin, customer.fullName.firstName);
			if (customer.fullName.CheckFirstName() == false)
				throw "Ten khong hop le!";
			transform(customer.fullName.firstName.begin(), customer.fullName.firstName.end(), customer.fullName.firstName.begin(), toupper);
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai ho ten bang chu!" << endl;
			goto NHAPLAITEN;
		}
	NHAPLAINGAYSINH:
		try
		{
		NHAPNGAYSINH:
			try
			{
				cout << "Nhap ngay sinh: ";
				cin >> customer.dateOfBirth.day;
				if (cin.fail())
				{
					cin.ignore();
					cin.clear();
					cin.seekg(1);
					throw "Du lieu phai la so\n";
				}
				if (customer.dateOfBirth.day <= 0 || customer.dateOfBirth.day > 31)
					throw "Du lieu phai la so duong va be hon 32\n";
			}
			catch (const char* msg)
			{
				cout << msg;
				cout << "Vui long nhap lai\n";

				goto NHAPNGAYSINH;
			}
		NHAPTHANGSINH:
			try
			{
				cout << "Nhap thang sinh: ";
				cin >> customer.dateOfBirth.month;
				if (cin.fail())
				{
					cin.ignore();
					cin.clear();
					cin.seekg(1);
					throw "Du lieu phai la so\n";
				}
				if (customer.dateOfBirth.month <= 0)
					throw "Du lieu phai la so duong\n";
			}
			catch (const char* msg)
			{
				cout << msg;
				cout << "Vui long nhap lai\n";
				goto NHAPTHANGSINH;
			}
		NHAPNAMSINH:
			try
			{
				cout << "Nhap nam sinh: ";
				cin >> customer.dateOfBirth.year;
				if (cin.fail())
				{
					cin.ignore();
					cin.clear();
					cin.seekg(1);
					throw "Du lieu phai la so\n";
				}
				if (customer.dateOfBirth.year <= 0)
					throw "Du lieu phai la so duong\n";
			}
			catch (const char* msg)
			{
				cout << msg;
				cout << "Vui long nhap lai\n";
				goto NHAPNAMSINH;
			}
			if (!customer.dateOfBirth.IsTrueDate())
			{
				throw "Ngay thang nam khong hop le\n";
			}
		}
		catch (const char* msg)
		{
			cout << msg;
			cout << "Vui long nhap lai\n";
			goto NHAPLAINGAYSINH;
		}
	NHAPLAIGIOITINH:
		try
		{
			cout << "Nhap gioi tinh khach hang: ";
			cin >> customer.sex;
			transform(customer.sex.begin(), customer.sex.end(), customer.sex.begin(), toupper);
			string trim(customer.sex);
			if (!(customer.sex == "NAM" || customer.sex == "NU"))
				throw "Gioi tinh phai la nam hoac nu";
		}
		catch (const char* msg)
		{
			cout << "Tham so dau vao khong hop le\n";
			cout << msg;
			cout << "\nVui long nhap lai\n";
			goto NHAPLAIGIOITINH;
		}
	NHAPLAISODIENTHOAI:
		try
		{
			cout << "Nhap so dien thoai khach hang: ";
			cin >> customer.phoneNumber;
			for (int i = 0; i < customer.phoneNumber.length(); i++)
			{
				if (!(customer.phoneNumber[i] >= '0' && customer.phoneNumber[i] <= '9'))
					throw "So dien thoai khong hop le!";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai" << endl;
			goto NHAPLAISODIENTHOAI;
		}
		cout << "Nhap dia chi cua khach hang: ";
		cin.ignore();
		getline(cin, customer.address);
		transform(customer.address.begin(), customer.address.end(), customer.address.begin(), toupper);
		return customer;
	}
	void fInputCustomers()
	{
		Customer customer;
		ifstream filein;
		filein.open("KHACHHANG.TXT", ios::in);

		if (filein.fail())
		{
			return;
		}
		while (!filein.eof())
		{
			customer.fInputCustomer(filein);
			this->AddHead(customer);
		}
		filein.close();
	}

	void printList()///
	{
		cout << endl;
		if (this->head == nullptr)
		{
			cout << "Danh sach rong\n";
			return;
		}
		PrintForm();
		CustomerNode* temp = head;
		while (temp != nullptr)
		{
			cout << left << setw(20) << "";
			temp->data.printCustomer();
			cout << endl;
			memset(t, '-', 144);
			cout << left << setw(20) << "" << t << endl;
			temp = temp->next;
		}
		memset(t, NULL, MAX);
	}
	void DeleteById(string id)//xóa 1
	{
		CustomerNode* pDel = head; // tạo một node pDel để xóa
		//Nếu pDel == Null thì danh sách rỗng
		if (pDel == nullptr) {
			cout << "Danh sach rong!!!";
		}
		//ngược lại thì xét điều kiện
		else {
			CustomerNode* pPre = nullptr;
			//dùng vòng lặp while để tìm ra pDel và pPre (vị trí đứng trước pDel)
			while (pDel != nullptr) {
				if (pDel->data.id.compare(id) == 0) {
					{
						break;
					}
				}
				pPre = pDel;
				pDel = pDel->next;
			}
			//Nếu pDel == null tức là không tìm thấy số cần xóa
			if (pDel == nullptr) {
				cout << "Khong tim thay ma khach hang can xoa";
			}
			// Ngược lại tiếp tục xét điều kiện
			else {
				// Nếu pDel == list.pHead, tức là số cần xóa ở đầu danh sách
				if (pDel == head) {
					head = head->next;
					pDel->next = nullptr;
					delete pDel;
					pDel = nullptr;
				}
				//Nếu pDel == list.pTail, tức là số cần xóa ở cuối danh sách
				else if (pDel->next == nullptr) {
					pPre->next = nullptr;
					delete pDel;
					pDel = nullptr;
				}
				// và trường hợp cuối cùng số muốn xóa nằm ở giữa danh sách
				else {
					pPre->next = pDel->next;
					pDel->next = nullptr;
					delete pDel;
					pDel = nullptr;
				}
			}
		}
	}
	bool IsExistId(string id)
	{
		CustomerNode* temp = head;
		while (temp != nullptr)
		{
			if (temp->data.id.compare(id) == 0)
				return true;
			temp = temp->next;
		}
		return false;
	}
	void searchName()
	{
		FullName fname;
		bool check = false;
	NHAPLAITEN:
		try
		{
			cout << "Nhap ten khach hang: ";
			cin >> fname.firstName;
			if (fname.CheckFirstName() == false)
				throw "Ten khong hop le!";
			transform(fname.firstName.begin(), fname.firstName.end(), fname.firstName.begin(), toupper);
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap ten bang chu!" << endl;
			goto NHAPLAITEN;
		}

		CustomerNode* temp = head;
		while (temp != nullptr)
		{
			if (fname.firstName.compare(temp->data.fullName.firstName) == 0)
			{
				if (!check)
					PrintForm();
				check = true;
				cout << left << setw(20) << "";
				temp->data.printCustomer();
				cout << endl;
				memset(t, '-', 144);
				cout << left << setw(20) << "" << t << endl;
			}
			temp = temp->next;
		}
		memset(t, NULL, MAX);
		if (!check)
			cout << "Hien khong co khach hang ten " << fname.firstName << endl;
	}
	void AddHead(Customer data)//true
	{
		CustomerNode* customerNode = new CustomerNode(data);
		if (this->head == nullptr)
		{
			this->head = customerNode;
		}
		else
		{
			customerNode->next = this->head;
			this->head = customerNode;
		}
	}

	void PrintForm()
	{
		memset(t, '=', 144);
		cout << left << setw(20) << "" << t << endl;
		cout << left << setw(20) << "" << "|" << left << setw(15) << "   CMND/CCCD" << "|" << left << setw(24) <<
			"\t\tHo va Ten" << "|" << left << setw(16) << "  So Dien Thoai";
		cout << "|" << left << setw(12) << " Ngay Sinh" << "|" << left << setw(9) << "Gioi Tinh" << "|" <<
			left << setw(52) << "\t      Dia Chi" << "|" << endl;
		memset(t, '=', 144);
		cout << left << setw(20) << "" << t << endl;
	}


};
