#include <iostream>
#include <string>
using namespace std;

class Animal 
{
	string name;
	int age;
public:
	Animal(string name = "", int age = 0) // 디폴트 매개변수
	{
		this->name = name;
		this->age = age;
	}
	Animal(const Animal& animal) {
		this->name = animal.name;
		this->age = animal.age;
	}
	virtual ~Animal(){ cout << "Animal 소멸" << endl; } // 소멸자에 virtual 키워드
	void setName(string name) {	this->name = name; }	// set
	void setAge(int age) { this->age = age; }
	string getName() { return name; }					// get
	int getAge() { return age; }
	friend void running(Animal* animal); // friend 키워드 사용
	virtual void crying() = 0; // 순수 가상함수 crying

};
void running(Animal* animal) {	// running
	cout  << animal->name << "가 달린다" << endl;
}
class Dog:public Animal 
{
	string bark;
public: 
	Dog(string name = "", int age = 0, string bark = "") : Animal(name, age)// 디폴트 매개변수
	{
		this->bark = bark;
	}
	Dog(const Dog& dog) :Animal(dog) 
	{
		this->bark=dog.bark;
	}

	virtual ~Dog() { cout << "Dog 소멸" << endl; } // 소멸자에 virtual 키워드
	void setBark(string bark) { this->bark = bark; } // set
	string getBark() { return bark; }				// get

	void crying() { cout << this->getName() <<"는 " << this->getBark() << endl; }
};
class Cat :public Animal 
{
	string bark;
public:
	Cat(string name = "", int age = 0, string bark = ""):Animal(name,age) // 디폴트 매개변수
	{
		this->bark = bark;
	}
	Cat(const Cat& cat) :Animal(cat) 
	{
		this->bark=cat.bark;
	}
	virtual ~Cat() { cout << "Cat 소멸" << endl; } // 소멸자에 virtual 키워드
	void setBark(string bark) { this->bark = bark; } // set
	string getBark() { return bark; } // get

	void crying() { cout << this->getName() <<"는 " << this->getBark() << endl; }
};
void run(Animal* animal)
{
	running(animal);
	animal->crying();
}


int main() {
	cout << "--추상클래스와 파생 클래스 구현--\n";
	Dog* dog = new Dog("강아지", 4, "멍멍");
	Cat* cat = new Cat("고양이", 2, "야옹");

	cout << "--매개 변수의 다형성 구현--\n";
	run(dog);
	run(cat);
	
	cout << "\n--복사생성자 직접 구현--\n";
	Dog copyDog(*dog);
	cout << copyDog.getName() << endl;
	cout << copyDog.getAge() << endl;
	cout << copyDog.getBark() << endl;

	cout << "\n--소멸자 실행--\n";
	delete dog;
	delete cat;
	return 0;

}
