#include <iostream>
#include <vector>
#include <algorithm>

class Student {
public:
    std::string name;
    std::string surname;
    std::string dateOfBirth;
    std::string phoneNumber;

    Student(std::string name, std::string surname, std::string dateOfBirth, std::string phoneNumber) {
        this->name = name;
        this->surname = surname;
        this->dateOfBirth = dateOfBirth;
        this->phoneNumber = phoneNumber;
    }

    bool operator==(const Student& other) const {
        return name == other.name && surname == other.surname && dateOfBirth == other.dateOfBirth && phoneNumber == other.phoneNumber;
    }
};

class StudentGroup {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void removeStudent(const Student& student) {
        students.erase(std::remove(students.begin(), students.end(), student), students.end());
    }

    std::vector<Student> searchBySurname(const std::string& surname) {
        std::vector<Student> result;
        for (const auto& student : students) {
            if (student.surname == surname) {
                result.push_back(student);
            }
        }
        return result;
    }

    std::vector<Student> searchByDateOfBirth(const std::string& dateOfBirth) {
        std::vector<Student> result;
        for (const auto& student : students) {
            if (student.dateOfBirth == dateOfBirth) {
                result.push_back(student);
            }
        }
        return result;
    }

    std::vector<Student> searchByPhoneNumber(const std::string& phoneNumber) {
        std::vector<Student> result;
        for (const auto& student : students) {
            if (student.phoneNumber == phoneNumber) {
                result.push_back(student);
            }
        }
        return result;
    }

    void sortBySurname() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.surname < b.surname;
            });
    }

    void sortByDateOfBirth() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.dateOfBirth < b.dateOfBirth;
            });
    }

    void sortByPhoneNumber() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.phoneNumber < b.phoneNumber;
            });
    }

    void printStudents() {
        for (const auto& student : students) {
            std::cout << "Имя: " << student.name << ", Фамилия: " << student.surname << ", Дата рождения: " << student.dateOfBirth << ", Номер телефона: " << student.phoneNumber << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    StudentGroup group;

    // Добавление студентов
    group.addStudent(Student("Глеб", "Мохов", "2005-01-01", "1234567890"));                                   
    group.addStudent(Student("Егор", "Ярошенко", "2006-02-02", "9876543210"));
    group.addStudent(Student("Скала", "Джонсон", "2006-03-03", "5555555555"));

    // Поиск студентов по фамилии
    std::vector<Student> studentsWithSurnameSmith = group.searchBySurname("Мохов");
    std::cout << "Студент с фамилией Мохов:" << std::endl;
    for (const auto& student : studentsWithSurnameSmith) {
        std::cout << "Имя: " << student.name << ", Фамилия : " << student.surname << ", Дата рождения : " << student.dateOfBirth << ", Номер телефона : " << student.phoneNumber << std::endl;
    }

    // Сортировка по дате рождения
    group.sortByDateOfBirth();
    std::cout << "Студенты отсортированные по дате рождения:" << std::endl;
    group.printStudents();

    std::cout << "Все студенты:" << std::endl;
    group.printStudents();

    // Удаление студента
    group.removeStudent(Student("Глеб", "Мохов", "2005-01-01", "1234567890"));

    
    std::cout << "Список без отчисленного судента :" << std::endl;
    group.printStudents();

    return 0;
}
