#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Mokslininkai.h"
#include "Fondas.h"
#include "Apie_Dialogas.h"

const string Cduom = "Duomenys.txt";
const string Crez = "Rezultatai.txt";
const string Crez2= "Rezultatai2.txt";
const string Crez3= "Rezultatai3.txt";
const double Cprem = 4;

namespace S2L1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

void StringTostring(String ^ s, string & os)
{
   using namespace Runtime::InteropServices;
   const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void Duomenys(Fondas * F, string dfvs)
{
  ifstream duom(dfvs.c_str());
  string kod, pav, vard;
  double indelis[Mokslininkai::Cpremijos];
  double p[Fondas::Cpremijos];
  for (int i = 0; i < Fondas::Cpremijos; i++){
	  duom >> p[i];
      F->DetiP(p[i], i);
  }
  while(!duom.eof()) {     
	  getline (duom, kod, ',');
	  getline (duom, pav, ',');
	  getline (duom, vard, ',');
	  for (int i=0; i<Mokslininkai::Cpremijos; i++)
        duom >> indelis[i];
	  Mokslininkai x;
	  x = Mokslininkai(kod, pav, vard, indelis);
      F->DetiIPabaiga(x);
  }
  duom.close();
}
//-----------------------------------------------------
// Spausdinami objekto F duomenys
void Isvesti(Fondas * F)
{
   ofstream rez(Crez.c_str(), ios::app);
   for (int i = 0; i < Fondas::Cpremijos; i++)
	   rez <<' '<< F->ImtiP(i);
   rez << endl << left << setw(15) << "Kodas" << setw(15) << "Pavarde" << setw(15) <<"Vardas"<< setw(15) << "Indeliai \n";
   rez << "-----------------------------------------\n";
   F->Pradzia();
   for( F->Pradzia(); F->Yra(); F->Sekantis())
	   rez << F->ImtiDuomenis().Spausdinti();
   rez << endl << "--------------------------------------\n\n\n";
   rez.close();
}
//-----------------------------------------------------
void Apskaiciavimas(Fondas * F, Fondas * R)
{
	for (int i = 0; i < Fondas::Cpremijos; i++)
		R->DetiP(F->ImtiP(i), i);
	F->Pradzia();
	while (F->Yra()){
	   R->DetiIPradzia(F->ImtiDuomenis());
       F->Sekantis();
       }
	R->Paskirstymas();
	R->Rikiavimas();
}
//-----------------------------------------------------
void RezultatuIsvedimas(Fondas * R, string rezFailas)
{
	ofstream rez(rezFailas.c_str(), ios::app);
	rez << endl << left << setw(15) << "Kodas" << setw(15) << "Pavarde" << setw(15) <<"Vardas"<< setw(20) << "Indeliai" <<
		setw(30) << "Premijos" << setw(10) << "Suma" << endl;
    rez << "-----------------------------------------------------------------------------------------\n";
	R->Pradzia();
    while (R->Yra()){
	   rez << R->ImtiDuomenis().SpausdintiPapildomai();
       R->Sekantis();
       }
	rez << endl;
	rez << "-----------------------------------------------------------------------------------------\n";
	rez.close();
}
//----------------------------------------------------
double Vidurkiai(Fondas * R, Fondas * U)
{
	for (int i = 0; i < Fondas::Cpremijos; i++)
		U->DetiP(R->ImtiP(i), i);
	R->Pradzia();
	double PremijuV = 0;
	int n = 0;
	while (R->Yra()){
		PremijuV += R->ImtiDuomenis().ImtiS();
		R->Sekantis();
		n++;
		}
	R->Pradzia();
	PremijuV  = PremijuV / n;
	while(R->Yra()){
		if (R->ImtiDuomenis().ImtiS() < PremijuV)
			U->DetiIPabaiga(R->ImtiDuomenis());
        R->Sekantis();
		}
	return PremijuV;
}
//-----------------------------------------------------
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			info = new Fondas;
	        infoc = new Fondas;
			infoc2 = new Fondas;
			dialog = gcnew Apie_Dialogas;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			delete info;
			delete infoc;
		    delete infoc2;
			delete dialog;
		}
	private: Fondas *info, *infoc, *infoc2; 
	private: Apie_Dialogas ^dialog;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  nuskaitytiToolStripMenuItem;

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::ToolStripMenuItem^  skaièiuotiToolStripMenuItem;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  vidurkisToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  apieToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nuskaitytiToolStripMenuItem1;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  iðeitiToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->nuskaitytiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nuskaitytiToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->iðeitiToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->skaièiuotiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vidurkisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->apieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->nuskaitytiToolStripMenuItem, 
				this->skaièiuotiToolStripMenuItem, this->vidurkisToolStripMenuItem, this->apieToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(764, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// nuskaitytiToolStripMenuItem
			// 
			this->nuskaitytiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->nuskaitytiToolStripMenuItem1, 
				this->toolStripSeparator1, this->iðeitiToolStripMenuItem1});
			this->nuskaitytiToolStripMenuItem->Name = L"nuskaitytiToolStripMenuItem";
			this->nuskaitytiToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->nuskaitytiToolStripMenuItem->Text = L"Failas";
			this->nuskaitytiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::nuskaitytiToolStripMenuItem_Click);
			// 
			// nuskaitytiToolStripMenuItem1
			// 
			this->nuskaitytiToolStripMenuItem1->Name = L"nuskaitytiToolStripMenuItem1";
			this->nuskaitytiToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->nuskaitytiToolStripMenuItem1->Text = L"Nuskaityti...";
			this->nuskaitytiToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::nuskaitytiToolStripMenuItem1_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// iðeitiToolStripMenuItem1
			// 
			this->iðeitiToolStripMenuItem1->Name = L"iðeitiToolStripMenuItem1";
			this->iðeitiToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			this->iðeitiToolStripMenuItem1->Text = L"Iðeiti";
			this->iðeitiToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::iðeitiToolStripMenuItem1_Click);
			// 
			// skaièiuotiToolStripMenuItem
			// 
			this->skaièiuotiToolStripMenuItem->Enabled = false;
			this->skaièiuotiToolStripMenuItem->Name = L"skaièiuotiToolStripMenuItem";
			this->skaièiuotiToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->skaièiuotiToolStripMenuItem->Text = L"Skaièiuoti";
			this->skaièiuotiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::skaièiuotiToolStripMenuItem_Click);
			// 
			// vidurkisToolStripMenuItem
			// 
			this->vidurkisToolStripMenuItem->Enabled = false;
			this->vidurkisToolStripMenuItem->Name = L"vidurkisToolStripMenuItem";
			this->vidurkisToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->vidurkisToolStripMenuItem->Text = L"Vidurkis";
			this->vidurkisToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::vidurkisToolStripMenuItem_Click);
			// 
			// apieToolStripMenuItem
			// 
			this->apieToolStripMenuItem->Name = L"apieToolStripMenuItem";
			this->apieToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->apieToolStripMenuItem->Text = L"Apie";
			this->apieToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::apieToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->richTextBox1->Location = System::Drawing::Point(0, 59);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(764, 191);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->label1->Location = System::Drawing::Point(12, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Duomenys";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->label2->Location = System::Drawing::Point(12, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 23);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Rezultatai";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->richTextBox2->Location = System::Drawing::Point(0, 279);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(764, 196);
			this->richTextBox2->TabIndex = 3;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->label3->Location = System::Drawing::Point(12, 478);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(336, 23);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Maþai uþdirbanèiø mokslininkø sàraðas";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->richTextBox3->Location = System::Drawing::Point(0, 504);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(764, 138);
			this->richTextBox3->TabIndex = 5;
			this->richTextBox3->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->label4->Location = System::Drawing::Point(491, 478);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 23);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Vidurkis:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(585, 482);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(127, 20);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(764, 644);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Programa";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void iðeitiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
	private: System::Void nuskaitytiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void skaièiuotiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 Apskaiciavimas(info, infoc);
		 ofstream rez2(Crez2.c_str());
         rez2.close();
		 RezultatuIsvedimas(infoc, Crez2);
		 vidurkisToolStripMenuItem->Enabled = true;
		 richTextBox2->LoadFile("Rezultatai2.txt", RichTextBoxStreamType::PlainText);
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void vidurkisToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 double vidurkis = Vidurkiai(infoc, infoc2);
			 ofstream rez3(Crez3.c_str());
             rez3.close();
			 RezultatuIsvedimas(infoc2, Crez3);
			 richTextBox3->LoadFile("Rezultatai3.txt", RichTextBoxStreamType::PlainText);
		     textBox1->Text = ((int)vidurkis).ToString();
		 }
private: System::Void apieToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ::DialogResult result = dialog->ShowDialog(this);
		 }
private: System::Void iðeitiToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void nuskaitytiToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
         openFileDialog1->DefaultExt = ".txt";
         openFileDialog1->Filter = "TXT failai|*.txt";
         if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
         openFileDialog1->FileName->Length > 0) {
         String^ dfv;
         dfv = openFileDialog1->FileName;
         richTextBox1->LoadFile(dfv, RichTextBoxStreamType::PlainText);
         string dfvs;
         StringTostring(dfv, dfvs);
		      ofstream rez(Crez.c_str());
              rez.close();
              Duomenys(info, dfvs);
			  Isvesti(info); 
			  richTextBox1->LoadFile("Rezultatai.txt", RichTextBoxStreamType::PlainText);
			  skaièiuotiToolStripMenuItem->Enabled = true;
   }

		 }
private: System::Void iðsaugotiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Inicializuoja saveFileDialog vaizdà
   saveFileDialog1->DefaultExt = ".txt";
   saveFileDialog1->Filter = "TXT failai|*.txt";

   // Patikrina, ar vartotojas pasirinko failà ið SaveFileDialog?
   if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
       saveFileDialog1->FileName->Length > 0) {
      String^ rfv;   // rezultatø failo vardas (String ^)
      rfv = saveFileDialog1->FileName;
      // Rezultatø failo vardas rfv (Sting ^) konvertuojamas á rfvs (string)
      string rfvs;   // rezultatø failo vardas (string)
      StringTostring(rfv, rfvs);
      // Sukuriamas tuðèias rezultatø failas
      ofstream fr(rfvs.c_str());
      fr.close();
      // Atliekami veiksmai su failu rfvs (pvz.: rezultatø spausdinimas)
      // ...
   }
		 }
};
}

