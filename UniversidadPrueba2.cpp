#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

// Funcion para mover el cursor en la consola
void gotoxy(int x, int y);

// Funciones Prototipo para los menus
void menuInicio();          // Menu para seleccionar el tipo de usuario que desea ingresar al sistema
void introAnimado();        // Intro animado del proyecto
void salir();               // Texto que aparece al finalizar el programa
void ingresarAdmin();       // Funcion para ingresar como administrador
void ingresarProfesor();    // Funcion para ingresar como Profesor  
void ingresarEstudiante();  // Funcion para ingresar como estudiante

// Funciones Prototipo para el menu del administrador
void menuAdmin();                           // Menu con las opciones del administrador
void agregarEstudiantes();                  // Funcion para agregar estudiantes
void agregarProfesor();					    // Funcion para agregar Profesor
void verRegistroEstudiantes(int);		    // Funcion para ver el registro de los estudiantes
void verRegistroFactultad(int);			    // Funcion para ver el registro de la Profesor
void modificarDetallesEstudiantes(int);     // Funcion para modificar los detalles de los estudiantes
void modificarDetallesProfesor(int);        // Funcion para modificar los detalles de la Profesor
void eliminarDatosEstudiantes(int);		    // Funcion para eliminar los datos de los estudiantes  
void eliminarDatosProfesor(int);		    // Funcion para eliminar los datos de la Profesor

// Funciones Prototipo para las caracteristicas de la Profesor
void subirCalificaciones(int);
void verCalificacionesEspecificas(int);

// Funcion prototipo para la caracteristica de los estudiantes
void verResultadosParaEstudiantes();

// Estructura para guardar los datos de cada estudiante, al igual que sus notas
struct estudiante {
    char nombre[40];
    char direccion[200];
    char telefono[40];
    char nacimiento[40];
    char contrasenia[20];

    int matricula;
    char id[40];
    char grado[20];
    float matematica, fisica, computacion, quimica, ingles, porcentaje;
    void calcularPorcentaje()
    {
        porcentaje = (matematica + fisica + computacion + quimica + ingles) / 5;
    }
};

// Otra estructura para guardar los datos de cada Profesor
struct profesor {
    char nombre[40];
    char direccion[200];
    char telefono[40];
    char nacimiento[40];
    char contrasenia[20];

    int id;
    char departamento[40];
};

// Variable global para publicar los resultados de los estudiantes
int publicarResultados = 0;

int main() {
    // Cambiamos el color de la consola y limpiamos pantalla
    system("color 9");
    system("cls");

    // Llamamos a la funcion de la intro animada para que se muestre
    //introAnimado();

    // Luego de la intro, llamamos al menu de inicio
    menuInicio();

    // Cuando finaliza el programa
    return 0;
}

void gotoxy(int x, int y) {         // Funcion para movernos en la consola
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void introAnimado() {        // Intro Animada
    // EDITAR - Poner BIENVENIDOS en vez de WELCOME en esta parte con codigo ASCII

    gotoxy(32, 4); cout << " *  *  *  *****  *     *****  ***    * * *    *****   ";
    Sleep(300);
    gotoxy(32, 5); cout << " *  *  *  *      *     *     *   *  *  *  *   *        ";
    Sleep(300);
    gotoxy(32, 6); cout << " *  *  *  *****  *     *     *   *  *  *  *   *****    ";
    Sleep(300);
    gotoxy(32, 7); cout << " *  *  *  *      *     *     *   *  *  *  *   *         ";
    Sleep(300);
    gotoxy(32, 8); cout << "  * * *   *****  ****  *****  ***   *  *  *   *****     ";
    Sleep(300);
    gotoxy(35, 10); cout << "=============================================" << endl;
    Sleep(500);
    gotoxy(39, 12); cout << "UNIVERSIDAD DE TECNOLOGIA JOHNNY BRAVO" << endl;
    Sleep(500);
    system("pause");
}

// Funcion con el que mostramos el menu y preguntamos al usuario que tipo de usuario es
void menuInicio() {
    char opcion_menu;
    do {
		system("cls");
		system("color e");
		gotoxy(30, 3); cout << "==================== SISTEMA DE REGISTROS ====================" << endl;
		gotoxy(47, 5); cout << "========== INICIO ==========";
		gotoxy(40, 7); cout << "Selecciona el tipo de usuario que eres:" << endl;
		gotoxy(40, 9); cout << "1. Ingresar como Administrador";
		gotoxy(40, 11); cout << "2. Ingresar como Profesor";
		gotoxy(40, 13); cout << "3. Ingresar como Estudiante";
		gotoxy(40, 15); cout << "4. Salir";
		gotoxy(40, 17); cout << "Ingresa una opcion : ";
		cin >> opcion_menu;
		system("cls");
		switch (opcion_menu) {
		    case '1': {
			    ingresarAdmin();
			    break;
		    }
		    case '2': {
			    ingresarProfesor();
			    break;
		    }
		    case '3': {
			    ingresarEstudiante();
			    break;
		    }
		    case '4': {
			    salir();
			    break;
		    }
		}
	} while (opcion_menu != '4');
}

// Funcion para mostrar los datos de nosotros al salir
void salir() {
    system("cls");
    system("color e");
    
    // EDITAR - Centrarlo y poner tu carné
    cout << "\n\n\t\t     Finalizando el programa... Hecho por:" << endl;
    cout << "\n\n";
    cout << "\t\t   Nombres                      Carne      \n\n";
    cout << "\t\t  Andres Ujpan                2290-23-286 \n";
    cout << "\t\t  Johnny Tiu                  xxxx-xx-xxx \n\n";
}

// Funcion para mostrar el menu del administrador
void ingresarAdmin() {
    char caracter;
    string contra, id;
    system("color e");

    cout << "\n\n";
    gotoxy(48, 3); cout << "ADMINISTRADOR";
    gotoxy(35, 4); cout << "=============================================";
    gotoxy(35, 6); cout << "Ingresa tu ID y contrasenia...";
    gotoxy(35, 8); cout << "ID: ";
    cin.ignore();
    cin >> id;
    gotoxy(35, 10); cout << "Contrasenia: ";
    cin.ignore();
    caracter = _getch();

    // Reemplazamos cada caracter con asteriscos
    while (caracter != 13) {        // Mientras no se presione enter
        contra.push_back(caracter);
        cout << '*';
        caracter = _getch();
    }

    if (id == "admin" && contra == "admin") // Contraseña para ingresar como administrador
        menuAdmin();
    else
    {
        gotoxy(35, 12); cout << "Ingresa un ID y contrasenia validos";
        gotoxy(35, 14); cout << "Presiona alguna tecla para volver a intentarlo";
        cin.ignore();
    }
}

// Menu del administrador
void menuAdmin() {
    int opcion_menu_admin;
    do {
        system("cls");
        system("color c");

        cout << "\t\t\t\t=================MENU PRINCIPAL================\n\n" << endl;
        cout << "\t\t\t\t1. Ver y Publicar Resultado\n\n";
        Sleep(300);
        cout << "\n\t\t\t\t 2. Agregar un nuevo Estudiante\n\n";
        Sleep(300);
        cout << "\t\t\t\t 3. Ver registro de Estudiante existente\n\n";
        Sleep(300);
        cout << "\t\t\t\t 4. Modificar registro de Estudiante existente.\n\n";
        Sleep(300);
        cout << "\t\t\t\t 5. Subir Notas de Estudiante.\n\n";
        Sleep(300);
        cout << "\t\t\t\t 6. Ver Notas de Estudiante Específico.\n\n";
        Sleep(300);
        cout << "\t\t\t\t 7. Eliminar registro de Estudiante.\n\n";
        Sleep(300);
        cout << "\n\t\t\t\t 8. Agregar una nueva Profesor\n\n";
        Sleep(300);
        cout << "\t\t\t\t 9. Ver Profesor existente\n\n";
        Sleep(300);
        cout << "\t\t\t\t 10. Modificar registro de Profesor existente\n\n";
        Sleep(300);
        cout << "\t\t\t\t 11. Eliminar registro de Profesor existente\n\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t 12. Volver a Inicio\n\n";
        cout << "\t\t\t\t==============================" << endl;
        Sleep(300);
        cout << "\t\t\t\tElije un opcion: <1-12> : ";
        Sleep(300);
        cin >> opcion_menu_admin;
        cout << endl;
        system("cls");
        switch (opcion_menu_admin) {
            case 1:
            {
                verResultadosParaEstudiantes();
                break;
            }
            case 2:
            {
                agregarEstudiantes();
                break;
            }
            case 3:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula: ";
                cin >> n;
                verRegistroEstudiantes(n);
                break;
            }
            case 4:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula a modificar: ";
                cin >> n;
                modificarDetallesEstudiantes(n);
                break;
            }
            case 5:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula a subir notas: ";
                cin >> n;
                subirCalificaciones(n);
                break;
            }
            case 6:
            {
                int n;
                cout << "Ingresa el numero de matricula: ";
                cin >> n;
                verCalificacionesEspecificas(n);
                break;
            }
            case 7:
            {
                int n;
                cout << "\n\nIngresa el numero de matricula a eliminar: ";
                cin >> n;
                eliminarDatosEstudiantes(n);
                break;
            }
            case 8:
            {
                agregarProfesor();
                break;
            }
            case 9:
            {
                int n;
                cout << "\n\nIingresa el ID del Profesor: ";
                cin >> n;
                verRegistroFactultad(n);
                break;
            }
            case 10:
            {
                int n;
                cout << "\n\nIingresa el ID del Profesor a modificar: ";
                cin >> n;
                modificarDetallesProfesor(n);
                break;
            }
            case 11:
            {
                int n;
                cout << "\n\nIngresa el ID del Profesor a eliminar : ";
                cin >> n;
                eliminarDatosProfesor(n);
                break;
            }
            case 12:
            {
                menuInicio();
                break;
            }
        }
	} while (opcion_menu_admin != 12);
}

void verResultadosParaEstudiantes()
{
    system("cls");
    estudiante s;
    // Declaramos un archivo de lectura
    ifstream archivoEstudiante;
    bool check = false;
    // Abrimos el archivo en modo binario
    archivoEstudiante.open("Estudiante.txt", ios::app);
    if (archivoEstudiante.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\tALL STUDENTS REPORT CARDS FOR REVIEW " << endl;
    cout << "==================================================================================" << endl;
    while (archivoEstudiante.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        cout << "\t\t\t\tSTUDENT NAME : " << s.nombre << endl
            << endl;
        cout << "\t\t\t\tSTUDENT ADMISSION ID NUMBER : " << s.id << endl
            << endl;
        cout << "\t\t\t\tSTUDENT ROLL NUMBER : " << s.matricula << endl
            << endl;
        cout << "\t\t\t\tMATH      : " << s.matematica << endl
            << endl;
        cout << "\t\t\t\tPHYSICS   : " << s.fisica << endl
            << endl;
        cout << "\t\t\t\tCHEMISTRY : " << s.quimica << endl
            << endl;
        cout << "\t\t\t\tENGLISH   : " << s.ingles << endl
            << endl;
        cout << "\t\t\t\tCOMPUTER  : " << s.computacion << endl
            << endl;
        cout << "\t\t\t\tPERCENTAGE: " << s.porcentaje << endl
            << endl;
        cout << "==================================================================================\n"
            << endl;
        check = true;
    }
    archivoEstudiante.close();
    if (check == false)
        cout << "\t\t\t\tNO RECORD FOUND... " << endl
        << endl;
    if (check == true)
    {
        cout << "\n\nFor Publishing Result press 1 for not press 0 : ";
        /* this will give access to students to view their marks
            otherwise when student see their result it will show
            result not uploaded yet */
        cin >> publicarResultados;
        if (publicarResultados == 1)
        {
            cout << "\n\nResult Published to STUDENT PORTAL\n\n";
        }
    }
    cout << "\tpress enter to continue....";
    cin.ignore();
    cin.get();
}

void agregarEstudiantes()
{
    system("cls");
    estudiante s;
    ofstream outfile;
    outfile.open("Student.txt", ios::app | ios::binary);
    if (outfile.fail())
    {
        cout << "THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout << "\n\n\n";
    cout << "\t\t\t\t======= Add A Student ========\n\n";
    cout << "ENTER FULL NAME : ";
    cin.ignore();
    cin.getline(s.nombre, 40);
    cout << "ENTER Admission Id : ";
    cin.getline(s.id, 40);
    cout << "ENTER D.O.B : ";
    cin.getline(s.nacimiento, 40);
    cout << "ENTER PHONE NUMBER : ";
    cin.getline(s.telefono, 40);
    cout << "ENTER ADDRESS : ";
    cin.getline(s.direccion, 200);
    cout << "ENTER CLASS STANDARD : ";
    cin.getline(s.grado, 20);
    cout << "Set A Password For the User : ";
    cin.getline(s.contrasenia, 20);
    cout << "ENTER ROLL NUMBER (INT Value) : ";
    cin >> s.matricula;
    outfile.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void verRegistroEstudiantes(int n)
{
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\n\t\t\t\t========== STUDENT PROFILE ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula == n)
        {
            cout << "\t\t\t\t NAME : " << s.nombre << endl;
            cout << "\t\t\t\t ADMISSION ID NUMBER : " << s.id << endl;
            cout << "\t\t\t\t ROLL NUMBER : " << s.matricula << endl;
            cout << "\t\t\t\t D.O.B : " << s.nacimiento << endl;
            cout << "\t\t\t\t STANDARD : " << s.grado << endl;
            cout << "\t\t\t\t PHONE NUMBER : " << s.telefono << endl;
            cout << "\t\t\t\t ADDRESS : " << s.direccion << endl;
            cout << "\t\t\t\t PASSWORD : " << s.contrasenia << endl;
            cout << "\t\t\t\t======================================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "press enter to continue...";
    cin.ignore();
    cin.get();
}

void modificarDetallesEstudiantes(int n)
{
    system("cls");
    estudiante s;
    fstream infile;
    infile.open("Student.txt", ios::binary | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\n\t\t\t\t==========MODIFY STUDENT PROFILE==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante));
        {
            if (s.matricula == n)
            {
                cout << "\t\t\t\t NAME : " << s.nombre << endl;
                cout << "\t\t\t\t ADMISSION ID NUMBER : " << s.id << endl;
                cout << "\t\t\t\t ROLL NUMBER : " << s.matricula << endl;
                cout << "\t\t\t\t D.O.B : " << s.nacimiento << endl;
                cout << "\t\t\t\t STANDARD : " << s.grado << endl;
                cout << "\t\t\t\t PHONE NUMBER :" << s.telefono << endl;
                cout << "\t\t\t\t ADDRESS :" << s.direccion << endl;
                cout << "\t\t\t\t PASSWORD : " << s.contrasenia << endl;
                cout << "\n\t\t\t\t=============================================" << endl;
                cout << "\t\t\t\t\tENTER THE NEW INFORMATION" << endl;
                cout << "\t\t\t\t=============================================" << endl;
                cout << "\n\t\t\t\tENTER FULL NAME : ";
                cin.ignore();
                cin.getline(s.nombre, 40);
                cout << "\t\t\t\tENTER Admission Id : ";
                cin.getline(s.id, 40);
                cout << "\t\t\t\tENTER D.O.B : ";
                cin.getline(s.nacimiento, 40);
                cout << "\t\t\t\tENTER PHONE NUMBER : ";
                cin.getline(s.telefono, 40);
                cout << "\t\t\t\tENTER ADDRESS : ";
                cin.getline(s.direccion, 200);
                cout << "\t\t\t\tENTER CLASS STANDARD : ";
                cin.getline(s.grado, 20);
                cout << "\t\t\t\tSet A Password For the User : ";
                cin.getline(s.contrasenia, 20);
                cout << "\t\t\t\tENTER ROLL NUMBER (INT Value) : ";
                cin >> s.matricula;
                int pos = (-1) * static_cast<int>(sizeof(estudiante));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
                cout << endl;
                cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY updated" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void eliminarDatosEstudiantes(int n)
{
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Student.txt", ios::binary);
    if (!infile)
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Record3.txt", ios::binary);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t===========DELETE A STUDENT RECORD==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula != n)
        {
            outfile.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
        }
    }
    infile.close();
    outfile.close();
    remove("Student.txt");
    rename("Record3.txt", "Student.txt");
    cout << endl;
    cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
    cout << "press enter to continue...";
    cin.ignore();
    cin.get();
}

void subirCalificaciones(int n)
{
    system("cls");
    estudiante s;
    fstream infile;
    infile.open("Student.txt", ios::binary | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\t\t\t\t==========UPLOAD STUDENT MARKS==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante));
        {
            if (s.matricula == n)
            {
                cout << "\t\t\t\t NAME : " << s.nombre << endl;
                cout << "\t\t\t\t ROLL NUMBER : " << s.matricula << endl;
                cout << "\t\t\t\t D.O.B : " << s.nacimiento << endl;
                cout << "\t\t\t\t STANDARD : " << s.grado << endl;
                cout << "\n\t\t\t\t=============================================" << endl;
                cout << "\t\t\t\t\t  UPLOAD MARKS BELOW" << endl;
                cout << "\t\t\t\t=============================================" << endl;
                cout << "\n\t\t\t\tENGLISH : ";
                cin >> s.ingles;
                cout << "\t\t\t\tMATH : ";
                cin >> s.matematica;
                cout << "\t\t\t\tPHYSICS : ";
                cin >> s.fisica;
                cout << "\t\t\t\tCHEMISTRY : ";
                cin >> s.quimica;
                cout << "\t\t\t\tCOMPUTER : ";
                cin >> s.computacion;
                s.calcularPorcentaje();
                int pos = (-1) * static_cast<int>(sizeof(estudiante));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char*>(&s), sizeof(estudiante));
                cout << endl;
                cout << "\n\t\t\t\tMarks Uploaded Successfully" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void verCalificacionesEspecificas(int n)
{
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\t\t\t\t========== STUDENT REPORT CARD ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula == n)
        {
            cout << "\t\t\t\t NAME : " << s.nombre << endl;
            cout << "\t\t\t\t ROLL NUMBER : " << s.matricula << endl;
            cout << "\t\t\t\t D.O.B : " << s.nacimiento << endl;
            cout << "\t\t\t\t STANDARD : " << s.grado << endl;
            cout << "\t\t\t\t==============================" << endl;
            cout << "\t\t\t\t PHYSICS   : " << s.fisica << endl;
            cout << "\t\t\t\t MATH      : " << s.matematica << endl;
            cout << "\t\t\t\t CHEMISTRY : " << s.quimica << endl;
            cout << "\t\t\t\t ENGLISH   : " << s.ingles << endl;
            cout << "\t\t\t\t COMPUTER  : " << s.computacion << endl;
            cout << endl;
            cout << "\t\t\t\t PERCENTAGE : " << s.porcentaje << "%" << endl;
            cout << "\t\t\t\t==============================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "press enter to continue...";
    cin.ignore();
    cin.get();
}

void agregarProfesor()
{
    system("cls");
    profesor f;
    ofstream outfile;
    outfile.open("Profesor.txt", ios::app | ios::binary);
    if (outfile.fail())
    {
        cout << "THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout << "\n\n";
    cout << "\t\t\t\t=======Add A Faculty ========\n\n";
    cout << "ENTER FULL NAME : ";
    cin.ignore();
    cin.getline(f.nombre, 40);
    cout << "ENTER PHONE NUMBER : ";
    cin.getline(f.telefono, 40);
    cout << "ENTER D.O.B : ";
    cin.getline(f.nacimiento, 40);
    cout << "ENTER ADDRESS : ";
    cin.getline(f.direccion, 200);
    cout << "ENTER Department: ";
    cin.getline(f.departamento, 40);
    cout << "Set a Password: ";
    cin.getline(f.contrasenia, 40);
    cout << "ENTER Faculty Id (INT type): ";
    cin >> f.id;
    outfile.write(reinterpret_cast<char*>(&f), sizeof(profesor));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void verRegistroFactultad(int n)
{
    system("cls");
    profesor f;
    ifstream infile;
    infile.open("Faculty.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\n\n\t\t\t\t========== FACULTY PROFILE ==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&f), sizeof(profesor)))
    {
        if (f.id == n)
        {
            cout << "\t\t\t\t NAME : " << f.nombre << endl;
            cout << "\t\t\t\t FACULTY ID NUMBER : " << f.id << endl;
            cout << "\t\t\t\t D.O.B : " << f.nacimiento << endl;
            cout << "\t\t\t\t DEPARTMENT : " << f.departamento << endl;
            cout << "\t\t\t\t PHONE NUMBER : " << f.telefono << endl;
            cout << "\t\t\t\t ADDRESS : " << f.direccion << endl;
            cout << "\t\t\t\t PASSWORD : " << f.contrasenia << endl;
            cout << "\t\t\t\t======================================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void modificarDetallesProfesor(int n)
{
    system("cls");
    profesor f;
    fstream infile;
    infile.open("Faculty.txt", ios::binary | ios::in | ios::out);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\n\n\t\t\t\t==========MODIFY FACULTY PROFILE==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char*>(&f), sizeof(profesor));
        {
            if (f.id == n)
            {
                cout << "\t\t\t\t NAME : " << f.nombre << endl;
                cout << "\t\t\t\t FACULTY ID NUMBER : " << f.id << endl;
                cout << "\t\t\t\t D.O.B : " << f.nacimiento << endl;
                cout << "\t\t\t\t DEPARTMENT : " << f.departamento << endl;
                cout << "\t\t\t\t PHONE NUMBER : " << f.telefono << endl;
                cout << "\t\t\t\t ADDRESS : " << f.direccion << endl;
                cout << "\t\t\t\t PASSWORD : " << f.contrasenia << endl;
                cout << "\n\t\t\t\t=========================================" << endl;
                cout << "\t\t\t\t\tENTER THE NEW INFORMATION" << endl;
                cout << "\t\t\t\t=========================================" << endl;
                cout << "\n\t\t\t\tENTER FULL NAME : ";
                cin.ignore();
                cin.getline(f.nombre, 40);
                cout << "\t\t\t\tENTER PHONE NUMBER : ";
                cin.getline(f.telefono, 40);
                cout << "\t\t\t\tENTER D.O.B : ";
                cin.getline(f.nacimiento, 40);
                cout << "\t\t\t\tENTER ADDRESS : ";
                cin.getline(f.direccion, 200);
                cout << "\t\t\t\tENTER Department: ";
                cin.getline(f.departamento, 40);
                cout << "\t\t\t\tSet a Password: ";
                cin.getline(f.contrasenia, 40);
                cout << "\t\t\t\tENTER Faculty Id (INT type): ";
                cin >> f.id;
                int pos = (-1) * static_cast<int>(sizeof(profesor));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char*>(&f), sizeof(profesor));
                cout << endl;
                cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY updated" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void eliminarDatosProfesor(int n)
{
    system("cls");
    profesor f;
    ifstream infile;
    infile.open("Faculty.txt", ios::binary);
    if (!infile)
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Record2.txt", ios::binary);
    infile.seekg(0, ios::beg);
    cout << "\n\n\t\t\t\t===========DELETE A FACULTY RECORD==========\n\n";
    while (infile.read(reinterpret_cast<char*>(&f), sizeof(profesor)))
    {
        if (f.id != n)
        {
            outfile.write(reinterpret_cast<char*>(&f), sizeof(profesor));
        }
    }
    infile.close();
    outfile.close();
    remove("Faculty.txt");
    rename("Record2.txt", "Faculty.txt");
    cout << endl;
    cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void ingresarProfesor()
{
    char cc, ch;
    string password;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t\t Login As Faculty \n\n";
    cout << "\t\t\t\t=============================================" << endl;
    cout << endl;
    cout << "\t\t\t\t Enter your Faculty Id and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t Faculty Id: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t Password: ";
    cin.ignore();
    ch = _getch();
    while (ch != 13)
    { // character 13 is enter
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    system("cls");
    profesor f;
    ifstream infile;
    infile.open("Faculty.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    while (infile.read(reinterpret_cast<char*>(&f), sizeof(profesor)))
    {
        if (f.id == id && f.contrasenia == password)
        {
        start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t  Welcome " << f.nombre << "\n\n\n";
            cout << "\t\t\t\t=================FACULTY MENU================\n\n"
                << endl;
            cout << "\t\t\t\t1. View profile\n\n";
            Sleep(300);
            cout << "\t\t STUDENT :\n";
            Sleep(300);
            cout << "\t\t\t\t 2. View existing Student record\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. Upload Student Marks.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 4. View Specific Student Marks.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 5. Log Out\n\n";
            cout << "\t\t\t\t==============================" << endl;
            Sleep(300);
            cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-5> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                verRegistroFactultad(f.id);
                goto start;
                break;
            }
            case '2':
            {
                int k;
                cout << "\n\nENTER STUDENT ROLL NUMBER TO VIEW HIS PROFILE : ";
                cin >> k;
                verRegistroEstudiantes(k);
                goto start;
                break;
            }
            case '3':
            {
                int k;
                cout << "\n\nENTER STUDENT ROLL NUMBER TO UPLOAD MARKS : ";
                cin >> k;
                subirCalificaciones(k);
                goto start;
                break;
            }
            case '4':
            {
                int k;
                cout << "\n\nENTER STUDENT ROLL NUMBER TO VIEW HIS RESULT : ";
                cin >> k;
                verCalificacionesEspecificas(k);
                goto start;
                break;
            }
            case '5':
            {
                menuInicio();
                break;
            }
            }
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
    {
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press 'H' key to continue...";
        char a;
        cin >> a;
        if (a == 'h' || a == 'H')
            menuInicio();
    }
}

void ingresarEstudiante()
{
    char cc, ch;
    string password;
    int id;
    system("cls");
    system("color e");
    cout << "\n\n";
    cout << "\t\t\t\t\t    Login As Student \n\n";
    cout << "\t\t\t\t=============================================" << endl;
    cout << endl;
    cout << "\t\t\t\t Enter your Roll No and Password below\n\n";
    cout << endl;
    cout << "\t\t\t\t Roll No: ";
    cin.ignore();
    cin >> id;
    cout << "\t\t\t\t Password: ";
    cin.ignore();
    ch = _getch();
    while (ch != 13)
    { // character 13 is enter
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    system("cls");
    estudiante s;
    ifstream infile;
    infile.open("Student.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    system("cls");
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(estudiante)))
    {
        if (s.matricula == id && s.contrasenia == password)
        {
        start:
            system("cls");
            cout << "\n\n\n\t\t\t\t\t\t Welcome " << s.nombre << "\n\n\n";
            cout << "\t\t\t\t================= STUDENT MENU ================\n\n"
                << endl;
            cout << "\t\t\t\t 1. View profile\n\n";
            Sleep(300);
            cout << "\t\t\t\t 2. View Result.\n\n";
            Sleep(300);
            cout << "\t\t\t\t 3. Log Out\n\n";
            cout << "\t\t\t\t==============================" << endl;
            Sleep(300);
            cout << "\t\t\t\tENTER YOUR CHOICE...:) <1-3> : ";
            Sleep(300);
            cin >> cc;
            cout << endl;
            system("cls");
            switch (cc)
            {
            case '1':
            {
                verRegistroEstudiantes(s.matricula);
                goto start;
                break;
            }
            case '2':
            {
                if (publicarResultados == 1)
                    verCalificacionesEspecificas(s.matricula);
                else
                {
                    cout << "\n\n\n\t\tResult Not Uploaded Yet. Contact Admin \n\n";
                    cout << "\t\tpress enter to continue...";
                    cin.ignore();
                    cin.get();
                }
                goto start;
                break;
            }
            case '3':
            {
                menuInicio();
                break;
            }
            }

            equality = true;
        }
    }
    infile.close();
    if (equality == false)
    {
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press 'H' key to continue...";
        char a;
        cin >> a;
        if (a == 'h' || a == 'H')
            menuInicio();
    }
}