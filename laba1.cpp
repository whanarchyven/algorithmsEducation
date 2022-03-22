#include <iostream>
#include <cstdlib> // для system
#include <string>
using namespace std;

class ArrayClass{
  
  public:
  int array_size;
  int *array;

  ArrayClass(int size){
    array_size=size;
    InitalizeArray();
  }

  void InitalizeArray(){
    array= new int[array_size];
    for(int i=0;i<array_size;i++){
      array[i]=rand() % array_size;
    }
  }

  void PrintArray(){
    for(int i=0;i<array_size;i++){
      if(i%10==0){
        cout<<endl;
      }
      cout<<" "<<array[i];
    }
  }

  bool PrimaryFind(int value){
    for(int i=0;i<array_size;i++){
      if(array[i]==value){
        break;
      }
      if(i==array_size-1){
        return false;
      }
    }
    return true;
  }

  void Sort(void){
    int current_min;
    int current_min_index;
    int i;
    for(i=0;i<array_size;i++){
      current_min=array[i];
      current_min_index=i;
      for(int j=i;j<array_size;j++){
        if(array[j]<current_min){
          current_min=array[j];
          current_min_index=j;
        }
      }
      int temp=array[i];
      array[i]=array[current_min_index];
      array[current_min_index]=temp;
    }
  }

  bool BinaryFind(int value){
    int lower=0;
    int upper=array_size;
    while(true){
      int current=(lower+upper)/2;
      if(array[current]==value){
        return true;
      }
      else if(lower>upper){
        return false;
      }
      else{
        if(array[current]>value){
          upper=current-1;
        }
        else{
          lower=current+1;
        }
      }
    }
  }

  void Insert(int value){
    array[array_size]=value;
    array_size++;
  }

  void InsertSorted(int value){
    Insert(value);
    Sort();
  }

  void Delete(int value){
    int need_index=-1;
    for(int i=0;i<array_size;i++){
      if(array[i]==value){
        need_index=i;
        break;
      }
    }
    if(need_index==-1){
      cout<<"Element not found"<<endl;
    }
    else{
      for(int i=need_index;i<array_size;i++){
        array[i]=array[i+1];
      }
      array_size--;
    }
  }

};

int TerminalPrimerySearch(ArrayClass arr){
  int value;
  string val;
  cout<<"//-------------------------//"<<"\n\n"<<endl;
  cout<<"Input element, that you wanna find, if you can finish, input 'q': ";
  cin>>val;
  if(val=="q"){
    return 0;
  }
  value=stoi(val);
  if(arr.PrimaryFind(value)==true){
    cout<<"Element found"<<endl;
  }
  else{
    cout<<"Element not found"<<endl;
  }
  cout<<"\n\n";
  TerminalPrimerySearch(arr);
};

int TerminalBinarySearch(ArrayClass arr){
  int value;
  string val;
  cout<<"//-------------------------//"<<"\n\n"<<endl;
  cout<<"Input element, that you wanna find, if you can finish, input 'q': ";
  cin>>val;
  if(val=="q"){
    return 0;
  }
  value=stoi(val);
  if(arr.BinaryFind(value)==true){
    cout<<"Element found"<<endl;
  }
  else{
    cout<<"Element not found"<<endl;
  }
  cout<<"\n\n";
  TerminalBinarySearch(arr);
};


// int TerminalInsert(ArrayClass arr){
//   int value;
//   string val;
//   cout<<"//-------------------------//"<<"\n\n"<<endl;
//   cout<<"Input element, that you wanna insert, if you can finish, input 'q': ";
//   cin>>val;
//   if(val=="q"){
//     return 0;
//   }
//   value=stoi(val);
//   arr.Insert(value);
//   cout<<"\n\n";
//   TerminalInsert(arr);
// };

// int TerminalInsertSorted(ArrayClass arr){
//   int value;
//   string val;
//   cout<<"//-------------------------//"<<"\n\n"<<endl;
//   cout<<"Input element, that you wanna insert, if you can finish, input 'q': ";
//   cin>>val;
//   if(val=="q"){
//     return 0;
//   }
//   value=stoi(val);
//   arr.InsertSorted(value);
//   cout<<"\n\n";
//   TerminalInsertSorted(arr);
// };


int main()
{
  int arr_size;
  cout << "Input size of array: ";
  cin>>arr_size;
  ArrayClass laba= ArrayClass(arr_size);
  for(;;){
    // cout<<"Done"<<endl;
    laba.PrintArray();
    cout<<"\n\n"<<endl;
    cout<<"\n";
    cout<<"Change Function:"<<endl;
    cout<<"1.Primary search"<<endl;
    cout<<"2.Sort array"<<endl;
    cout<<"3.Binary find (in sorted array only) "<<endl;
    cout<<"4.Insert element in array"<<endl;
    cout<<"5.Insert element in sorted array"<<endl;
    cout<<"6.Delete element in array"<<endl;
    cout<<"7.Finish the programm"<<endl;
    int choose;
    cout<<"\n---Choose function: ";
    cin>>choose;
    switch(choose){
      case 1:{
        TerminalPrimerySearch(laba);
        break;
      }
      case 2:{
        laba.Sort();
        break;
      }
      case 3:{
        TerminalBinarySearch(laba);
        break;
      }
      case 4:{
        int val;
        cout<<"//-------------------------//"<<"\n\n"<<endl;
        cout<<"Input element, that you wanna insert: ";
        cin>>val;
        laba.Insert(val);
        break;
      }
      case 5:{
        int val;
        cout<<"//-------------------------//"<<"\n\n"<<endl;
        cout<<"Input element, that you wanna insert: ";
        cin>>val;
        laba.InsertSorted(val);
        break;
      }
      case 6:{
        int val;
        cout<<"//-------------------------//"<<"\n\n"<<endl;
        cout<<"Input element, that you wanna delete: ";
        cin>>val;
        laba.Delete(val);
        break;
      }
      case 7:{
        return 0;
      }
    }
  }

  return 0;
}
