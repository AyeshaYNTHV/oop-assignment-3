#pragma once

namespace Project3 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    /// <summary>
    /// Summary for ETeacher
    /// </summary>
    public ref class ETeacher : public System::Windows::Forms::Form
    {
    public:
        ETeacher(void)
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
        ~ETeacher()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    private: System::Windows::Forms::TextBox^ textBoxTeacherName;
    private: System::Windows::Forms::Button^ buttonAddTeacher;
    private: System::Windows::Forms::Button^ buttonDeleteTeacher;
    private: System::Windows::Forms::DataGridView^ dataGridViewTeachers;

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
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->textBoxTeacherName = (gcnew System::Windows::Forms::TextBox());
            this->buttonAddTeacher = (gcnew System::Windows::Forms::Button());
            this->buttonDeleteTeacher = (gcnew System::Windows::Forms::Button());
            this->dataGridViewTeachers = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTeachers))->BeginInit();
            this->SuspendLayout();
            // 
            // richTextBox1
            // 
            this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(44, 26);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(199, 36);
            this->richTextBox1->TabIndex = 0;
            this->richTextBox1->Text = L"Enter Teacher Name";
            // 
            // textBoxTeacherName
            // 
            this->textBoxTeacherName->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->textBoxTeacherName->Location = System::Drawing::Point(44, 68);
            this->textBoxTeacherName->Name = L"textBoxTeacherName";
            this->textBoxTeacherName->Size = System::Drawing::Size(199, 20);
            this->textBoxTeacherName->TabIndex = 1;
            // 
            // buttonAddTeacher
            // 
            this->buttonAddTeacher->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->buttonAddTeacher->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonAddTeacher->Location = System::Drawing::Point(12, 139);
            this->buttonAddTeacher->Name = L"buttonAddTeacher";
            this->buttonAddTeacher->Size = System::Drawing::Size(101, 64);
            this->buttonAddTeacher->TabIndex = 2;
            this->buttonAddTeacher->Text = L"Add Teacher";
            this->buttonAddTeacher->UseVisualStyleBackColor = false;
            this->buttonAddTeacher->Click += gcnew System::EventHandler(this, &ETeacher::buttonAddTeacher_Click);
            // 
            // buttonDeleteTeacher
            // 
            this->buttonDeleteTeacher->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->buttonDeleteTeacher->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonDeleteTeacher->Location = System::Drawing::Point(171, 139);
            this->buttonDeleteTeacher->Name = L"buttonDeleteTeacher";
            this->buttonDeleteTeacher->Size = System::Drawing::Size(101, 64);
            this->buttonDeleteTeacher->TabIndex = 3;
            this->buttonDeleteTeacher->Text = L"Delete Teacher";
            this->buttonDeleteTeacher->UseVisualStyleBackColor = false;
            this->buttonDeleteTeacher->Click += gcnew System::EventHandler(this, &ETeacher::buttonDeleteTeacher_Click);
            // 
            // dataGridViewTeachers
            // 
            this->dataGridViewTeachers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewTeachers->Location = System::Drawing::Point(12, 220);
            this->dataGridViewTeachers->Name = L"dataGridViewTeachers";
            this->dataGridViewTeachers->Size = System::Drawing::Size(260, 150);
            this->dataGridViewTeachers->TabIndex = 4;
            // 
            // ETeacher
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 391);
            this->Controls->Add(this->dataGridViewTeachers);
            this->Controls->Add(this->buttonDeleteTeacher);
            this->Controls->Add(this->buttonAddTeacher);
            this->Controls->Add(this->textBoxTeacherName);
            this->Controls->Add(this->richTextBox1);
            this->Name = L"ETeacher";
            this->Text = L"ETeacher";
            this->Load += gcnew System::EventHandler(this, &ETeacher::ETeacher_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTeachers))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void ETeacher_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadTeachers();
    }

    private: System::Void buttonAddTeacher_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ teacherName = textBoxTeacherName->Text;

        if (String::IsNullOrWhiteSpace(teacherName)) {
            MessageBox::Show("Please enter a teacher name", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "INSERT INTO Teachers (tName) VALUES (@tName)";

        SqlCommand^ command = gcnew SqlCommand(query, connection);
        command->Parameters->AddWithValue("@tName", teacherName);

        try {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Teacher added successfully");
            LoadTeachers();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

    private: System::Void buttonDeleteTeacher_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ teacherName = textBoxTeacherName->Text;

        if (String::IsNullOrWhiteSpace(teacherName)) {
            MessageBox::Show("Please enter a teacher name", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "DELETE FROM Teachers WHERE tName = @tName";

        SqlCommand^ command = gcnew SqlCommand(query, connection);
        command->Parameters->AddWithValue("@tName", teacherName);

        try {
            connection->Open();
            int rowsAffected = command->ExecuteNonQuery();
            if (rowsAffected > 0) {
                MessageBox::Show("Teacher deleted successfully");
            }
            else {
                MessageBox::Show("Teacher not found");
            }
            LoadTeachers();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

    private: void LoadTeachers() {
        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "SELECT * FROM Teachers";

        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
        DataTable^ dataTable = gcnew DataTable();

        try {
            connection->Open();
            adapter->Fill(dataTable);
            dataGridViewTeachers->DataSource = dataTable;
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
