#include<iostream>
#include<cstdlib>
#include<string>
#include <cctype>
#include <cstring>
#include<ctime>
using namespace std;
struct student{
    string id;
    string firstName;
    string lastName;
    int age;
    string sex;
    string course[6];
    student *next;
};
struct student *head=NULL;
struct course{
    string courseNo;
    string courseTitle;
    int crhr;
    course *next;
};
struct course *head2=NULL;

void displayCourse();
void enroll (string firstName, string lastName, int age, string sex){
    int choice;
    student *temp= new student;
    temp->firstName = firstName;
    temp->lastName = lastName;
    temp->age=age;
    temp->sex=sex;
    srand(time(0));
    temp->id=to_string(1000+(rand()%8999));
    course *temp2;
    int count2 = 0;
    cout << "Now you need to register for 6 courses"<<
            " please write the index of your chosen course "<<
            "one by one, you must choose 6 courses\n";
 while(count2<6){
    int count=0;
    displayCourse();
    cin>>choice;
    count2++;
temp2 = head2;
        while(temp2 != NULL){
            count++;
            if(choice == count){
                temp->course[count2-1]=temp2->courseNo;
                cout << "you have registered for the course with course number "<<
                temp->course[count2-1]<< endl;
                break;
             }
            else
                 temp2 = temp2->next;
        }
}
    cout<<"Your 4 digit id is: ";
    cout<<endl<<temp->id<<endl;
    temp->next = NULL;
// put the registered student in proper order....sort!
    if(head==NULL)
        head = temp;
    else if(head->next==NULL){
        if((head->firstName+head->lastName)>=(firstName+lastName)){
            temp->next = head;
            head = temp;
        }
        else{
            head->next=temp;
        }
    }
    else{
        student *current = head;
        student *prev;
        while(current!=NULL && (current->firstName+current->lastName)<(firstName+lastName)){
            prev = current;
            current = current->next;
        }
        if(current==head){
            temp->next = head;
            head = temp;
        }
        else if(current==NULL){
            prev->next=temp;
        }
        else{
           temp->next = current;
           prev->next = temp;
           }
     }
}
void addCourse(string courseNo,string courseTitle, int crhr){
    course *temp = new course;
    course *temp2= new course;
    temp->courseNo = courseNo;
    temp->courseTitle = courseTitle;
    temp->crhr = crhr;
    temp->next = NULL;
    if(head2 == NULL)
        head2 = temp;
    else{
        temp2 = head2;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
};
void grade(string no){
int grade;
string tmp;
student *temp = new student;
temp=head;
    int found;
    if(head == NULL)
        cout << "No student data\n";
    else{
    while(temp!=NULL){
        found=0;
        int count=0;
        while(count<6 && found!=1){
                if(temp->course[count]==no){
                    found=1;
                    break;
                }
                count++;
            }
        if(found == 1){
            cout<<temp->firstName<<" "<<temp->lastName
            <<"\nEnter grade: ";
            cin>>grade;
            tmp=to_string (grade); // ?
            temp->course[count]= temp->course[count]+" = "+ tmp;
        }
     temp=temp->next;
    }
    if(found==0)
        cout<<"\n no students registered for "<<no;
    }
};
void searchStu(string id){
student *temp= new student;
temp = head;
int count=0;
while(temp!=NULL && temp->id!=id){
        temp = temp->next;
    }
    if(temp == NULL)
        cout<< "\n Student not found\n";
    else{
    cout<<"First Name: "<< temp->firstName << endl
        <<"Last Name: "<< temp->lastName << endl
        <<"ID: "<< temp->id << endl
        <<"Age: "<< temp->age << endl;
        for(int i=0; i<6; i++){
                count++;
                cout << count<< ". "<< temp->course[i]<<endl;
            }
    }
};
void searchCourse(string no){
course *temp = new course;
temp = head2;
while(temp!=NULL && temp->courseNo!=no){
        temp = temp->next;
    }
    if(temp == NULL)
        cout<< "\nCourse not found\n";
    else{
        cout<<"Course Title: "<< temp->courseTitle << endl
            <<"Course Number: "<< temp->courseNo << endl
            <<"Credit Hour: "<< temp->crhr<< endl;
    }
};
void displayAll(){
    student *temp = new student;
    int count=0;
    if(head == NULL)
        cout << "No student data\n";
    else{
        temp = head;
        while(temp!=NULL){
            cout << "ID: "<<temp->id << endl;
            cout << "First name: "<<temp->firstName << endl;
            cout << "last name: "<<temp->lastName << endl;
            cout << "Age: "<<temp->age << endl;
            cout << "Sex: "<<temp->sex << endl;
            cout << "registered courses, and your grades: \n";
        for(int i=0; i<6; i++){
                count++;
                cout << count<< ". "<< temp->course[i]<<endl;
            }
            count=0;
            temp=temp->next;
       }
   }
};
void sortList(){
string studentList[100];
int count=0;
student *temp= new student;
temp = head;
    if(head==NULL)
        cout<<"\n empty list\n";
    else{
        cout<<"  Name\tID\n" ;
        while(temp!=NULL){
            studentList[count]=temp->firstName+" "
            +temp->lastName+" "+temp->id;
            count++;
            temp = temp->next;
        }
        for (int i=0; i<count; i++){
            cout<<i+1<<". "<<studentList[i]<<"\n";
        }
    }
   };
void displayCourse(){
    int count = 0;
    course *temp;
    if(head2 == NULL)
        cout << "No courses\n";
    else{
        temp = head2;
        while(temp != NULL){
            count++;
            cout << count<<"." << endl;
            cout << "course name: " << temp->courseTitle << endl;
            cout << "course NO: " << temp->courseNo << endl;
            cout << "credit hour: " << temp->crhr << endl;
            temp = temp->next;
        }
    }
};
void deleteStu(string id){
    student *temp, *temp3;
    if(head==NULL)
        cout <<"No data inside\n";
    if(head->id==id){
        temp = head;
        head = head->next;
        delete temp;
    }
    else{
        temp = head;
        while(temp!=NULL && temp->id!=id){
            temp3 = temp;
            temp = temp->next;
        }
    if(temp == NULL)
        cout<< "\nStudent not found\n";
    else{
        temp3->next = temp->next;
        delete temp;
    }
  }
};
void deleteCourse(string no){
    course *temp, *temp3;
    if(head2==NULL)
        cout <<"No data inside\n";
    if(head2->courseNo==no){
        temp = head2;
        head2 = head2->next;
        delete temp;
    }
    else{
        temp = head2;
        while(temp!=NULL && temp->courseNo!=no){
            temp3 = temp;
            temp = temp->next;
        }
    if(temp == NULL)
        cout<< "\nCourse not found\n";
    else
        temp3->next = temp->next;
    delete temp;
    }
};
bool password(string s){
    int count=0;
    while (s != "1234"&&count<3){
        cout << "wrong password,you have "<<3-count<<" more trials, try again: ";
        cin >> s;
        count++;
    }
  if(count==3)
  return false;
else
return true;
};
int main(){
    int choice=0, age, crhr;
    string id, firstName, lastName, sex, courseTitle, courseNo, sec;
    cout << "welcome to the student record\n"
         <<"\t management  system, \n press any key"
         <<" to continue\n";
       while(choice != -1){
    cout <<"\n what would you like to do...?\n"
         <<"press 1 to register student\n"
         <<"press 2 to add course\n"
         <<"press 3 to maintain student grades\n"
         <<"press 4 to search for a student using id no\n"
         <<"press 5 to search for a course using course no\n"
         <<"press 6 to see a sorted list of students\n"
         <<"press 7 to display the all students' details\n"
         <<"press 8 to delete a student's record\n"
         <<"press 9 to delete a course\n";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "please enter your first name: ";
            cin>>firstName;
            cout << "please enter your last name: ";
            cin>>lastName;
            cout << "please enter your age: ";
            cin>>age;
            cout << "please enter m or f for your sex: ";
            cin >> sex;
            enroll(firstName,lastName,age,sex);
            break;
        case 2:
            cout << "enter password: ";
            cin >> sec;
            if(password(sec) == true){
            cout << "please enter course name: ";
            cin >> courseTitle;
            cout << "please enter course No: ";
            cin >> courseNo;
            cout << "please enter credit hour: ";
            cin >> crhr;
            addCourse(courseNo, courseTitle,crhr);
             }
            break;
        case 3:
            cout << "enter password: ";
            cin >> sec;
            if(password(sec) == true){
            cout<<"Enter course number: ";
            cin>>courseNo;
            grade(courseNo);
            }
            break;
        case 4:
            cout << "enter id: ";
            cin >> id;
            searchStu(id);
            break;
        case 5:
            cout << "enter course no: ";
            cin >> courseNo;
            searchCourse(courseNo);
            break;
        case 6:
            sortList();
            break;
        case 7:
            cout << "enter password: ";
            cin >> sec;
            if(password(sec) == true)
                displayAll();
            break;
        case 8:
            cout << "enter password: ";
            cin >> sec;
            if(password(sec) == true) {
                cout << "Enter Id of student you want to delete: ";
                cin >> id;
                deleteStu(id);
                sortList();
            }
            break;
        case 9:
            cout << "enter password: ";
            cin >> sec;
            if(password(sec) == true){
                cout << "enter course number: ";
                cin >> courseNo;
                deleteCourse(courseNo);
                displayCourse();
            }
             break;
        default:
            if(choice==-1)
                cout<<"Thank you\nGood bye";
            cout<< "incorrect response! please try again\n";
        }
    }

return 0;
}
