#include <string>
#include <iostream>

using namespace std;

class Nasabah {
    private:
        string no_rekening;
        string fullName;
        string username;
        string password;
        string email;
        string branch;
        string phone;
        string savingType;
        string cardType;
        string noKtp;
        string npwp;
        string religion;
        string birthday;
        string address;
        string job;
        int salary;
    public:
        Nasabah(string _no_rekening, string _nama, string _username, string _password, string _email, string _branch, string _phone, string _savingType, string _cardType, string _noKtp, string _npwp, string _religion, string _birthday, string _address, string _job, int _salary) {
            no_rekening = _no_rekening;
            fullName = _nama;
            username = _username;
            password = _password;
            email = _email;
            branch = _branch;
            phone = _phone;
            savingType = _savingType;
            cardType = _cardType;
            noKtp = _noKtp;
            npwp = _npwp;
            religion = _religion;
            birthday = _birthday;
            address = _address;
            job = _job;
            salary = _salary;
        }

        string getUsername() {
            return username;
        }

        string getPassword() {
            return password;
        }

        string getFullName() {
            return fullName;
        }
};