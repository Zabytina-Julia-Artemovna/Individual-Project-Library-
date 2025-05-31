#pragma once
#include "../Include/tvector.h"
#include "../Library_classes/book.h"
#include "../Library_classes/fio.h"
#include "../Library_classes/post.h"
#include "../Library_classes/passport_data.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(133, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(361, 69);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Библиотека";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(317, 431);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(177, 139);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(65, 466);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(177, 139);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Войти как заведующий библиотекой";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(122, 166);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 52);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Логин";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(136, 277);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(174, 52);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Пароль";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(223, 221);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(238, 38);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(223, 341);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(238, 38);
			this->textBox2->TabIndex = 6;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 653);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text != "librarian123" || textBox2->Text != "qwerty") {
			MessageBox::Show("Неверный логин и/или пароль", "Ошибка");
		}
		else {

			this->Controls->Clear();
			Button^ book_button = gcnew Button();
			Button^ readers_button = gcnew Button();
			Button^ workers_button = gcnew Button();

			book_button->Text = "Книги";
			book_button->Location = Point(50, 50);
			book_button->Size = System::Drawing::Size(100, 50);

			readers_button->Text = "Читатели";
			readers_button->Location = Point(50, 120);
			readers_button->Size = System::Drawing::Size(100, 50);

			workers_button->Text = "Сотрудники";
			workers_button->Location = Point(50, 190);
			workers_button->Size = System::Drawing::Size(100, 50);

			this->Controls->Add(book_button);
			this->Controls->Add(readers_button);
			this->Controls->Add(workers_button);

		}

	
	}
};
}
