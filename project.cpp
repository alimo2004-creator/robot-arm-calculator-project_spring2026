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
#include <string> // Required for 'string material'
#define g 9810

using namespace std;

class materials {    // making a class for materials
public:
    double yield;    // Mpa
    double density;  // g/cm^3
    string material;
};

//array of materials
materials mat[]={
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


class motor {
public :
    string motor;
    double mass_motor;   //kg
    double torque_motor; //Nm
    double Dim_motor;    // DIAMETER MOTOR
    double width_motor;  // WIDTH OF MOTOR
    double omega_motor;  // ANGULAR VELOCITY[RAD/S]

};



//array of motor

motor mot[]={
        {"EC-max 22 25W (283856)", 0.11, 0.023, 22, 48.5, 9800},
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
        {"EC-max 22 25W 48V (283860)", 0.110, 0.0232, 22, 48.5, 12900}

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

//array for gear boxes
gear gear_box[]={

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
    {"GP 32 C 456:1", 456, 0.210, 32, 0.65, 49.8}

};

int main()
{
    int shape, mat_choice;
    double Moment, mass_link, mass_payload, length, height, base, radius, I_inertia, alphamax, sigma, density, sigma_yield;

    // -------------------------- Material Selection ----------------------------------
    cout<<"Select material:"<<endl;

    for(int i=0; i<9; i++)
    {
        cout<<i+1<<") "<<mat[i].material<<endl;
    }

    cout<<"10) Add another material"<<endl;


    while (true) {
        cout << "Enter your choice: ";
        cin >> mat_choice;

        if (cin.fail()) {//if the input is not a number
        cin.clear(); // clear the wrong entered input
        cin.ignore(10000, '\n'); // to prevent outputing the error the same number of entered characters
        cout << "Invalid input! Please enter a number." << endl;
        }
        else if (mat_choice < 1 || mat_choice > 10) { // if the input is a number out of range
            cout << "Choice out of range, try again (1-10)." << endl;
        }
        else {
            break; //break the loop if the number is in the range
        }
    }

    density = mat[mat_choice - 1].density;
    sigma_yield = mat[mat_choice - 1].yield;

    //if the user wants to add another material
    if(mat_choice==10)
    {
        cout<<"Enter material density:";
        cin>>density;
        cout<<"Enter yield strength:";
        cin>>sigma_yield;
    }

    // --------------------- Shape Selection & Initial Calcs -------------------
    // do while loop to reset the program if the input is invalid

    do
    {
        cout<<"Select cross section shape{(1)rectangular or (2)circular}:"<<endl;
        cin>>shape;
        cin.clear();
        cin.ignore(10000,'\n');

        // -------------------------------for rectangular calculations-----------------------
        if(shape==1)
        {
            cout<<"Enter dimensions in mm: "<<endl;
            cout<<"base=";
            cin>>base;
            cout<<"height=";
            cin>>height;
            cout<<"length=";
            cin>>length;
            //conversion of density from gm/cm^3 to ton/mm^3 to ensure the stress is in MPa
            mass_link=density*0.000000001*(base*height*length); //link mass
            I_inertia=(base*pow(height,3))/12; //inertia
        }
        // -----------------------for circular calculations-------------------------------
        else if(shape==2)
        {
            cout<<"Enter dimensions in mm: "<<endl;
            cout<<"radius=";
            cin>>radius;
            cout<<"length=";
            cin>>length;
            //conversion of density from gm/cm^3 to ton/mm^3 to ensure the stress is in MPa
            mass_link=density*0.000000001*(M_PI*pow(radius,2)*length);  //mass
            I_inertia=(M_PI*pow(radius,4))/4; //inertia
        }
        else
        {
            cout<<"error (invalid shape)"<<endl;
        }
    } while(shape!=1 && shape!=2);

    cout<<"Enter payload mass in kg:"<<endl;
    cin>>mass_payload;

    //conversion from kg to ton
    mass_payload*=0.001;
    cout<<"Enter maximum angular acceleration (rad/s^2):"<<endl;
    cin>>alphamax;

    // -----------------equation of bending moment-------------------
    Moment=mass_link*g*(length/2)+(mass_payload*g*length)+(mass_link*pow(length/2,2)*alphamax+mass_payload*pow(length,2)*alphamax);
    if(shape==1) //rectangular
        sigma=(Moment*height)/(2*I_inertia);
    else if(shape==2)  //circular
        sigma=(Moment*radius)/I_inertia;

    //to calculate the stress before optimization
    cout<<"stress before optimization= "<<sigma<<" MPa"<<endl;

    // --------------------------- Optimization Loops ---------------------------
    // if the stress is greater than the yield strength
    while(sigma>sigma_yield)
    {
        if(shape==1)
        {
            base*=1.01;
            height*=1.01;
            mass_link=density*0.000000001*(base*height*length);
            I_inertia=(base*pow(height,3))/12;
        }
        else if(shape==2)
        {
            radius*=1.01;
            mass_link=density*0.000000001*(M_PI*pow(radius,2)*length);
            I_inertia=(M_PI*pow(radius,4))/4;
        }
        Moment=mass_link*g*(length/2)+(mass_payload*g*length)+(mass_link*pow(length/2,2)*alphamax+mass_payload*pow(length,2)*alphamax);

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
        Moment=mass_link*g*(length/2)+(mass_payload*g*length)+(mass_link*pow(length/2,2)*alphamax+mass_payload*pow(length,2)*alphamax);

        if(shape==1)
            sigma=(Moment*height)/(2*I_inertia);
        else if(shape==2)
            sigma=(Moment*radius)/I_inertia;
    }

    mass_link*=1000;//to convert the link mass to kgs
    mass_payload*=1000;//to convert the payload mass to kgs

    // stress, mass and dimensions after optimization
    cout<<"stress after optimization= "<<sigma<<" MPa"<<endl;
    cout<<"mass of link after optimization: "<<mass_link<<" Kg"<<endl;

    if(shape==1)
        cout<<"optimized base: "<<base<<" mm"<<endl<<"optimized height: "<<height<<" mm"<<endl;
    else if(shape==2)
        cout<<"optimized radius: "<<radius<<" mm"<<endl;


//------------------------part 2 -------------------------------
double omega_req;
double cost, torque_req, torque_motor, torque_out, eff, gear_ratio;
double omega_out, omega_motor, Dim_motor, width_motor;
double mass_motor, mass_gear, Dim_gear, width_gear;
double best_omega_out = 0, best_torque_out = 0;
int opt_choice;

cout << "\nEnter required speed (rad/s): ";
cin >> omega_req;


cout << "Select optimization priority:\n 1) Minimize Weight\n 2) Minimize Cost \nEnter choice: ";
cin >> opt_choice;


double torque_req_Nm =                        //Required Torque Calculation
    (mass_link * (g/1000.0) * ((length/1000.0) / 2.0)) +
    (mass_payload * (g/1000.0) * (length/1000.0) ) +
    (mass_link * pow((length/1000.0)/2.0, 2) * alphamax) +
    ((mass_payload * pow(length/1000.0, 2)) * alphamax);

// convert Nm to mNm
torque_req = torque_req_Nm * 1000.0;

double best_cost = 999999.0;
string best_motor_name, best_gear_name;

int motor_count = sizeof(mot) / sizeof(mot[0]);//   to count number of motors
int gear_count = sizeof(gear_box) / sizeof(gear_box[0]);//  to count number of gearboxes


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

        if (torque_out >= torque_req && omega_out >= omega_req) {

            if(opt_choice == 1) {
                cost = mass_motor + mass_gear;
            } else {
                cost = (mass_motor + mass_gear) + ((Dim_motor + Dim_gear) / 100.0) + ((width_motor + width_gear) / 100.0);  // Priority: Cost
            }

            if (cost < best_cost) {      // checking on the cost
                best_cost = cost;
                best_motor_name = mot[i].motor;
                best_gear_name = gear_box[j].gear;


                best_omega_out = omega_out;
                best_torque_out = torque_out;
            }
        }
    }
}

//Display the best combination minimizing the cost function
if (best_cost != 999999.0 ) {
    cout << "\n------- BEST COMBINATION -------\n";
    cout << "Motor: " << best_motor_name << endl;
    cout << "Gearbox: " << best_gear_name << endl;

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
return 0;
}
