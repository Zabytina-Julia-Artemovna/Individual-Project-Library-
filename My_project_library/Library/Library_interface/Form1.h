#pragma once

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
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(167, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(471, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"БИБЛИОТЕКА";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(173, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 42);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Логин";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(173, 255);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(148, 42);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Пароль";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(180, 190);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(263, 47);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(170, 328);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(263, 47);
			this->textBox2->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(364, 456);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(176, 100);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(24, 528);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(176, 100);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Войти как заведующий библиотеки";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 661);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "" || textBox2->Text == "") {
			MessageBox::Show("Заполните все поля", "Ошибка");
		}
		else {
			if (textBox1->Text != "librarian_123") {
				MessageBox::Show("Неверный логин", "Ошибка");
			}
			if (textBox2->Text != "qwerty") {
				MessageBox::Show("Неверный пароль", "Ошибка");
			}
		}
		if (textBox1->Text == "librarian_123" || textBox2->Text == "qwerty") {
			for each (Control ^ control in this->Controls)
			{
				control->Visible = false;
			}

			Button^ button_readers = gcnew Button();
			button_readers->Text = "Читатели";
			button_readers->Location = Point(300, 150);
			button_readers->Size = Drawing::Size(200, 50);
			button_readers->Font = gcnew Drawing::Font("Microsoft Sans Serif", 12);
			this->Controls->Add(button_readers);

			Button^ button_books = gcnew Button();
			button_books->Text = "Книги";
			button_books->Location = Point(300, 220);
			button_books->Size = Drawing::Size(200, 50);
			button_books->Font = gcnew Drawing::Font("Microsoft Sans Serif", 12);
			this->Controls->Add(button_books);
			button_books->Click += gcnew EventHandler(this, &Form1::button_books_Click);


			Button^ button_staff = gcnew Button();
			button_staff->Text = "Сотрудники";
			button_staff->Location = Point(300, 290);
			button_staff->Size = Drawing::Size(200, 50);
			button_staff->Font = gcnew Drawing::Font("Microsoft Sans Serif", 12);
			this->Controls->Add(button_staff);
		}
	}
		   void button_books_Click(Object^ sender, EventArgs^ e) {
			   Button^ button = gcnew Button();
			   button->Text = "Книги";
			   button->Location = Point(300, 220);
			   button->Size = Drawing::Size(200, 50);
			   button->Font = gcnew Drawing::Font("Microsoft Sans Serif", 12);
			   this->Controls->Add(button);
		   }

	};
}
