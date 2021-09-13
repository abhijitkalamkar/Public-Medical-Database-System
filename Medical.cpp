#include <iostream>

using namespace std;

struct MedicalRecords
{
    string bloodGroup, diagnosedDisease;
    int age;
    float height, weight;
};

class PatientParent
{
private:
    MedicalRecords ParentMediRec;
public:
    PatientParent();
    void setParentMedicalRecords();
    string getParentDiagnosedDisease();
};

PatientParent::PatientParent()
{
    ParentMediRec.age = 0;
    ParentMediRec.bloodGroup = "";
    ParentMediRec.diagnosedDisease = "";
}

void PatientParent::setParentMedicalRecords()
{
    cout << "Enter the following details of the family member: \n";
    cout << "Age: \t\t";
    cin >> ParentMediRec.age;
    cout << "Blood Group: \t";
    cin >> ParentMediRec.bloodGroup;
    cout << "Diagnosed Disease: \t";
    cin >> ParentMediRec.diagnosedDisease;
    cout << endl;
}

string PatientParent::getParentDiagnosedDisease()
{
    return ParentMediRec.diagnosedDisease;
}

//////////////////////////////////////////////////////

class Patient : public PatientParent
{
private:
    long patientId;
    string symptoms[10];
    MedicalRecords PatientMediRec;

public:
    Patient();
    void setPatientMedicalRecords();
    long getPatientId();
    void setSymptoms();
    void displayRecords();
};

Patient::Patient()
{
    patientId = 0;

    for (int i = 0; i < 10; i++)
        symptoms[i] = "";

    PatientMediRec.age = 0;
    PatientMediRec.bloodGroup = "";
    PatientMediRec.diagnosedDisease = "";
    PatientMediRec.height = 0.0;
    PatientMediRec.weight = 0.0;
}

bool checkIsY(string &c)  
{
    while (c != "n" && c != "N" && c != "y" && c != "Y")
    {
        cin >> c;
        if (c != "n" && c != "N" && c != "y" && c != "Y")
            cout << "Y or N, only: ";
    }
    if (c == "y" || c == "Y")
        return true;
    else
        return false;
}

void Patient::setPatientMedicalRecords()
{
    cout << endl;
    cout << "---------------------" << endl;
    cout << "| REGISTER YOURSELF |" << endl;
    cout << "---------------------" << endl;
    cout << endl;

    cout << "Patient Id (4 digit number): ";
    cin >> patientId;

    cout << "Age: \t\t";
    cin >> PatientMediRec.age;

    cout << "Blood Group: \t";
    cin >> PatientMediRec.bloodGroup;

    cout << "Height (cm): \t";
    cin >> PatientMediRec.height;

    cout << "Weight (kg): \t";
    cin >> PatientMediRec.weight;

    cout << endl;
    cout << "---------------------------" << endl;
    cout << "| REGISTERED SUCCESSFULLY |" << endl;
    cout << "---------------------------" << endl;
    cout << endl;
}

long Patient::getPatientId()
{
    return patientId;
}

void Patient::setSymptoms()
{
    string choice;
    int j = 0;
    do
    {
        cout << "\nEnter a symptom: \t\t";
        cin >> symptoms[j++];

        do
        {
            cout << "Add another symptom? (y/n): \t";
            cin >> choice;
        } while (choice != "n" && choice != "N" && choice != "y" && choice != "Y");

    } while (choice != "n" && choice != "N");
    cout << endl;
}

void Patient::displayRecords()
{
    cout << "--------------------" << endl;
    cout << "|       " << patientId << "       |" << endl;
    cout << "--------------------" << endl;
    cout << "Age: " << PatientMediRec.age << endl;
    cout << "Blood Group: " << PatientMediRec.bloodGroup << endl;
    cout << "Height: " << PatientMediRec.height << endl;
    cout << "Weight: " << PatientMediRec.weight << endl;
    cout << "SYMPTOMS: ";
    for(int i =0; i < 5; i++)
    {
        cout << symptoms[i] << " ";
    }
    cout << "\nRelatives's Disease: " << getParentDiagnosedDisease();
    cout << "\n---------------------" << endl;
    cout << endl;
}

int searchPatientId(long tempPatiemtId, int setCount, Patient *P)
{
    int flag = 0, z;
    cout << "Enter the Patient Id: ";
    cin >> tempPatiemtId;
    cout << endl;

    for (int i = 0; i < setCount; i++)
    {
        if (P[i].getPatientId() == tempPatiemtId)
        {
            flag = 1;
            z = i;
            break;
        }
    }

    if (flag == 0)
    {
        return -1;
    }
    else
    {
        return z;
    }
}

//////////////////////////////////////////////////////

int main()
{
    Patient P[10];
    PatientParent PP[10];

    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "| WELCOME TO THE PUBLIC MEDICAL DATABASE SYSTEM |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;

    int choice, setCount = 0;
    do
    {
        cout << "1. Register a patient\n";
        cout << "2. Add family medical history\n";
        cout << "3. Add current symptoms of the patient\n";
        cout << "4. Display patient records\n";
        cout << "5. Exit\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        long tempPatiemtId;
        int flag = 0, z;

        switch (choice)
        {
        case 1:
            P[setCount].setPatientMedicalRecords();
            setCount++;
            break;
        case 2:
            z = searchPatientId(tempPatiemtId, setCount, P);
            if (z == -1)
            {
                cout << "Record Not Found!\n\n";
            }
            else
            {
                P[z].setParentMedicalRecords();
            }

            break;
        case 3:
            z = searchPatientId(tempPatiemtId, setCount, P);
            if (z == -1)
            {
                cout << "Record Not Found!\n\n";
            }
            else
            {
                P[z].setSymptoms();
            }

            break;
        case 4:
            cout << "DISPLAYING RECORDS" << endl;
            for (int i = 0; i < setCount; i++)
            {
                P[i].displayRecords();
            }
            break;

        case 5:
            cout << "-----------------------------------------------" << endl;
            cout << "| THANK YOU FOR USING PUBLIC MEDICAL DATABASE |" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "| PROJECT BY ABHIJIT KALAMKAR AND SAURABH JOSHI AND ANIKET KAMBLE|" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << endl;
            break;
        default:
            cout << "------------------------------------------------" << endl;
            cout << "| Please enter the choice betweent 1 - 6 only! |" << endl;
            cout << "------------------------------------------------" << endl;
            cout << endl;
        }
    } while (choice != 5);

    return 0;
}
