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
    public ref class CourseException : public Exception
    {
    public:
        CourseException(String^ message) : Exception(message) {}
    };

    // Derived class for specific exceptions
    public ref class CourseDatabaseException : public CourseException
    {
    public:
        CourseDatabaseException(String^ message) : CourseException(message) {}
    };

    /// <summary>
    /// Summary for Course
    /// </summary>
    public ref class Course : public System::Windows::Forms::Form
    {
    public:
        Course(void)
        {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Course()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::RichTextBox^ richTextBox1;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(12, 74);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(645, 188);
            this->dataGridView1->TabIndex = 0;
            // 
            // richTextBox1
            // 
            this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(241, 12);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(180, 43);
            this->richTextBox1->TabIndex = 1;
            this->richTextBox1->Text = L"Course Timetable";
            // 
            // Course
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(669, 278);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"Course";
            this->Text = L"Course";
            this->Load += gcnew System::EventHandler(this, &Course::Course_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void Course_Load(System::Object^ sender, System::EventArgs^ e) {
        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        String^ query = "SELECT " +
            "c.CourseName AS CourseName, " +
            "t.tName AS TeacherName, " +
            "r.RoomNumber AS RoomNumber, " +
            "tt.ClassDay, " +
            "tt.StartTime, " +
            "tt.EndTime " +
            "FROM Courses c " +
            "INNER JOIN Teachers t ON c.TeacherID = t.TeacherID " +
            "INNER JOIN StudentCourses sc ON c.CourseID = sc.CourseID " +
            "INNER JOIN Timetables tt ON sc.StudentCourseID = tt.StudentCourseID " +
            "INNER JOIN Rooms r ON tt.RoomID = r.RoomID " +
            "ORDER BY c.CourseName, tt.ClassDay, tt.StartTime";

        SqlConnection^ connection = gcnew SqlConnection(connectionString);
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
        DataTable^ dataTable = gcnew DataTable();

        try {
            connection->Open();
            adapter->Fill(dataTable);
            dataGridView1->DataSource = dataTable;
        }
        catch (SqlException^ ex) {
            throw gcnew CourseDatabaseException("Database error: " + ex->Message);
        }
        catch (Exception^ ex) {
            throw gcnew CourseException("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }
    };
}
