#include <iostream>
using namespace std;
double calculateFunctionPoints(int EI, int EO, int EQ, 
                               int ILF, int EIF,string complexity) {
    int weightsLow[] = {3, 4, 3, 7, 5};
    int weightsAverage[] = {4, 5, 4, 10, 7};
    int weightsHigh[] = {6, 7, 6, 15, 10};
    
    
    int* weights;
    if (complexity == "low") {
        weights = weightsLow;
    } else if (complexity == "average") {
        weights = weightsAverage;
    } else {
        weights = weightsHigh;
    }

    double UFP = (EI * weights[0] +  EO* weights[1] + EQ * weights[2] +ILF* weights[3] +EIF * weights[4]);
    double CAF = 0.65 +0.01*3*14;
    double FP = UFP*CAF;
    return FP;
}

int main() {
  int EI,EO,EQ,ILF,EIF;
  string complexity;
  cout<<"Enter the values Functional units: "<<endl;
  cout<<"Enter External Inputs(EI): ";
  cin>>EI;
  cout<<"Enter External Onputs(EO): ";
  cin>>EO;
  cout<<"Enter External Inquiries(EQ): ";
  cin>>EQ;
  cout<<"Enter Internal Logical files(ILF): ";
  cin>>ILF;
  cout<<"Enter External Interface files(EIF): ";
  cin>>EIF;
  cout<<"Enter Complexity(LOW,AVERAGE,HIGH): ";
  cin>>complexity;
  double fp = calculateFunctionPoints(EI, EO, EQ, ILF, EIF, complexity);
  cout << "Estimated Function Points (FP): " << fp << endl;
  return 0;
}
