#include <string>
#include <iostream>

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

        static string inputData(string title, string message = "") {
            cout << "------------------------------\n";
            string value;
            if (message != "") {
                cout << message;
            } else {
                cout << "Masukkan " << title << ": ";
            }
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

        static void clearScreen() {
            cout << "\033[2J\033[1;1H";
        }
};
