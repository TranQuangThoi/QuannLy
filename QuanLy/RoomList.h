#pragma once
#include "Room.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define MAX 300
char t[MAX];
class RoomList
{
public:
	int maxRoom;
	class RoomNode {
	public:
		Room data;
		RoomNode* next;
		RoomNode(Room data)
		{
			this->data = data;
			next = nullptr;
		}
	};
	RoomNode* head;
	RoomList()
	{
		this->head = nullptr;
		this->fInputRooms();
		this->maxRoom = this->GetMaxRoom();
	}


	void  UpdateRoomA()
	{
		string id;
	NHAPIDPHONGP:
		try
		{
			cout << "Nhap ID cua san sau khi don: ";
			cin >> id;
			if (!(id[0] == 'M' || id[0] == 'N' && id.length() == 4))
				throw "ID san khong hop le";
			RoomNode* roomnode = head;
			while (roomnode != nullptr)
			{
				if (roomnode->data.id.compare(id) == 0 && roomnode->data.state == -1)
				{
					UpdateState(id, 0);
					fOutputRooms();
					return;
				}
				roomnode = roomnode->next;
			}
			throw "Khong co id san trong danh sach hoac san dang trong";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai ID san" << endl;
			goto NHAPIDPHONGP;
		}
	}
	void  UpdateState(string id, int k)
	{
		RoomNode* temp = head;
		while (temp != nullptr)
		{
			if (id.compare(temp->data.id) == 0)
			{
				temp->data.state = k;
				cout << "Da cap nhat trang thai san thanh " << (k == 0 ? "trong" :
					(k == 1) ? "khong trong" : "dang bao tri") << endl;
				cout << "San cua quy khach la: " << temp->data.id << endl;
				this->fOutputRooms();
				return;
			}
			temp = temp->next;
		}
	}
	bool  IsFullRoom(string id)
	{
		RoomNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.id.compare(id) == 0)
			{
				if (temp->data.state == 1)
					return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool  IsEmptyRoom(string id)
	{

		RoomNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.id.compare(id) == 0)
			{
				if (temp->data.state == 0)
					return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool  IsEmptyRoom(char type)
	{
		RoomNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.id[0] == type && temp->data.state == 0)
				return true;
			temp = temp->next;
		}
		return false;
	}
	Room  GetFirstEmptyRoom(char type)
	{
		RoomNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.id[0] == type && temp->data.state == 0)
				return temp->data;
			temp = temp->next;
		}
	}
	void  PrintRoomList()
	{
		RoomNode* temp = this->head;
		cout << "Thong tin cua tung san" << endl;
		memset(t, '=', 38);
		cout << right << setw(60) << "" << t << endl;
		cout << right << setw(60) << "" << "|" << left << setw(10) << " Ma san";
		cout << "|" << left << setw(12) << " Loai san";
		cout << "|" << left << setw(12) << " Trang thai" << "|" << endl;
		memset(t, '=', 38);
		cout << right << setw(60) << "" << t << endl;
		while (temp != nullptr)
		{
			cout << right << setw(60) << "" << "|  " << left << setw(8) << temp->data.id;
			if (temp->data.id[0] == 'M')
			{
				cout << "|  " << left << setw(10) << "SAN 11";
				if (temp->data.state == 0)
					cout << "|  " << left << setw(10) << "TRONG" << "|" << endl;
				else
					cout << "|  " << left << setw(10) << "DAY" << "|" << endl;
			}
			else
			{
				cout << "|  " << left << setw(10) << "SAN 5";
				if (temp->data.state == 0)
					cout << "|  " << left << setw(10) << "TRONG" << "|" << endl;
				else
					cout << "|  " << left << setw(10) << "DAY" << "|" << endl;
			}
			memset(t, '-', 38);
			cout << right << setw(60) << "" << t << endl;
			temp = temp->next;
		}
		memset(t, NULL, MAX);
	}
	void  PrintEmptyRoomList()//true
	{
		RoomNode* temp = this->head;
		cout << "Thong tin cua tung san trong" << endl;
		memset(t, '=', 38);
		cout << right << setw(60) << "" << t << endl;
		cout << right << setw(60) << "" << "|" << left << setw(10) << " Ma san";
		cout << "|" << left << setw(12) << " Loai san";
		cout << "|" << left << setw(12) << " Trang thai" << "|" << endl;
		memset(t, '=', 38);
		cout << right << setw(60) << "" << t << endl;
		while (temp != nullptr)
		{
			if (temp->data.state == 0)
			{
				cout << right << setw(60) << "" << "|  " << left << setw(8) << temp->data.id;
				if (temp->data.id[0] == 'M')
				{
					cout << "|  " << left << setw(10) << "SAN 11";
					if (temp->data.state == 0)
						cout << "|  " << left << setw(10) << "TRONG" << "|" << endl;
					else
						cout << "|  " << left << setw(10) << "DAY" << "|" << endl;
				}
				else
				{
					cout << "|  " << left << setw(10) << "SAN 5";
					if (temp->data.state == 0)
						cout << "|  " << left << setw(10) << "TRONG" << "|" << endl;
					else
						cout << "|  " << left << setw(10) << "DAY" << "|" << endl;
				}
				memset(t, '-', 38);
				cout << right << setw(60) << "" << t << endl;
			}
			temp = temp->next;
		}
		memset(t, NULL, MAX);
	}
	bool  IsExistRoom(string id)//true
	{
		RoomNode* temp = this->head;
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
	int  GetMaxRoom()
	{
		int count = 0;
		RoomNode* temp = this->head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void  AddHead(Room data)
	{
		RoomNode* roomNode = new RoomNode(data);
		if (this->head == nullptr)
		{
			this->head = roomNode;
		}
		else
		{
			roomNode->next = this->head;
			this->head = roomNode;
		}
		this->fOutputRooms();
	}
	void  DetroyRoomList()//true
	{
		RoomNode* temp = this->head;
		while (this->head != nullptr)
		{
			this->head = temp->next;
			delete temp;
			temp = this->head;
		}
	}
	bool  IsNoMoreEmptyRoom()
	{
		RoomNode* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->data.state == 0)
				return false;
			temp = temp->next;
		}
		return true;
	}
	void  UpdateMaxRoom()//true khi xay them phong
	{
		int n;
	NHAPN:
		try
		{
			cout << "Nhap so san muon them: ";
			cin >> n;
			if (cin.fail())
			{
				cin.seekg(1);
				throw "Du lieu phai la so!!!\n";
			}
			if (n <= 0)
			{
				throw "Du lieu phai la so duong!!!\n";
			}

		}
		catch (const char* msg)
		{
			cout << msg;
			cout << "Vui long nhap lai";
			goto NHAPN;
		}
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap thong tin san thu " << i << endl;
			this->InputRoom();
		}
		this->maxRoom += n;
	}
	void  InputRoom()//true
	{
		Room room;
	NHAPIDPHONG:
		try
		{
			cout << "Nhap ID cua san moi ";
			cin >> room.id;
			if (!(room.id[0] == 'M' || room.id[0] == 'N' && room.id.length() == 4))
				throw "ID san khong hop le";
			if (this->IsExistRoom(room.id))
				throw "ID san da ton tai";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai ID san" << endl;
			goto NHAPIDPHONG;
		}
		room.state = 0;
		this->AddHead(room);
	}
	Room  fInputRooom(ifstream& filein, bool k)
	{
		Room room;
		if (k)
		{
			string temp;
			getline(filein, temp, '\n');// loai bo ki tu xuong hang
		}
		getline(filein, room.id, ',');
		filein >> room.state;
		return room;
	}
	void  fOutputRooms()// true
	{
		ofstream fileout;
		fileout.open("DANHSACHSAN.TXT", ios::out);
		RoomNode* temp = head;
		while (temp->next != nullptr)
		{
			fileout << temp->data.id << ',' << temp->data.state << endl;
			temp = temp->next;
		}
		fileout << temp->data.id << ',' << temp->data.state;
		fileout.close();
	}
	void  fInputRooms()
	{
		ifstream filein;
		Room room;
		bool k = false;
		filein.open("DANHSACHSAN.TXT", ios::in);
		while (!filein.eof())
		{
			room = fInputRooom(filein, k);
			k = true;
			AddHead(room);
		}
		filein.close();
	}
};