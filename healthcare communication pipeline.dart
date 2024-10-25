// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract HealthcareCommunication {
    // Structure to store patient data
    struct Patient {
        string name;
        uint age;
        string medicalHistory;
        address doctor;
        bool exists;
    }

    // Mapping to store patient information
    mapping(address => Patient) private patients;

    // Events to log activities
    event PatientAdded(address patientAddress, string name, uint age, string medicalHistory, address doctor);
    event MedicalHistoryUpdated(address patientAddress, string medicalHistory);

    // Function to add a new patient
    function addPatient(address _patientAddress, string memory _name, uint _age, string memory _medicalHistory, address _doctor) public {
        require(!patients[_patientAddress].exists, "Patient already exists");
        patients[_patientAddress] = Patient(_name, _age, _medicalHistory, _doctor, true);
        emit PatientAdded(_patientAddress, _name, _age, _medicalHistory, _doctor);
    }

    // Function to update medical history
    function updateMedicalHistory(address _patientAddress, string memory _medicalHistory) public {
        require(patients[_patientAddress].exists, "Patient does not exist");
        require(msg.sender == patients[_patientAddress].doctor, "Only the assigned doctor can update medical history");
        patients[_patientAddress].medicalHistory = _medicalHistory;
        emit MedicalHistoryUpdated(_patientAddress, _medicalHistory);
    }

    // Function to retrieve patient details
    function getPatientDetails(address _patientAddress) public view returns (string memory, uint, string memory, address) {
        require(patients[_patientAddress].exists, "Patient does not exist");
        Patient memory patient = patients[_patientAddress];
        return (patient.name, patient.age, patient.medicalHistory, patient.doctor);
    }
}
