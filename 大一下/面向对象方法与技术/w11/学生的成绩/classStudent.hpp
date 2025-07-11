//
//  classStudent.hpp
//  学生的成绩
//
//  Created by 杨博文 on 2024/5/10.
//

#ifndef classStudent_hpp
#define classStudent_hpp

#include <iostream>
#include <fstream>

class student
{
private:
    std::string _name;
    int _id;
    float _scoreLanguage;
    float _scoreMath;
    float _scoreEnglish;
public:
    friend std::ostream& operator<<(std::ostream& o,const student& s);
    friend std::istream& operator>>(std::istream& i,student& s);
    bool operator>(const student& s) const;
    bool operator==(const student& s) const;
    bool operator<(const student& s) const;
};

#endif /* classStudent_hpp */
