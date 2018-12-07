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
        int markCount;
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
            this->markCount = n;
        }

        string getSubCode(){
            return subCode;
        }

        int getNumOfStudents(){
            return markCount;
        }

        student *getStudents()
        {
            return std;
        }

        int countGrade(string grade){
            int count = 0;
            for(size_t i = 0; i < markCount; i++)
            {
                if (std[i].getGrade() == grade) count++;    
            }
            
            return count;
        }

        double precentageOfGrade(string grade){

            return countGrade(grade) * 100.0 / markCount;
        }

        double getMean(){
            int sum = 0;
            for(size_t i = 0; i < markCount; i++)
            {
                sum += std[i].getmark();
            }
            
            return sum / markCount;
        }

        double getStandardDiviation(){
            double temp = 0;
            for(size_t i = 0; i < markCount; i++)
            {
                temp += pow((std[i].getmark() - getMean()),2);
            }
            
            return pow((temp/markCount),0.5);
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
            this -> countOfSub = c;
        }

        subject *getSubject()
        {
            return sub;
        }

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

        void displayStudents(int code)
        {
            bool isTrue = true;

            cout << "_____________________________\n" << endl;
            cout << "********|" << code << "|**********" << endl;
            cout << "_____________________________\n" << endl;

            for(size_t i = 0; i < countOfSub; i++)
            {       
                for(size_t j = 0; j < sub[i].getNumOfStudents(); j++)
                {
                    if(sub[i].getStudents()[j].getStuID() == code)
                    {
                        cout << "       ";                      
                        cout << sub[i].getSubCode() << ' ';
                        cout << sub[i].getStudents()[j].getmark() << ' ';
                        cout << sub[i].getStudents()[j].getGrade() << endl; 
                        j = sub[i].getNumOfStudents();
                        isTrue = false;
                    }
                }      
            }
            cout << "_____________________________\n" << endl;

            if (isTrue){
                cout << "_____________________________\n" << endl;
                cout << "Error.! Given ID not found.\n";
                cout << "_____________________________\n" << endl;
            } 
        }

        void displaySubjects(string subcode)
        {
            bool isTrue = true;
            for(size_t i = 0; i < countOfSub; i++)
            {
                if(sub[i].getSubCode() == subcode)
                {
                    cout << "_____________________________\n" << endl;
                    cout << "**********|" << subcode << "|**********" << endl;
                    cout << "_____________________________\n" << endl;

                    for(size_t j = 0; j < sub[i].getNumOfStudents(); j++)
                    {
                        cout << "       ";
                        cout << sub[i].getStudents()[j].getStuID() << ' ';
                        cout << sub[i].getStudents()[j].getmark() << ' ';
                        cout << sub[i].getStudents()[j].getGrade() << endl;
                    }

                    cout << "_____________________________\n" << endl;

                    isTrue = false;
                }
            }
            if (isTrue){
                cout << "_____________________________\n" << endl;
                cout << "Error.! Given code not found.\n";
                cout << "_____________________________\n" << endl;
            } 
        }

        void displaySubSummary(string subcode)
        {
            bool isTrue = true;
            for(size_t i = 0; i < countOfSub; i++)
            {
                if(sub[i].getSubCode() == subcode)
                {
                    cout << "_____________________________\n" << endl;
                    cout << "**********|" << subcode << "|**********" << endl;
                    cout << "_____________________________\n" << endl;

                    cout << "   Standard diviation : " << sub[i].getStandardDiviation() << endl;
                    cout << "   Average : " << sub[i].getMean() << endl;
                    cout << "   Num of A's : " << sub[i].countGrade("A") << endl;
                    cout << "   Num of B's : " << sub[i].countGrade("B") << endl;
                    cout << "   Num of C's : " << sub[i].countGrade("C") << endl;
                    cout << "   Num of D's : " << sub[i].countGrade("D") << endl;
                    cout << "   Num of E's : " << sub[i].countGrade("E") << endl;

                    cout << "_____________________________\n" << endl;

                    isTrue = false;
                }
            }
            if (isTrue){
                cout << "_____________________________\n" << endl;
                cout << "Error.! Given code not found.\n";
                cout << "_____________________________\n" << endl;
            } 
        }

        void saveSummary()
        {
            ofstream file("summdata.txt");
            for(size_t i = 0; i < countOfSub; i++)
            {
                file << sub[i].getSubCode() << ' ' << sub[i].getNumOfStudents() << ' ';
                file << "A" << ' ' << sub[i].precentageOfGrade("A") << "%" << ' ';
                file << "B" << ' ' << sub[i].precentageOfGrade("B") << "%" << ' ';
                file << "C" << ' ' << sub[i].precentageOfGrade("C") << "%" << ' ';
                file << "D" << ' ' << sub[i].precentageOfGrade("D") << "%" << ' ';
                file << "E" << ' ' << sub[i].precentageOfGrade("E") << "%" << ' ' << endl;
            }
            cout << "Create summary succesfuly.!\n";
            cout << "_____________________________\n" << endl;
        }

        void init(){
            int m = 0;
            ifstream file;
            file.open("subject.txt");
            while (!file.eof())
            {
                int num;
                string name;

                file >> name >> num;

                sub[m].setsubcode(name);
                sub[m].setNumOfStudent(num);

                for(size_t i = 0; i < num; i++)
                {    
                    int student, mark;
                    file >> student >> mark;
                    sub[m].getStudents()[i].setStuID(student);
                    sub[m].getStudents()[i].setmark(mark);
                    sub[m].getStudents()[i].setGrade(getgrade(mark));
                }
                m++;
            }
            setCount(m);
        }

        void menu()
        {
            cout << "\n+++++++++++|MENU|+++++++++++++" << endl;
            cout << "______________________________" << endl;
            cout << "|                            |" << endl;
            cout << "| 1. Display Subject         |" << endl;
            cout << "| 2. Display Student         |" << endl;
            cout << "| 3. Display Subject Summary |" << endl;
            cout << "| 4. Save Summaries          |" << endl;
            cout << "| 5. Exit Program            |" << endl;
            cout << "|                            |" << endl;
            cout << "++++++++++++++++++++++++++++++\n" << endl;

            cout << "Enter your choice : ";
        }
};

int main()
{    
    storeSubject sub = storeSubject();
    sub.init();
    
    bool isContinue = true;
    char any;
    char choice;
    string code;
    int ID;
    
    while (isContinue)
    {
        sub.menu();
        cin >> choice;
        cout << "_____________________________\n" << endl;

        switch(choice)
        {
            case '1':
                ;
                cout << "Enter Subject code : ";
                cin >> code;

                sub.displaySubjects(code);

                cout << "Press any key to continue.! ";
                cin >> any;
                break;

            case '2':
                ;
                cout << "Enter Student ID : ";
                cin >> ID;

                sub.displayStudents(ID);

                cout << "Press any key to continue.! ";
                cin >> any;
                break;

            case '3':
                ;
                cout << "Enter Subject code : ";
                cin >> code;

                sub.displaySubSummary(code);

                cout << "Press any key to continue.! ";
                cin >> any;
                break;

            case '4':
                ;
                sub.saveSummary();

                cout << "Press any key to continue.! ";
                cin >> any;
                break;

            case '5':
                ;
                cout << "exite programme succesfuly.!\n ";
                isContinue = false;
                break;

            default:
                ;
                cout << "Invalid input.!\n";
        }
    }   
}