#pragma once

#include <string>

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for ECourse
	/// </summary>
	public ref class ECourse : public System::Windows::Forms::Form
	{
	public:
		ECourse(void)
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
		~ECourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonAddCourse;
	private: System::Windows::Forms::Button^ buttonDeleteCourse;
	private: System::Windows::Forms::DataGridView^ dataGridViewCourses;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonAddCourse = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteCourse = (gcnew System::Windows::Forms::Button());
			this->dataGridViewCourses = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCourses))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(47, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(188, 45);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"Enter Course Name";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->textBox1->Location = System::Drawing::Point(47, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(188, 20);
			this->textBox1->TabIndex = 1;
			// 
			// buttonAddCourse
			// 
			this->buttonAddCourse->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->buttonAddCourse->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAddCourse->Location = System::Drawing::Point(42, 106);
			this->buttonAddCourse->Name = L"buttonAddCourse";
			this->buttonAddCourse->Size = System::Drawing::Size(96, 43);
			this->buttonAddCourse->TabIndex = 2;
			this->buttonAddCourse->Text = L"Add Course";
			this->buttonAddCourse->UseVisualStyleBackColor = false;
			this->buttonAddCourse->Click += gcnew System::EventHandler(this, &ECourse::buttonAddCourse_Click);
			// 
			// buttonDeleteCourse
			// 
			this->buttonDeleteCourse->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->buttonDeleteCourse->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDeleteCourse->Location = System::Drawing::Point(144, 106);
			this->buttonDeleteCourse->Name = L"buttonDeleteCourse";
			this->buttonDeleteCourse->Size = System::Drawing::Size(91, 43);
			this->buttonDeleteCourse->TabIndex = 3;
			this->buttonDeleteCourse->Text = L"Delete Course";
			this->buttonDeleteCourse->UseVisualStyleBackColor = false;
			this->buttonDeleteCourse->Click += gcnew System::EventHandler(this, &ECourse::buttonDeleteCourse_Click);
			// 
			// dataGridViewCourses
			// 
			this->dataGridViewCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCourses->Location = System::Drawing::Point(12, 174);
			this->dataGridViewCourses->Name = L"dataGridViewCourses";
			this->dataGridViewCourses->Size = System::Drawing::Size(260, 144);
			this->dataGridViewCourses->TabIndex = 4;
			// 
			// ECourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 330);
			this->Controls->Add(this->dataGridViewCourses);
			this->Controls->Add(this->buttonDeleteCourse);
			this->Controls->Add(this->buttonAddCourse);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"ECourse";
			this->Text = L"ECourse";
			this->Load += gcnew System::EventHandler(this, &ECourse::ECourse_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCourses))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ECourse_Load(System::Object^ sender, System::EventArgs^ e) {
		// Load courses into the DataGridView
		LoadCourses();
	}
		   // Function to load courses from the database into the DataGridView
	private: System::Void LoadCourses() {
		String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
		String^ query = "SELECT * FROM Courses";
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(command);
		DataTable^ dataTable = gcnew DataTable();

		try {
			connection->Open();
			adapter->Fill(dataTable);
			dataGridViewCourses->DataSource = dataTable;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		finally {
			connection->Close();
		}
	}

		   // Event handler for the Add button click
	private: System::Void buttonAddCourse_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ courseName = textBox1->Text;
		String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
		String^ query = "INSERT INTO Courses (CourseName) VALUES (@CourseName)";
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		command->Parameters->AddWithValue("@CourseName", courseName);

		try {
			connection->Open();
			command->ExecuteNonQuery();
			MessageBox::Show("Course added successfully");
			// Reload courses after addition
			LoadCourses();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		finally {
			connection->Close();
		}
	}

		   // Event handler for the Delete button click
	private: System::Void buttonDeleteCourse_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ courseName = textBox1->Text;
		String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
		String^ query = "DELETE FROM Courses WHERE CourseName = @CourseName";
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		SqlCommand^ command = gcnew SqlCommand(query, connection);
		command->Parameters->AddWithValue("@CourseName", courseName);

		try {
			connection->Open();
			int rowsAffected = command->ExecuteNonQuery();
			if (rowsAffected > 0) {
				MessageBox::Show("Course deleted successfully");
				// Reload courses after deletion
				LoadCourses();
			}
			else {
				MessageBox::Show("Course not found");
			}
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
