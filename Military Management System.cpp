 #include<iostream>
 #include<Windows.h>
 #include<conio.h>
 #include<fstream>
 #include<string>
 
 using namespace std;
 int main();
 void adminPortal();
 void generalPortral();
 void LieutenatPortal();
 void karnalPortal();
 void brigadierPortal();
 void majorPortal();
 void captionLieutenantPortal();
 void secondLieutenantPortal();
 void subedarPortal();
 
 struct Node{
 	string id;
	string rank;
 	string name;
	string gendar;
	string DOB;
	string city;
	string jDate;
	string email;
	string emailPass;
	int age;
 	float salary;
 	float height;
 	Node *left;
 	Node *right;
 };
 
 class Person{
 	public:
 		Node *root;
 	public:
 		Person();
 		Node *Registration(string d,Node *temp);
 		string selectRank();
 		bool login();
 		
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
		cout<<"Enter your choice : "; 
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
														cout<<"Invalid choice\n\n\n"
														<<"\t\tPlease enter valid choice\n"
														<<"Press any key...";
														getch();
														system("cls");
														this->selectRank();
								
		}			
 }
 

bool Person::login(){
	string username,password;
	cout<<"Enter user Name : "; getline(cin,username);
	cout<<"Enter Password : "; getline(cin,password);
	
	string path = ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\email/");
	string pass;
	ifstream fin;
	fin.open((path+username+".txt").c_str(),ios::in);
	
	string getUserName,getPass;
	fin>>getUserName;
	fin>>getPass;
	
	if(username!=getUserName && password!=getPass){
		cout<<"User name & password is not found\n";
		return false;
	}else if(username!=getUserName && password==getPass){
		cout<<"User name is not Found";
		return false;
	}else if(username==getUserName && password!=getPass){
		cout<<"Invalid Password\n";
		return false;
	}else if(username==getUserName && password==getPass){
		return true;
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
		void reStoreAccordingToId(string path,Node *temp);
		string reStoreSelection(string d,Node *temp);
		void storeHistory(string path,Node *temp);		
		void searchingRecord();
		string searchRecordSelection(string d);
		string deleteSelection();

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
		cout<<"Enter age : "; cin>>temp->age;
		cout<<"Enter Height : "; cin>>temp->height; cin.ignore();
		cout<<"Enter Email : "; getline(cin,temp->email);
		cout<<"Enter Password : "; getline(cin,temp->emailPass);
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
	
	string num;
	string path = this->deleteSelection();
	cout<<"Enter id for deletion : "; cin>>num;
	remove((path + num + ".txt").c_str()); 
	
	cout<<num<<" Record is deleted\n\n";
	cout<<"Press any key...";
	getch();
	adminPortal();
	 
	
}


string Admin::deleteSelection(){
	string d = this->selectRank();
	string path;
 	if(d=="10"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\ArmyChief/");
	 } else if(d=="9"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfgenerals/");
	 } else if(d=="8"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOflieutenant/");
	 } else if(d=="7"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfKarnals/");
	 } else if(d=="6"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfBrigadier/");
	 } else if(d=="5"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOdMajor/");
	 } else if(d=="4"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfCaptionLieutenant/");
	 } else if(d=="3"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSecondLieutenant/");
	 } else if(d=="2"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSubedar/");
	 } else if(d=="1"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/");
	 } else{
	 	cout<<"Invalid value";
	 }

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
	
	cout<<"Press any key...";
	getch();
	system("cls");
	adminPortal();
}


string Admin::reStoreSelection(string d,Node *temp){
	string path;
 	if(d=="10"){
		 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\ArmyChief/");
	 } else if(d=="9"){
	 	 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfgenerals/");
	 } else if(d=="8"){
	 	 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOflieutenant/");
	 } else if(d=="7"){
		 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfKarnals/");
	 } else if(d=="6"){
		 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfBrigadier/");
	 } else if(d=="5"){
		 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOdMajor/");
	 } else if(d=="4"){
		 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfCaptionLieutenant/");
	 } else if(d=="3"){
		 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSecondLieutenant/");
	 } else if(d=="2"){
	 	 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSubedar/");
	 } else if(d=="1"){
	 	 path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/");
	 } else{
	 	cout<<"Invalid value";
	 }

	this->reStoreAccordingToId(path,temp);

 }


void Admin::reStoreAccordingToId(string path,Node *temp){
	
	ofstream myfile,mf;
	myfile.open((path+temp->id+".txt").c_str());
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tAge : "<<temp->age<<endl
	<<"\t\t\tHeight : "<<temp->height<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl
	<<"\t\t****************************************************************"<<endl;
	myfile.close();
	string path2=("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\email/");
	mf.open((path2+temp->email+".txt").c_str());
	mf<<temp->email<<endl;
	mf<<temp->emailPass;
	mf.close();

	storeHistory(path,temp);

}

void Admin::storeHistory(string path,Node *temp){
	ofstream myfile;
	myfile.open((path+"History.txt").c_str(),ios::app);
	myfile<<"\t\t****************************************************************"<<endl
	<<"\t\t\tId : "<<temp->id<<endl
	<<"\t\t\tName : "<<temp->name<<endl
	<<"\t\t\tGendar : "<<temp->gendar<<endl
	<<"\t\t\tDOB : "<<temp->DOB<<endl
	<<"\t\t\tCity : "<<temp->city<<endl
	<<"\t\t****************************************************************"<<endl;
	myfile.close();
	cout<<"Press any key...";
	getch();
	adminPortal();
}


string Admin::searchRecordSelection(string d){
	string path;
 	if(d=="10"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\ArmyChief/");
	 } else if(d=="9"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfgenerals/");
	 } else if(d=="8"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOflieutenant/");
	 } else if(d=="7"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfKarnals/");
	 } else if(d=="6"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfBrigadier/");
	 } else if(d=="5"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOdMajor/");
	 } else if(d=="4"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfCaptionLieutenant/");
	 } else if(d=="3"){
		return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSecondLieutenant/");
	 } else if(d=="2"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSubedar/");
	 } else if(d=="1"){
	 	return path= ("C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/");
	 } else{
	 	cout<<"Invalid value";
	 }


 }

void Admin::searchingRecord(){
	string returnRank= this->selectRank();
	string path = this->searchRecordSelection(returnRank);
	string search,line;
	cout<<"Enter id for search : "; cin>>search;
	
	string asd = search+".txt";
	ifstream fin;
	fin.open((path+asd).c_str());
	if(!fin){
		cout<<"Record is not Found\n";
	}else {
		while(getline(fin,line)){
			cout<<line<<endl;
		}
	}
	cout<<"\n\nPress any key...";
	getch();
	system("cls");
	adminPortal();
	
}

class Generals{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};


string Generals::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Generals Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Lieutenant                                 |\n"
		<<"\t\t\t\t\t\t|             2  >> Karnals                                    |\n"
		<<"\t\t\t\t\t\t|             3  >> Brigadier                                  |\n"
		<<"\t\t\t\t\t\t|             4  >> Major                                      |\n"
		<<"\t\t\t\t\t\t|             5  >> Caption Lieutenant                         |\n"
		<<"\t\t\t\t\t\t|             6  >> Second Lieutenant                             |\n"
		<<"\t\t\t\t\t\t|             7  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             8  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> Back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "8";
				break;
				case 2:
					return "7";
						break;
						case 3:
							return "6";
							break;
							case 4:
								return "5";
								break;
								case 5:
									return "4";
									break;
									case 6:
										return "3";
										break;
										case 7:
											return "2";
											break;
											case 8:
												return "1";
												break;
												case 0:
													main();
													break;
													default:
													cout<<"Invalid choice\n\n\n"
												<<"\t\tPlease enter valid choice\n"
												<<"Press any key...";
												getch();
												system("cls");
												generalPortral();
		}
		
 }
 
 
 void Generals::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	generalPortral();
}
 
 string Generals::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "8"){
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
 
//////////Lieutenant Class
class Lieutenant{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};


string Lieutenant::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Lieutenant Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Karnals                                    |\n"
		<<"\t\t\t\t\t\t|             2  >> Brigadier                                  |\n"
		<<"\t\t\t\t\t\t|             3  >> Major                                      |\n"
		<<"\t\t\t\t\t\t|             4  >> Caption Lieutenant                         |\n"
		<<"\t\t\t\t\t\t|             5  >> Second Lieutenant                             |\n"
		<<"\t\t\t\t\t\t|             6  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             7  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "7";
				break;
				case 2:
					return "6";
						break;
						case 3:
							return "5";
							break;
							case 4:
								return "4";
								break;
								case 5:
									return "3";
									break;
									case 6:
										return "2";
										break;
										case 7:
											return "1";
											break;
											case 0:
												main();
												break;
												default:
												cout<<"Invalid choice\n\n\n"
												<<"\t\tPlease enter valid choice\n"
												<<"Press any key...";
												getch();
												system("cls");
												LieutenatPortal();
		}
		
 }
 
 
 void Lieutenant::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	LieutenatPortal();
}
 
 string Lieutenant::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "7"){
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
 
 
 
 //////////Karnals Class

class Karnals{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};


string Karnals::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Lieutenant Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Brigadier                                  |\n"
		<<"\t\t\t\t\t\t|             2  >> Major                                      |\n"
		<<"\t\t\t\t\t\t|             3  >> Caption Lieutenant                         |\n"
		<<"\t\t\t\t\t\t|             4  >> Second Lieutenant                             |\n"
		<<"\t\t\t\t\t\t|             5  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             6  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> Back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "6";
				break;
				case 2:
					return "5";
						break;
						case 3:
							return "4";
							break;
							case 4:
								return "3";
								break;
								case 5:
									return "2";
									break;
									case 6:
										return "1";
										break;
										case 0:
											main();
											break;
											default:
											cout<<"Invalid choice\n\n\n"
									<<"\t\tPlease enter valid choice\n"
									<<"Press any key...";
									getch();
									system("cls");
									karnalPortal();
		}
		
 }
 
 
 void Karnals::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	karnalPortal();
}
 
 string Karnals::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "6"){
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
 
 
 //////////Brigadier Class

class Brigadier{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};


string Brigadier::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Brigadier Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Major                                      |\n"
		<<"\t\t\t\t\t\t|             2  >> Caption Lieutenant                         |\n"
		<<"\t\t\t\t\t\t|             3  >> Second Lieutenant                             |\n"
		<<"\t\t\t\t\t\t|             4  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             5  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "5";
				break;
				case 2:
					return "4";
						break;
						case 3:
							return "3";
							break;
							case 4:
								return "2";
								break;
								case 5:
									return "1";
									break;
									case 0:
										main();
										break;
										default:
										cout<<"Invalid choice\n\n\n"
									<<"\t\tPlease enter valid choice\n"
									<<"Press any key...";
									getch();
									system("cls");
									brigadierPortal();
		}
		
 }
 
 
 void Brigadier::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	brigadierPortal();
}
 
 string Brigadier::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "5"){
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
 
 
 
 //////////Major Class

class Major{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};


string Major::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Major Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Caption Lieutenant                         |\n"
		<<"\t\t\t\t\t\t|             2  >> Second Lieutenant                             |\n"
		<<"\t\t\t\t\t\t|             3  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             4  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> Back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "4";
				break;
				case 2:
					return "3";
						break;
						case 3:
							return "2";
							break;
							case 4:
								return "1";
								break;
								case 0:
									main();
									break;
									default:
									cout<<"Invalid choice\n\n\n"
									<<"\t\tPlease enter valid choice\n"
									<<"Press any key...";
									getch();
									system("cls");
									majorPortal();
		}
		
 }
 
 
 void Major::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	majorPortal();
}
 
 string Major::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "4"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfCaptionLieutenant/.\\History.txt";
	}else if(x == "3"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSecondLieutenant/.\\History.txt";
	}else if(x == "2"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSubedar/.\\History.txt";
	}else if(x == "1"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/.\\History.txt";
	}
	
	
}  
 
 
 
  //////////CaptionLieutenant Class

class CaptionLieutenant{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};


string CaptionLieutenant::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Caption Lieutenant Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Second Lieutenant                             |\n"
		<<"\t\t\t\t\t\t|             2  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             3  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> Back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "3";
				break;
				case 2:
					return "2";
						break;
						case 3:
							return "1";
							break;
							case 0:
								main();
								break;
								default:
							cout<<"Invalid choice\n\n\n"
							<<"\t\tPlease enter valid choice\n"
							<<"Press any key...";
							getch();
							system("cls");
							captionLieutenantPortal();
		}
		
 }
 
 
 void CaptionLieutenant::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	captionLieutenantPortal();
}
 
 string CaptionLieutenant::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "3"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSecondLieutenant/.\\History.txt";
	}else if(x == "2"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSubedar/.\\History.txt";
	}else if(x == "1"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/.\\History.txt";
	}
	
	
}  
 
 
 
//////////SecondLieutenant Class

class SecondLieutenant{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};

string SecondLieutenant::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Second Lieutenant Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Subedar                                       |\n"
		<<"\t\t\t\t\t\t|             2  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> Back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "2";
				break;
				case 2:
					return "1";
						break;
						case 0:
							main();
							break;
							default:
							cout<<"Invalid choice\n\n\n"
							<<"\t\tPlease enter valid choice\n"
							<<"Press any key...";
							getch();
							system("cls");
							secondLieutenantPortal();	
		}
		
 }
 
 void SecondLieutenant::displayRecord(){
	string path = this->displayRecordDecision();
	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	secondLieutenantPortal();
}
 
 string SecondLieutenant::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "1"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/.\\History.txt";
	}
	
	
}  
 
//////////Subedar Class

class Subedar{
	public:
		string selectRank();
		void displayRecord();
		string displayRecordDecision();
};

string Subedar::selectRank(){
 		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Subedar Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Soliders                                         |\n"
		<<"\t\t\t\t\t\t|             0  >> Back                                         |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
		int choice;
		cout<<"Enter your choice : "; 
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				return "1";
				break;
				case 0:
					main();
					break;
					default:
					cout<<"Invalid choice\n\n\n"
					<<"\t\tPlease enter valid choice\n"
					<<"Press any key...";
					getch();
					system("cls");
					subedarPortal();			
		}
		
 }
 
 
 void Subedar::displayRecord(){
	
	string path = this->displayRecordDecision();

	ifstream infile;
	string line;
	infile.open(path.c_str());
		while(getline(infile,line))
	 {
		cout<<line<<endl;
	}
	subedarPortal();
}
 
 string Subedar::displayRecordDecision(){
	string x = this->selectRank();
	string path;
	if(x == "1"){
	 return path= "C:\\Users\\Abdullah\\Documents\\Semester projects\\Military Management System project\\Military-Management-System\\Central Autority\\Registration\\reOfSoliders/.\\History.txt";
	}
	
} 
 

void adminPortal(){
	Admin c;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t << || Admin Portal || >>\n\n"
		<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n"
		<<"\t\t\t\t\t\t _________________________________________________________________ \n"
		<<"\t\t\t\t\t\t|                                           	                  |\n"
		<<"\t\t\t\t\t\t|             1  >> Registration                               |\n"
		<<"\t\t\t\t\t\t|             2  >> Display Record                                          |\n"
		<<"\t\t\t\t\t\t|             3  >> Search Record                               |\n"
		<<"\t\t\t\t\t\t|             4  >> Delete Record                                         |\n"
		<<"\t\t\t\t\t\t|             5  >> Back                                          |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	 	int adminChoice;		
	 	cout<<"Enter Choice : "; cin>>adminChoice;
	 	if(adminChoice==1){
	 		string x = c.selectRank();
 			c.Registration(x,c.root);
 			cin.ignore();
 			system("cls");
 			//adminPortal();
		 } else if(adminChoice==2){
		 	c.displayRecord();
		 }else if(adminChoice==3){
			c.searchingRecord();
				 	
		 }else if(adminChoice==4){
		 	string d=" ";
			 c.deletion(c.root,d);
		 	
		 }else if(adminChoice==5){
		 	main();
}else{

cout<<"Invalid choice\n\n\n"
<<"\t\tPlease enter valid choice\n"
<<"Press any key...";
getch();
system("cls");
adminPortal();
}
}


void generalPortral(){
	Generals g;
	g.displayRecord();
}


void LieutenatPortal(){
Lieutenant l;
l.displayRecord();	

}

void karnalPortal(){
Karnals k;
k.displayRecord();
}

void brigadierPortal(){
Brigadier b;
b.displayRecord();	
}

void majorPortal(){
	Major m;
	m.displayRecord();
}									 

void captionLieutenantPortal(){
	CaptionLieutenant cap;
	cap.displayRecord();
}


void secondLieutenantPortal(){
SecondLieutenant secndLieut;
secndLieut.displayRecord();	
}

void subedarPortal(){
Subedar sub;	
sub.displayRecord();
}


/////////////////////////////Main Function 
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
	 cin.ignore();
	 switch(choice){
	 	case 1:
	 		while(true){
	 		if(c.login()){
		 system("cls");
	 		adminPortal();
		 
	}else {
		cout<<"Press any key...";
		getch();
		system("cls");
		c.login();
	}
	
}
		 break;
	 		case 2:
	 			while(true){
	 				
	 			if(c.login()){
	 				system("cls");
	 			c.displayRecord();	
				 }else{
				 	cout<<"Press any key...";
					getch();
					system("cls");
				 	c.login();
				 }
	 		}
	 			break;
	 			case 3:
	 				{
	 					while(true){
	 					if(c.login()){
	 					system("cls");
	 					generalPortral();	
					}else{
					cout<<"Press any key...";
					getch();
					system("cls");
						c.login();
					}
				}
	 			}
	 				break;
	 				case 4:
	 					while(true){
	 					if(c.login()){
	 					system("cls");
						LieutenatPortal();
						 }else{
						 	cout<<"Press any key...";
							getch();
							system("cls");
						 	c.login();
						 }
					}
	 					break;
	 					case 5:
	 						while(true){
	 						if(c.login()){
							 system("cls");	
	 						karnalPortal();
							 }else{
							 cout<<"Press any key...";
							getch();
							system("cls");
							 	c.login();
							 }
						}
	 						break;
	 						case 6:
	 							while(true){
	 							if(c.login()){
	 							system("cls");
	 							brigadierPortal();
								 }else{
								 cout<<"Press any key...";
								getch();
								system("cls");
								 	c.login();
								 }
							}
	 							break;
	 							case 7:
	 								while(true){	 
	 								if(c.login()){
	 								system("cls");
	 								majorPortal();
									 }else{
									cout<<"Press any key...";
									getch();
									system("cls");
									 	c.login();
									 }
								}
	 								break;
	 								case 8:
	 									while(true){ 
	 									if(c.login()){
	 									system("cls");
	 									captionLieutenantPortal();	
										 }else{
										 	cout<<"Press any key...";
											getch();
											system("cls");
										 	c.login();
										 }
									}
	 									break;
	 									case 9:
	 										while(true){	 
	 										if(c.login()){
	 										system("cls");
	 										secondLieutenantPortal();	
											 }else{
											cout<<"Press any key...";
											getch();
											system("cls");
											 	c.login();
											 }
										}
	 										break;
	 										case 10:
	 											while(true){
	 											if(c.login()){
	 											system("cls");
	 											subedarPortal();	
												 }else{
												 	cout<<"Press any key...";
													getch();
													system("cls");
												 	c.login();
												 }
											}
	 											break;
	 											case 11:
	 												///////////
	 												break;
	 												case 12:
	 													break;
	 													default:
	 														cout<<"Invalid choice\n\n\n"
	 														<<"\t\tPlease enter valid choice\n"
	 														<<"Press any key...";
	 														getch();
	 														system("cls");
	 														main();
	 														
	 }
	 
	 return 0;
 }
