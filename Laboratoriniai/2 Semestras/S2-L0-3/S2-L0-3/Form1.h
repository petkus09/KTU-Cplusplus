#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Fakultetas.h"
#include "dialogas.h"

const char CDfv[] = "U1.txt";
const char CRfv[] = "Rezultatai.txt";


namespace S2L03 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void Duomenys(Fakultetas * R)
{
  ifstream fd(CDfv);
  bool yra = true;
  string pv, vd, gr;
  int np, pz [Studentas::Cpaz];
  while(!fd.eof() && yra) {         // kol yra duomenø ir ji telpa á masyvà
    getline(fd, pv, ',');
    fd >> ws;
    getline(fd, vd, ',');
    fd >> ws;
    getline(fd, gr, ',');
    fd >> np;
    for (int i=0; i<np; i++)
      fd >> pz[i];
    fd.ignore();
    if(!fd.eof() && (R->Kiek() < Fakultetas::CMax ) )
       R->Deti(Studentas(pv, vd, gr, np, pz));
    else 
       yra = false;
  }
  fd.close();
}
//-----------------------------------------------------
// Spausdinami objekto R duomenys
void Spausdinti(Fakultetas * R, int reik)
{
   ofstream fr(CRfv, ios::app);
   fr << "Ávesta reikðmë " << reik << endl;
   fr << " Pavarde    Vardas    Grupe   Pazymiai \n";
   fr << "------------------------------------------\n";
   for (int i = 0;  i < R->Kiek(); i++)
     fr << R->Imti(i).Spausdinti();
   fr << "------------------------------------------\n\n\n";
  fr.close();
}
//-----------------------------------------------------
// Kopijuojami pirmunai is objekto D i objektà R
void Kurti(Fakultetas * D, Fakultetas * R)
{
   for (int i = 0;  i < D->Kiek(); i++)
     if (!D->Imti(i))
      ;
     else
      R->Deti(D->Imti(i));
}


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
			info = new Fakultetas;
	        infoc = new Fakultetas;
			dialog = gcnew dialogas;

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
	private: Fakultetas *info, *infoc;    // duomenys ir rezultatai
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  failasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  skaitytiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redaguotiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  skaièiuotiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  baigtiToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		dialogas ^dialog;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->failasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->skaitytiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redaguotiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->skaièiuotiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->baigtiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->failasToolStripMenuItem, 
				this->redaguotiToolStripMenuItem, this->baigtiToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(401, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// failasToolStripMenuItem
			// 
			this->failasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->skaitytiToolStripMenuItem});
			this->failasToolStripMenuItem->Name = L"failasToolStripMenuItem";
			this->failasToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->failasToolStripMenuItem->Text = L"Failas";
			// 
			// skaitytiToolStripMenuItem
			// 
			this->skaitytiToolStripMenuItem->Name = L"skaitytiToolStripMenuItem";
			this->skaitytiToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->skaitytiToolStripMenuItem->Text = L"Skaityti";
			this->skaitytiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::skaitytiToolStripMenuItem_Click);
			// 
			// redaguotiToolStripMenuItem
			// 
			this->redaguotiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->skaièiuotiToolStripMenuItem});
			this->redaguotiToolStripMenuItem->Name = L"redaguotiToolStripMenuItem";
			this->redaguotiToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->redaguotiToolStripMenuItem->Text = L"Redaguoti";
			// 
			// skaièiuotiToolStripMenuItem
			// 
			this->skaièiuotiToolStripMenuItem->Enabled = false;
			this->skaièiuotiToolStripMenuItem->Name = L"skaièiuotiToolStripMenuItem";
			this->skaièiuotiToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->skaièiuotiToolStripMenuItem->Text = L"Skaièiuoti";
			this->skaièiuotiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::skaièiuotiToolStripMenuItem_Click);
			// 
			// baigtiToolStripMenuItem
			// 
			this->baigtiToolStripMenuItem->Name = L"baigtiToolStripMenuItem";
			this->baigtiToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->baigtiToolStripMenuItem->Text = L"Baigti";
			this->baigtiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::baigtiToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->richTextBox1->Location = System::Drawing::Point(0, 27);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(401, 335);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 374);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"L0 programa";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void baigtiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
private: System::Void skaièiuotiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
             ::DialogResult result = dialog->ShowDialog(this);
			 if(result == ::DialogResult::OK){
				 int reik = dialog->imti ();
			 Spausdinti(info, reik);          // spausdinami duomenys
             Kurti(info, infoc);
             Spausdinti(infoc, reik); 
		 }
			 richTextBox1->LoadFile("Rezultatai.txt", RichTextBoxStreamType::PlainText);
		 }
private: System::Void skaitytiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            ofstream fr(CRfv);
            fr.close();
            Duomenys(info);// skaitomi duomenys
			skaièiuotiToolStripMenuItem->Enabled = true;
		 }
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

