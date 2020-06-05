#include<iostream>
#include<vector>
#include<algorithm>

struct student {
	std::string surname;
	std::string name;
	double mark;
};

void print(const std::vector<student>& vec)
    {
        for (size_t i = 0; i <vec.size(); ++i)
            std::cout << vec[i].surname << " " << vec[i].name << " " << vec[i].mark << std::endl;
        std::cout << std::endl;
    }

int main()
{
    
    std::vector<student> Vec =
    {
        {"Abashin","Vasya",1},
        {"Chistyakova","Alex",3},
        {"Kiseleva","Anna",2},
        {"Gorunova","Mary",4},
    };
    print(Vec);
    //1
    std::cout << 1<<std::endl;
    std::sort(Vec.begin(), Vec.end(), [](student st1, student st2) { return st1.mark > st2.mark; });
    print(Vec);
    //2 - add new student
    std::cout << 2 << std::endl;
    student st;
    std::cout << "Enter surname: " << std::endl; std::cin >> st.surname;
    std::cout << "Enter name: " << std::endl; std::cin >> st.name;
    std::cout << "Enter mark: " << std::endl; std::cin >> st.mark;
    Vec.push_back(st);
    print(Vec);
    //3
    std::cout << 3 << std::endl;
    std::vector<student> new_Vec;
    std::copy_if(Vec.begin(), Vec.end(), back_inserter(new_Vec), [](student st) {return st.name[0]== 'A'; });
    print(new_Vec);
    //4 - seek max surname
    std::cout << 4 << std::endl;
    std::sort(new_Vec.begin(), new_Vec.end(), [](student st1, student st2){return ((st1.surname).size()>(st2.surname).size());});
    std::cout << new_Vec[0].surname << " " << new_Vec[0].name << " " << new_Vec[0].mark << std::endl;

}