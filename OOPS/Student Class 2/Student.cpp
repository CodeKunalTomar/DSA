class Student {
	public :
	
		int age;
		const int rollNumber;
		int &x;		// age reference variable

		
		//Initialisation List
		Student(int r, int age) : rollNumber(r), age(age), x(this -> age) {
			//rollNumber = r;
			
		}

		
};

