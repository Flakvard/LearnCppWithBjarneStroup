/*
    1. List sets of plausible operations for the examples of real-world objects in 
    §9.1 (such as toaster). 
    startToaster();
    stopToaster();
    checkCelsius();
    checkButton();
    setMeasurementCelsius();
    setTimer();
    startTimer();
    checkTimer();
*/
/*
    2. Design and implement a Name_pairs class holding (name,age) pairs where 
    name is a string and age is a double. Represent that as a vector<string>
    (called name) and a vector<double> (called age) member.
    Provide an input operation read_names() that reads a series of names.
    Provide a read_ages() operation that prompts the user for an age for each name.
    Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) 
    in the order determined by the name vector.
    Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the age
    vector to match.
    Implement all “operations” as member functions.
    Test the class (of course: test early and often).
*/

#include "../std_lib_facilities.h"
class Name_pairs{
    public:
        class Invalid{};
        Name_pairs();
        void read_names();
        void read_ages();
        void print();
        void printSorted();
    private:
        vector<double> age;
        vector<string> name;

};

int main(){
    Name_pairs namepair;
    namepair.print();
    namepair.printSorted();
}

Name_pairs::Name_pairs(){
    Name_pairs::read_names();
    Name_pairs::read_ages();
}

void Name_pairs::read_names(){
    cout<<"Write list of names\nEnd with 'quit'\n";
    string x;
    for(;cin>>x;){
        if(x == "quit") break;
        name.push_back(x);
    }
}
void Name_pairs::read_ages(){
    cout<<"Write ages for each of the name list\nEnd with 'quit'\n";
    string x;
    double age_num = 0;
    for(;cin>>x;){
        if(x == "quit") break;
        istringstream(x)>>age_num;
        age.push_back(age_num);
    }
    if (age.size() != name.size()){
        throw Invalid();
    }
}

void Name_pairs::print(){
    size_t count = name.size();
    for (size_t i = 0; i < count; i++){
        cout<<i<<'\t'<<name[i]<<'\t'<<age[i]<<'\n';
    }
}

void Name_pairs::printSorted(){
    vector<string> nameCopy = name;
    std::sort(nameCopy.begin(),nameCopy.end());

    for(size_t k = 0; k < nameCopy.size(); k++){
        for(size_t i = 0; i < nameCopy.size(); i++){
            if (name[k] == nameCopy[i]){
                cout<<k<<'\t'<<nameCopy[k]<<'\t'<<age[i]<<'\n';
            }
        }
    }
}
