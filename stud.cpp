#include <iostream>
#include <iomanip>
using namespace std;

class student {
public:
    string name;
    int roll;
    string* sub;

    virtual void accept(int n) {
        cout << "\nEnter roll: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
        sub = new string[n];
        cout << "Enter subjects:\n";
        for (int i = 0; i < n; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> sub[i];
        }
    }

    virtual void display(int n) {
        cout << left << setw(10) << "Roll No" << setw(15) << "Name" << "Subjects\n";
        cout << setw(10) << roll << setw(15) << name;
        for (int i = 0; i < n; i++) {
            cout << sub[i] << " ";
        }
        cout << endl;
    }

   
};

class academics : public student {
public:
    int* internal;
    int* external;
    string *code;
    int* total;
    float percentage;

    void accept(int n) override {
        student::accept(n);
        internal = new int[n];
        external = new int[n];
        total = new int[n];
        code=new string[n];

        for (int i = 0; i < n; i++) {
            cout<<"Enter code for "<<sub[i]<<": ";
            cin>>code[i];
            cout << "\nEnter internal marks for " << sub[i] << ": ";
            cin >> internal[i];
            cout << "Enter external marks for " << sub[i] << ": ";
            cin >> external[i];
            total[i] = internal[i] + external[i];
        }

        int grandTotal = 0, maxMarks = 200 * n;
        for (int i = 0; i < n; i++) {
            grandTotal += total[i];
        }
        percentage = (static_cast<float>(grandTotal) / maxMarks) * 100;
    }

    void display(int n) override {
        cout << left << setw(10) << "Roll No" << setw(15) << "Name" << setw(15) << "Subject"
             << setw(15) << "subcode"<<setw(15)<<"Internal" << setw(15) << "External" << setw(10) << "Total" << setw(15) << "Percentage" << endl;

        for (int i = 0; i < n; i++) {
            if (i == 0) { // Display roll and name only for the first subject
                cout << left << setw(10) << roll << setw(15) << name;
            } else {
                cout << left << setw(10) << " " << setw(15) << " ";
            }
            cout << setw(15) << sub[i]<<setw(15)<<code[i]
                 << setw(15) << internal[i] << setw(15) << external[i] << setw(10) << total[i];
            if (i == 0)  // Display percentage only for the first row of each student
                cout << setw(15) << fixed << setprecision(2) << percentage;
            cout << "\n";
        }
    }

  
};

int main() {
    int n, ch, roll_to_delete, roll_to_edit, roll_to_search;
    academics* records[100];
    int record_count = 0;

    cout << "\nEnter the number of subjects: ";
    cin >> n;

    do {
        cout << "\nMenu:\n1) Build a master table\n2) List a table\n3) Insert a new entry"
             << "\n4) Delete old entry\n5) Edit an entry\n6) Search for a record\n7) Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                records[record_count] = new academics();
                records[record_count]->accept(n);
                record_count++;
                break;
            }
            case 2: {
                cout << "\nMaster Table:\n";
                for (int i = 0; i < record_count; i++) {
                    records[i]->display(n);
                }
                break;
            }
            case 3: {
                records[record_count] = new academics();
                records[record_count]->accept(n);
                record_count++;
                break;
            }
            case 4: {
                cout << "\nEnter roll number to delete: ";
                cin >> roll_to_delete;
                bool found = false;
                for (int i = 0; i < record_count; i++) {
                    if (records[i]->roll == roll_to_delete) {
                        delete records[i];
                        for (int j = i; j < record_count - 1; j++) {
                            records[j] = records[j + 1];
                        }
                        record_count--;
                        found = true;
                        cout << "\nRecord deleted successfully.\n";
                        break;
                    }
                }
                if (!found) cout << "\nRecord not found.\n";
                break;
            }
            case 5: {
                cout << "\nEnter roll number to edit: ";
                cin >> roll_to_edit;
                bool found = false;
                for (int i = 0; i < record_count; i++) {
                    if (records[i]->roll == roll_to_edit) {
                        cout << "\nEnter new details:\n";
                        records[i]->accept(n);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\nRecord not found.\n";
                break;
            }
            case 6: {
                cout << "\nEnter roll number to search: ";
                cin >> roll_to_search;
                bool found = false;
                for (int i = 0; i < record_count; i++) {
                    if (records[i]->roll == roll_to_search) {
                        cout << "\nRecord found:\n";
                        records[i]->display(n);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\nRecord not found.\n";
                break;
            }
            case 7:
                cout << "\nExiting...\n";
                for (int i = 0; i < record_count; i++) {
                    delete records[i];
                }
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (ch != 7);

    return 0;
}
