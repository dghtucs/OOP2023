#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	
	// (1)
	int data_;
	int id;
	static int count;//这里很重要，需要用static来实现递加操作
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif