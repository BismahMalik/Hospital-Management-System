#include<iostream>
using namespace std;
//Classes
class Patient;
class Diagnosis;
class Reception;
class Doctor
{
	string D_Name,D_number,D_department,D_gender;
	int D_Id;
	public:
	//Default Constructor
	Doctor()
	{
	}
	//Parametrized Constructor
	Doctor(string pName,string pNumber,string pDepart,string pGender, int pId)
	{
	   	D_Name=pName;
		D_number=pNumber;
		D_department=pDepart;
		D_gender=pGender;
		D_Id=pId;
		
	}
	//Setter and getters
	void setDataDoc(string pName,string pNumber,string pDepart,string pGender, int pId)
	{
		D_Name=pName;
		D_number=pNumber;
		D_department=pDepart;
		D_gender=pGender;
		D_Id=pId;
	
	}
	void setDName(string pName)
	{
		D_Name=pName;
	}
	void setDNumber(string pNumber)
	{
		D_number=pNumber;
	}
	void setDepart(string pDepart)
	{
		D_department=pDepart;
	}
	void setGender(string pGender)
	{
		D_gender=pGender;
	}
	void setDid(int pId)
	{
		D_Id=pId;
	}
	
	string getDName()
	{
		return D_Name;
	}
	string getDNumber()
	{
		return D_number;
	}
	string getDepart()
	{
		return D_department;
	}
	string getGender()
	{
		return D_gender;
	}
	
	int getDid()
	{
		return D_Id;
	}
	
	
	void Name()
    {
		cout<<"\n Enter Doctor Name: ";
		cin>>D_Name;
	}
    void getNameD()
	{
		cout<<"\nDoctor Name: "<<D_Name;
	}
	//Function to enter data
	void Enter()
	{
		cout<<"\n Enter Doctor Name: ";
		cin>>D_Name;
		cout<<"\n Enter Doctor Number: ";
		cin>>D_number;
		cout<<"\n Enter Doctor Department: ";
		cin>>D_department;
		cout<<"\n Enter Doctor Gender: ";
	    cin>>D_gender;
	    cout<<"\n Enter Doctor ID: ";
		cin>>D_Id;
	}
	//Function to print doctor data
	void PrintDoc()
	{
	    cout<<"\n\t\t Doctor Name: "<<D_Name;
		cout<<"\n\t\t Doctor Number: "<<D_number;
		cout<<"\n\t\t Doctor Department: "<<D_department;
		cout<<"\n\t\t Doctor Gender: "<<D_gender;
		cout<<"\n\t\t Doctor ID: "<<D_Id;
	}
		
	};
	
	
	
class Patient{
	private:
	int P_Id;
	string P_name,gender;
	Doctor *DOC;
	string DOA;
	public:
		//Default Constructor
	Patient()
    {
	}
	//parametrized Constructor
	Patient(int Id,string name,Doctor *Doc, string Date)
	{
		P_Id=Id;
		P_name=name;
		DOC=Doc;
		DOA=Date;
		
	}
		//Funtion to Set Data.
	void setData(int Id,string name,Doctor *Doc, string Date)
	{
		P_Id=Id;
		P_name=name;
		DOC=Doc;
		DOA=Date;
		
	}
	
	//Setter and getters
	void setPName(string name)
	{
		P_name=name;
	}
	void setPid(int Id)
	{
		P_Id=Id;
	}
	void setDocName()
	{
		DOC->Name();
	}
	string getPName()
	{
		return P_name;
	}
	
	int getDid()
	{
		return P_Id;
	}
	string getDocName()
	{
		return DOC->getDName();
	}
	
	
	void setName()
	{
		cout<<"\n Enter Patient Name: ";
		cin>>P_name;
	}
	void getName()
	{
		cout<<"\nPatient Name: "<<P_name;
	}
	//Function to enter Patient details
	void Enter()
    {
		cout<<"\n Enter Patient Name: ";
		cin>>P_name;
		cout<<"\n Enter Patient ID: ";
		cin>>P_Id;
		cout<<"\n Enter Date Of Admission: ";
		cin>>DOA;
		DOC->Name();
	}
	//Function to print patient details
	void Print()
	{
		cout<<endl<<"\n\t\tPatient Name: "<<P_name;
		cout<<endl<<"\n\t\tPatient ID: "<<P_Id;
		cout<<endl<<"\n\t\tDate of Admission: "<<DOA;
		DOC->PrintDoc();
	}
		//Funtion to Display Data.
	void Display()
	{
		cout<<endl<<"\n\t\tPatient Name: ";
		cin>>P_name;
		cout<<endl<<"\n\t\tPatient ID: ";
		cin>>P_Id;
		cout<<endl<<"\n\t\tDate of Admission: ";
		cin>>DOA;
	    DOC->getNameD();
	}
	};
class Diagnosis{
	
	friend class Patient;
	Patient *Pname;
	Doctor *Dname;
	string diagnosis, DO_Order;//Date of order
	public:
		//Default Constructor
	Diagnosis()
	{
	}
	//Parametrized Constructor
	Diagnosis(Patient *PName,Doctor *DName,string pDiagnosis,string Order)
	{
		Pname=PName;
		Dname=DName;
		diagnosis=pDiagnosis;
		DO_Order=Order;
	}
	void setDataDiag(Patient *PName,Doctor *DName,string pDiagnosis,string Order)
	{
		Pname=PName;
	    Dname=DName;
	    diagnosis=pDiagnosis;
		DO_Order=Order;
	}
	//Function to print diagnoisis
	void PrintDiagnosis()
	{
	    
		Pname->getName();
		Dname->getNameD();
		cout<<"\nDiagnosis: "<<diagnosis;
		cout<<"\nDate of Order: "<<DO_Order;
	}
	//Function to enter diagnosis
	void Enter()
	{
	    Pname->setName();
		Dname->Name();
		cout<<"\n Enter Diagnosis: ";
		cin>>diagnosis;
		cout<<"\n Enter Date of Order: ";
		cin>>DO_Order;
	}
	};
class Reception{
	string	R_Name;
	int R_Id;
	int size;
	Doctor *DR;
	Patient *PR;
	Diagnosis *D;
	public:
	Reception()
	{
	  size=4;
	}
	Reception(string RName,int RID,Doctor *Dname,Patient *Pname)
	{
		R_Name=RName;
		R_Id=RID;
		DR=new Doctor[size];
		PR=new Patient[size];
		D=new Diagnosis[size];
		
	}
	void setDataReception(string RName, int RID,Doctor *Dname, Patient *Pname)
	{
		R_Name=RName;
		R_Id=RID;
	}
	void PrintRecep()
	{
		cout<<"\n\t\tReceptionist Name: "<<R_Name;
		cout<<"\n\t\tReceptionist ID: "<<R_Id;
	}
	void AddDoctor()
	{
		int size;
		char ch;
		cout<<"\n Enter No.of New Doctors: ";
		cin>>size;
		Doctor DR[size];
		for(int i=0;i<size;i++)
		{
		    cout<<"\n Enter NEW DOCTOR Details: \n-----------------------";
			DR[i].Enter();
		}
		cout<<" Enter Number of Array for which data is to be displayed: ";
		cin>>ch;
		if(ch>size)
			{
				cout<<"\n\t\t YOU ENTERED A NUMBER LARGER THAN ARRAY SIZE";
			}
	    for(int i=ch;i<=ch;i++)
		{

		    cout<<"\n NEW DOCTOR Details: \n-----------------------";
			DR[i].PrintDoc();
		    
		}
		cout<<"\n Enter 'D'to display all array data: ";
		cin>>ch;
		if(ch=='D')
		{
			for(int i=0;i<size;i++)
		{
		    cout<<"\n NEW DOCTOR Details: \n-----------------------";
			DR[i].PrintDoc();
		}
		}
	
				
	}
	void AddPatient()
	{
		int size;
		char ch;
		cout<<"\n Enter No.of New Patients: ";
		cin>>size;
		Patient PR[size];
	    for(int i=0;i<size;i++)
		{
			cout<<"\n Enter NEW Patient Details: \n-----------------------";
			PR[i].Enter();
		}
		cout<<"\n Enter Number of Array for which data is to be displayed: ";
		cin>>ch;
		if(ch>size)
			{
				cout<<"\n\t\t YOU ENTERED A NUMBER LARGER THAN ARRAY SIZE";
			}
		for(int i=ch;i<=ch;i++)
		{
			
			    cout<<"\n NEW Patient Details: \n-----------------------";
			    PR[i].Display();
		    
			
		}
		cout<<" Enter 'D'to display all array data: ";
		cin>>ch;	
		if(ch=='D')
		{
			for(int i=0;i<size;i++)
		{
			cout<<"\nNEW Patient Details: \n-----------------------";
			PR[i].Display();
		}
		}
	}
	void AddDiagnosis()
	{
	    int size;
	    char ch;
		cout<<"\n Enter No.of Diagnosis: ";
		cin>>size;
		Diagnosis D[size];
	    for(int i=0;i<size;i++)
		{
			cout<<"\n Enter Diagnosis Details: \n-----------------------";
			D[i].Enter();
		}
		cout<<"\n Enter Number of Array for which data is to be displayed: ";
		cin>>ch;
		if(ch>size)
			{
				cout<<"\n\t\t YOU ENTERED A NUMBER LARGER THAN ARRAY SIZE";
			}
		for(int i=ch;i<=ch;i++)
		{
			cout<<"\n Diagnosis Details: \n-----------------------";
			D[i].PrintDiagnosis();
		    
		}
		cout<<" Enter 'D'to display all array data: ";
		cin>>ch;	
		if(ch=='D')
		{
			for(int i=0;i<size;i++)
		{
			cout<<"\n\t\t Diagnosis Details: \n-----------------------";
			D[i].PrintDiagnosis();
		}
		}				
	}
	void UpdateDoctor()
	{
	  DR->setDNumber("0334-3456798");
	  DR->setDepart("Cardiology");	
	  cout<<"\n Updated Details\n----------------------";
	  cout<<"\n New Number: "<<DR->getDNumber();	
	  cout<<"\n New Department: "<<DR->getDepart();
	}
	void UpdatePatient()
	{
		
		DR->setDName("Amnah");
		cout<<"\n Updated Details\n----------------------";
	    cout<<"\n New Doctor of Patient: "<<PR->getDocName();
	}
	
	void DeleteDoctor()
	{
		cout<<"\n Doctor Data Deleted.";
		delete DR;
		
	}
	void DeletePatient()
	{
		cout<<"\n Patient Data Deleted.";
		delete PR;
		
	}
	void DeleteDiagnosis()
	{
	   cout<<"\n Diagnosis Data Deleted.";
	   delete D;
	    			
	}
			
	};


class ProgramLoop{
	Patient P1;
	Doctor D1;
	Diagnosis Dia;
	Reception R1;
	public:
	ProgramLoop()
	{
	  bool loopFlag=true;
	  char choice;
	  do
	  {
	  	cout<<endl<<"\nEnter Choice." 
		<<"\n'A' for Adding patient data."
		<<"\n'B' for Updating Patient Data."
		<<"\n'C' for Printing Patient Data."
		<<"\n'D' for Deleting Patient Data."
		<<"\n'E' for Adding Doctor Data."
		<<"\n'F' for Updating Doctor Data."
		<<"\n'G' for Printing Doctor Data."
		<<"\n'H' for Deleting Doctor Data."
		<<"\n'I' for Adding Dignosis."
		<<"\n'i' for Printing Dignosis."
		<<"\n'J' for Deleting Dignosis."
		<<"\n'K' for Adding New Patient."
		<<"\n'L' for Adding New Doctor."
		<<"\n'M' for Adding New Diagnosis."
		<<"\n'X' for Closing program.\n";
		cin>>choice;
	  	switch(choice)
	  	{
	  	 case 'A':
		 {
	  	 	string name;
	  	 	int Id;
	  	 	string Date;
	  	 	Doctor D2("Alina","0334-65656556","Neuro","Female",211318);
			cout<<"\n\t\tEnter Patient Name: ";
	  	 	cin>>name;
	  	 	cout<<"\n\t\tEnter ID: ";
	  	 	cin>>Id;
	  	 	cout<<"\n\t\tEnter Date of admission: ";
	  	 	cin>>Date;
	  	 	cout<<"\n\t\tPatient added.";
			P1.setData(Id,name,&D2,Date);
			break;
		 }
		 
		 case 'B':
		 {
		 	Reception R;
		 	R.UpdatePatient();
			break;
		 }
		 case 'C':
		 {
		 	P1.Print();
			break;
		 }
		 
		 case 'D':
		 {
		 	Reception R;
		 	R.DeletePatient();
			break;
		 }
		 case 'E':
		 {
		 	D1.Enter();
		 	cout<<"\n\t\tDoctor added.";
			break;
		 }
		 case 'F':
		 {
		 	Reception R;
			R.UpdateDoctor();
			break;
		 }
		 
		 case 'G':
		 {
		 	D1.PrintDoc();
			break;
		 }
		 case 'H':
		 {
		 	Reception R;
			R.DeleteDoctor();
			break;
		 }
		 
		 case 'I':
		 {
		 	string Diagnosis,Order;
			cout<<"\n Enter Diagnosis: ";
		 	cin>>Diagnosis;
		 	cout<<"\n Enter Date of Order: ";
		 	cin>>Order;
		 	cout<<"\n\t\tDiagnosis added.";
		 	Dia.setDataDiag(&P1,&D1,Diagnosis,Order);
			break;
		 }
		 
		 case 'i':
		 {
		 	Dia.PrintDiagnosis();
			break;
		 }
		 
		 case 'J':
		 {
		 	Reception R;
			R.DeleteDiagnosis();
			break;
		 }
		 case 'K':
		 {
		 	Reception R;
			R.AddPatient();
			break;
		 }
		 
		 case 'L':
		 {
		 	Reception R;
			R.AddDoctor();
			break;
		 }
		 
		 case 'M':
		 {
		 	Reception R;
			R.AddDiagnosis();
			break;
		 }
		 
		 case 'X':
		 {
		    cout<<endl<<"\n\t\t\t\t\t\tProgram Exited";
			loopFlag=false;
			break;
		 }
		 default:
		 	cout<<"\n Wrong Choice.";
	    }
	  }while(loopFlag==true);
}
	};
	
//Main body
int main()
{
	ProgramLoop P;
			
	return 0;
}
	
