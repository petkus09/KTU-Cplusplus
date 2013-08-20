#pragma once
#include <windows.h>       // Èia yra failø iðrinkimui reikalingi tipai
#include <strsafe.h>       // TCHAR[] funkcijos
#include <vcclr.h>
#include "Medis.h"
const string Crez = "Rezultatai.txt";
const string Crez2 = "Rezultatai2.txt";

namespace S2L5 {

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
void Atrinkimas(Medis * info, SarasuGrupe * galutinis, RichTextBox^  richTextBox2, TextBox^  textBox4)
{
	double vidurkis = info->VyruVidurkis();
	stringstream ss;
	ss << right << setw(4) << vidurkis;
	String ^sak = gcnew String((ss.str()).c_str()); // string to String
	textBox4->Text = sak;
	info->VaikinuAtrinkimas(galutinis, vidurkis);
	ofstream rez(Crez2.c_str());
	rez.close();
	galutinis->Rikiavimas();
	galutinis->Isvedimas(Crez2);
	galutinis->Isvedimas(Crez);
	richTextBox2->LoadFile("Rezultatai2.txt", RichTextBoxStreamType::PlainText);
}
//----------------------------------------------------
void PapildomasNuskaitymas(TCHAR Cduom[MAX_PATH], SarasuGrupe * papild)
{
	string pavarde, vardas;
	int u[5];
	ifstream duom(Cduom);
	while (!duom.eof())
	{
	  getline (duom, pavarde, ',');
	  getline (duom, vardas, ',');
	  for (int i = 0; i < 5; i++)
		  duom >> u[i];
	  duom.ignore();
	  papild->DetiIPabaiga(Studentas(pavarde, vardas, "", "", "", 5, u, ""));
	}
	duom.close();
}
//----------------------------------------------------
void Nuskaitymas(TCHAR Cduom[MAX_PATH], Medis * info)
{
	string fakultetas, pavarde, vardas, grupe, metai, lytis;
	int u[1];
	u[0] = 0;
	ifstream duom(Cduom);
	Fakultetas * F = new Fakultetas;
	getline (duom, fakultetas);
	F->DetiInfo(fakultetas);
	while (!duom.eof())
	{
	  getline (duom, pavarde, ',');
	  getline (duom, vardas, ',');
	  duom >> grupe >> metai >> lytis;
	  duom.ignore();
	  F->DetiIPabaiga(Studentas(pavarde, vardas, grupe, metai, lytis, 0, u, fakultetas));
	}
	info->DetiFakulteta(F);
	duom.close();
}
//----------------------------------------------------
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
			info = new Medis;
			papild = new SarasuGrupe;
			galutinis = new SarasuGrupe;
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
			delete papild;
			delete galutinis;
		}
	private: Medis *info;
	private: SarasuGrupe * papild;
	private: SarasuGrupe * galutinis;
	private: System::Windows::Forms::Label^  label1;
	protected: 

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox4;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(14, 62);
			this->label1->MaximumSize = System::Drawing::Size(400, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(400, 0);
			this->label1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(63, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"*Duomenys.txt";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Atverti Failus";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Ðablonai:";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 14;
			this->listBox1->Location = System::Drawing::Point(9, 130);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(822, 116);
			this->listBox1->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(756, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Iðeiti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 60);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Papildomi failai:";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(197, 54);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Atverti Failus";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(91, 57);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"*Pagalbinis.txt";
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(14, 118);
			this->label7->MaximumSize = System::Drawing::Size(400, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(400, 0);
			this->label7->TabIndex = 11;
			// 
			// listBox2
			// 
			this->listBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->ItemHeight = 14;
			this->listBox2->Location = System::Drawing::Point(9, 273);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(822, 32);
			this->listBox2->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 107);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Ðablonø failai:";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 249);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Papildomi failai:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(323, 55);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Jungti failus";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(845, 355);
			this->tabControl1->TabIndex = 16;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->listBox2);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(837, 329);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Pradþia";
			this->tabPage1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(837, 329);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Duomenys";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->richTextBox1->Location = System::Drawing::Point(6, 6);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(825, 317);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label9);
			this->tabPage3->Controls->Add(this->textBox4);
			this->tabPage3->Controls->Add(this->textBox3);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->richTextBox2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(837, 329);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Rezultatai";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(284, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(70, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Vyrø vidurkis:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(360, 7);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(616, 8);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(218, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(3, 5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Skaièiuoti";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(186)));
			this->richTextBox2->Location = System::Drawing::Point(3, 31);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(831, 293);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(869, 370);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"S2-L5";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox1->Text == L"") {
               MessageBox::Show (L"Áraðykite ðablonà", L"Neávesta reikðmë", MessageBoxButtons::OK, MessageBoxIcon::Error);
               return;
             }

             if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && folderBrowserDialog1->SelectedPath ->Length > 0) {
               listBox1->Items->Clear();             // Iðvalome listBox1 komponentà

               WIN32_FIND_DATA ffd;                  // Paieðkai reikalingi ...
               HANDLE hFind = INVALID_HANDLE_VALUE;  // ... tarnybiniai kintamieji

               // Funkcijai PtrToStringChars() reikalingas #include <vcclr.h>
               pin_ptr<const wchar_t> pletinys = PtrToStringChars(textBox1->Text);

               TCHAR katalogas[MAX_PATH];        // Saugosime kelià iki duomenø failø
               TCHAR paieskosSablonas[MAX_PATH]; // Saugosime paieðkos ðablonà
               TCHAR pilnasVardas[MAX_PATH];     // Saugosime konkretaus duomenø failo pilnà (su keliu) vardà

               // Sudarome kelià á katalogà, kuriame sudëti duomenø failai
               pin_ptr<const wchar_t> pasirinktasKatalogas = PtrToStringChars(folderBrowserDialog1->SelectedPath);
               StringCchCopy(katalogas, MAX_PATH, pasirinktasKatalogas);
               StringCchCat(katalogas, MAX_PATH, TEXT("\\"));
               label1->Text = gcnew String(katalogas);

               // Sudarome paieðkos ðablonà
               StringCchCopy(paieskosSablonas, MAX_PATH, katalogas);
               StringCchCat(paieskosSablonas, MAX_PATH, pletinys);

               // Atliekame paieðkà
               hFind = FindFirstFile(paieskosSablonas, &ffd);
               if (hFind == INVALID_HANDLE_VALUE) { // Tikriname, gal nëra nei vieno ðablonà atitinkanèio failo
                 listBox1->Items->Add(gcnew String(L"Ðablonà atitinkanèiø failø nerasta."));
                 return;
               }
               do {
                 // Sudarome pilnà (su keliu) rasto duomenø failo vardà
                 StringCchCopy(pilnasVardas, MAX_PATH, katalogas);
                 StringCchCat(pilnasVardas, MAX_PATH, ffd.cFileName);
                 
                 // naudojame failo vardà, kuris saugomas kintamajame pilnasVardas,
                 // pavyzdþiui, ifstream fd(pilnasVardas);
				 Nuskaitymas(pilnasVardas, info);

                 // ðioje programoje tiesiog iðvedame listBox1 komponente
                 listBox1->Items->Add(String::Format(L"{0}", gcnew String(pilnasVardas)));
               } while (FindNextFile(hFind, &ffd) != 0);
               FindClose(hFind);
             }
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox2->Text == L"") {
               MessageBox::Show (L"Áraðykite papildomà failà", L"Neávesta reikðmë", MessageBoxButtons::OK, MessageBoxIcon::Error);
               return;
             }

             if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && folderBrowserDialog1->SelectedPath ->Length > 0) {
               listBox2->Items->Clear();             // Iðvalome listBox1 komponentà

               WIN32_FIND_DATA ffd;                  // Paieðkai reikalingi ...
               HANDLE hFind = INVALID_HANDLE_VALUE;  // ... tarnybiniai kintamieji

               // Funkcijai PtrToStringChars() reikalingas #include <vcclr.h>
               pin_ptr<const wchar_t> pletinys = PtrToStringChars(textBox2->Text);

               TCHAR katalogas[MAX_PATH];        // Saugosime kelià iki duomenø failø
               TCHAR paieskosSablonas[MAX_PATH]; // Saugosime paieðkos ðablonà
               TCHAR pilnasVardas[MAX_PATH];     // Saugosime konkretaus duomenø failo pilnà (su keliu) vardà

               // Sudarome kelià á katalogà, kuriame sudëti duomenø failai
               pin_ptr<const wchar_t> pasirinktasKatalogas = PtrToStringChars(folderBrowserDialog1->SelectedPath);
               StringCchCopy(katalogas, MAX_PATH, pasirinktasKatalogas);
               StringCchCat(katalogas, MAX_PATH, TEXT("\\"));
               label7->Text = gcnew String(katalogas);

               // Sudarome paieðkos ðablonà
               StringCchCopy(paieskosSablonas, MAX_PATH, katalogas);
               StringCchCat(paieskosSablonas, MAX_PATH, pletinys);

               // Atliekame paieðkà
               hFind = FindFirstFile(paieskosSablonas, &ffd);
               if (hFind == INVALID_HANDLE_VALUE) { // Tikriname, gal nëra nei vieno ðablonà atitinkanèio failo
                 listBox2->Items->Add(gcnew String(L"Papildomà failà atitinkanèiø failø nerasta."));
                 return;
               }
               do {
                 // Sudarome pilnà (su keliu) rasto duomenø failo vardà
                 StringCchCopy(pilnasVardas, MAX_PATH, katalogas);
                 StringCchCat(pilnasVardas, MAX_PATH, ffd.cFileName);
                 
                 // naudojame failo vardà, kuris saugomas kintamajame pilnasVardas,
                 // pavyzdþiui, ifstream fd(pilnasVardas);
				 PapildomasNuskaitymas(pilnasVardas, papild);
                 // ðioje programoje tiesiog iðvedame listBox1 komponente
                 listBox2->Items->Add(String::Format(L"{0}", gcnew String(pilnasVardas)));
               } while (FindNextFile(hFind, &ffd) != 0);
               FindClose(hFind);
             }
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 info->DuomenuPapildymas(papild);
			 info->Isvesti(Crez);
			 richTextBox1->LoadFile("Rezultatai.txt", RichTextBoxStreamType::PlainText);
		 }
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 String ^sak = gcnew String(info->SkaiciuotiLyti().c_str()); // string to String
			 textBox3->Text = sak;
			 Atrinkimas(info, galutinis, richTextBox2, textBox4);
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}