 #include<iostream>
 #include<Windows.h>
 #include<conio.h>
 #include<fstream>
 using namespace std;
 
 struct Node{
 	int id,rank;
 	string name,gendar;
	string DOB,city,state,jDate,email;
 	float salary;
 	Node *left;
 	Node *right;
 };
 
 class Person{
 	public:
 		Node *root;
 	public:
 		Person();
 		Node *solidersRegistration(int d,Node *temp);
 };
 
 Person::Person(){
 	root=NULL;
 }
 
 
 
 

//Class of Central Authority 
 class CentralAuthority: public Person{
 	public:
 		Node *solidersRegistration(int d,Node *temp);
 };
 

Node *CentralAuthority::solidersRegistration(int d,Node *temp){
		if(temp==NULL){
		temp=new Node;
		cout<<"Enter id : "; cin>>temp->id; cin.ignore();
		cout<<"Enter name : "; getline(cin,temp->name);
		cout<<"Enter  Gender: "; getline(cin,temp->gendar);
		cout<<"Enter DOB : "; getline(cin,temp->DOB);
		cout<<"Enter city : "; getline(cin,temp->city);
		cout<<"Enter state : "; getline(cin,temp->state);
		cout<<"Enter joining date : "<<__TIMESTAMP__;
		temp->left=NULL;
		temp->right=NULL;
		if(root==NULL){
			root=temp;
		}
		
	}
	else{
		if(temp->id > d){
			temp->left=solidersRegistration(d,temp->left);
		}
		else{
			temp->right=solidersRegistration(d,temp->right);
		}
	}
	return temp;
	
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Desktop\\Project of hospital Managment\\allRecords\\AdminDoctor\\login/"+username+".txt";
	myfile.open(path.c_str());
	myfile<<;
	myfile.close();

}
 
 






 
 int main(){
 	cout<<"Compilation is successfull...!!!\n";
 	CentralAuthority c;
 	c.solidersRegistration(12,c.root);
 }
 
 
 
 
 
 
 
 
 /*
 
 int main(){
 	
 	system("COLOR 0A");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
	<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n"
	<<"\t\t\t\t\t@@|                                           		                                  |@@\n"
	<<"\t\t\t\t\t@@|                                           		                                  |@@\n"
	<<"\t\t\t\t\t@@|                                           		                                  |@@\n"
	<<"\t\t\t\t\t@@|                                           		                                  |@@\n"
	<<"\t\t\t\t\t@@|                                           		                                  |@@\n"
	<<"\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n"
	<<"\t\t\t\t\t@@|                                                                                       |@@\n"
	<<"\t\t\t\t\t@@|                            MILITRAY MANAGEMENT SYSTEM                                 |@@\n"
	<<"\t\t\t\t\t@@|                                                                                       |@@\n"
	<<"\t\t\t\t\t@@|                                                                                       |@@\n"
	<<"\t\t\t\t\t@@|                                                                                       |@@\n"
	<<"\t\t\t\t\t@@|                                               Created by:-                            |@@\n"
	<<"\t\t\t\t\t@@|                                                            Abdullah BuTT 038 BSSE     |@@\n"
	<<"\t\t\t\t\t@@|                                                            Maryam BuTT 031 BSSE       |@@\n"
	<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n"
	<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
	 
	 
	cout<<"press any key...";	
	getch();
	system("cls");
	
	 int choice;
	 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || LOGIN AS || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Registration                                  |\n"
		<<"\t\t\t\t\t\t|             2  >> Soliders                                      |\n"
		<<"\t\t\t\t\t\t|             3  >> Commanders                                    |\n"
		<<"\t\t\t\t\t\t|             4  >> Authorities                                   |\n"
		<<"\t\t\t\t\t\t|             5  >> Gmail                                         |\n"
		<<"\t\t\t\t\t\t|             6  >> Communication                                 |\n"
		<<"\t\t\t\t\t\t|             7  >> Exit                                          |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	 
	 cout<<"ENTER CHOICE : "; 
	 cin>>choice;
	 switch(choice){
	 	case 1:
	 		break;
	 		case 2:
	 			break;
	 			case 3:
	 				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || COMMANDERS || >>\n\n"
					<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
					<<"\t\t\t\t\t\t _________________________________________________________________ \n"
					<<"\t\t\t\t\t\t|                                           	                  |\n"
					<<"\t\t\t\t\t\t|             1  >> File Upload                                  |\n"
					<<"\t\t\t\t\t\t|             2  >> Sign out                                      |\n"
					<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	 				break;
	 				case 4:
	 					break;
	 					case 5:
	 						break;
	 						case 6:
	 							break;
	 							default:
	 								cout<<"Invalid Choice"<<endl;
	 								
	 }
	 
	 return 0;
 }*/
