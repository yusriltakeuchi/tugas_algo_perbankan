#include <iostream>
#include <conio.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

class Helper {
    public:
        static string generateRandomDigitNumber(int length) {
            string randomString = "";
            for (int i = 0; i < length; i++) {
                randomString += to_string(rand() % 10);
            }
            return randomString;
        }

        static string pickDataArray(string items[], int length, string title, string subtitle) {
            cout << "\n=================================";
            cout << "\n    Daftar " << title << "       ";
            cout << "\n=================================";

            for(int k = 0; k < length; k++) {
                cout << "\n" << k+1 << ". " << items[k];
            }
            int selectedItem = 0;
            cout << "\nSilahkan pilih " << subtitle << " : ";cin >> selectedItem;
            cout << "\n";
            return items[selectedItem-1];
        }

        static string inputData(string title) {
            cout << "------------------------------\n";
            string value;
            cout << "Masukkan " << title << ": ";
            std::getline(std::cin, value);
            return value;
        }

        static std::string to_string(int i) {
            std::stringstream ss;
            ss << i;
            return ss.str();
        } 

        static int to_int(std::string s) {
            std::stringstream ss(s);
            int result = 0;
            ss >> result;
            return result;
        }
};

class PemukaanRekening {
    public:
        string branchs[5] = {
            "Slipi", "Kemanggisan", "Kebon Jeruk", "Kebayoran Lama", "Kebayoran Baru",
        };
        string savingTypes[3] = {
            "Tabungan Pelajar", "Tabungan Bisnis", "Tabungan Umum",
        };
        string cardTypes[4] = {
            "Reguler", "Gold", "Platinum", "Black",
        };

        int start() {
            string selectedBranch = Helper::pickDataArray(branchs, 5, "Cabang Bank", "cabang");
            cin.ignore();

            string username = Helper::inputData("Username");
            string email = Helper::inputData("Email");
            string password = Helper::inputData("Password");
            string phone = Helper::inputData("Nomor Telepon");

            string selectedSavingType = Helper::pickDataArray(savingTypes, 3, "Jenis Tabungan", "jenis tabungan");
            cin.ignore();
            string selectedCardType = Helper::pickDataArray(cardTypes, 4, "Jenis Kartu", "jenis kartu");
            cin.ignore();

            string noKtp = Helper::inputData("Nomor Identitas Penduduk (KTP)");
            string npwp = Helper::inputData("NPWP");

            string fullName = Helper::inputData("Nama Lengkap");
            string religion = Helper::inputData("Agama");
            string birthday = Helper::inputData("Tanggal Lahir (dd/mm/yyyy)");
            string address = Helper::inputData("Alamat");

            string job = Helper::inputData("Pekerjaan");
            int salary = Helper::to_int(Helper::inputData("Penghasilan"));

            string noRekening = "";
            noRekening = generateNoRekening(
                selectedBranch, 
                username, 
                password, 
                phone, 
                selectedSavingType, 
                selectedCardType, 
                noKtp, 
                npwp, 
                fullName, 
                religion, 
                birthday, 
                address, 
                job, 
                salary
            );

            if (noRekening != "") {
                /// print all data input and no rekening
                cout << "\n=================================";
                cout << "\n    Data Pembukaan Rekening       ";
                cout << "\n=================================";
                cout << "\nCabang Bank: " << selectedBranch;
                cout << "\nUsername: " << username;
                cout << "\nEmail: " << email;
                cout << "\nPassword: " << password;
                cout << "\nNomor Telepon: " << phone;
                cout << "\nJenis Tabungan: " << selectedSavingType;
                cout << "\nJenis Kartu: " << selectedCardType;
                cout << "\nNomor Identitas Penduduk (KTP): " << noKtp;
                cout << "\nNPWP: " << npwp;
                cout << "\nNama Lengkap: " << fullName;
                cout << "\nAgama: " << religion;
                cout << "\nTanggal Lahir: " << birthday;
                cout << "\nAlamat: " << address;
                cout << "\nPekerjaan: " << job;
                cout << "\nPenghasilan: " << salary;
                cout << "\n=================================";
                cout << "\nNomor Rekening: " << noRekening;
                cout << "\n=================================";
                return 1;
            }
            return 0;
        }

        /// no Rekening = savingTypeCode + branchCode + random7DigitNumber
        string generateNoRekening(
            string branch, 
            string username, 
            string password, 
            string phone, 
            string savingType, 
            string cardType, 
            string noKtp, 
            string npwp, 
            string fullName, 
            string religion, 
            string birthday, 
            string address, 
            string job, 
            int salary
        ) {
            string randomNumber = Helper::generateRandomDigitNumber(7);
            string noRekening = getCodeSavingType(savingType) + getCodeBranch(branch) + randomNumber;
            return noRekening;
        }

        string getCodeBranch(string branch) {
            if (branch == "Slipi") {
                return "01";
            } else if (branch == "Kemanggisan") {
                return "02";
            } else if (branch == "Kebon Jeruk") {
                return "03";
            } else if (branch == "Kebayoran Lama") {
                return "04";
            } else if (branch == "Kebayoran Baru") {
                return "05";
            }
            return "";
        }

        string getCodeSavingType(string savingType) {
            if (savingType == "Tabungan Pelajar") {
                return "1";
            } else if (savingType == "Tabungan Bisnis") {
                return "2";
            } else if (savingType == "Tabungan Umum") {
                return "3";
            }
            return "";
        }
};

void chooseMenu() {
    cout << "\n=================================";
    cout << "\n    PERBANKAN KELOMPOK 2         ";
    cout << "\n=================================";
    cout << "\n1. Pembukaan Rekening";
    cout << "\n2. Deposito";
    cout << "\n3. Kredit Tanpa Agunan (KTA)";

    int menu;
    cout << "\nSilahkan pilih layanan: ";cin >> menu;

    PemukaanRekening pemukaanRekening;
    int status;
    switch(menu) {
        case 1:
            status = pemukaanRekening.start();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "Pilihan menu tidak ditemukan";
            chooseMenu();
            break;
    }

    if (status == 1) {
        cout << "\nApakah Anda ingin memilih layanan lainnya lagi? [y/n]\n";
        string choose = Helper::inputData("Pilihan");
        if (choose == "y" || choose == "yes") {
            /// clear screen
            system("cls");
            chooseMenu();
        } else {
            cout << "\nTerima kasih telah melakukan transaksi dengan kami";
        }    
    }
}

int main() {
    chooseMenu();
    return 0;
}
