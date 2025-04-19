#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Doctor;
class BillingStaff;
class PatientRecord {
private:
    string name;
    string id;
    string dob;
    vector<string> medicalHistory;
    vector<string> currentTreatments;
    vector<string> billingDetails;

    void addMedicalEntry(const string& entry) {
        medicalHistory.push_back(entry);
    }

    void addTreatment(const string& treatment) {
        currentTreatments.push_back(treatment);
    }

    void addBillingEntry(const string& entry) {
        billingDetails.push_back(entry);
    }

public:
    PatientRecord(const string& n, const string& i, const string& d) 
        : name(n), id(i), dob(d) {}

    string getPublicInfo() const {
        return "Name: " + name + "\nID: " + id + "\nDOB: " + dob;
    }

    string getMedicalInfo() const {
        string info = "Medical History:\n";
        for (const auto& entry : medicalHistory) {
            info += "- " + entry + "\n";
        }
        info += "Current Treatments:\n";
        for (const auto& treatment : currentTreatments) {
            info += "- " + treatment + "\n";
        }
        return info;
    }

    string getBillingInfo() const {
        string info = "Billing Details:\n";
        for (const auto& entry : billingDetails) {
            info += "- " + entry + "\n";
        }
        return info;
    }

    friend class Doctor;
    friend class BillingStaff;
};

class Doctor {
private:
    string name;
public:
    Doctor(const string& n) : name(n) {}

    void recordDiagnosis(PatientRecord& record, const string& diagnosis) {
        record.addMedicalEntry("Diagnosis by Dr. " + name + ": " + diagnosis);
    }

    void prescribeTreatment(PatientRecord& record, const string& treatment) {
        record.addTreatment("Prescribed by Dr. " + name + ": " + treatment);
    }

    string viewMedicalRecord(const PatientRecord& record) {
        return record.getMedicalInfo();
    }
};

class BillingStaff {
private:
    string name;
public:
    BillingStaff(const string& n) : name(n) {}

    void addCharge(PatientRecord& record, const string& service, double amount) {
        record.addBillingEntry(service + ": $" + to_string(amount) + " (added by " + name + ")");
    }

    string viewBillingRecord(const PatientRecord& record) {
        return record.getBillingInfo();
    }
};

class Receptionist {
public:
    string viewPatientInfo(const PatientRecord& record) {
        return record.getPublicInfo();
    }
};

int main() {
    PatientRecord patient("Smith", "P10001", "2022-06-11");
    Doctor drJones("Jones");
    BillingStaff billMiller("Miller");
    Receptionist receptionist;
    drJones.recordDiagnosis(patient, "Sour throat");
    drJones.prescribeTreatment(patient, "Arinac 10mg daily");
    cout << "Doctor viewing medical record:" << endl;
    cout << drJones.viewMedicalRecord(patient);
    billMiller.addCharge(patient, "Consultation", 140.00);
    billMiller.addCharge(patient, "Blood Test", 90.50);
    cout << "Billing staff viewing billing record:" << endl;
    cout << billMiller.viewBillingRecord(patient);
    cout << "Receptionist viewing patient info:" << endl;
    cout << receptionist.viewPatientInfo(patient);

    return 0;
}