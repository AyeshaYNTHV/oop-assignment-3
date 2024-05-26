#pragma once
#include "Student.h"
#include "Room.h"
#include "Teacher.h"
#include "Course.h"
#include "EStudent.h"
#include "ETeacher.h"
#include "ERoom.h"
#include "ECourse.h"

namespace Project3 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
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
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::RichTextBox^ richTextBox2;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::RichTextBox^ richTextBox3;
    protected:

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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // richTextBox1
            // 
            this->richTextBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(106, 12);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(357, 45);
            this->richTextBox1->TabIndex = 2;
            this->richTextBox1->Text = L"BU H-11 TIMETABLE MANAGEMENT";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(12, 116);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(163, 63);
            this->button1->TabIndex = 3;
            this->button1->Text = L"Student Timetable";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(12, 185);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(163, 66);
            this->button2->TabIndex = 4;
            this->button2->Text = L"Teacher Timetable";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button3->Font = (gcnew System::Drawing::Font(L"Sitka Text", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button3->Location = System::Drawing::Point(12, 257);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(163, 64);
            this->button3->TabIndex = 5;
            this->button3->Text = L"Rooms Timetable";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button4->Font = (gcnew System::Drawing::Font(L"Sitka Text", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button4->ForeColor = System::Drawing::SystemColors::ControlText;
            this->button4->Location = System::Drawing::Point(12, 327);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(163, 60);
            this->button4->TabIndex = 6;
            this->button4->Text = L"Course Timetable";
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            // 
            // richTextBox2
            // 
            this->richTextBox2->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox2->Location = System::Drawing::Point(73, 75);
            this->richTextBox2->Name = L"richTextBox2";
            this->richTextBox2->Size = System::Drawing::Size(48, 35);
            this->richTextBox2->TabIndex = 7;
            this->richTextBox2->Text = L"View";
            // 
            // button5
            // 
            this->button5->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button5->Font = (gcnew System::Drawing::Font(L"Sitka Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button5->Location = System::Drawing::Point(345, 116);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(154, 65);
            this->button5->TabIndex = 8;
            this->button5->Text = L"Edit Student";
            this->button5->UseVisualStyleBackColor = false;
            this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);

            // 
            // button6
            // 
            this->button6->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button6->Font = (gcnew System::Drawing::Font(L"Sitka Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button6->Location = System::Drawing::Point(345, 187);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(155, 64);
            this->button6->TabIndex = 9;
            this->button6->Text = L"Edit Teacher";
            this->button6->UseVisualStyleBackColor = false;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);

            // 
            // button7
            // 
            this->button7->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button7->Font = (gcnew System::Drawing::Font(L"Sitka Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button7->ForeColor = System::Drawing::SystemColors::WindowText;
            this->button7->Location = System::Drawing::Point(345, 257);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(154, 63);
            this->button7->TabIndex = 10;
            this->button7->Text = L"Edit Room";
            this->button7->UseVisualStyleBackColor = false;
            this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
            // 
            // button8
            // 
            this->button8->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->button8->Font = (gcnew System::Drawing::Font(L"Sitka Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button8->Location = System::Drawing::Point(345, 331);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(153, 55);
            this->button8->TabIndex = 11;
            this->button8->Text = L"Edit Course";
            this->button8->UseVisualStyleBackColor = false;
            this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
            // 
            // richTextBox3
            // 
            this->richTextBox3->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox3->Location = System::Drawing::Point(383, 75);
            this->richTextBox3->Name = L"richTextBox3";
            this->richTextBox3->Size = System::Drawing::Size(50, 34);
            this->richTextBox3->TabIndex = 12;
            this->richTextBox3->Text = L"Edit";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(556, 410);
            this->Controls->Add(this->richTextBox3);
            this->Controls->Add(this->button8);
            this->Controls->Add(this->button7);
            this->Controls->Add(this->button6);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->richTextBox2);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->richTextBox1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        Student^ s = gcnew Student();
        s->Show();
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        Teacher^ t = gcnew Teacher();
        t->Show();
    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        Room^ r = gcnew Room();
        r->Show();
    }
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
        Course^ c = gcnew Course();
        c->Show();
    }
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
        EStudent^ es = gcnew EStudent();
        es->Show();
    }

    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		ETeacher^ et = gcnew ETeacher();
		et->Show();
    }

    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		ERoom^ er = gcnew ERoom();
		er->Show();
    }

	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		ECourse^ ec = gcnew ECourse();
		ec->Show();
    }
    };
}
