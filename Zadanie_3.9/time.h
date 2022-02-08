#pragma once
class time
{
private:
	int hour;
	int minute;
	int second;
public:
	//����������� �� ���������
	time() : hour(0), minute(0), second(0){}
	time(int h, int m, int s) : hour(h), minute(m), second(s) {}
	//����������� �����������
	time(const time& tmp) : hour(tmp.hour), minute(tmp.minute), second(tmp.second) {}
	//����������
	~time();
	time& operator=(const time& tmp);
	time& operator+=(const time& tmp);
	int gethour() const { return hour; }
	int getminute() const { return minute; }
	int getsecond() const { return second; }
};

