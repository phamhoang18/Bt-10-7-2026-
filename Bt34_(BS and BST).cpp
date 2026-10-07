#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
	
struct QLNV{
	string Manv, Hoten;
	int ngay, thang, nam;
	float luong;
};
	
void td(){
	cout << left << setw(20) << "Ma nhan vien" << setw(20) << "Ten nhan vien" << setw(20) << "Ngay sinh" << setw(20) << "Muc luong" << endl;
	cout << string(80, '-') << endl;
}
	
void Nhap(int n, QLNV *q){
	for (int i = 0; i < n; i++){
		cout << "- Nhap thong tin nhan vien thu " << i+1 << ": " << endl;
		cout << "	+ Ma nhan vien: "; getline(cin >> ws, q[i].Manv);
		cout << "	+ Ten nhan vien: "; getline(cin, q[i].Hoten);
		do{
			cout << "	+ Nam: "; cin >> q[i].nam;
		}while (q[i].nam < 0);
		do{
			cout << "	+ Thang: "; cin >> q[i].thang;
		}while (q[i].thang < 0 || q[i].thang > 12);
		do
		{
			cout << "	+ Ngay: "; cin >> q[i].ngay;
		}while (q[i].ngay < 0 || q[i].ngay > 31);
		do{
			cout << "	+ Muc luong: "; cin >> q[i].luong;
		}while (q[i].luong < 0);
	}
}
	
void Xuat(int n, QLNV *q){
	for(int i = 0; i < n; i++){
		string ngayxuat = to_string(q[i].ngay) + "/" + to_string(q[i].thang) + "/" + to_string(q[i].nam);
		cout << left << setw(20) << q[i].Manv << setw(20) << q[i].Hoten << setw(20) << ngayxuat << setw(20) << q[i].luong << endl;
	}
}
	
void BS(int n, QLNV *q){
	for (int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if (q[j].luong > q[j+1].luong){
				swap(q[j], q[j+1]);
			}	
		}
	}
}
	
void Find(int n, QLNV *q, float x){
	int left = 0;
	int right = n - 1;
	int found = -1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (abs(q[mid].luong - x) < 0.001){
			found = mid;
			break;
		}
			
		if (q[mid].luong > x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
		
	if (found){
		cout << "=> Khong co nhan vien nao co muc luong " << x << " trieu dong!" << endl;
		return;
	}
		
	int first = found;
	while (first > 0 && abs(q[first - 1].luong - x) < 0.001){
		first--;
	}
		
	int last = found;
	while (last < n - 1 && abs(q[last + 1].luong - x) < 0.001){
		last++;
	}
		
	cout << "- Hien thi danh sach cac nhan vien co muc luong " << x << " co trong danh sach ban dau: " << endl;
	td();
	for (int i = first; i <= last; i++){
		Xuat(1, &q[i]);
	}
}
	
int main(){
	int n;
	do{
		cout << "- Nhap so luong nhan vien: "; cin >> n; cin.ignore();
	}while (n <= 0);
		
	QLNV *q = new QLNV[n];
		
	Nhap(n, q);
	
	cout << "\n- Hien thi danh sach nhan vien: " << endl;	
	td();
	Xuat(n, q);
		
	cout << "\n- Hien thi danh sach sau khi co su sap xep: " << endl;
	BS(n, q);
	td();
	Xuat(n, q);
		
	float x;
	do{
		cout << "\n- Nhap muc luong nhan vien can tim: "; cin >> x; cin.ignore();
	}while (x < 0);
		
	Find(n, q, x);
	delete[] q;
	return 0;
}
