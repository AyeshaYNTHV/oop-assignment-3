#pragma once

#include <exception>

namespace Project3 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    // Base class for exception handling
    public ref class StudentException : public Exception
    {
    public:
        StudentException(String^ message) : Exception(message) {}
    };

    // Derived class for specific exceptions
    public ref class StudentDatabaseException : public StudentException
    {
    public:
        StudentDatabaseException(String^ message) : StudentException(message) {}
    };

    public ref class Student : public System::Windows::Forms::Form
    {
    public:
        Student(void)
        {
            InitializeComponent();
        }

    protected:
        ~Student()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::RichTextBox^ richTextBox1;
        System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
               this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
               this->SuspendLayout();
               // 
               // dataGridView1
               // 
               this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridView1->Location = System::Drawing::Point(12, 107);
               this->dataGridView1->Name = L"dataGridView1";
               this->dataGridView1->Size = System::Drawing::Size(718, 309);
               this->dataGridView1->TabIndex = 0;
               // 
               // richTextBox1
               // 
               this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
               this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->richTextBox1->Location = System::Drawing::Point(290, 34);
               this->richTextBox1->Name = L"richTextBox1";
               this->richTextBox1->Size = System::Drawing::Size(157, 40);
               this->richTextBox1->TabIndex = 3;
               this->richTextBox1->Text = L"Student Timetable";
               // 
               // Student
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(742, 428);
               this->Controls->Add(this->richTextBox1);
               this->Controls->Add(this->dataGridView1);
               this->ForeColor = System::Drawing::SystemColors::AppWorkspace;
               this->Name = L"Student";
               this->Text = L"Student";
               this->Load += gcnew System::EventHandler(this, &Student::Student_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
               this->ResumeLayout(false);

           }
#pragma endregion

    private: System::Void Student_Load(System::Object^ sender, System::EventArgs^ e) {
        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        String^ query = "SELECT " +
            "s.sName AS StudentName, " +
            "c.CourseName AS CourseName, " +
            "t.tName AS TeacherName, " +
            "r.RoomNumber AS RoomNumber, " +
            "tt.ClassDay, " +
            "tt.StartTime, " +
            "tt.EndTime " +
            "FROM Students s " +
            "INNER JOIN StudentCourses sc ON s.StudentID = sc.StudentID " +
            "INNER JOIN Courses c ON sc.CourseID = c.CourseID " +
            "INNER JOIN Teachers t ON c.TeacherID = t.TeacherID " +
            "INNER JOIN Timetables tt ON sc.StudentCourseID = tt.StudentCourseID " +
            "INNER JOIN Rooms r ON tt.RoomID = r.RoomID " +
            "ORDER BY s.sName, tt.ClassDay, tt.StartTime";

        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
        DataTable^ dataTable = gcnew DataTable();

        try {
            connection->Open();
            adapter->Fill(dataTable);
            dataGridView1->DataSource = dataTable;
        }
        catch (SqlException^ ex) {
            throw gcnew StudentDatabaseException("Database error: " + ex->Message);
        }
        catch (Exception^ ex) {
            throw gcnew StudentException("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }
    };
}
