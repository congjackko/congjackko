#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

/*SU DUNG PHIEN BAN C++ 11 TRO LEN A VI O DAY CO HAM TO_STRING A ,CHAY BANG CONG CU MICROSHOFT VISAUL STUDIO 2017 A*/

/*
	MOT SO LUU Y KHI CHAY CHUONG TRINH
	DUNG CONG CU PHIEN BAN C++ TREN
	DUNG KIEU STRING DE CHAY SO
	CO DUNG THEM MOT SO KI THUAT DA TICH GOP DUOC VAO DAY
	CO SU DUNG LAI HAM DE CHAY
	CAM ON THAY DA DOC GHI CHU NAY A
*/

/*CAC HAM THUC THI TREN CHUOI*/
//sang tao phep nhan chuoi
template <class T>
string operator*(const string &a, const T &n) {//n dong vai tro la so nhan trong chuoi
	string s = "";
	for (int i = 0; i < n; i++) {
		s += a;
	}
	return s;
}
//Cong hai so thong qua chuoi
string sum_number(string a, string b) {
	string sum = "";
	string temp = "0";
	//de co the an toan ta nen bo sung sao cho 2 chuoi co do dai bang nhau
	if (a.length() < b.length()) {
		a = temp * (b.length() - a.length()) + a;
	}
	else if (a.length() > b.length()) {
		b = temp * (a.length() - b.length()) + b;
	}
	short k = 0;//Dong vai tro la bo nho
	//Dao nguoc chuoi a,b
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.length() != 0) {
		k += stoi(a.substr(0, 1)) + stoi(b.substr(0, 1));
		a.erase(0, 1); b.erase(0, 1);
		sum = to_string(k % 10) + sum;
		k /= 10;
	}
	if (k != 0) {
		sum = to_string(k) + sum;
	}
	return sum;
}
//Ham chuyen tu chuoi thanh vector
template <class T>
vector<string> string_convert_to_vector(string s, T n) {//n de tien hanh phan tach chuoi
	vector<string> atemp;
	string k = "0";
	T t = n - s.length() % n;
	if (t != n) {
		s = k * t + s;//chuc nang bo sung them so  khong con thieu
	}

	while (s.length() != 0) {
		atemp.push_back(s.substr(0, n));
		s.erase(0, n);
	}
	return atemp;
}
//Ham thuc hien tim thuong va du cua mot so doi trong chuoi
void division_for_two(string s, int &a, int &b) {
	//chuoi s chuoi gom hai ki tu , so a la thuong , so b la du
	int n = stoi(s);
	a = n / 2;
	b = n % 2;
}
//Ham kiem tra xem chuoi co phai la toan so 0 hay khong
bool Condition(string s) {
	bool k = false;
	long long  i = 0;
	while (k == false && i < s.length()) {
		if (s[i] != '0') {
			k = true;
		}
		i++;
	}
	return k;
}

/*CAC HAM CHUYEN DOI*/

//Chuyen doi chuoi nhi phan thanh chuoi bat phan
string bin_oct(string binary) {
	vector<string> temp = string_convert_to_vector(binary, 3);
	string a = "";//su dung bien a de truy vet
	string oct[] = { "000","001","010","011","100","101","110","111" };
	int n = sizeof(oct) / sizeof(oct[0]);
	for (int i = 0; i < temp.size(); i++) {
		int j = 0;
		string k = temp[i];
		while (j < n) {
			if (k == oct[j]) {
				a += to_string(j);//O day em bien so thanh chuoi , em dung visual studeio
				break;
			}
			j++;
		}
	}
	return a;
}
//Chuyen doi chuoi nhi phan thanh thap hexxa
string bin_hex(string binary) {
	vector<string> temp = string_convert_to_vector(binary, 4);
	string a = "";//su dung bien a de truy vet
	string hex[] = { "0000","0001","0010","0011","0100","0101","0110","0111", "1000","1001","1010","1011","1100","1101","1110","1111" };
	int i = 0;
	for (int i = 0; i < temp.size(); i++) {
		int j = 0;
		string k = temp[i];
		while (j < 16) {
			if (k == hex[j]) {
				if (j < 10) {
					a += to_string(j);
				}
				else {
					switch (j) {
					case 10:a += 'A'; break;
					case 11:a += 'B'; break;
					case 12:a += 'C'; break;
					case 13:a += 'D'; break;
					case 14:a += 'E'; break;
					case 15:a += 'F'; break;
					}
				}
			}
			j++;
		}
	}
	return a;
}
//Chuyen tu he co so 10 sang he co so nhi phan
string dec_bin(string temp) {
	//tieng hanh phep chia 
	int a, b;//a la thuong , b la du , i danh dau vi tri cua
	string number = "", value1 = "", value2 = "", t = "";//t:la ham chua chinh,cua chuoi nhi phan value1:du thuong tren mot phep tinh , value 2: du du tren tung phep tinh
	do {
		number = ""; value1 = ""; value2 = "";
		while (temp.length() != 0) {
			number = value2 + temp.substr(0, 1);
			division_for_two(number, a, b);
			value2 = to_string(b); value1 = value1 + to_string(a);
			temp.erase(0, 1);
		}

		temp = value1;
		t = value2 + t;
	} while (Condition(value1) == true);
	return t;
}
//Chuyen tu he co so nhi phan sang he co so 10
string bin_dec(string temp) {// o day em dung kieu long long em thay van chua du tong quat nhung hien tai em van chua nghia ra duoc a
	string m = "0";
	long long n = temp.length();
	for (long long i = 0; i < n; i++) {
		if (temp[i] == '1') {
			string k = to_string(long long(pow(2, n - i - 1)));
			m = sum_number(m, k);
		}
	}
	return m;
}
//Chuyen tu he co so 10 sang he co so bat phan
string dec_oct(string dec) {
	//y tuong su dung cac ham tren
	//chuyen tu he co so 10 sang nhi phan
	string n_bin = dec_bin(dec);
	//chuyen tu nhi phan sang bat phan
	string n_oct = bin_oct(n_bin);
	return n_oct;
}
//Chuyen tu he co so 10 sang he co so thap luc phan
string dec_hex(string dec) {
	//y tuong su dung cac ham tren
	//chuyen tu he co so 10 sang nhi phan
	string n_bin = dec_bin(dec);
	//chuyen tu nhi phan sang bat phan
	string n_hex = bin_hex(n_bin);
	return n_hex;
}
//ham chuyen tu bat phan sang nhi phan
string oct_bin(string oct) {
	string a = "";//su dung bien a de truy vet
	string binary[] = { "000","001","010","011","100","101","110","111" };
	for (int i = 0; i < oct.length(); i++) {
		a += binary[stoi(oct.substr(i, 1))];
	}
	return a;
}
//ham chuyen tu thapnhiphan sang nhi phan
string hex_bin(string hex) {
	string a = "";//su dung bien a de truy vet
	string bin[] = { "0000","0001","0010","0011","0100","0101","0110","0111", "1000","1001","1010","1011","1100","1101","1110","1111" };
	int i = 0;
	for (int i = 0; i < hex.length(); i++) {
		int j = 0;
		switch (hex[i]) {
		case 'A':j = 10; break;
		case 'B':j = 11; break;
		case 'C':j = 12; break;
		case 'D':j = 13; break;
		case 'E':j = 14; break;
		case 'F':j = 15; break;
		default:
			j = stoi(hex.substr(i, 1));
			break;
		}
		a += bin[j];
	}
	return a;
}
//ham chuyen tu bat phan sang thap phan
string oct_dec(string oct) {
	//chuyen tu he bat phan sang nhi phan
	string n_bin = oct_bin(oct);
	//chuyen tu he nhi phan sang he thap pha
	string n_dec = bin_dec(n_bin);
	return n_dec;
}
//Ham chuyen tu hex phan sang thap phan
string hex_dec(string hex) {
	//Ham chuyen tu hex sang nhi phan
	string n_bin = hex_bin(hex);
	//Ham chuyen tu nhi phan sang thap phan
	string n_dec = bin_dec(n_bin);
	return n_dec;
}
//Ham chuyen tu bat phan sang thap luc phan
string oct_hex(string oct) {
	//Chuyen tu oct sang bin
	string n_bin = oct_bin(oct);
	//Chyen tu bin sang hex
	string n_hex = bin_hex(n_bin);
	return n_hex;
}
//Ham chuyen tu thap luc phan sang bat phan
string hex_oct(string hex) {
	//Chuyen tu hex sang bin
	string n_bin = hex_bin(hex);
	//Chyen tu bin sang oct
	string n_oct = bin_oct(n_bin);
	return n_oct;
}

//Ham kiem tra dieu kien nhap
//Kiem tra chuoi chi co so so voi dec
bool isDec(string s) {
	string condition = "0123456789";
	int j = 0, n = s.length();
	while (j < n) {
		if (condition.find(s[j]) == -1) {
			break;
		}
		j++;
	}
	if (j == n) return true; else return false;
}
//Kiem tra chuoi chi co so so voi bin
bool isBin(string s) {
	string condition = "01";
	int j = 0, n = s.length();
	while (j < n) {
		if (condition.find(s[j]) == -1) {
			break;
		}
		j++;
	}
	if (j == n) return true; else return false;
}
//Kiem tra chuoi chi co so so voi oct
bool isOct(string s) {
	string condition = "01234567";
	int j = 0, n = s.length();
	while (j < n) {
		if (condition.find(s[j]) == -1) {
			break;
		}
		j++;
	}
	if (j == n) return true; else return false;
}
//Kiem tra chuoi chi co so so voi hex
bool isHex(string s) {
	string condition = "0123456789ABCDEF";
	int j = 0, n = s.length();
	while (j < n) {
		if (condition.find(s[j]) == -1) {
			break;
		}
		j++;
	}
	if (j == n) return true; else return false;
}


//Ham dua ra cau hinh nhap
short configuration() {
	short select = 0;
	//khoi dau la nhi phan
	cout << "1 : Tu nhi phan sang thap phan:" << endl;
	cout << "2 : Thap phan sang nhi phan:" << endl;
	cout << "3 : Tu nhi phan sang bat phan:" << endl;
	cout << "4 : Bat phan sang nhi phan:" << endl;
	cout << "5 : Tu nhi phan sang thap luc phan:" << endl;
	cout << "6 : Thap luc phan sang nhi phan:" << endl;
	//khoi dau la bat phan
	cout << "7 : Tu thap phan sang bat phan:" << endl;
	cout << "8 : Bat phan sang thap phan:" << endl;
	cout << "9 : Tu thap phan sang thap luc phan:" << endl;
	cout << "10 : Thap luc phan sang thap phan:" << endl;
	//khoi dau la thap nhi phan
	cout << "11 : Tu bat phan sang thap luc phan:" << endl;
	cout << "12 : Thap luc phan sang thap bat phan:" << endl;
	string k = "";
	do {
		cout << "Lua chon " << k << " phep bien doi:" << endl;
		cin >> select;
		k = "lai";
	} while (select <= 0 || select > 12);
	cin.ignore();//xoa bo nho dem
	return select;
}

//Ham nhap chung
void Input_Data(bool(*Condition)(string), string(*Process)(string)) {
	bool dk = false;
	string k = "", s;
	while (dk == false) {
		cout << "Nhap " << k << " gia tri can chuyen doi:" << endl;
		getline(cin, s);
		dk = Condition(s);
		k = "lai";
	}
	//Ham chuyen doi 
	cout << "Gia tri sau khi chuyen doi la: \n" << Process(s) << endl;
}
//Ham thuc hien qua trinh chuyen doi
void Process() {
	string number, print;
	switch (configuration())
	{
	case 1:
		Input_Data(isBin, bin_dec);
		break;
	case 2:
		Input_Data(isDec, dec_bin);
		break;
	case 3:
		Input_Data(isBin, bin_oct);
		break;
	case 4:
		Input_Data(isOct, oct_bin);
		break;
	case 5:
		Input_Data(isBin, bin_hex);
		break;
	case 6:
		Input_Data(isHex, hex_bin);
		break;
	case 7:
		Input_Data(isDec, dec_oct);
		break;
	case 8:
		Input_Data(isOct, oct_dec);
		break;
	case 9:
		Input_Data(isDec, dec_hex);
		break;
	case 10:
		Input_Data(isHex, hex_dec);
		break;
	case 11:
		Input_Data(isOct, oct_hex);
		break;
	case 12:
		Input_Data(isHex, hex_oct);
		break;

	default:
		break;
	}
}
//Ham thuc hien qua trinh lap
void Loop() {
	short j = 1;
	while (j != 0) {
		Process();
		cout << "Ban co muon thuc hien tiep hay khong , neu khong nhat 0 de thoat.Nhan phim so bat ki de tiep tuc" << endl;
		cin >> j;
		cin.ignore();
	}
}
int main()
{
	Loop();

	return 0;
}
