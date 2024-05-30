#pragma once

namespace Project3 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class EStudent : public System::Windows::Forms::Form
    {
    public:
        EStudent(void)
        {
            InitializeComponent();
        }

    protected:
        ~EStudent()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ textBoxStudentName;
    private: System::Windows::Forms::Button^ buttonAddStudent;
    private: System::Windows::Forms::Button^ buttonDeleteStudent;
    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    private: System::Windows::Forms::DataGridView^ dataGridViewStudents;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textBoxStudentName = (gcnew System::Windows::Forms::TextBox());
            this->buttonAddStudent = (gcnew System::Windows::Forms::Button());
            this->buttonDeleteStudent = (gcnew System::Windows::Forms::Button());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->dataGridViewStudents = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->BeginInit();
            this->SuspendLayout();
            // 
            // textBoxStudentName
            // 
            this->textBoxStudentName->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->textBoxStudentName->Location = System::Drawing::Point(43, 71);
            this->textBoxStudentName->Name = L"textBoxStudentName";
            this->textBoxStudentName->Size = System::Drawing::Size(203, 20);
            this->textBoxStudentName->TabIndex = 0;
            // 
            // buttonAddStudent
            // 
            this->buttonAddStudent->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->buttonAddStudent->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonAddStudent->Location = System::Drawing::Point(12, 127);
            this->buttonAddStudent->Name = L"buttonAddStudent";
            this->buttonAddStudent->Size = System::Drawing::Size(101, 64);
            this->buttonAddStudent->TabIndex = 1;
            this->buttonAddStudent->Text = L"Add Student";
            this->buttonAddStudent->UseVisualStyleBackColor = false;
            this->buttonAddStudent->Click += gcnew System::EventHandler(this, &EStudent::buttonAddStudent_Click);
            // 
            // buttonDeleteStudent
            // 
            this->buttonDeleteStudent->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->buttonDeleteStudent->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonDeleteStudent->Location = System::Drawing::Point(171, 127);
            this->buttonDeleteStudent->Name = L"buttonDeleteStudent";
            this->buttonDeleteStudent->Size = System::Drawing::Size(101, 64);
            this->buttonDeleteStudent->TabIndex = 2;
            this->buttonDeleteStudent->Text = L"Delete Student";
            this->buttonDeleteStudent->UseVisualStyleBackColor = false;
            this->buttonDeleteStudent->Click += gcnew System::EventHandler(this, &EStudent::buttonDeleteStudent_Click);
            // 
            // richTextBox1
            // 
            this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(43, 26);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(203, 39);
            this->richTextBox1->TabIndex = 3;
            this->richTextBox1->Text = L"Enter Student Name";
            // 
            // dataGridViewStudents
            // 
            this->dataGridViewStudents->Location = System::Drawing::Point(12, 208);
            this->dataGridViewStudents->Name = L"dataGridViewStudents";
            this->dataGridViewStudents->Size = System::Drawing::Size(260, 171);
            this->dataGridViewStudents->TabIndex = 4;
            // 
            // EStudent
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 391);
            this->Controls->Add(this->dataGridViewStudents);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->buttonDeleteStudent);
            this->Controls->Add(this->buttonAddStudent);
            this->Controls->Add(this->textBoxStudentName);
            this->Name = L"EStudent";
            this->Text = L"EStudent";
            this->Load += gcnew System::EventHandler(this, &EStudent::EStudent_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void buttonAddStudent_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ studentName = textBoxStudentName->Text;

        if (String::IsNullOrWhiteSpace(studentName)) {
            MessageBox::Show("Please enter a student name", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "INSERT INTO Students (sName) VALUES (@sName)";

        SqlCommand^ command = gcnew SqlCommand(query, connection);
        command->Parameters->AddWithValue("@sName", studentName);

        try {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Student added successfully");
            LoadStudents();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

    private: System::Void buttonDeleteStudent_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ studentName = textBoxStudentName->Text;

        if (String::IsNullOrWhiteSpace(studentName)) {
            MessageBox::Show("Please enter a student name", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "DELETE FROM Students WHERE sName = @sName";

        SqlCommand^ command = gcnew SqlCommand(query, connection);
        command->Parameters->AddWithValue("@sName", studentName);

        try {
            connection->Open();
            int rowsAffected = command->ExecuteNonQuery();
            if (rowsAffected > 0) {
                MessageBox::Show("Student deleted successfully");
            }
            else {
                MessageBox::Show("Student not found");
            }
            LoadStudents();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

    private: System::Void EStudent_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadStudents();
    }

    private: void LoadStudents() {
        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "SELECT * FROM Students";

        SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(query, connection);
        DataTable^ dataTable = gcnew DataTable();

        try {
            connection->Open();
            dataAdapter->Fill(dataTable);
            dataGridViewStudents->DataSource = dataTable;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }
    };
}
