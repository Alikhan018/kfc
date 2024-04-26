#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Start
{
public:
    Start()
    {
        for (int i = 0; i < 11; i++)
            cout << " ";
        for (int i = 0; i < 20; i++)
            cout << "*";
        cout << endl;
        for (int i = 0; i < 8; i++)
            cout << " ";
        cout << "ASSESSMENT MANAGEMENT SYSTEM\n";
        for (int i = 0; i < 11; i++)
            cout << " ";
        for (int i = 0; i < 20; i++)
            cout << "*";
        cout << endl;
    }
};
class Course
{
    string name;

public:
    Course() {}
    void setCourseName(string c)
    {
        name = c;
    }
    string getCourseName()
    {
        return name;
    }
};
class User
{
protected:
    string name;
    string Username;
    string Password;
    string type;
    Course cr;

public:
    User() {}
    void setName(string n)
    {
        name = n;
    }
    void setUsername(string n)
    {
        Username = n;
    }
    void setPassword(string n)
    {
        Password = n;
    }
    void setAll(string x, string y, string z)
    {
        name = x;
        Username = y;
        Password = z;
    }
    string getName()
    {
        return name;
    }
    string getUsername()
    {
        return Username;
    }
    string getPassword()
    {
        return Password;
    }
    virtual void display()
    {
        cout << "UserName : " << Username;
    }
    virtual void setCourse(string x)
    {
        cr.setCourseName(x);
    }
    virtual string getCourse()
    {
        return cr.getCourseName();
    }
    virtual string getType() = 0;
};
class Student : public User
{
    int courseNumber;
    Course course[3];
    string type;

public:
    Student() : User()
    {
        courseNumber = 3;
        course[0].setCourseName("OOP");
        course[1].setCourseName("SE");
        course[2].setCourseName("Marketing");
        type = "Student";
    }
    void display()
    {
        User::display();
        cout << "Courses taken by the student are:\n";
        int i = 0;
        while (i < courseNumber)
        {
            cout << course[i].getCourseName() << endl;
            i++;
        }
    }
    string getType()
    {
        return type;
    }
};
class Teacher : public User
{
private:
    string type;

public:
    Teacher() : User()
    {
        type = "Teacher";
    }
    void setCourse(string x)
    {
        cr.setCourseName(x);
    }
    void display()
    {
        User::display();
        cout << "Subject: " << cr.getCourseName() << endl;
    }
    string getType()
    {
        return type;
    }
};
class LoginTwo
{
public:
    LoginTwo() {}

    User *loginStudent()
    {
        try
        {
            cin.ignore();
            cout << "Enter username\n";
            string a;
            getline(cin, a);
            cout << "Enter Password\n";
            string b;
            getline(cin, b);
            string str;
            ifstream in("data.txt");
            if (!in)
            {
                throw "err";
            }
            in >> str;
            while (!(in.eof()))
            {
                if (str == "Teachers")
                {
                    break;
                }
                string username, password;
                in >> username >> password;
                if (a == username && b == password)
                {
                    cout << "Logged In as Student\n";
                    User *nu = new Student();
                    nu->setName(username);
                    nu->setUsername(username);
                    nu->setPassword(password);
                    return nu;
                }
            }
            throw 0;
        }
        catch (int throwedValue)
        {
            cout << "Wrong credentials\n";
            return NULL;
        }
        catch (const char *x)
        {
            cout << x;
            return NULL;
        }

        return NULL;
    }

    User *loginTeacher()
    {
        try
        {
            cin.ignore();
            cout << "Enter username\n";
            string a;
            getline(cin, a);
            cout << "Enter Password\n";
            string b;
            getline(cin, b);
            string str;
            ifstream in("data.txt");
            if (!in)
            {
                throw "err";
            }
            while (in >> str)
            {
                if (str == "Students")
                {
                    while (in >> str && str != "Teachers")
                    {
                    }
                }
                string username, password;
                in >> username >> password;
                if (a == username && b == password)
                {
                    cout << "Logged In as Teacher\n";
                    User *nu = new Teacher();
                    nu->setName(username);
                    nu->setUsername(username);
                    nu->setPassword(password);
                    return nu;
                }
            }
            throw 0;
        }
        catch (int throwedValue)
        {
            cout << "Wrong credentials\n";
            return NULL;
        }
        catch (const char *x)
        {
            cout << x;
            return NULL;
        }
        return NULL;
    }
};

class LoginOne
{
public:
    LoginOne() {}

    User *loginMenu()
    {
        User *u = NULL;
        while (true)
        {
            cout << "Please select an option\n1. Teacher\n2. Student\n";
            string choiceStr;
            cin >> choiceStr;
            if (choiceStr == "1")
            {
                LoginTwo lt;
                u = lt.loginTeacher();
                return u;
                break;
            }
            else if (choiceStr == "2")
            {
                LoginTwo lt;
                u = lt.loginStudent();
                return u;
                break;
            }
            else
            {
                cout << "Invalid option selected\n";
            }
        }
        return u;
    }
};

class Assessment : public Course
{
protected:
    string Task;
    string startDate;
    string endDate;

public:
    Assessment()
    {
        Task = "NULL";
        startDate = "";
        endDate = "";
    }
    virtual void setTask(string a, string b) = 0;
    virtual string getTask() = 0;
    virtual void setDates(string s, string e) = 0;
    virtual string getStartDate() = 0;
    virtual string getEndDate() = 0;
};
class Assignment : public Assessment
{
public:
    void setTask(string a, string b)
    {
        ofstream assignment("assign.txt", ios::app);
        assignment << b<< " Subject \n";
        assignment << a << endl;
        assignment.close();
    }
    string getTask()
    {
        string text = "";
        string str = "";
        ifstream assign("assign.txt");
        while (assign >> str)
        {
            text += str;
        }
        return text;
    }
    void setDates(string s, string e)
    {
        startDate = s;
        endDate = e;
    }
    string getStartDate()
    {
        return startDate;
    }
    string getEndDate()
    {
        return endDate;
    }
};
class Quiz : public Assessment
{
public:
    void setTask(string a, string b)
    {
        ofstream assignment("Quiz.txt", ios::app);
        assignment << b << " Subject\n";
        assignment << a;
        assignment.close();
    }
    string getTask()
    {
        string text = "";
        string str = "";
        ifstream assign("Quiz.txt");
        while (assign >> str)
        {
            text += str;
        }
        return text;
    }
    void setDates(string s, string e)
    {
        startDate = s;
        endDate = e;
    }
    string getStartDate()
    {
        return startDate;
    }
    string getEndDate()
    {
        return endDate;
    }
};
class Project : public Assessment
{
public:
    void setTask(string a, string b)
    {
        ofstream assignment("proj.txt", ios::app);
        assignment << b << " Subject\n";
        assignment << a;
        assignment.close();
    }
    string getTask()
    {
        string text = "";
        string str = "";
        ifstream assign("proj.txt");
        while (assign >> str)
        {
            text += str;
        }
        return text;
    }
    void setDates(string s, string e)
    {
        startDate = s;
        endDate = e;
    }
    string getStartDate()
    {
        return startDate;
    }
    string getEndDate()
    {
        return endDate;
    }
};
class StudentDashboard
{
    int choice;

public:
    void displayDashboard(Assessment** a, User* u)
    {
        while (true)
        {
            cout << "\nSTUDENT DASHBOARD\n"
                 << "1.VIEW ASSIGNMENT\n"
                 << "2.UPLOAD ASSIGNMENT\n"
                 << "3.VIEW QUIZ\n"
                 << "4.ATTEMPT QUIZ\n"
                 << "5.VIEW PROJECT\n"
                 << "6.SUBMIT PROJECT\n"
                 << "7.VIEW GRADES\n"
                 << "8.PERSONAL DETAILS\n"
                 << "9.QUIT\n";
            if (a[0]->getTask() == "NULL" && a[1]->getTask() == "NULL" && a[2]->getTask() == "NULL")
            {
                cout << "\nNo assessments available.\n";
            }
            cin >> choice;
            if (choice == 1)
            {
                viewAssignment(a);
            }
            else if (choice == 2)
            {
                uploadAssignment();
            }
            else if (choice == 3)
            {
                viewQuiz(a);
            }
            else if (choice == 4)
            {
                attemptQuiz(a);
            }
            else if (choice == 5)
            {
                viewProject(a);
            }
            else if (choice == 6)
            {
                uploadProject();
            }
            else if (choice == 7)
            {
                viewGrades();
            }
            else if (choice == 8)
            {
                u->display();
            }
            else if (choice == 9)
            {
                return;
            }
            else
            {
                cout << "Invalid option selected\n";
            }
        }
    }
    void viewAssignment(Assessment **a)
    {
        cout << "Assignment On: " << a[0]->getTask() << endl;
        cout << "StartDate: " << a[0]->getStartDate() << endl;
        cout << "EndDate: " << a[0]->getEndDate() << endl;
    }
    void uploadAssignment()
    {
        cout << "Enter name of assignment file with extension you want to upload(txt file should be named after your roll no otherwise assignment will not be checked): ";
        string filename;
        cin >> filename;
        ofstream file(filename);
        if (file)
        {
            cout << "File uploaded\n";
            file.close();
        }
        else
        {
            cout << "Cannot upload file\n";
        }
    }
    void viewQuiz(Assessment **a)
    {
        cout << "Quiz On : " << a[1]->getTask() << endl;
        cout << "StartDate: " << a[1]->getStartDate() << endl;
        cout << "EndDate: " << a[1]->getEndDate() << endl;
    }
    void attemptQuiz(Assessment **a)
    {
        viewQuiz(a);
        string x;
        cout << "Enter your answer to quiz\n";
        cin >> x;
        ofstream quiz("test.txt");
        quiz << x;
        quiz.close();
    }
    void viewProject(Assessment **a)
    {
        cout << "Project On : " << a[2]->getTask();
        cout << "StartDate: " << a[2]->getStartDate() << endl;
        cout << "EndDate: " << a[2]->getEndDate() << endl;
    }
    void uploadProject()
    {
        cout << "Enter name of project file with extension you want to upload: ";
        string filename;
        cin >> filename;
        ofstream file(filename);
        if (file)
        {
            cout << "File uploaded\n";
            file.close();
        }
        else
        {
            cout << "Cannot upload file\n";
        }
    }
    void viewGrades()
    {
        ifstream in("Grade.txt");
        string str;
        while (in >> str)
        {
            cout << str << "\n";
        }
    }
};
class TeacherDashboard
{
public:
    TeacherDashboard() {}
    void displayDashboard(Assessment **a, string sub)
    {
        cout << "\tWelcome To Teacher DashBoard \n";
        int choice = 0;
        cin.ignore();
        while (true)
        {
            cout << "1.UPLOAD ASSIGNMENT\n"
                 << "2.UPLOAD QUIZ\n"
                 << "3.UPLOAD PROJECT\n"
                 << "4.CHECK ASSIGNMENT\n"
                 << "5.CHECK QUIZ\n"
                 << "6.CHECK PROJECT\n"
                 << "7.MARK FINAL GRADES OF STUDENTS\n"
                 << "8.Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                uploadAssignment(a, sub);
            }
            else if (choice == 2)
            {
                uploadQuiz(a, sub);
            }
            else if (choice == 3)
            {
                uploadProject(a, sub);
            }
            else if (choice == 4)
            {
                checkAssignment(a);
            }
            else if (choice == 5)
            {
                checkQuiz(a);
            }
            else if (choice == 6)
            {
                checkProject(a);
            }
            else if (choice == 7)
            {
                grades(sub);
            }
            else if (choice == 8)
            {
                cout << "Exited\n";
                break;
            }
            else
            {
                cout << "Invalid Option\n";
            }
        }
    }
    void uploadAssignment(Assessment **a, string sub)
    {
        cout << "Enter task of assignment you want to upload (" << sub << "): \n";
        string task = "";
        cin.ignore();
        getline(cin, task);
        a[0]->setTask(task, sub);
        string n, b;
        cout << "Enter start date:\n";
        cin >> n;
        cout << "Enter end date:\n";
        cin >> b;
        a[0]->setDates(n, b);
    }
    void uploadQuiz(Assessment **a, string sub)
    {
        cout << "Enter Questions of quiz you want to upload(" << sub << "): \n";
        string task;
        cin.ignore();
        getline(cin, task);
        a[1]->setTask(task, sub);
        cout << "Enter start date:\n";
        string n, b;
        cin >> n;
        cout << "Enter end date:\n";
        cin >> b;
        a[1]->setDates(n, b);
    }
    void uploadProject(Assessment **a, string sub)
    {
        cout << "Enter Project you want to upload(" << sub << "): \n";
        string task;
        cin.ignore();
        getline(cin, task);
        a[2]->setTask(task, sub);
        cout << "Enter start date:\n";
        string n, b;
        cin >> n;
        cout << "Enter end date:\n";
        cin >> b;
        a[2]->setDates(n, b);
    }
    void checkAssignment(Assessment **a)
    {
        cout << a[0]->getTask() << endl;
        string str;
        cout << "Enter .txt with the roll no of which you want to check assignment of:\n";
        cin >> str;
        ifstream check(str);
        if (!check)
        {
            cout << "File not found.";
        }
        while (check >> str)
        {
            cout << str << " ";
        }
        cout << endl;
        cout << "How many marks would you like to give on this assignment\n";
        ofstream marks("marksheet.txt", ios::app);
        cin >> str;
        marks << str;
        cout << " Enter name of student as well";
        cin >> str;
        marks << str << endl;
        marks.close();
    }
    void checkQuiz(Assessment **a)
    {
        cout << a[1]->getTask() << endl;
        string str;
        cout << "Enter .txt with the roll no of which you want to check Quiz of:\n";
        cin >> str;
        ifstream check(str);
        if (!check)
        {
            cout << "File not found.";
        }
        while (check >> str)
        {
            cout << str << " ";
        }
        cout << endl;
        cout << "How many marks would you like to give on this quiz\n";
        ofstream marks("marksheetQuiz.txt", ios::app);
        cin >> str;
        marks << str;
        cout << " Enter name of student as well";
        cin >> str;
        marks << str << endl;
        marks.close();
    }
    void checkProject(Assessment **a)
    {
        cout << a[2]->getTask() << endl;
        string str;
        cout << "Enter .txt with the roll no of which you want to check project of:\n";
        cin >> str;
        ifstream check(str);
        if (!check)
        {
            cout << "File not found.";
        }
        while (check >> str)
        {
            cout << str << " ";
        }
        cout << endl;
        cout << "How many marks would you like to give on this project\n";
        ofstream marks("marksheetProj.txt", ios::app);
        cin >> str;
        marks << str;
        cout << " Enter name of student as well";
        cin >> str;
        marks << str << endl;
        marks.close();
    }
    void grades(string sub)
    {
        ofstream of("Grade.txt");
        string input;
        cout << "Enter grades and names of current 5 students(" << sub << "): \n";
        int i = 1;
        of << sub << " Subject\n";
        while (i < 6)
        {
            getline(cin, input);
            of << input << endl;
            i++;
        }
        of.close();
    }
};
int main()
{
    Start s;
    do
    {
        LoginOne l;
        User *user = NULL;
        user = l.loginMenu();
        if (user == NULL)
        {
            return 0;
        }
        Assessment *a[3];
        Assignment asn;
        Quiz quz;
        Project proj;
        a[0] = &asn;
        a[1] = &quz;
        a[2] = &proj;
        if (user->getType() == "Student")
        {
            StudentDashboard sdb;
            sdb.displayDashboard(a, user);
        }
        else if (user->getType() == "Teacher")
        {
            cout << "Enter your subject:\n";
            string sub;
            cin >> sub;
            user->setCourse(sub);
            TeacherDashboard tdb;
            tdb.displayDashboard(a, sub);
        }
        else
        {
            cout << "Cannot Login\n";
        }
        cout << "Do you want to do another login(y/n)?\n";
        char ch;
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
        {
            cout << "\nAssessment Management Closed\n";
            break;
        }
    } while (true);
    return 0;
}