template <class T>
class minElement {
    // Complete the class.Make a private variable,constructors and method called
    // check() which takes one parameter and prints the output in new line.
    private:
    T y;
    
    public:
    minElement(T val){
        y = val;
    }
    
    void check(T x){
        if(x < y){
            cout<<x<<endl;
        }else{
            cout<<y<<endl;
        }
    }
};