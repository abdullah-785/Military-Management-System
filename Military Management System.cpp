 #include<iostream>
 #include<Windows.h>
 #include<conio.h>
 #include<fstream>
 
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


void Admin::reStoreSelection(string d,Node *temp){
	//int x;
	//x = int(d);
 	switch(9){
			case 10:
				this->recordOfArmyCheif(temp);
				break;
				case 9:
					reOfgenerals(temp);
						break;
						case 8:
							reOflieutenant(temp);
							break;
							case 7:
								reOfKarnals(temp);
								break;
								case 6:
									reOfBrigadier(temp);
									break;
									case 5:
										reOdMajor(temp);
										break;
										case 4:
											reOfCaptionLieutenant(temp);
											break;
											case 3:
												reOfSecondLieutenant(temp);
												break;
												case 2:
													reOfSubedar(temp);
													break;
													case 1:
														reOfSoliders(temp);
														break;
													default:
														cout<<"Invalid choice";
														break;
								
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
		<<"\t\t\t\t\t\t|             1  >> Registration                               |\n"
		<<"\t\t\t\t\t\t|             2  >> Army Cheif Portal                                 |\n"
		<<"\t\t\t\t\t\t|             3  >> Generals Portal                                   |\n"
		<<"\t\t\t\t\t\t|             4  >> Lieutenant Portal                                 |\n"
		<<"\t\t\t\t\t\t|             5  >> Karnals Portal                                    |\n"
		<<"\t\t\t\t\t\t|             6  >> Brigadier Portal                                  |\n"
		<<"\t\t\t\t\t\t|             7  >> Major Portal                                      |\n"
		<<"\t\t\t\t\t\t|             7  >> Caption Lieutenant Portal                         |\n"
		<<"\t\t\t\t\t\t|             7  >> Second Lieutenant Portal                             |\n"
		<<"\t\t\t\t\t\t|             7  >> Subedar Portal                                       |\n"
		<<"\t\t\t\t\t\t|             7  >> Email                                         |\n"
		<<"\t\t\t\t\t\t|             7  >> Exit                                          |\n"
		<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	 
	 cout<<"ENTER CHOICE : "; 
	 cin>>choice;
	 switch(choice){
	 	case 1:
	 		{
	 		string x = c.selectRank();
 			c.Registration(x,c.root);
 			cin.ignore();
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
