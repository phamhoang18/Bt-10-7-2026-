#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;

struct KH{
	int makh;
	string tenkh, sdt;
	float tongtienthanhtoan;
};

void td(){
	cout << left << setw(20) << "Ma khach hang" << setw(20) << "Ten khach hang" << setw(20) << "So dien thoai" << setw(20) << "Tong tien thanh toan" << endl;
	cout << string(80, '-') << endl;
}

void nhap(KH *k, int n){
	for (int i = 0; i < n; i++){
		cout << "- Nhap khach hang thu " << i+1 << ": " << endl;
		cout << "	+ Ma khach hang: "; cin >> k[i].makh; 
		cout << "	+ Ten khach hang: "; getline(cin >> ws, k[i].tenkh); 
		cout << "	+ So dien thoai: "; getline(cin, k[i].sdt);
		do{
			cout << "	+ Tong tien thanh toan: "; cin >> k[i].tongtienthanhtoan;
		}while (k[i].tongtienthanhtoan < 0);
	}
}

void xuat(KH *k, int n){
	for (int i = 0; i < n; i++){
		cout << left << setw(20) << k[i].makh << setw(20) << k[i].tenkh << setw(20) << k[i].sdt << setw(20) << fixed << setprecision(2) << k[i].tongtienthanhtoan << endl;
	}
}

void insertion_sort(KH *k, int n){
	for (int i = 1; i < n; i++){
		KH x = k[i];
		int y = i - 1;
		while (y > 0 && k[y].tongtienthanhtoan > x.tongtienthanhtoan){
			k[y + 1] = k[y];
			y--;
		}
		k[y + 1] = x;
	}	
}

void BST(KH *k, int n, float x){
	int left = 0;
	int right = n - 1;
	int found = -1;
	while (left < right){
		int mid = (left + right) / 2;
		if (abs(k[mid].tongtienthanhtoan - x) < 0.0001){
			found = mid;
			break;
		}
		
		if (k[mid].tongtienthanhtoan > x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	
	if (found == -1){
		cout << "\n=> Khong tim thay thong tin hang hoa co gia " << x << " trieu dong!" << endl;
	}
	
	int first = found;
	while (first > 0 && abs(k[first - 1].tongtienthanhtoan - x) < 0.0001){
		first--;
	}
	
	int last = found;
	while (last < n - 1 && abs(k[last + 1].tongtienthanhtoan - x) < 0.001){
		last++;
	}
	
	cout << "\nHien thi danh sach hang hoa co tong thanh toan bang " << x << " trieu dong: " << endl;
	td();
	for (int i = first; i <= last; i++){
		xuat(&k[i], 1);
	}
}

int main(){
	int n;
	do{
		cout << "- Nhap so luong khach hang: "; cin >> n; cin.ignore();
	}while (n < 0);
	
	KH *k = new KH[n];
	
	nhap(k, n);
	
	cout << "\n- Hien thi danh sach khach hang sau khi nhap: " << endl;
	td();
	xuat(k, n);
	
	insertion_sort(k, n);
	cout << "\n- Hien thi danh sach khach hang sau khi co su sap xep: " << endl;
	td();
	xuat(k, n);
	
	float x;
	do{
		cout << "\n- Nhap gia hang hoa can tim: "; cin >> x; cin.ignore();
	}while (x < 0);
	
	BST(k, n, x);
	
	delete[] k;
	return 0;
}
