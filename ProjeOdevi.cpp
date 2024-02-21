#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;
int yanlisSayisi;

//Prototip Aralýðý
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
//Prototip Aralýðý

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
	cout << "------------------- Ana Menü'ye Hoþgeldiniz. --------------------\n\n"
		<< "|\t'Top Hangi Bardakta?' oyununu oynamak için '1' yazýn.   |\n\n"
		<< "|\t'Sayý Tahmin' oyununu oynamak için '2' yazýn.           |\n\n"
		<< "|\t'Adam Asmaca' oyununu oynamak için '3' yazýn.           |\n\n"
		<< "|\tPuan tablolarýný görmek için '4' yazýn.                 |\n\n"
		<< "|\tProgramdan çýkmak için '0' yazýn.                       |\n\n"
		<< "-----------------------------------------------------------------\n";
	cin >> kontrol;
	while (kontrol<0||kontrol>4)
	{
		cout << "Hatalý deðer girdiniz, lütfen tekrar deneyin.\n";
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
		cout << "\t\t\tLütfen 1 ile 3 arasýnda bir sayý giriniz.\n\t\t\t";
		cin >> tahmin;
	}
	if (tahmin == top)
		cout << "\n\t\t\tTebrikler Doðru Bildin!!!\n\n";
	else
		cout << "\n\t\t\tBulamadýn Top " << top << ". Bardaktaydý.\n\n";
	cout << "\t\t\tYeniden oynamak için '1'\n"
		<< "\t\t\tAna menüye dönmek için '2'\n"
		<< "\t\t\tProgramdan çýkmak için '0' yazýn.\n\t\t\t";
	int secenek;
	cin >> secenek;
	while (secenek < 0 || secenek > 2)
	{
		cout << "Hatalý deðer girdiniz, lütfen tekrar deneyin.\n";
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
	cout << "\n\t\t\t1000 ile 9999 arasýnda bir sayý tuttum, bakalým bulabilecek misin?\n\n\t\t";
	cin >> tahmin;
	while (tahmin != num)
	{
		while (tahmin < 1000 || tahmin>9999)
		{
			cout << "\t\t\tLütfen 1000 ile 9999 arasýnda bir sayý gir.\n\t\t";
			cin >> tahmin;
		}
		if (tahmin > num)
			cout << "\t\t\tBüyük bir sayý girdin, tekrar dene.\n\t\t";
		else
			cout << "\t\t\tKüçük bir sayý girdin, tekrar dene.\n\t\t";
		cin >> tahmin;
		sayac++;
	}
	int puan = 10000 / sayac;
	cout << "\n\t\tTebrikler sayýyý " << sayac << " denemede buldun. (" << num << ")\n\t\t"<<puan<<" puan aldýn!\n\n";
	cout << "\t\tYeniden oynamak için '1'\n"
		<< "\t\tAna menüye dönmek için '2'\n"
		<< "\t\tPuanýný kaydetmek için '3'\n"
		<< "\t\tProgramdan çýkmak için '0' yazýn.\n\t\t";
	int secenek;
	cin >> secenek;
	while (secenek < 0 || secenek > 3)
	{
		cout << "Hatalý deðer girdiniz, lütfen tekrar deneyin.\n";
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

		cout << "\nKullanýlan Harfler = '";
		for (int i = 0; i < sayac; i++)
			cout << harfler[i] << " ";
		cout << "'" << endl;

		cout << "\nKelime = ";
		for (int i = 0; i < kelime.length(); i++)
			cout << yeniKelime[i] << " ";

		cout << "\n\nLütfen Türkçe karakter kullanmayýn(ý, ö, ü, ç, ð, þ) \n\n"
			<< "Kelimeyi tahmin etmek istiyorsanýz '5' yazýn.\n\n"
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
					cout << "Bu harfi daha önce kullandýnýz lütfen baþka bir harf girin.\n";
					cin >> tahmin;
					break;
				}
			}
		}
		if (tahmin == '5')
		{
			cout << "\nTahmininizi yazýn : ";
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
		cout << "Tebrikler Kelimeyi Buldun.(" << kelime << ")\nPuanýn : " << puan << endl;
	}
	else
	{
		system("cls");
		Yanlis6();
		cout << "\nÖldün, oyun bitti.\nKelime = " << kelime << endl;
	}
	cout << "\nYeniden oynamak için '1'\n"
		<< "Ana menüye dönmek için '2'\n"
		<< "Puanýný kaydetmek için '3'\n"
		<< "Programdan çýkmak için '0' yazýn.\n";
	int secenek;
	cin >> secenek;
	while (secenek < 0 || secenek > 3)
	{
		cout << "Hatalý deðer girdiniz, lütfen tekrar deneyin.\n";
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
			cout << "Oyunu kaybettiðiniz için puanýnýzý kaydedemezsiniz.\n"
				<< "Ana menüye dönmek için herhangi bir þey yazýn.\n";
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
	dosya << isim << ", " << puan << " puan aldý." << endl;
	dosya.close();
}
void DosyayaKaydetAdamAsmaca(int puan)
{
	ofstream dosya;
	string isim;
	cout << "isminizi girin : ";
	cin >> isim;
	dosya.open("AdamAsmacaPuan.txt", ios::app);
	dosya << isim << ", " << puan << " puan aldý." << endl;
	dosya.close();
}
void PuanTablolari()
{
	system("cls");
	int secenek;
	cout << "-------------------------------------------------------------------------\n\n|";
	cout << "\tSayý Tahmin oyununun puan tablosunu görmek için '1' yazýn.      |\n\n|"
		<< "\tAdam Asmaca oyununun puan tablosunu görmek için '2' yazýn.      |\n\n"
		<< "-------------------------------------------------------------------------\n\n|"
		<< "\tAna menüye dönmek için '3' yazýn.                               |\n\n|"
		<< "\tProgramdan çýkmak için '0' yazýn.                               |\n\n"
		<< "-------------------------------------------------------------------------\n";
	cin >> secenek;
	while (secenek < 0 || secenek > 3)
	{
		cout << "Hatalý deðer girdiniz, lütfen tekrar deneyin.\n";
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
	cout << "\nAna menüye dönmek için herhangi bir þey yazýn.\n";
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
	cout << "\nAna menüye dönmek için herhangi bir þey yazýn.\n";
	cin >> secenek;
	AnaMenu();
}