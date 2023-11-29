#include <string>
#include <iostream>

using namespace std;

class Authentication {
    private:
        Nasabah* nasabah[100];
        int registeredNasabah;
        int signInIndex;
    public:
        bool login() {
            /// login account
            string username = Helper::inputData("Username");
            string password = Helper::inputData("Password");
            /// Validate account exists
            for (int i = 0; i < registeredNasabah; ++i) {
                if (nasabah[i]->getUsername() == username && nasabah[i]->getPassword() == password) {
                    signInIndex = i;
                    return true;
                }
            }
            cout << "\nLogin gagal. Username atau password salah.\n";
            return false;
        }

        Nasabah getSignInNasabah() {
            return *nasabah[signInIndex];
        }

        void addNasabah(const Nasabah& _nasabah) {
            if (registeredNasabah >= 100) {
                cout << "\nJumlah nasabah sudah mencapai batas maksimal\n";
                return;
            }
            nasabah[registeredNasabah] = new Nasabah(_nasabah);
            registeredNasabah++;
        }

        Authentication() {
            registeredNasabah = 0;
        }

        ~Authentication() {
            for (int i = 0; i < registeredNasabah; ++i) {
                delete nasabah[i];
            }
        }
};
