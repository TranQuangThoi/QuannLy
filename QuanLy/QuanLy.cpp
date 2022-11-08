#include <string>
#include "windows.h" 
#include "RoomList.h"
#include "CustomerList.h"
#include "TradeList.h"
#include "ServiceList.h"
void Menu(TradeList* tradeList);
void Start();
void SetColor(int color);
void banner();
void Option(int option, TradeList*& tradeList);
Picture* scan = new Picture();

int main()
{
	banner();
	Start();
	return 0;
}
void Start()
{
	system("pause");
	system("cls");
	TradeList* tradeList = new TradeList();
	
	Menu(tradeList);
	SetColor(13);
	int option;
	do
	{
	NHAPLAILUACHON:
		try
		{
			cout << "Nhap lua chon cua ban: ";
			cin.seekg(1);
			cin >> option;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw "Vui long nhap so!!!";
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "Vui long nhap lai lua chon!!!\n";
			goto NHAPLAILUACHON;
		}
		Option(option, tradeList);
	} while (option != 0);
}
void Menu(TradeList* tradeList)
{
	SetColor(3);
	cout << right << setw(25) << "" << "*================= QUAN LY SAN BANH ==================*" << endl;
	cout << right << setw(26) << "|" << right << setw(55) << "|" << endl;
	cout << right << setw(25) << "" << "|\t1. Khach hang dat san" << right << setw(28) << "|" << "\tGia san 5 (N)/SANG: " << tradeList->price->perHourN << endl;
	cout << right << setw(25) << "" << "|\t2. Khach hang tra san " << right << setw(27) << "|" << "\tGia san 11 (M)/SANG: " << tradeList->price->perHourM << endl;
	cout << right << setw(25) << "" << "|\t3. Tim kiem khach hang" << right << setw(27) << "|" << endl;
	cout << right << setw(25) << "" << "|\t4. Tim kiem khach hang dang muon san" << right << setw(13) << "|" << endl;
	cout << right << setw(25) << "" << "|\t5. Danh sach khach hang" << right << setw(26) << "|" << endl;
	cout << right << setw(25) << "" << "|\t6. Danh sach khach hang dang muon san" << right << setw(12) << "|" << endl;
	cout << right << setw(25) << "" << "|\t7. Danh sach lich su giao dich" << right << setw(19) << "|" << endl;
	cout << right << setw(25) << "" << "|\t8. Danh sach san" << right << setw(33) << "|" << endl;
	cout << right << setw(25) << "" << "|\t9. Danh sach cac san con trong" << right << setw(19) << "|" << endl;
	cout << right << setw(25) << "" << "|\t10. Cap nhat them san" << right << setw(28) << "|" << endl;
	cout << right << setw(25) << "" << "|\t11. Cap nhat lai gia san" << right << setw(25) << "|" << endl;
	cout << right << setw(25) << "" << "|\t12. Cap nhat trang thai san sau khi bao tri" << right << setw(6) << "|" << endl;
	cout << right << setw(25) << "" << "|\t13. So luong san cua san banh" << right << setw(20) << "|" << endl;
	cout << right << setw(25) << "" << "|\t14. Doanh thu trong ngay" << right << setw(25) << "|" << endl;
	cout << right << setw(25) << "" << "|\t15. Danh sach cac dich vu" << right << setw(24) << "|" << endl;
	cout << right << setw(25) << "" << "|\t16. Dat dich vu" << right << setw(34) << "|" << endl;
	cout << right << setw(25) << "" << "|\t0. Exit" << right << setw(42) << "|" << endl;
	cout << right << setw(25) << "" << "*======================================================*" << endl;

}
void Option(int option, TradeList*& tradeList)
{
	system("cls");
	Menu(tradeList);
	SetColor(7);
	switch (option)
	{
	case 1:
		tradeList->BooKSan();
		system("pause");
		system("cls");
		Menu(tradeList);
		break;
	case 2:
		tradeList->CheckSan();
		break;
	case 3:
		tradeList->customerList->searchName();
		break;
	case 4:
		tradeList->searchName();
		break;
	case 5:
		tradeList->customerList->printList();
		break;
	case 6:
		tradeList->printTrade();
		break;
	case 7:
		tradeList->printHistoryList();
		break;
	case 8:
		tradeList->roomList->PrintRoomList();
		break;
	case 9:
		tradeList->roomList->PrintEmptyRoomList();
		break;
	case 10:
		tradeList->roomList->UpdateMaxRoom();
		break;
	case 11:
		tradeList->price->UpdatePrice();
		system("cls");
		Menu(tradeList);
		break;
	case 12:
		tradeList->roomList->UpdateRoomA();
		break;
	case 13:
		cout << "Tong so san hien tai cua san banh la: " << tradeList->roomList->GetMaxRoom() << endl;
		break;
	case 14:
		tradeList->EarnToday();
		break;
	case 15:
		tradeList->serviceList->PrintServiceList();
		break;
	case 16:
		int n;
		tradeList->serviceList->UpdateDatDichVu();
		break;
	case 0:
		tradeList->DetroyTradeList();
		cout << "Da thoat chuong trinh!! Cam on quy khach da su dung dich vu cua chung toi!!" << endl;
		system("pause");
		break;
	default:
		cout << "Vui long nhap cac so tu 0->17" << endl;
		break;
	}
}
void SetColor(int color)
{
	WORD wColor;

	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info))
	{
		wColor = (screen_buffer_info.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hConsoleOutput, wColor);
	}
}
void banner()
{
	SetColor(7);
	cout << "\n\n" << right << setw(30) << "" << "TRUONG DAI HOC SU PHAM KY THUAT TP.HCM\n";
	cout << right << setw(35) << "" << "KHOA DAO TAO CHAT LUONG CAO\n\n\n\n\n";
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(42) << "" << "DO AN CUOI KY\n\n";
	cout << right << setw(32) << "" << "Mon hoc: Cau truc du lieu va giai thuat\n";
	cout << right << setw(35) << "" << "Hoc ky 1 Nam hoc 2022-2023\n\n";
	cout << right << setw(40) << "" << "QUAN LY SAN BANH\n\n\n\n\n";
	SetColor(5);
	cout << right << setw(35) << "" << "Giang Vien: PGS.TS. Hoang Van Dung\n\n\n";
	cout << right << setw(50) << "" << "Danh sach thanh vien thuc hien\n";
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(26) << "|" << " Ma so SV |" << left << setw(25) << " Ho va ten" << "| Ty le dong gop |" << endl;
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(26) << "|" << " 20110xxx |" << left << setw(25) << " Huynh Bao Toan" << left << setw(17) << "| 33.33%" << "|" << endl;
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(26) << "|" << " 20110xxx |" << left << setw(25) << " Tran Quang Thoi" << left << setw(17) << "| 33.33%" << "|" << endl;
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(26) << "|" << " 20110xxx |" << left << setw(25) << " Cao Ngoc Quy" << left << setw(17) << "| 33.33%" << "|" << endl;
	cout << right << setw(25) << "" << "-------------------------------------------------------" << endl;
	cout << right << setw(25) << "" << "\n\n";
	cout << right << setw(25) << "" << "\tCHAO MUNG BAN DEN VOI SAN BANH CUA CHUNG TOI\n\n\n";
	scan->inputPicture();
}
