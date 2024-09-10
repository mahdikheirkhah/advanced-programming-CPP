#include <iostream>
using namespace std;
struct complex {
	double real,imag;
	complex(double x = 0, double y = 0){
		real = x;
		imag = y;
	}
	void input(void){
		cout<<"input the value of real part: "<<endl;
		cin>>real;
		cout<<"input the value of imaginary part:  "<<endl;
		cin>>imag;
	}
	complex add(complex k){
		complex c;
		c.real = real + k.real;
		c.imag = imag + k.imag;
		return c; 
	}
	complex sub(complex k){
		complex c;
		c.real = real - k.real;
		c.imag = imag - k.imag;
		return c;
	}
	complex mul(complex k){
		complex c;
		c.real=(real*k.real)-(imag*k.imag);
		c.imag=(real*k.imag)+(imag*k.real);
		return c;
	}
	complex neg(void){
		complex c;
		c.real=(real)* -1;
		c.imag=(imag)* -1;
		return c;
	}
};
struct myarray{
	int n = 0; 
	complex *a  =  nullptr;
	myarray(complex *ma,int k){
		n = k;
		a=new complex [n];
		static int tedade_cons=0;
		for(auto i=0;i<k;i++){
			a[i].imag= ma[i].imag;
			a[i].real= ma[i].real;
		}
		tedade_cons++;
		cout<<"constructor : "<<tedade_cons<<endl;
	}
	myarray(const myarray& k){
		n=k.n;
		a= new complex[n];
		static int tedade_copycons=0;
		for(auto i=0;i<k.n;i++){
			a[i].imag= k.a[i].imag;
			a[i].real= k.a[i].real;
		}
		tedade_copycons++;
		cout<<"copy constructor : "<<tedade_copycons<<endl;
		}
	myarray add(const myarray& k){
		cout<<"add :"<<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i].add(k.a[i]);
		}
		return c;
	}
	myarray sub(const myarray& k){
		cout<<"sub :"<<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i].sub(k.a[i]);
		}
		return c;
	}
	myarray mul(const myarray& k){
		cout<<"mul :"<<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i].mul(k.a[i]);
		}
		return c;
	}
	myarray neg(void){
		cout<<"neg :"<<endl;
		myarray c(a,n);
	    for (auto i=0;i<n;i++){
			c.a[i] = a[i].neg();
		}
		return c;
	}
	void print (void){
		cout <<"n = "<<n<<endl;
		for (auto i=0;i<n;i++){
			cout << "real part of "<<i<<" element = "<<a[i].real<<endl;
			cout << "imaginary part of ["<<i<<"] element = "<<a[i].imag<<endl;
		}
	}
	~ myarray(){
		static int tedade_deconstructor=0;
		tedade_deconstructor++;
		cout<<"deconstrucor : "<<tedade_deconstructor<<endl;
	}
};
void f1 (void);
void input (double *p,int n);
int getmemory(void);
myarray sort(myarray a); 
int main(int argc, char **argv)
{
	f1();
	return 0;
}
void input (complex *p,int n){
	for(auto i=0;i<n;i++){
		cout<<"input the real part of "<<i<<" element:"<<endl;
		cin>>p[i].real;
		cout<<"input the imaginary part of "<<i<<" element:"<<endl;
		cin>>p[i].imag;
	}
}
int getmemory(void){
	int n;
	cout<<"input the size of array:"<<endl;
	cin>>n;
	return n;
}
myarray sort(myarray a){
	for(int i=0;i<a.n-1;i++){
		if(a.a[i].real>a.a[i+1].real){
			double temp = a.a[i].real;
			a.a[i].real=a.a[i+1].real;
			a.a[i+1].real=temp;
		}
		if(a.a[i].imag>a.a[i+1].imag){
			double temp = a.a[i].imag;
			a.a[i].imag=a.a[i+1].imag;
			a.a[i+1].imag=temp;
		}
	}
	return a;
}
void f1 (void){
	int n;
	n= getmemory();
	complex *x = new complex [n];
	input(x,n);
	myarray a(x,n); 
	myarray b(x,n);
	myarray c(x,n);
	a=sort(a);
	b=a;
    c=a.add(b);
    c.print();
    c=a.sub(b);
    c.print();
    c=a.mul(b);
    c.print();
    c=a.neg();
    c.print();
}   
