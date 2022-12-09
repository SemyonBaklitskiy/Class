#include <iostream>
#include <vector>

class student {
private:
    std::string name;
    int age;
    double averageMark;

public:
    student() {
        name = "No name";
        age = 0;
        averageMark = 0;
    }

    student(const std::string name, const int age, const double averageMark) {
        this -> name = name;
        this -> age = age;
        this -> averageMark = averageMark;

        std::cout << "Student " << this -> name << " was created!" << std::endl; 
    }

    ~student() {
        std::cout << "Student " << name << " was destructed!" << std::endl;   
    }

    int get_age() {
        return age;
    }

    std::string get_name() {
        return name;
    }

    double get_average_mark() {
        return averageMark;
    }

    void set_name(const std::string name) {
        this->name = name;
    }

    void set_age(const int age) {
        if (this -> age <= 50)
            this -> age = age;
    }


    void set_average_mark(const double averageMark) {
        if (averageMark <= 10)
            this -> averageMark = averageMark;
    }

    void to_learn(const std::string subject) {
        std::cout << "Student " << name << " is learning " << subject << std::endl;
        if (averageMark + 1 <= 10) {
            averageMark += 1;

        } else {
            averageMark = 10;
        }
    }
};

double average_mark(std::vector<student> students);

int main() {
    student semyon("Semyon", 19, 7.5);
    student vitek("Vitya", 19, 0.5);
    student boss("Danya", 19, 9.99);
    student danya("Danya Kalinin", 20, 7.0);
    student masha("Masha", 19, 5.0);

    std::vector<student> students = { semyon, vitek, boss, danya, masha };

    std::cout << "Average mark before learning: " << average_mark(students) << std::endl;
    for (int i = 0; i < 3; ++i) {
        semyon.to_learn("Physics");
        vitek.to_learn("All");
        boss.to_learn("Nothing");
        danya.to_learn("Math");
        masha.to_learn("Informatics");
    }

    students = { semyon, vitek, boss, danya, masha };
    std::cout << "Average mark after learning: " << average_mark(students) << std::endl;
}

double average_mark(std::vector<student> students) {
    const int size = students.size();
    double summ = 0.0;

    for (int studentIndex = 0; studentIndex < size; ++studentIndex) 
        summ += students[studentIndex].get_average_mark();
    
    return summ / size;
}