#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;
int yanlisSayisi;

//Prototip Aral���
void BardakOyunu();
void AnaMenu();
void SayiTahminOyunu();
void AdamAsmaca();
void AdamCiz();
string KelimeSec();
void Yanlis0();
void Yanlis1();
void Yanlis2();
void Yanlis3();
void Yanlis4();
void Yanlis5();
void Yanlis6();
void DosyayaKaydetSayiTahmin(int puan);
void DosyayaKaydetAdamAsmaca(int puan);
void PuanTablolari();
void TabloYazdirSayiTahmin();
void TabloYazdirAdamAsmaca();
//Prototip Aral���

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Turkish");
	AnaMenu();
	return 758;
}
void AnaMenu()
{
	int kontrol;
	system("cls");
	cout << "------------------- Ana Men�'ye Ho�geldiniz. --------------------\n\n"
		<< "|\t'Top Hangi Bardakta?' oyununu oynamak i�in '1' yaz�n.   |\n\n"
		<< "|\t'Say� Tahmin' oyununu oynamak i�in '2' yaz�n.           |\n\n"
		<< "|\t'Adam Asmaca' oyununu oynamak i�in '3' yaz�n.           |\n\n"
		<< "|\tPuan tablolar�n� g�rmek i�in '4' yaz�n.                 |\n\n"
		<< "|\tProgramdan ��kmak i�in '0' yaz�n.                       |\n\n"
		<< "-----------------------------------------------------------------\n";
	cin >> kontrol;
	while (kontrol<0||kontrol>4)
	{
		cout << "Hatal� de�er girdiniz, l�tfen tekrar deneyin.\n";
		cin >> kontrol;
	}
	switch (kontrol)
	{
	case 1:
		BardakOyunu();
		break;
	case 2:
		SayiTahminOyunu();
		break;
	case 3:
		AdamAsmaca();
		break;
	case 4:
		PuanTablolari();
		break;
	default:
		break;
	}
}
void BardakOyunu()
{
	system("cls");
	int top = rand() % 3 + 1, tahmin;
	cout << "\t\t\t  -------    -------    -------\n"
		<< "\t\t\t /       \\  /       \\  /       \\"
		<< "\n\t\t\t|    1    ||    2    ||    3    |"
		<< "\n\t\t\t|    ?    ||    ?    ||    ?    |"
		<< "\n\t\t\t|         ||         ||         |\n"
		<< "\n\t\t\t\tTop Hangi Bardakta ? \n\t\t\t";
	cin >> tahmin;
	while (tahmin > 3 || tahmin < 1)
	{
		cout << "\t\t\tL�tfen 1 ile 3 aras�nda bir say� giriniz.\n\t\t\t";
		cin >> tahmin;
	}
	if (tahmin == top)
		cout << "\n\t\t\tTebrikler Do�ru Bildin!!!\n\n";
	else
		cout << "\n\t\t\tBulamad�n Top " << top << ". Bardaktayd�.\n\n";
	cout << "\t\t\tYeniden oynamak i�in '1'\n"
		<< "\t\t\tAna men�ye d�nmek i�in '2'\n"
		<< "\t\t\tProgramdan ��kmak i�in '0' yaz�n.\n\t\t\t";
	int secenek;
	cin >> secenek;
	while (secenek < 0 || secenek > 2)
	{
		cout << "Hatal� de�er girdiniz, l�tfen tekrar deneyin.\n";
		cin >> secenek;
	}
	switch (secenek)
	{
	case 1:
		BardakOyunu();
		break;
	case 2:
		AnaMenu();
		break;
	default:
		break;
	}
}
void SayiTahminOyunu()
{
	system("cls");
	int num = rand() % 9000 + 1000, tahmin, sayac = 1;
	cout << "\n\t\t\t1000 ile 9999 aras�nda bir say� tuttum, bakal�m bulabilecek misin?\n\n\t\t";
	cin >> tahmin;
	while (tahmin != num)
	{
		while (tahmin < 1000 || tahmin>9999)
		{
			cout << "\t\t\tL�tfen 1000 ile 9999 aras�nda bir say� gir.\n\t\t";
			cin >> tahmin;
		}
		if (tahmin > num)
			cout << "\t\t\tB�y�k bir say� girdin, tekrar dene.\n\t\t";
		else
			cout << "\t\t\tK���k bir say� girdin, tekrar dene.\n\t\t";
		cin >> tahmin;
		sayac++;
	}
	int puan = 10000 / sayac;
	cout << "\n\t\tTebrikler say�y� " << sayac << " denemede buldun. (" << num << ")\n\t\t"<<puan<<" puan ald�n!\n\n";
	cout << "\t\tYeniden oynamak i�in '1'\n"
		<< "\t\tAna men�ye d�nmek i�in '2'\n"
		<< "\t\tPuan�n� kaydetmek i�in '3'\n"
		<< "\t\tProgramdan ��kmak i�in '0' yaz�n.\n\t\t";
	int secenek;
	cin >> secenek;
	while (secenek < 0 || secenek > 3)
	{
		cout << "Hatal� de�er girdiniz, l�tfen tekrar deneyin.\n";
		cin >> secenek;
	}
	switch (secenek)
	{
	case 1:
		SayiTahminOyunu();
		break;
	case 2:
		AnaMenu();
		break;
	case 3:
		DosyayaKaydetSayiTahmin(puan);
		AnaMenu();
		break;
	default:
		break;
	}
}
void AdamAsmaca()
{
	yanlisSayisi = 0;
	system("cls");
	string kelime = KelimeSec(), yeniKelime, kelimeTahmin;
	char temp;
	char harfler[32], tahmin;
	int sayac = 0, puan = 0;
	for (int i = 0; i < kelime.length(); i++)
		yeniKelime.push_back('_');
	while (kelime != yeniKelime && yanlisSayisi < 6 && kelimeTahmin != kelime)
	{
		bool degisim = false;
		system("cls");
		AdamCiz();

		cout << "\nKullan�lan Harfler = '";
		for (int i = 0; i < sayac; i++)
			cout << harfler[i] << " ";
		cout << "'" << endl;

		cout << "\nKelime = ";
		for (int i = 0; i < kelime.length(); i++)
			cout << yeniKelime[i] << " ";

		cout << "\n\nL�tfen T�rk�e karakter kullanmay�n(�, �, �, �, �, �) \n\n"
			<< "Kelimeyi tahmin etmek istiyorsan�z '5' yaz�n.\n\n"
			<< "Bir harf gir : ";
		cin >> tahmin;
		bool dene = true;
		while (dene)
		{
			dene = false;
			for (int i = 0; i < 32; i++)
			{
				if (tahmin == harfler[i])
				{
					dene = true;
					cout << "Bu harfi daha �nce kulland�n�z l�tfen ba�ka bir harf girin.\n";
					cin >> tahmin;
					break;
				}
			}
		}
		if (tahmin == '5')
		{
			cout << "\nTahmininizi yaz�n : ";
			cin >> kelimeTahmin;
			if (kelimeTahmin != kelime)
				yanlisSayisi++;
		}
		else
		{
			harfler[sayac] = tahmin;
			for (int i = 0; i < kelime.length(); i++)
			{
				if (tahmin == kelime[i])
				{
					yeniKelime[i] = tahmin;
					degisim = true;
				}
			}
			if (!degisim)
				yanlisSayisi++;
			sayac++;
		}
	}
	if (kelime==yeniKelime||kelime==kelimeTahmin)
	{
		if (yanlisSayisi == 0)
			yanlisSayisi = 1;
		puan = (2000 * kelime.length()) / yanlisSayisi;
		cout << "Tebrikler Kelimeyi Buldun.(" << kelime << ")\nPuan�n : " << puan << endl;
	}
	else
	{
		system("cls");
		Yanlis6();
		cout << "\n�ld�n, oyun bitti.\nKelime = " << kelime << endl;
	}
	cout << "\nYeniden oynamak i�in '1'\n"
		<< "Ana men�ye d�nmek i�in '2'\n"
		<< "Puan�n� kaydetmek i�in '3'\n"
		<< "Programdan ��kmak i�in '0' yaz�n.\n";
	int secenek;
	cin >> secenek;
	while (secenek < 0 || secenek > 3)
	{
		cout << "Hatal� de�er girdiniz, l�tfen tekrar deneyin.\n";
		cin >> secenek;
	}
	switch (secenek)
	{
	case 1:
		AdamAsmaca();
		break;
	case 2:
		AnaMenu();
		break;
	case 3:
		if (puan!=0)
			DosyayaKaydetAdamAsmaca(puan);
		else
		{
			cout << "Oyunu kaybetti�iniz i�in puan�n�z� kaydedemezsiniz.\n"
				<< "Ana men�ye d�nmek i�in herhangi bir �ey yaz�n.\n";
			cin >> temp;
		}
		AnaMenu();
		break;
	default:
		break;
	}
}
void AdamCiz()
{
	switch (yanlisSayisi)
	{
	case 0:
		Yanlis0();
		break;
	case 1:
		Yanlis1();
		break;
	case 2:
		Yanlis2();
		break;
	case 3:
		Yanlis3();
		break;
	case 4:
		Yanlis4();
		break;
	case 5:
		Yanlis5();
		break;
	default:
		break;
	}
}
string KelimeSec()
{
	string kelime;
	int sayi = rand() % 50 + 1;
	ifstream dosya;
	dosya.open("AdamAsmacaKelimeleri.txt", ios::in);
	for (int i = 0; i < sayi; i++)
		dosya >> kelime;
	dosya.close();
	return kelime;
}
void Yanlis0()
{
	cout << " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< "---" << endl;
}
void Yanlis1()
{
	cout << " |------------|" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< "---" << endl;
}
void Yanlis2()
{
	cout << " |------------|" << endl
		<< " |" << setw(14) << right << "( )" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< " |" << endl
		<< "---" << endl;
}
void Yanlis3()
{
	cout << " |------------|" << endl
		<< " |" << setw(14) << right << "( )" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << endl
		<< "---" << endl;
}
void Yanlis4()
{
	cout << " |------------|" << endl
		<< " |" << setw(14) << right << "( )" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << setw(14) << right << "/|\\" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << endl
		<< "---" << endl;
}
void Yanlis5()

{
	cout << " |------------|" << endl
		<< " |" << setw(14) << right << "( )" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << setw(14) << right << "/|\\" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << setw(14) << right << "/ \\" << endl
		<< "---" << endl;
}
void Yanlis6()
{
	cout << " |------------|" << endl
		<< " |" << setw(14) << right << "( )" << endl
		<< " |" << setw(13) << right << "|" << endl
		<< " |" << endl
		<< " |" << setw(13) << right << "\\   \\  " << endl
		<< " |" << setw(12) << right << "-----" << endl
		<< "---" << setw(13) << right << "/   /   " << endl;
}
void DosyayaKaydetSayiTahmin(int puan)
{
	ofstream dosya;
	string isim;
	cout << "\t\tisminizi girin : ";
	cin >> isim;
	dosya.open("SayiTahminPuan.txt", ios::app);
	dosya << isim << ", " << puan << " puan ald�." << endl;
	dosya.close();
}
void DosyayaKaydetAdamAsmaca(int puan)
{
	ofstream dosya;
	string isim;
	cout << "isminizi girin : ";
	cin >> isim;
	dosya.open("AdamAsmacaPuan.txt", ios::app);
	dosya << isim << ", " << puan << " puan ald�." << endl;
	dosya.close();
}
void PuanTablolari()
{
	system("cls");
	int secenek;
	cout << "-------------------------------------------------------------------------\n\n|";
	cout << "\tSay� Tahmin oyununun puan tablosunu g�rmek i�in '1' yaz�n.      |\n\n|"
		<< "\tAdam Asmaca oyununun puan tablosunu g�rmek i�in '2' yaz�n.      |\n\n"
		<< "-------------------------------------------------------------------------\n\n|"
		<< "\tAna men�ye d�nmek i�in '3' yaz�n.                               |\n\n|"
		<< "\tProgramdan ��kmak i�in '0' yaz�n.                               |\n\n"
		<< "-------------------------------------------------------------------------\n";
	cin >> secenek;
	while (secenek < 0 || secenek > 3)
	{
		cout << "Hatal� de�er girdiniz, l�tfen tekrar deneyin.\n";
		cin >> secenek;
	}
	switch (secenek)
	{
	case 1:
		TabloYazdirSayiTahmin();
		break;
	case 2:
		TabloYazdirAdamAsmaca();
		break;
	case 3:
		AnaMenu();
		break;
	default:
		break;
	}
}
void TabloYazdirSayiTahmin()
{
	system("cls");
	ifstream dosya;
	string satir;
	dosya.open("SayiTahminPuan.txt", ios::in);
	cout << "-----------------------------------------------\n\n";
	while (!dosya.eof())
	{
		getline(dosya, satir);
		cout << "\t" << satir << endl;
	}
	cout << "-----------------------------------------------\n";
	dosya.close();
	char secenek;
	cout << "\nAna men�ye d�nmek i�in herhangi bir �ey yaz�n.\n";
	cin >> secenek;
	AnaMenu();
}
void TabloYazdirAdamAsmaca()
{
	system("cls");
	fstream dosya;
	string satir;
	dosya.open("AdamAsmacaPuan.txt", ios::in);
	cout << "-----------------------------------------------\n\n";
	while (!dosya.eof())
	{
		getline(dosya, satir);
		cout << "\t" << satir << endl;
	}
	cout << "-----------------------------------------------\n";
	dosya.close();
	char secenek;
	cout << "\nAna men�ye d�nmek i�in herhangi bir �ey yaz�n.\n";
	cin >> secenek;
	AnaMenu();
}