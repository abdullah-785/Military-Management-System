 #include<iostream>
 #include<Windows.h>
 #include<conio.h>
 #include<fstream>
 #include<string>
 
 using namespace std;
 struct Node{
 	string id,rank;
 	string name,gendar;
	string DOB,city,jDate,email;
 	float salary;
 	Node *left;
 	Node *right;
 };
 
 class Person{
 	public:
 		Node *root;
 	public:
 		Person();
 		Node *Registration(string d,Node *temp);
 		void recordOfArmyCheif(Node *temp);
 		string selectRank();
 		
 };
 
 Person::Person(){
 	root=NULL;
 }
 
 string Person::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Rank Selection || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Army Cheif                                 |\n"
		<<"\t\t\t\t\t\t|             2  >> Generals                                   |\n"
		<<"\t\t\t\t\t\t|             3  >> Lieutenant                                 |\n"
		<<"\t\t\t\t\t\t|             4  >> Karnals                                    |\n"
		<<"\t\t\t\t\t\t|             5  >> Brigadier                                  |\n"
		<<"\t\t\t\t\t\t|             6  >> Major                                      |\n"
		<<"\t\t\t\t\t\t|             7  >> Caption Lieutenant                         |\n"
		<<"\t\t\t\t\t\t|             8  >> Second Lieutenant                             |\n"
		<<"\t\t\t\t\t\t|             9  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             10  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Which person do you register : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "10";
				break;
				case 2:
					return "9";
						break;
						case 3:
							return "8";
							break;
							case 4:
								return "7";
								break;
								case 5:
									return "6";
									break;
									case 6:
										return "5";
										break;
										case 7:
											return "4";
											break;
											case 8:
												return "3";
												break;
												case 9:
													return "2";
													break;
													case 10:
														return "1";
														break;
													default:
														cout<<"Invalid choice";
														break;
								
		}
		
		
 }
 
//Class of Central Authority 
class Admin: public Person{
 	public:
 		Node *Registration(string d,Node *temp);
 		void display(Node *temp);
 		void deletion(Node *temp, string num);
 		Node *Min(Node* root);		
 		Node *getParent(Node *temp,string n);
 		void DeleteRecordFromDatabase(string d);
 		string displayRecordDecision();
 		void displayRecord();
 		
 		void recordOfArmyCheif(Node *temp);
 		void reOfgenerals(Node *temp);
 		void reOflieutenant(Node *temp);
 		void reOfKarnals(Node *temp);
 		void reOfBrigadier(Node *temp);
 		void reOdMajor(Node *temp);
 		void reOfCaptionLieutenant(Node *temp);
 		void reOfSecondLieutenant(Node *temp);
 		void reOfSubedar(Node *temp);
 		void reOfSoliders(Node *temp); 
 		void reStoreSelection(string d,Node *temp);
 };
 
 //Registration function of Admin
Node *Admin::Registration(string d,Node *temp){
	//The heighest star is 10.
		string star = "10";
		if(temp==NULL){
		temp=new Node;
		cout<<"Enter id : "; getline(cin,temp->id);
		cout<<"Enter name : "; getline(cin,temp->name);
		cout<<"Enter  Gender: "; getline(cin,temp->gendar);
		cout<<"Enter DOB : "; getline(cin,temp->DOB);
		cout<<"Enter city : "; getline(cin,temp->city);
		
		reStoreSelection(d,temp);
		
		temp->left=NULL;
		temp->right=NULL;
		if(root==NULL){
			root=temp;
		}
		
	}
	else{
		if(star > d){
			temp->left=Registration(d,temp->left);
		}
		else{
			temp->right=Registration(d,temp->right);
		}
	}
	
return temp;
}

//Display function of Admin
void Admin::display(Node *temp){
	if(temp!=NULL){
		display(temp->left);
		cout<<"\t\t\tId : "<<temp->id<<endl
		<<"\t\t\tName : "<<temp->name<<endl
		<<"\t\t\tGendar : "<<temp->gendar<<endl
		<<"\t\t\tDOB : "<<temp->DOB<<endl
		<<"\t\t\tCity : "<<temp->city<<endl;
		display(temp->right);
	}
}

//Delete function of admin
void Admin::deletion(Node *temp, string d){
	Node *parent, *min;
	string number;
	this->DeleteRecordFromDatabase(d);
	if(temp==NULL){
		cout<<"Number Not Found";
	} else if(temp->id==d){
		
	if(temp->left == NULL && temp->right == NULL)
	{
		parent = this->getParent(root,temp->id);
		if(parent->left == temp)
			parent->left = NULL;
		else if(parent->right == temp)
			parent->right = NULL;
		delete temp;
	}
}
else if((temp->left == NULL && temp->right != NULL) || (temp->left == NULL && temp->right != NULL)){
	parent = this->getParent(root,temp->id);
	if(temp->left != NULL){
		if(parent->left == temp)
		parent->left = temp->left;
	else if(parent->right == temp)
		parent->right = temp->right;
	}
	else if(temp->right != NULL){
		if(parent->left == temp)
		parent->left = temp->left;
	else if(parent->right == temp)
		parent->right = temp->right;
	}
	delete temp;
}
else if((temp->left != NULL) && (temp->right != NULL)){
	min = this->Min(temp->right);
	this->deletion(temp->right,min->id);
	temp->id = number;
}

}

//To find Minimun value
Node *Admin::Min(Node* root) {
	Node* tmp = root;  
    while (tmp->left != NULL) {  
        tmp = tmp->left;  
    }  
    cout<<tmp->id; 
    return root;
} 



Node *Admin::getParent(Node *temp,string n){
	if(temp->id==n){
		cout<<"Root have no parent";
	}else{
	while(temp!=NULL){
		if(temp->left->id==n || temp->right->id==n){
			cout<<temp->id<<endl;
			return temp;
			break;
		}else if(temp->id>n){
			temp=temp->left;
		}
		else if(temp->id<n){
			temp=temp->right;
		}
	}	
	}
}

void Admin::DeleteRecordFromDatabase(string d){
	remove(("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\ArmyChief/" + d + ".txt").c_str()); 
	
}

string Admin::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "10"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\ArmyChief/.\\History.txt";
	}else if(x == "9"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfgenerals/.\\History.txt";
	}else if(x == "8"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOflieutenant/.\\History.txt";
	}else if(x == "7"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfKarnals/.\\History.txt";
	}else if(x == "6"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfBrigadier/.\\History.txt";
	}else if(x == "5"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOdMajor/.\\History.txt";
	}else if(x == "4"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfCaptionLieutenant/.\\History.txt";
	}else if(x == "3"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSecondLieutenant/.\\History.txt";
	}else if(x == "2"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSubedar/.\\History.txt";
	}else if(x == "1"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/.\\History.txt";
	}
	
	
}

void Admin::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	
	
	
	
}




void Admin::reStoreSelection(string d,Node *temp){
 	if(d=="10"){
	 this->recordOfArmyCheif(temp);
	 } else if(d=="9"){
	 	reOfgenerals(temp);
	 } else if(d=="8"){
	 	reOflieutenant(temp);
	 } else if(d=="7"){
	 	reOfKarnals(temp);
	 } else if(d=="6"){
	 	reOfBrigadier(temp);
	 } else if(d=="5"){
	 	reOdMajor(temp);
	 } else if(d=="4"){
	 	reOfCaptionLieutenant(temp);
	 } else if(d=="3"){
	 	reOfSecondLieutenant(temp);
	 } else if(d=="2"){
	 	reOfSubedar(temp);
	 } else if(d=="1"){
	 	reOfSoliders(temp);
	 } else{
	 	cout<<"Invalid value";
	 }

 }
 


void Admin::recordOfArmyCheif(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\ArmyChief/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}
void Admin::reOfgenerals(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfgenerals/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}

void Admin::reOflieutenant(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOflieutenant/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}
void Admin::reOfKarnals(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfKarnals/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}
void Admin::reOfBrigadier(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfBrigadier/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}
void Admin::reOdMajor(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOdMajor/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}
void Admin::reOfCaptionLieutenant(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfCaptionLieutenant/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}

void Admin::reOfSecondLieutenant(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSecondLieutenant/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}

void Admin::reOfSubedar(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSubedar/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}

void Admin::reOfSoliders(Node *temp) {
	ofstream myfile;
	string path="C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/"+temp->id+".txt";
	myfile.open(path.c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl;
	myfile.close();

}

 
 
//Main Functin 
 int main(){
 	Admin c;
 	
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
		<<"\t\t\t\t\t\t|             1  >> Admin Portal                               |\n"
		<<"\t\t\t\t\t\t|             2  >> Army Cheif Portal                                 |\n"
		<<"\t\t\t\t\t\t|             3  >> Generals Portal                                   |\n"
		<<"\t\t\t\t\t\t|             4  >> Lieutenant Portal                                 |\n"
		<<"\t\t\t\t\t\t|             5  >> Karnals Portal                                    |\n"
		<<"\t\t\t\t\t\t|             6  >> Brigadier Portal                                  |\n"
		<<"\t\t\t\t\t\t|             7  >> Major Portal                                      |\n"
		<<"\t\t\t\t\t\t|             8  >> Caption Lieutenant Portal                         |\n"
		<<"\t\t\t\t\t\t|             9  >> Second Lieutenant Portal                             |\n"
		<<"\t\t\t\t\t\t|             10  >> Subedar Portal                                       |\n"
		<<"\t\t\t\t\t\t|             11  >> Email                                         |\n"
		<<"\t\t\t\t\t\t|             12  >> Exit                                          |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	 
	 cout<<"ENTER CHOICE : "; 
	 cin>>choice;
	 switch(choice){
	 	case 1:
	 		
	 			
	 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || LOGIN AS || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Registration                               |\n"
		<<"\t\t\t\t\t\t|             2  >> Display Record                                          |\n"
		<<"\t\t\t\t\t\t|             3  >> Delete Record                                         |\n"
		<<"\t\t\t\t\t\t|             4  >> Back                                          |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	 	int adminChoice;		
	 	cout<<"Enter Choice : "; cin>>adminChoice;
	 	if(adminChoice==1){
	 		string x = c.selectRank();
 			c.Registration(x,c.root);
 			cin.ignore();
 			system("cls");
 			c.display(c.root);
 			main();
		 } else if(adminChoice==2){
		 	
		 	c.displayRecord();
		 	
		 	
		 }else if(adminChoice==3){
			string d;
			 cout<<"Enter id for deletion : ";
			  cin>>d;
			 c.deletion(c.root,d);
				 	
		 }else if(adminChoice==4){
		 	main();
		 }else{
		 	cout<<"Invalid Choice\n\n";
		 }	

	 		break;
	 		case 2:
	 			break;
	 			case 3:
	 				break;
	 				case 4:
	 					break;
	 					case 5:
	 						break;
	 						case 6:
	 							break;
	 							default:
	 								cout<<"Invalid Choice"<<endl;
	 								break;
	 }
	 
	 return 0;
 }
