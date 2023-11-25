#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

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
            if (value == "") {
            	cout << "\nData tidak boleh kosong\n";
            	return inputData(title);
			}
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

class Deposito {
    public:
        string instruksi_jatuh_tempo[2] = {
            "Perpanjang Pokok", "Berhenti",
        };
        int start() {
            cin.ignore();
            string sumber_rekening_pendebit = Helper::inputData("Sumber Rekening Pendebit");
            int tenor_deposito = getTenor();
            int nominal_deposito = Helper::to_int(Helper::inputData("Nominal Deposito"));

            /// Bunga 3.25%
            float bunga = 0.0325;

            float bunga_deposito;
            float hitungTenor = (((float)tenor_deposito / 12) / (float)tenor_deposito);
            hitungTenor = round(hitungTenor * 100) / 100;
            
            bunga_deposito = (float)nominal_deposito * bunga * hitungTenor * 0.8;
            cout << "\nBunga Deposito: Rp" << fixed << setprecision(0) << bunga_deposito;

            /// Pilihan deposito:
            /// 1. Perpanjang Pokok 
            /// 2. Berhenti
            string pilihan_instruksi_jatuh_tempo = Helper::pickDataArray(instruksi_jatuh_tempo, 2, "Instruksi Jatuh Tempo", "instruksi jatuh tempo");
            cin.ignore();

            if (pilihan_instruksi_jatuh_tempo == "Perpanjang Pokok") {
                cout << "\nAnda memilih perpanjang pokok\n";
            } else {
                cout << "\nAnda memilih berhenti\n";
            }

            cout << "\n=================================";
            cout << "\n    DEPOSITO                    ";
            cout << "\n=================================";
            cout << "\nSumber Rekening Pendebit: " << sumber_rekening_pendebit;
            cout << "\nTenor Deposito: " << tenor_deposito;
            cout << "\nNominal Deposito: Rp" << fixed << setprecision(0) << nominal_deposito;
            cout << "\nBunga: " << fixed << setprecision(4) << bunga << "%";
            cout << "\nBunga Deposito: Rp" << fixed << setprecision(0) << bunga_deposito << "/tahun";
            cout << "\nInstruksi Jatuh Tempo: " << pilihan_instruksi_jatuh_tempo;
            cout << "\n=================================";
            return 1;
        }

        int getTenor() {
            int tenor = 0;
            while (true) {
                tenor = Helper::to_int(Helper::inputData("Tenor Deposito [1-12]"));
                if (tenor <= 12) {
                    break;
                } else {
                    cout << "[Error] Tenor deposito tidak bisa lebih dari 12 bulan\n";
                }
            }
            return tenor;
        }
};

class KTA {
    public:
        int start() {
            cin.ignore();
            string no_rekening = Helper::inputData("Nomor Rekening");
            string no_ktp = Helper::inputData("Nomor Identitas Penduduk (KTP)");
            string no_kk = Helper::inputData("Nomor Kartu Keluarga (KK)");
            string no_npwp = Helper::inputData("Nomor NPWP");
            int slip_gaji = Helper::to_int(Helper::inputData("Slip Gaji"));

            float dana_cair;
            int nominal_pinjaman = getNominalPinjaman();
            int tenor = getTenor();
            float bunga = 0.5;

            float hitungTenor = (((float)tenor / 12) / (float)tenor);
            hitungTenor = round(hitungTenor * 100) / 100;

            dana_cair =  (float)nominal_pinjaman - (((float)nominal_pinjaman * bunga) * hitungTenor);
            dana_cair = round(dana_cair * 100) / 100;

            cout << "\n=================================";
            cout << "\nDANA CAIR: Rp" <<  fixed << setprecision(0) << dana_cair;
            cout << "\n=================================";

            return 1;
        }

        int getNominalPinjaman() {
            int pinjaman = 0;
            while (true) {
                pinjaman = Helper::to_int(Helper::inputData("Nominal Pinjaman"));
                if (pinjaman <= 100000000) {
                    break;
                } else {
                    cout << "[Error] Nominal pinjaman tidak bisa lebih dari 100jt\n";
                }
            }
            return pinjaman;
        }

        int getTenor() {
            int tenor = 0;
            while (true) {
                tenor = Helper::to_int(Helper::inputData("Tenor Pinjaman [1-12]"));
                if (tenor <= 12) {
                    break;
                } else {
                    cout << "[Error] Tenor pinjaman tidak bisa lebih dari 12 bulan\n";
                }
            }
            return tenor;
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
    cout << "\n4. Keluar";

    int menu;
    cout << "\nSilahkan pilih layanan: ";cin >> menu;

    PemukaanRekening pemukaanRekening;
    KTA kta;
    Deposito deposito;
    int status;
    switch(menu) {
        case 1:
            status = pemukaanRekening.start();
            break;
        case 2:
            status = deposito.start();
            break;
        case 3:
            status = kta.start();
            break;
        case 4:
            exit(0);
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
