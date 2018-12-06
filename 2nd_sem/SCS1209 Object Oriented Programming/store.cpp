#include <bits/stdc++.h>
using namespace std;

class student
{
    int mark;
    int stdID;
    string grade;

  public:
    void setmark(int mark)
    {
        this->mark = mark;
    }

    void setStuID(int ID)
    {
        this->stdID = ID;
    }

    void setGrade(string grade)
    {
        this->grade = grade;
    }

    int getStuID() {
        return stdID;
    }

    string getGrade(){
        return grade;
    }

    int getmark(){
        return mark;
    }
};

class subject
{
    private:
        int n;
        string subCode;
        student *std;

    public:
        subject()
        {
            std = new student[100];
        }

        void setsubcode(string code)
        {
            this->subCode = code;
        }

        void setNumOfStudent(int n)
        {
            this->n = n;
        }

        string getSubCode(){
            return subCode;
        }

        int getNumOfStudents(){
            return n;
        }

        student *getStudents()
        {
            return std;
        }

        void displaySubjects(){
            for(size_t i = 0; i < n; i++)
            {
                cout << std[i].getStuID() << ' ';
                cout << std[i].getmark() << ' ';
                cout << std[i].getGrade() << endl;
            }  
        }

};

class storeSubject
{
    private:
        int countOfSub;
        subject *sub;

    public:
        storeSubject()
        {
            sub = new subject[10];
        }

        void setCount(int c){
            this -> countOfSub = ++c;
        }

        subject *getSubject()
        {
            return sub;
        }

        void displayStudents(int code)
        {
            for(size_t i = 0; i < countOfSub; i++)
            {       
                for(size_t j = 0; j < sub[i].getNumOfStudents(); j++)
                {
                    if(sub[i].getStudents()[j].getStuID() == code)
                    {
                        cout << sub[i].getSubCode() << ' ';
                        cout << sub[i].getStudents()[j].getmark() << ' ';
                        cout << sub[i].getStudents()[j].getGrade() << endl; 
                        j = sub[i].getNumOfStudents();
                    }
                }      
            }
        }
};

string getgrade(int mark)
{
    if (0 <= mark <= 100)
    {
        if (mark < 30)
            return "F";
        else if (mark < 40)
            return "D";
        else if (mark < 55)
            return "C";
        else if (mark < 70)
            return "B";
        else
            return "A";
    }
}

int main()
{    
    storeSubject sub = storeSubject();
    int m = 0;
    ifstream file;
    file.open("subject.txt");
    while (!file.eof())
    {
        int num;
        string name;

        file >> name >> num;

        sub.getSubject()[m].setsubcode(name);
        sub.getSubject()[m].setNumOfStudent(num);

        for(size_t i = 0; i < num; i++)
        {    
            int student, mark;
            file >> student >> mark;
            sub.getSubject()[m].getStudents()[i].setStuID(student);
            sub.getSubject()[m].getStudents()[i].setmark(mark);
            sub.getSubject()[m].getStudents()[i].setGrade(getgrade(mark));
        }
        m++;
    }

    sub.setCount(m);

    // int code = 17000001;
    // sub.displayStudents(code);
    
    // sub.getSubject()[0].displaySubjects();
    
}