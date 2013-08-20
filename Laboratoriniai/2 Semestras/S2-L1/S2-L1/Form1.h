#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Mokslininkai.h"
#include "Fondas.h"

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

void Duomenys(Fondas * F)
{
  ifstream duom(Cduom.c_str());
  string kod, pav, vard;
  double indelis[Mokslininkai::Cpremijos];
  double p[Fondas::Cpremijos];
  F->DetiKiek(0);
  for (int i = 0; i < Fondas::Cpremijos; i++)
	  duom >> p[i];
  for (int i = 0; i < Fondas::Cpremijos; i++)
    F->DetiP(p[i], i);
  while(!duom.eof()) {     
	  getline (duom, kod, ',');
	  getline (duom, pav, ',');
	  getline (duom, vard, ',');
	  for (int i=0; i<Mokslininkai::Cpremijos; i++)
        duom >> indelis[i];
      F->Deti(Mokslininkai(kod, pav, vard, indelis));
	  F->DetiKiek(F->Kiek() + 1);
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

   for (int i = 0;  i < F->Kiek(); i++)
       rez << F->Imti(i).Spausdinti();
   rez << endl << "--------------------------------------\n\n\n";
  rez.close();
}
//-----------------------------------------------------
void Apskaiciavimas(Fondas * F, Fondas * R)
{
	R->DetiKiek(0);
	for (int i = 0; i < Fondas::Cpremijos; i++)
		R->DetiP(F->ImtiP(i), i);
	for (int i = 0; i < F->Kiek(); i++){
		R->Deti(F->Imti(i));
	    R->DetiKiek(R->Kiek() + 1);
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
	for (int i = 0;  i < R->Kiek(); i++)
       rez << R->Imti(i).SpausdintiPapildomai();
	rez << endl;
	rez << "-----------------------------------------------------------------------------------------\n";
	rez.close();
}
//----------------------------------------------------
double Vidurkiai(Fondas * R, Fondas * U)
{
	double PremijuV = 0;
	U->DetiKiek(0);
	for (int i = 0; i < R->Kiek(); i++)
		PremijuV += R->Imti(i).ImtiS();
	PremijuV  = PremijuV / R->Kiek();
	for (int i = 0; i < R->Kiek(); i++)
		if (R->Imti(i).ImtiS() < PremijuV)
		{
			U->Deti(R->Imti(i));
			U->DetiKiek(U->Kiek() + 1);
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
		}
	private: Fondas *info, *infoc, *infoc2; 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  nuskaitytiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  iðeitiToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::ToolStripMenuItem^  skaièiuotiToolStripMenuItem;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;


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
			this->skaièiuotiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->iðeitiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->nuskaitytiToolStripMenuItem, 
				this->skaièiuotiToolStripMenuItem, this->iðeitiToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(764, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::menuStrip1_ItemClicked);
			// 
			// nuskaitytiToolStripMenuItem
			// 
			this->nuskaitytiToolStripMenuItem->Name = L"nuskaitytiToolStripMenuItem";
			this->nuskaitytiToolStripMenuItem->Size = System::Drawing::Size(72, 20);
			this->nuskaitytiToolStripMenuItem->Text = L"Nuskaityti";
			this->nuskaitytiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::nuskaitytiToolStripMenuItem_Click);
			// 
			// skaièiuotiToolStripMenuItem
			// 
			this->skaièiuotiToolStripMenuItem->Enabled = false;
			this->skaièiuotiToolStripMenuItem->Name = L"skaièiuotiToolStripMenuItem";
			this->skaièiuotiToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->skaièiuotiToolStripMenuItem->Text = L"Skaièiuoti";
			this->skaièiuotiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::skaièiuotiToolStripMenuItem_Click);
			// 
			// iðeitiToolStripMenuItem
			// 
			this->iðeitiToolStripMenuItem->Name = L"iðeitiToolStripMenuItem";
			this->iðeitiToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->iðeitiToolStripMenuItem->Text = L"Iðeiti";
			this->iðeitiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::iðeitiToolStripMenuItem_Click);
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
              ofstream rez(Crez.c_str());
              rez.close();
			  ofstream rez2(Crez2.c_str());
              rez2.close();
			  ofstream rez3(Crez3.c_str());
              rez3.close();
              Duomenys(info);
			  Isvesti(info); 
			  richTextBox1->LoadFile("Rezultatai.txt", RichTextBoxStreamType::PlainText);
			  skaièiuotiToolStripMenuItem->Enabled = true;
			 }
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void skaièiuotiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 Apskaiciavimas(info, infoc);
		 double vidurkis = Vidurkiai(infoc, infoc2);
		 RezultatuIsvedimas(infoc, Crez2);
		 RezultatuIsvedimas(infoc2, Crez3);
		 richTextBox2->LoadFile("Rezultatai2.txt", RichTextBoxStreamType::PlainText);
		 richTextBox3->LoadFile("Rezultatai3.txt", RichTextBoxStreamType::PlainText);
		 textBox1->Text = ((int)vidurkis).ToString();
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

