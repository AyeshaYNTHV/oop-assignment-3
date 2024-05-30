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
    /// Summary for ERoom
    /// </summary>
    public ref class ERoom : public System::Windows::Forms::Form
    {
    public:
        ERoom(void)
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
        ~ERoom()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    private: System::Windows::Forms::TextBox^ textBoxRoomNumber;
    private: System::Windows::Forms::Button^ buttonAddRoom;
    private: System::Windows::Forms::Button^ buttonDeleteRoom;
    private: System::Windows::Forms::DataGridView^ dataGridViewRooms;

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
            this->textBoxRoomNumber = (gcnew System::Windows::Forms::TextBox());
            this->buttonAddRoom = (gcnew System::Windows::Forms::Button());
            this->buttonDeleteRoom = (gcnew System::Windows::Forms::Button());
            this->dataGridViewRooms = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRooms))->BeginInit();
            this->SuspendLayout();
            // 
            // richTextBox1
            // 
            this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(42, 25);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(202, 38);
            this->richTextBox1->TabIndex = 0;
            this->richTextBox1->Text = L"Enter Room Number";
            // 
            // textBoxRoomNumber
            // 
            this->textBoxRoomNumber->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->textBoxRoomNumber->Location = System::Drawing::Point(42, 69);
            this->textBoxRoomNumber->Name = L"textBoxRoomNumber";
            this->textBoxRoomNumber->Size = System::Drawing::Size(202, 20);
            this->textBoxRoomNumber->TabIndex = 1;
            // 
            // buttonAddRoom
            // 
            this->buttonAddRoom->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->buttonAddRoom->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonAddRoom->Location = System::Drawing::Point(12, 139);
            this->buttonAddRoom->Name = L"buttonAddRoom";
            this->buttonAddRoom->Size = System::Drawing::Size(101, 64);
            this->buttonAddRoom->TabIndex = 2;
            this->buttonAddRoom->Text = L"Add Room";
            this->buttonAddRoom->UseVisualStyleBackColor = false;
            this->buttonAddRoom->Click += gcnew System::EventHandler(this, &ERoom::buttonAddRoom_Click);
            // 
            // buttonDeleteRoom
            // 
            this->buttonDeleteRoom->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->buttonDeleteRoom->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonDeleteRoom->Location = System::Drawing::Point(171, 139);
            this->buttonDeleteRoom->Name = L"buttonDeleteRoom";
            this->buttonDeleteRoom->Size = System::Drawing::Size(101, 64);
            this->buttonDeleteRoom->TabIndex = 3;
            this->buttonDeleteRoom->Text = L"Delete Room";
            this->buttonDeleteRoom->UseVisualStyleBackColor = false;
            this->buttonDeleteRoom->Click += gcnew System::EventHandler(this, &ERoom::buttonDeleteRoom_Click);
            // 
            // dataGridViewRooms
            // 
            this->dataGridViewRooms->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewRooms->Location = System::Drawing::Point(12, 220);
            this->dataGridViewRooms->Name = L"dataGridViewRooms";
            this->dataGridViewRooms->Size = System::Drawing::Size(260, 150);
            this->dataGridViewRooms->TabIndex = 4;
            // 
            // ERoom
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 391);
            this->Controls->Add(this->dataGridViewRooms);
            this->Controls->Add(this->buttonDeleteRoom);
            this->Controls->Add(this->buttonAddRoom);
            this->Controls->Add(this->textBoxRoomNumber);
            this->Controls->Add(this->richTextBox1);
            this->Name = L"ERoom";
            this->Text = L"ERoom";
            this->Load += gcnew System::EventHandler(this, &ERoom::ERoom_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRooms))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void ERoom_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadRooms();
    }

    private: System::Void buttonAddRoom_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ roomNumber = textBoxRoomNumber->Text;

        if (String::IsNullOrWhiteSpace(roomNumber)) {
            MessageBox::Show("Please enter a room number", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "INSERT INTO Rooms (RoomNumber) VALUES (@RoomNumber)";

        SqlCommand^ command = gcnew SqlCommand(query, connection);
        command->Parameters->AddWithValue("@RoomNumber", roomNumber);

        try {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Room added successfully");
            LoadRooms();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

    private: System::Void buttonDeleteRoom_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ roomNumber = textBoxRoomNumber->Text;

        if (String::IsNullOrWhiteSpace(roomNumber)) {
            MessageBox::Show("Please enter a room number", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "DELETE FROM Rooms WHERE RoomNumber = @RoomNumber";

        SqlCommand^ command = gcnew SqlCommand(query, connection);
        command->Parameters->AddWithValue("@RoomNumber", roomNumber);

        try {
            connection->Open();
            int rowsAffected = command->ExecuteNonQuery();
            if (rowsAffected > 0) {
                MessageBox::Show("Room deleted successfully");
            }
            else {
                MessageBox::Show("Room not found");
            }
            LoadRooms();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally {
            connection->Close();
        }
    }

    private: void LoadRooms() {
        String^ connectionString = "Data Source=DESKTOP-HIIQS0G\\MSSQLSERVER03;Initial Catalog=abcd;Integrated Security=True";
        SqlConnection^ connection = gcnew SqlConnection(connectionString);

        String^ query = "SELECT * FROM Rooms";

        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, connection);
        DataTable^ dataTable = gcnew DataTable();

        try {
            connection->Open();
            adapter->Fill(dataTable);
            dataGridViewRooms->DataSource = dataTable;
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
