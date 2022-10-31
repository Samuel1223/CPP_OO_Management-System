/*
心得：這次物件導向的課程有改變我寫程式的習慣
1. 很好理解,思考, 尤其複雜起來優勢越大
2. 很好更改只要對class更動就可以
3. 甚至是執行速度
4. 畫草圖！！
https://drive.google.com/drive/folders/14mHvPI2eiANNNoFOpjOfOpur1K-OUDQE?usp=sharing

*/


/*
  # Author: Samuel Yu <samueltoyu@gmail.com>
  # License: No License XD
  # Copyright: Samuel
  
Hi ! This is Samuel form NTUST, Permission is hereby granted, free of charge, to deal
in the Software without restriction, subject to the no conditions lol 


*/

//include 需要的東西
#include<fstream>
#include<string.h>
#include<iostream>
#include<vector>
#include<time.h>


using namespace std;
 
//聯絡人物件 降低時間複雜度 比較直觀
class Contact
{


	public:
	
	long ph;
	string name,add,email;
	std::vector<string> messages;
	
	void create_contact()
	{
		cout<< "Phone: ";
		cin >> ph;
		cout << "Name: ";
		cin >> name;
		cout << "Address: ";
		cin >> add;
		cout << "Email address: ";
		cin >> email;
 
		cout << "\n";

	}

	void show_contact()
	{
		cout<<endl<<"Phone #: "<<ph;
		cout<<endl<<"Name: "<<name;
		cout<<endl<<"Address: "<<add;
		cout<<endl<<"Email Address : "<<email;
		
		cout<<endl<<"message"<< endl;
		for (int i=0; i< messages.size(); i++){
            cout<< messages[i] << endl;
        }//for
		cout<<endl;
	}

	long getPhone()
	{
		return ph;
	}

	string getName()
	{
		return name;
	}

	string getAddress()
	{
		return add;
	}

	string getEmail()
	{
		return email;
	}
};// contactbook


//系統物件
class System{
    
private:
    std::vector<Contact> contacters ;
    int mode;
    
public:
    
    void add_newcontact(){
        Contact a_contact;
        a_contact.create_contact();
        
        contacters.push_back(a_contact);
    }//add_newcontact
    
    
    int get_len_of_contact(){
        return contacters.size();
    }//get_len_of_contact
    
    
    void list_allcontact(){
        for (int i=0; i< get_len_of_contact(); i++){
            contacters[i].show_contact();
        }//for
    }//list_allcontact
    
    
    
    void search_contact(){
        cout<< "do you want to search by name(0) or number(1)";
        cin>> mode;
        
        if (mode == 0){
            string searchname;
            cout<< "please enter a name:" << endl;
            cin >> searchname;
            
            int find = 0;
            for (int i=0; i< get_len_of_contact(); i++){
                if (contacters[i].name == searchname){
                    contacters[i].show_contact();
                    find = 1;
                }//if
                
            }//for
            
            if (find == 0){
                cout<< "we don't have this contacter" << endl;
            }//if
            
        }//if
        
        
        
        else if (mode ==1){
            long searchphone;
            cout<< "please enter a phone:" << endl;
            cin >> searchphone;
            
            int find = 0;
            for (int i=0; i< get_len_of_contact(); i++){
                if (contacters[i].ph == searchphone){
                    contacters[i].show_contact();
                    find = 1;
                }//if
                
            }//for
            
            if (find == 0){
                cout<< "we don't have this contacter" << endl;
            }//if
            
        }//else if
        
        
        else{
            cout<< "the mode number is incorrect"<< endl;
        }//else
        
    }// search contact
    
    void edit_contact(){
        
        string searchname;
            cout<< "please enter a name:" << endl;
            cin >> searchname;
            
            int find = 0;
            for (int i=0; i< get_len_of_contact(); i++){
                if (contacters[i].name == searchname){
                    
                    cout<< "which kind of info you want to edit: name(0), phone(1), address(2), email(3)"<<endl;
                    cin>> mode;
                    switch (mode){
                        case 0:
                            cout<<"please enter the new name";
                            cin >> contacters[i].name ;
                            break;
                        
                         case 1:
                            cout<<"please enter the new phone";
                            cin >> contacters[i].ph ;
                            break;
                         case 2:
                            cout<< "please enter the new address";
                            cin >> contacters[i].add ;
                            break;
                         case 3:
                            cout<< "please enter the new email";
                            cin >> contacters[i].email ;
                            break;
                        default:
                            cout<< "the mode number is incorrect"<< endl;

                    }//switch
                    contacters[i].show_contact();
                    find = 1;
                }//if
                
            }//for
            
            if (find == 0){
                cout<< "we don't have this contacter" << endl;
            }//if
        
        
    }//editcontact
    
    void delete_contact(){
        string searchname;
            
            int del_mode;
            cout << "please enter the delete mode: precise delete(0), delete all(1)"<<endl;
            cin >> del_mode; 
            cout << "please enter a name:" << endl;
            cin >> searchname;
            
            if (del_mode == 0){
                int find = 0;
                for (int i=0; i< get_len_of_contact(); i++){
                    if (contacters[i].name == searchname){
                        contacters.erase(contacters.begin()+i); 
                        find = 1;
                    }//if
                    
                }//for
            
                if (find == 0){
                    cout<< "we don't have this contacter" << endl;
                }//if
            }//if
            
            if (del_mode == 1){
                contacters.clear();
        
            }//if
                
            
        
    }//delete_contact
    
    void save_file(){
        ofstream out_contact_file;
        out_contact_file.open("contact.txt");
        
        out_contact_file << get_len_of_contact() << endl;
        
        for (int i =0; i< get_len_of_contact();i++){
           out_contact_file << contacters[i].name << " "<< contacters[i].ph<< " "<< contacters[i].add << " "<< contacters[i].email << endl; 
        }//for
        out_contact_file.close();
    }//save_file
    
    
    
    void load_file(){
        ifstream contact_file;
        contact_file.open("contact.txt");
        
        if (!contact_file){
            cout<< "the file is not found"<< endl;
            return;
        }
        
        contacters.clear();
        
        int file_len;
        contact_file >> file_len;
        
        for (int i =0; i<file_len; i++){
            Contact a_contact;
            contact_file >> a_contact.name;
            contact_file >> a_contact.ph;
            contact_file >> a_contact.add;
            contact_file >> a_contact.email;
            
            contacters.push_back(a_contact);
    
        }//for     
        
        contact_file.close();
        
        
    }//load_file
    
    void send_message(){
        
        string sender;
        cout<< "who is the sender ??"<< endl;
        cin >> sender;

        string reciever;
        cout<< "who is reciever ??" << endl;
        cin >> reciever;
        
        string message;
        cout<< "enter the message: "<< endl;
        cin >> message;
        
        int sfind = 0;
        for (int i=0; i< get_len_of_contact(); i++){
            if (contacters[i].name == sender){
                // 基於當前系統的時間
                time_t now = time(0);
               
                // 把now換成字串的格式
                char* dt = ctime(&now);
                contacters[i].messages.push_back("sent:" + message + "   "+ dt) ;
                sfind = 1;
            }//if
            
        }//for
        
        int rfind = 0;
        for (int i=0; i< get_len_of_contact(); i++){
            if (contacters[i].name == reciever){
                // 基於當前系統的時間
                time_t now = time(0);
               
                // 把now換成字串的格式
                char* dt = ctime(&now);
                contacters[i].messages.push_back("recieve:" + message + "   "+ dt) ;
                rfind = 1;
            }//if
            
        }//for
        
        if (sfind == 0){
            cout<< "we don't have this contacter as sender" << endl;
        }//if
        
        if (rfind == 0){
            cout<< "we don't have this contacter as reciever" << endl;
        }//if
            

        
        
        
        
    }//send_message

    
    
    
    
    
    
    
    
};// System



//主程式
int main()
{   
    System system1;
    while (true){
        cout<< "Main MENU" << endl <<
                 "========================================"<<endl<<
                
                "[1] Add a new Contact"<<endl<<
                
                "[2] List all Contacts"<<endl<<
                
                "[3] Search for contact"<<endl<<
                
                "[4] Edit a Contact"<<endl<<
                
                "[5] Delete a Contact"<<endl<<
                
                "[6] Get len of contact"<<endl<<
                
                "[7] Save the file"<<endl<<
                
                "[8] load the file"<<endl<<
                
                "[9] send the message"<<endl<<
                
                "[0] Exit"<<endl<<
                
                "=========================================="<<endl;
        cout<< "Enter the choice:"<< endl;
        int system_mode;
        cin >> system_mode;
        switch(system_mode){
            case 1:
                system1.add_newcontact();
                break;
            case 2:
                system1.list_allcontact();
                break;
            case 3:
                system1.search_contact();
                break;
            case 4:
                system1.edit_contact();
                break;
            case 5:
                system1.delete_contact();
                break;
            case 6:
                cout<< "the len of contacters: "<<system1.get_len_of_contact() << endl;
                break;
            case 7:
                system1.save_file();
                break;
            case 8:
                system1.load_file();
                break;
            case 9:
                system1.send_message();
                break;
            case 0:
                return 0;
                break;
        }//switch
        
    }//while
    
    
  return 0;
};

