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
    public ref class TeacherException : public Exception
    {
    public:
        TeacherException(String^ message) : Exception(message) {}
    };

    // Derived class for specific exceptions
    public ref class TeacherDatabaseException : public TeacherException
    {
    public:
        TeacherDatabaseException(String^ message) : TeacherException(message) {}
    };

    /// <summary>
    /// Summary for Teacher
    /// </summary>
    public ref class Teacher : public System::Windows::Forms::Form
    {
    public:
        Teacher(void)
        {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Teacher()
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
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
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
            this->dataGridView1->Location = System::Drawing::Point(12, 92);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(645, 178);
            this->dataGridView1->TabIndex = 0;
            // 
            // richTextBox1
            // 
            this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(257, 36);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(183, 40);
            this->richTextBox1->TabIndex = 3;
            this->richTextBox1->Text = L"Teacher Timetable";
            // 
            // Teacher
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(669, 287);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"Teacher";
            this->Text = L"Teacher";
            this->Load += gcnew System::EventHandler(this, &Teacher::Teacher_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void Teacher_Load(System::Object^ sender, System::EventArgs^ e) {
        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        String^ query = "SELECT " +
            "t.tName AS TeacherName, " +
            "c.CourseName AS CourseName, " +
            "r.RoomNumber AS RoomNumber, " +
            "tt.ClassDay, " +
            "tt.StartTime, " +
            "tt.EndTime " +
            "FROM Teachers t " +
            "INNER JOIN Courses c ON t.TeacherID = c.TeacherID " +
            "INNER JOIN StudentCourses sc ON c.CourseID = sc.CourseID " +
            "INNER JOIN Timetables tt ON sc.StudentCourseID = tt.StudentCourseID " +
            "INNER JOIN Rooms r ON tt.RoomID = r.RoomID " +
            "ORDER BY t.tName, tt.ClassDay, tt.StartTime";

        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
        DataTable^ dataTable = gcnew DataTable();

        try {
            connection->Open();
            adapter->Fill(dataTable);
            dataGridView1->DataSource = dataTable;
        }
        catch (SqlException^ ex) {
            throw gcnew TeacherDatabaseException("Database error: " + ex->Message);
        }
        catch (Exception^ ex) {
            throw gcnew TeacherException("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }
    };
}
