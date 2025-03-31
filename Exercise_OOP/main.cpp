#include <iostream>
#include <concepts>

template <typename T> requires std::floating_point<T>
class Complex_number{
	private:
	T real_part;
	T imag_part;
	public:
	
	// costruttore di default:
	Complex_number() 
		: real_part(0), imag_part(0)
	{} 
	
	// costruttore user-defined
	Complex_number(T r, T i)
		: real_part(r), imag_part(i)
	{}
	
	// ottenere la parte reale
	T real(void) const {
        return real_part;
    }
	
	// ottenere la parte immaginaria
	T imag(void) const {
		return imag_part;
	}
	
	// ottenere il coniugato
	Complex_number<T> conjugated(void) const{
		return Complex_number<T>(real_part, -imag_part);
	}
	
	// overload dell'operatore <<
	std::ostream&
    operator<<(std::ostream& os, const Complex_number<T>& c) {
    if (c.imag() == 0) 
        os << c.real(); // se la parte immaginaria è uguale a 0 il numero compesso è uguale alla parte reale
    else{
		if (c.imag() > 0)
			os << c.real() << "+" << c.imag() << "i"; 
		else 
            os << c.real() << c.imag() << "i"; // se la parte immaginariaè negativa non devo aggiungere - perche questo fa già parte di c.imag()
    }
	return os;
	}
	
	// overload di +=
	Complex_number& operator+=(const Complex_number& other) {
        T a = real_part;
		T b = imag_part;
		T c = other.real();
		T d = other.imag();
		real_part = a + c;
		imag_part = b + d; 
        return *this; // restituisce l'oggetto modificato
	}
	// In questo modo viene modificatol'oggetto che il metodo richiama
	
	// overload di + 
	Complex_number operator+(const Complex_number& other) const { // somma tra due Complex_number 
		Complex_number sum = *this; //copia dell'oggetto corrente
		sum += other; // l'operatore += è stato definito precedentemente
		return sum;  
	}	
	// Definendo in questo modo l'overload di +, non vienie modificato l'oggetto che il metodo richiama, a differenza di +=
	
	// overload di *=
	Complex_number& operator*=(const Complex_number& other) {
        T a = real_part;
		T b = imag_part;
		T c = other.real();
		T d = other.imag();
		real_part = a*c - b*d;   //(a+ib)*(c+id) = ac + iad + ibc + (i)^2bd =  ac + iad + ibc - bd
		imag_part = a*d + b*c;  // Re((a+ib)*(c+id)) = ac - bd   Im((a+ib)*(c+id)) = ad + bc
        return *this; 
	}
	
	// overload di *
	Complex_number operator*(const Complex_number& other) const { // prodotto tra due Complex_number 
		Complex_number prod = *this; 
		prod *= other; // l'operatore *= è stato definito precedentemente
		return prod;  
	}	
		
}

int main() {
    ComplexNumber c1(1, 2);
    ComplexNumber c2(1, -2);
	ComplexNumber c3(2, 3);

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
	std::cout << "c3 = " << c3 << std::endl;

    ComplexNumber sum = c1 + c3;
    std::cout << "c1 + c3 = " << sum << std::endl;

    ComplexNumber prod = c1 * c3;
    std::cout << "c1 * c3 = " << prod << std::endl;

    std::cout << "Il coniugato di c1 è " << c1.conjugate() << std::endl;
	std::cout << "La parte reale di c1 è " <<  c1.real_part() << std::endl;
	std::cout << "La parte immaginaria di c1 è " << c1.imag_part() << std::endl;

    return 0;
}