
#include "MyForm.h"
#include "Student.h"
#include "Room.h"
#include "Teacher.h"
#include "Course.h"
#include "EStudent.h"
#include "ETeacher.h"
#include "ERoom.h"
#include "ECourse.h"

using namespace System;
using namespace System::Windows::Forms;




int main(array<String^>^ args) {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project3::MyForm form;
    Application::Run(% form);

    return 0;
}
