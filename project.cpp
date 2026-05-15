/*
                     TEAM 34
Basel Ibrahim Ahmed Ahmed         2400338
Ali Mohamed Ahmed Hassan          2400469
Mohamed Abdallah Abdelkader       2400866
Pierre Ossama Magdi Siha          2400389
Abdelmaqsoud Maher Abdelmaqsoud   2400519

                  ALL MECHANICAL
*/

//---------------wanted to make a big array for motors and gearboxes to achieve a valid combination each time-------------------
//i wanted to use a .csv file to store all the materials , motors and gearboxes but we decided to make it as classes in the end
//all comments are made by us ;)

#include <iostream>
#include <cmath>
#include <vector> // Required for a dynamic material database
#include <string> // Required for 'string material'
#define g 9810   // as we are working with mm

using namespace std;

//---------------------------classes-------------------------
class materials {
public:
    double yield;    // MPa
    double density;  // g/cm^3
    string material;
};
class motor {
public :
    string motor;
    double mass_motor;   //kg
    double torque_motor; //Nm
    double Dim_motor;    // DIAMETER MOTOR
    double width_motor;  // WIDTH OF MOTOR
    double omega_motor;  // ANGULAR VELOCITY[RPM]

};
class gear {
public :
    string gear;
    double gear_ratio;
    double mass_gear;
    double Dim_gear;
    double eff;           //EFFECIENCY
    double width_gear;
    };
//--------------------------------------------arrays--------------------------------------------
//array of materials
vector<materials>mat={
    {130, 7.3, "Cast Iron"},
    {130, 8.94, "Copper nickel"},
    {200, 8.73, "Brass"},
    {241, 2.7, "Aluminum"},
    {247, 7.58, "Steel"},
    {72, 1.16, "Acrylic"},
    {70, 8.92, "Copper"},
    {275, 7.86, "Stainless steel"},
    {941, 19.25, "Tungsten"}
};
// we used many motors and gearboxes to avoid the invalid combination output
//array of motor
motor mot[] = {
        {"EC-max 22 25 W (283856)", 0.11, 0.023, 22, 48.5, 9800},
        {"EC-max 22 25W High Speed", 0.11, 0.0218, 22, 48.5, 12900},
        {"EC-max 22 25W Variant B", 0.11, 0.0227, 22, 48.5, 12900},
        {"EC-max 22 25W Low Speed", 0.09, 0.027, 22, 48.5, 4390},
        {"EC-max 22 15W Compact", 0.08, 0.0106, 22, 32, 12100},
        {"EC-max 22 15W Compact B", 0.08, 0.0108, 22, 32, 12100},
        {"EC-max 30 40W", 0.15, 0.0334, 30, 42, 9250},
        {"EC-max 30 60W High Speed", 0.20, 0.0734, 30, 47, 17500},
        {"EC-max 30 90W", 0.25, 0.111, 30, 65, 17200},
        {"EC-max 30 90W Low Speed", 0.25, 0.118, 30, 65, 13100},
        {"EC-max 22 25W No-Load", 0.12, 0.023, 22, 48.5, 12400},
        {"EC-max 22 25W Max Speed", 0.12, 0.023, 22, 48.5, 18000},
        {"EC-max 16 8W", 0.042, 0.0084, 16, 34, 10200},
        {"EC-max 16 8W High Speed", 0.042, 0.008, 16, 34, 13500},
        {"EC-max 40 70W", 0.310, 0.085, 40, 70, 7800},
        {"EC-max 40 120W", 0.460, 0.130, 40, 100, 8200},
        {"RE 25 20W", 0.130, 0.026, 25, 54, 9500},
        {"RE 30 60W", 0.238, 0.088, 30, 68, 8700},
        {"RE 40 150W", 0.480, 0.170, 40, 71, 6900},
        {"EC-max 22 25W 12V (283856)", 0.110, 0.0230, 22, 48.5, 12400},
        {"EC-max 22 25W 18V (283857)", 0.110, 0.0218, 22, 48.5, 12900},
        {"EC-max 22 25W 24V (283858)", 0.110, 0.0227, 22, 48.5, 12900},
        {"EC-max 22 25W 36V (283859)", 0.110, 0.0225, 22, 48.5, 12200},
        {"EC-max 22 25W 48V (283860)", 0.110, 0.0232, 22, 48.5, 12900},
        {"ECX FLAT 32 L", 0.070, 0.0739, 32, 24.0, 10000},
        {"ECX PRIME 22 L", 0.110, 0.0673, 22, 60.0, 13300},
        {"IDX 70 S 600W", 1.600, 1.0690, 70, 141.0, 3870},
        {"IDX 56 L 400W", 1.200, 0.8000, 56, 120.0, 4000},
        {"EC-4pole 30 200W", 0.300, 0.0956, 30, 64.0, 16100},
        {"EC frameless HT 76 M", 0.850, 1.5000, 76, 45.0, 3500}

};
//array for gear boxes
gear gear_box[] = {
    {"GPX22 3.9:1", 3.9, 0.056, 22, 0.96, 21.6},
    {"GPX22 6.6:1", 6.6, 0.045, 22, 0.90, 19.9},
    {"GPX22 10:1", 10, 0.050, 22, 0.92, 22},
    {"GPX22 16:1", 16, 0.055, 22, 0.88, 24},
    {"GPX22 44:1 (SP)", 44, 0.106, 22, 0.80, 48.6},
    {"GPX22 44:1 (Ceramic)", 44, 0.058, 22, 0.81, 26.4},
    {"GPX22 64:1", 64, 0.060, 22, 0.78, 30},
    {"GPX22 100:1", 100, 0.065, 22, 0.75, 32},
    {"GP22 333:1 HD", 333, 0.070, 22, 0.65, 45},
    {"GPX22 439:1", 439, 0.089, 22, 0.66, 43},
    {"GPX22 734:1", 734, 0.090, 22, 0.66, 43},
    {"GP22 4.4:1 HP", 4.4, 0.060, 22, 0.84, 25.25},
    {"GPX16 5.4:1", 5.4, 0.018, 16, 0.89, 14.5},
    {"GPX16 29:1", 29, 0.021, 16, 0.80, 18.2},
    {"GPX16 118:1", 118, 0.025, 16, 0.73, 21.9},
    {"GPX32 14:1", 14, 0.145, 32, 0.85, 35.8},
    {"GPX32 33:1", 33, 0.180, 32, 0.75, 42.5},
    {"GPX32 190:1", 190, 0.215, 32, 0.65, 49.2},
    {"GPX32 456:1", 456, 0.220, 32, 0.65, 49.2},
    {"GP 32 A 33:1", 33, 0.165, 32, 0.75, 43.1},
    {"GP 32 A 190:1", 190, 0.205, 32, 0.65, 49.8},
    {"GP 32 C 456:1", 456, 0.210, 32, 0.65, 49.8},
    {"GPX 52 A 3-stage", 118.0, 0.850, 52, 0.70, 80.5},
    {"GPX 70 LN 2-stage", 25.0, 1.500, 70, 0.80, 105.2},
    {"GPX 26 3-stage", 118.0, 0.120, 26, 0.73, 45.4},
    {"GPX 26 C Ceramic 3-stage", 118.0, 0.125, 26, 0.73, 45.4},
    {"GP 62 A 2-stage 25:1", 25.0, 1.800, 62, 0.75, 105.0},
    {"GP 62 A 3-stage 100:1", 100.0, 2.300, 62, 0.70, 130.0},
    {"GP 62 A 4-stage 300:1", 300.0, 2.800, 62, 0.65, 155.0},
    {"GP 81 A 2-stage 18:1", 18.0, 3.200, 81, 0.75, 115.0},
    {"GP 81 A 3-stage 120:1", 120.0, 4.500, 81, 0.70, 150.0},
    {"GP 81 A 4-stage 500:1", 500.0, 5.500, 81, 0.65, 185.0},
    {"GPX 52 C 2-stage 33:1", 33.0, 1.100, 52, 0.80, 85.0},
    {"GPX 52 C 3-stage 150:1", 150.0, 1.450, 52, 0.75, 110.0}
};
//--------------------------------------functions part 1----------------------------------------

void selectMaterial(string material,double& density, double& sigma_yield)
{
    int mat_choice;

    cout << "Select material:" << endl;
    for (int i = 0; i < mat.size(); i++)
        cout << i + 1 << ") " << mat[i].material << endl;
    cout <<mat.size()+1<<") Add another material" << endl;

    while (true)
    {
        cin >> mat_choice;
        //cin.peek()used to check if there is no characters entered while entering an integer
        if (cin.peek() == '\n' && mat_choice >= 1 && mat_choice <= mat.size()+1)
            {break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice, try again:\n";
    }

    if (mat_choice == mat.size()+1)
    {
        cout << "Enter material name: ";
        string dummy;
        getline(cin, dummy); // flush leftover buffer

        while (true) {
        getline(cin, material);
        if (!material.empty()) {
        break;
    }
    cout << "Invalid input, try again:\n";
}
        cout << "Enter material density: ";
        while (true)
    {
        cin >> density;
        //cin.peek()used to check if there is no characters entered while entering an integer
        if (cin.peek() == '\n' && density>0 )
            {break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice, try again:\n";
    }
        cout << "Enter yield strength: ";
            while (true)
            {
                cin >> sigma_yield;
                //cin.peek()used to check if there is no characters entered while entering an integer
                if (cin.peek() == '\n' && sigma_yield>0)
                {break;}
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid choice, try again:\n";
            }
            mat.push_back({sigma_yield,density,material});
    }
    else
    {
        density = mat[mat_choice - 1].density;
        sigma_yield = mat[mat_choice - 1].yield;
    }
}
void selectShape(int& shape, double& base, double& height, double& radius,
    double& length, double& mass_link, double& I_inertia,
    double density)
    //density is not passed by reference because it is not changeable for the same material
    {
        cout << "Select cross section shape (1)rectangular or (2)circular:" << endl;
        while (true){
               cin>>shape;
            if(cin.peek()=='\n' && (shape==1 || shape ==2) ){
                break;
            }
            cin.fail();
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice, try again:\n";
        }
        if(shape==1)
        {
            cout<<"Enter dimensions in mm: "<<endl;
            cout<<"base=";
            cin>>base;
            //while loops to make sure dimensions is positive
            while(true){
                if(base>0 && cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, enter positive values only"<<endl;
                cin>>base;
            }
            cout<<"height=";
            cin>>height;
            while(true){
                if(height>0 && cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, enter positive values only"<<endl;
                cin>>height;
            }
            cout<<"length=";
            cin>>length;
            while(true){
                if(length>0 && cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, enter positive values only"<<endl;
                cin>>length;
            }
            //conversion of density from gm/cm^3 to ton/mm^3 to ensure the stress is in MPa
            mass_link=density*0.000000001*(base*height*length); //link mass
            I_inertia=(base*pow(height,3))/12; //inertia
        }
        // -----------------------for circular calculations-------------------------------
        else
        {
            cout<<"Enter dimensions in mm: "<<endl;
            cout<<"radius=";
            cin>>radius;
            // same as rectangular , while loops to make sure dimensions is positive
           while(true){
                if(radius>0 && cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, enter positive values only"<<endl;
                cin>>radius;
            }
            cout<<"length=";
            cin>>length;
            while(true){
                if(length>0 && cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, enter positive values only"<<endl;
                cin>>length;
            }
            //conversion of density from gm/cm^3 to ton/mm^3 to ensure the stress is in MPa
            mass_link=density*0.000000001*(M_PI*pow(radius,2)*length);  //mass
            I_inertia=(M_PI*pow(radius,4))/4; //inertia
        }
    }
double Momentcalc(double &mass_link,double &length, double mass_payload,double alphamax){
    return mass_link*g*(length/2)+(mass_payload*g*length)+(mass_link*pow(length/2,2)*alphamax+mass_payload*pow(length,2)*alphamax);
}
void optimization (double &sigma ,int shape,double sigma_yield,double density, double &mass_link, double mass_payload
                     ,double &base, double &height,double &radius, double &length,double &I_inertia,double alphamax,double &Moment)
                     {
                         while(sigma>sigma_yield)
                            {
                                if(shape==1)
                                {
                                    base*=1.01;//increasing base length by 1%
                                    height*=1.01;//increasing height length by 1%
                                    mass_link=density*0.000000001*(base*height*length);
                                    I_inertia=(base*pow(height,3))/12;
                                }
                                else if(shape==2)
                                {
                                    radius*=1.01;
                                    mass_link=density*0.000000001*(M_PI*pow(radius,2)*length);
                                    I_inertia=(M_PI*pow(radius,4))/4;
                                }
                                Moment=Momentcalc(mass_link,length,mass_payload,alphamax);
                                if(shape==1)
                                    sigma=(Moment*height)/(2*I_inertia);
                                else if(shape==2)
                                    sigma=(Moment*radius)/I_inertia;
                            }

                            // if the stress is so small compared to the yield strength
                            while(sigma<=0.95*sigma_yield)
                            {
                                if(shape==1)
                                {
                                    base*=0.99;
                                    height*=0.99;
                                    mass_link=density*0.000000001*(base*height*length);
                                    I_inertia=(base*pow(height,3))/12;
                                }
                                else if(shape==2)
                                {
                                    radius*=0.99;
                                    mass_link=density*0.000000001*(M_PI*pow(radius,2)*length);
                                    I_inertia=(M_PI*pow(radius,4))/4;
                                }
                                Moment=Momentcalc(mass_link,length,mass_payload,alphamax);

                                if(shape==1)
                                    sigma=(Moment*height)/(2*I_inertia);
                                else if(shape==2)
                                    sigma=(Moment*radius)/I_inertia;
                            }
                     }
//--------------------------------------functions part 2-----------------------------------

double required_torque(double moment,double mass_link,double length, double mass_payload,double alphamax,double torque_req_Nm,double &torque_req){
moment = Momentcalc(mass_link,length,mass_payload,alphamax); //to get the previously declared moment function
torque_req_Nm=moment; //Required Torque Calculation

torque_req = torque_req_Nm/1000; // as the  mass of the link became kg it was best to /1000 not *1000
return torque_req;
}


void MotorGearbox(int motor_count,int gear_count,double mass_motor, double  mass_gear,double torque_motor,double omega_motor,double Dim_motor,
                 double width_motor,double gear_ratio, double eff,double Dim_gear,double width_gear,double torque_out,double omega_out,
                 double &omega_req,double req_torque,double &torque_req,double cost,string &best_motor_name, string &best_gear_name,
                 double &Moment,double &mass_link,double &length, double& mass_payload,double &alphamax,int opt_choice,double torque_req_Nm,
                 double &best_omega_out,double &best_torque_out,double &best_cost ){

best_omega_out = 0, best_torque_out = 0,best_cost = 999999.0;
req_torque= required_torque(Moment , mass_link,length,mass_payload,alphamax,torque_req_Nm,torque_req);
motor_count = sizeof(mot) / sizeof(mot[0]);//   to count number of motors
gear_count = sizeof(gear_box) / sizeof(gear_box[0]);//  to count number of gearboxes

for (int i = 0; i < motor_count; i++) {             //Select motor-gearbox
    for (int j = 0; j < gear_count; j++) {


        mass_motor = mot[i].mass_motor ;
        mass_gear  = gear_box[j].mass_gear ;

        // convert Nm to mNm
        torque_motor = mot[i].torque_motor * 1000.0;

        omega_motor = mot[i].omega_motor *(2.0 * M_PI / 60.0);
        Dim_motor   = mot[i].Dim_motor;
        width_motor = mot[i].width_motor;

        gear_ratio  = gear_box[j].gear_ratio;
        eff         = gear_box[j].eff;
        Dim_gear    = gear_box[j].Dim_gear;
        width_gear  = gear_box[j].width_gear;

        torque_out = torque_motor * gear_ratio * eff; // Motor-Gearbox Output Torque Calculation [mNm]
        omega_out  = omega_motor / gear_ratio;       // Motor-Gearbox Output Speed Calculation

        if (torque_out >= req_torque && omega_out >= omega_req) {

            if(opt_choice == 1) {
                cost = mass_motor + mass_gear;
            } else {
                cost = (mass_motor + mass_gear) + ((Dim_motor + Dim_gear) / 100.0) + ((width_motor + width_gear) / 100.0);  // Priority: Cost
            }

            if (cost < best_cost) {      // checking on the cost
                best_cost = cost;
                best_motor_name = mot[i].motor;
                best_gear_name = gear_box[j].gear;

                // to replace the value
                best_omega_out = omega_out;
                best_torque_out = torque_out;
            }
        }
    }
}



}

//=================================================  main  =================================================

int main()
{
    int restart_program;// to choose wether to restart the program or end it
    do{
    string material;
    int shape, mat_choice;
    double Moment, mass_link, mass_payload, length, height=1.0, base=1.0, radius=1.0, I_inertia, alphamax, sigma, density, sigma_yield,omega_req;

    // -------------------------- Material Selection ----------------------------------
    selectMaterial(material ,density,sigma_yield);


    // --------------------- Shape Selection & Initial Calcs -------------------
    selectShape(shape, base, height, radius, length, mass_link, I_inertia, density);

    cout<<"Enter payload mass in kg:"<<endl;
    cin>>mass_payload;
    while(true){
                if(mass_payload>0 && cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, enter positive values only"<<endl;
                cin>>mass_payload;
            }

    //conversion from kg to ton
    mass_payload*=0.001;
    cout<<"Enter maximum angular acceleration (rad/s^2):"<<endl;
    cin>>alphamax;
    while(true){
                if(cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, try again"<<endl;
                cin>>alphamax;
            }

    cout << "\nEnter required speed (rad/s): "<<endl;
    cin >> omega_req;
    while(true){
                if(cin.peek()=='\n'){
                    break;
                }
                cin.fail();
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Invalid input, try again."<<endl;
                cin>>omega_req;
            }



    // -----------------equation of bending moment-------------------
    Moment=Momentcalc(mass_link,length,mass_payload,alphamax);
    if(shape==1) //rectangular
        sigma=(Moment*height)/(2*I_inertia);
    else if(shape==2)  //circular
        sigma=(Moment*radius)/I_inertia;

    //to calculate the stress before optimization
    cout<<"\n==================== optimizations ====================\n"<<endl;
    cout<<"stress before optimization= "<<sigma<<" MPa"<<endl;

    // --------------------------- Optimization Loops ---------------------------
    optimization(sigma ,shape,sigma_yield,density, mass_link,mass_payload ,base, height, radius, length, I_inertia ,alphamax, Moment);


    mass_link*=1000;//to convert the link mass to kgs
    mass_payload*=1000;//to convert the payload mass to kgs

    // stress, mass and dimensions after optimization
    cout<<"stress after optimization= "<<sigma<<" MPa"<<endl;
    cout<<"mass of link after optimization: "<<mass_link<<" Kg"<<endl;

    if(shape==1)
        cout<<"optimized base: "<<base<<" mm"<<endl<<"optimized height: "<<height<<" mm"<<endl;
    else if(shape==2)
        cout<<"optimized radius: "<<radius<<" mm"<<endl;


//-------------------------------------------part 2 ---------------------------------------------------

double cost, torque_req, torque_motor, torque_out, eff, gear_ratio,torque_req_Nm,moment,motor_count,gear_count,req_torque;
double omega_out, omega_motor, Dim_motor, width_motor,mass_motor, mass_gear, Dim_gear, width_gear;
double best_omega_out = 0, best_torque_out = 0,best_cost = 999999.0;
int opt_choice;
string best_motor_name, best_gear_name;

cout << "Select optimization priority:\n 1) Minimize Weight\n 2) Minimize Cost \nEnter choice: ";
while (true) {
    cin >> opt_choice;

    // Check if input is a valid integer and strictly equals 1 or 2
    if (cin.peek() == '\n' && (opt_choice == 1 || opt_choice == 2)) {
        break; // Valid input, exit loop
    }

    // If input is invalid, clear the error flag and empty the buffer
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid choice! Please enter 1 or 2: ";
}
required_torque(Moment , mass_link,length,mass_payload,alphamax,torque_req_Nm,torque_req); //retrieving torque function

//cout << "\nDEBUG - The Computer Calculated Required Torque: " << torque_req << " mNm\n";//for debugging any error during vertification and building
//motor-gear function
MotorGearbox( motor_count,gear_count,mass_motor, mass_gear,torque_motor,omega_motor,Dim_motor,
                 width_motor,gear_ratio, eff,Dim_gear,width_gear,torque_out,omega_out,
                 omega_req,req_torque,torque_req,cost,best_motor_name,best_gear_name,
                 Moment,mass_link,length, mass_payload,alphamax,opt_choice,torque_req_Nm,
                 best_omega_out,best_torque_out,best_cost);

//===================Display the best combination minimizing ==========================
if (best_cost != 999999.0 ) {
    cout << "\n------- BEST COMBINATION -------\n";
    cout << "Motor: " << best_motor_name << endl;
    cout << "Gearbox: " << best_gear_name << endl;

//to choose the priority in minimizing
    if (opt_choice == 1){
        cout << "Minimum Weight: " << best_cost << " kg" << endl;
    } else {
        cout << "Minimum Cost Score: " << best_cost << endl;
    }

    // Print the BEST variables, not the loop remainder variables
    cout << "Output Torque: " << best_torque_out << " mNm" << endl;
    cout << "Output Speed: " << best_omega_out << " rad/s" << endl;
    cout << "Required Torque: " << torque_req << " mNm" << endl;
}
else {
    cout << "\nNo valid combination found.\n";
}

cout<<"1)Restart program"<<endl<<"2)End program"<<endl;
    while (true)
    {
        cin >> restart_program;
        //cin.peek()used to check if there is no characters entered while entering an integer
        if (cin.peek() == '\n' && (restart_program==1 ||restart_program==2 ) )
            {break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice, try again:\n";
    }
}while(restart_program==1);
return 0;
}
